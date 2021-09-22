#include "../include/ont.h"
#include "pthread.h"

/// Структура для хранения событий
typedef struct Ont_records
{
    uint32_t cur_index_of_event;
    uint32_t count_element;
    struct Ont_connection ont_connection[NUM_OF_RECORDS];
} Ont_records;

/** Функция сравнения статусов.
 *  При совпадении статусов функция возвращает true,
 *  иначе возвращает false.
*/ 
static bool find_status(
                    const struct Ont_connection *const ont,
                    const enum Ont_status *const status);

/** Функция сравнения времени.
 *  При совпадении времени функция возвращает true,
 *  иначе возвращает false.
*/ 
static bool find_time(
                    const struct Ont_connection *const ont,
                    const time_t *const time);

/// Функция расcчитывает уникальный индекс для индексации внутри базовой структуры 
static int ont__get_index(
    uint32_t const num_port,
    uint32_t const num_ont,
    uint32_t *const index);

/// Функция добавления нового элемента в список
static int list__add_element(
    struct Ont_connection *const element,
    struct Ont_records *const list);

/// Функция определения количества элементов списка
static int list__get_size(
    struct Ont_records *const list,
    uint32_t *const count);

/// Функция инициализации списка
static int list__init(struct Ont_records *const list);

/// Базовая структура для хранения информации об ONT соединений
static struct Ont_records ont_records[NUM_OF_ONT_CONNECTIONS] = {0};

/// Мьютекс для синхронизации обращения к базовой структуре
static pthread_rwlock_t lock = {0};

/// Функция инициализации библиотеки
__attribute__((constructor))
static void _init(void);

/// Функция деинициализации библиотеки
__attribute__((destructor))
static void _fini(void);

/** Функция поиска карточки, подходящей по фильтру.
 * 
 * При успешном выполнении, функция возвращает указатель на карточку,
 * соответствующей фильтру.
 * 
 * При наличии ошибки, функция возвращает NULL.
*/
static void* find(
    void *base,
    void *const key,
    size_t num,
    size_t size,
    bool (*compare)(const void *, const void *));

__attribute__((constructor))
static void _init(void) 
{
    pthread_rwlock_init(&lock, NULL);
    for(int i = 0; i < NUM_OF_ONT_CONNECTIONS; i++) 
    {
        list__init(&ont_records[i]);
    }
}

__attribute__((destructor))
static void _fini(void) 
{
    for(int i = 0; i < NUM_OF_ONT_CONNECTIONS; i++) 
    {
        list__init(&ont_records[i]);
    }
}

/** Функция вычисления уникального индекса для индексации внутри базовой структуры.
 * 
 * При успешном вычислении, функция возвращает NO_ERRORS и инициализирует
 * значение указателя index, вычисленным индексом.
 * 
 * При наличии ошибки, функция возвращает код, соответствующий ошибке.
*/
static int ont__get_index(
    uint32_t const num_port, 
    uint32_t const num_ont,
    uint32_t *const index)
{
    enum Errors errors = NO_ERRORS;
    bool const is_num_port_in_range = (num_port >= NUM_OF_PORTS);
    bool const is_num_ont_in_range = (num_ont >= NUM_OF_ONT_ON_PORT);


    if (NULL == index)
    {
        errors = NULL_PTR_ERROR;
        goto finally;
    }

    if (is_num_port_in_range)
    {
        errors = NUM_PORT_ERROR;
        goto finally;
    }
    if (is_num_ont_in_range)
    {
        errors = NUM_ONT_ERROR;
        goto finally;
    }

    *index = num_port * NUM_OF_ONT_ON_PORT + num_ont;

 finally:
    return errors;
}

/** Функция добавления нового события в базовую структуру
 * 
 * При успешном добавлении, функция возвращает NO_ERRORS и 
 * новое событие сохранено в базовой структуре, в соответствущем
 * для него месте в структуре.
 * 
 * При наличии ошибки, функция возвращает код, соответствующий ошибке.
*/
int ont__add_card(struct Ont_info const *const ont_info)
{
    enum Errors errors = NO_ERRORS;
    uint32_t index = 0;
    struct Ont_connection ont_connection = {0};

    if (NULL == ont_info)
    {
        errors = NULL_PTR_ERROR;
        goto finally;
    }

    errors = ont__get_index(ont_info->num_port, ont_info->num_ont, &index);

    if (errors < 0)
    {
        goto finally;
    }

    strncpy(ont_connection.serial, ont_info->serial, ONT_SERIAL_SIZE);
    strncpy(ont_connection.eq_id, ont_info->eq_id, ONT_EQ_ID_SIZE);
    strncpy(ont_connection.fw_version, ont_info->fw_version, ONT_FW_VERSION_SIZE);
    ont_connection.link_up = ont_info->link_up;
    ont_connection.link_down = ont_info->link_down;
    ont_connection.status = ont_info->status;

    errors = pthread_rwlock_wrlock(&lock);

    if (errors < 0)
    {
        errors = MUTEX_ERROR;
        goto finally;
    }

    errors = list__add_element(&ont_connection, &ont_records[index]);

    errors = pthread_rwlock_unlock(&lock);

    if (errors < 0)
    {
        errors = MUTEX_ERROR;
        goto finally;
    }

 finally:
    return errors;
}

/** Функция получения всех событий по одной ont
 * 
 * При успешном выполнении, функция возвращает код ошибки NO_ERRORS,
 * а указатель ont_connection, имеет копию данных связанных с нужной ont.
 * 
 * При наличии ошибки, функция возвращает код, соответствующий ошибке.
*/
int ont__get_card(
    uint32_t const num_port,
    uint32_t const num_ont,
    struct Ont_connection *const ont_connection,
    size_t const size)
{
    enum Errors errors = NO_ERRORS;
    uint32_t index = 0;

    if(NUM_OF_RECORDS != size)
    {
        errors = ARRAY_SIZE_ERROR;
        goto finally;
    }

    errors = ont__get_index(num_port, num_ont, &index);

    if (errors < 0)
    {
        goto finally;
    }

    if (NULL == ont_connection)
    {
        errors = NULL_PTR_ERROR;
        goto finally;
    }
    
    errors = pthread_rwlock_rdlock(&lock);

    if (errors < 0)
    {
        errors = MUTEX_ERROR;
        goto finally;
    }

    memcpy(ont_connection, ont_records[index].ont_connection, sizeof(struct Ont_connection) * NUM_OF_RECORDS);

    errors = pthread_rwlock_unlock(&lock);

    if (errors < 0)
    {
        errors = MUTEX_ERROR;
        goto finally;
    }
    
 finally:
    return errors;
}

static void* find(
    void *base,
    void *const key,
    size_t const num,
    size_t const size,
    bool (*compare)(const void *, const void *))
{
    void *result = NULL;

    for(size_t i = 0; i < num; i++)
    {
        if(compare(base, key))
        {
            result = base;
            goto finally;
        }

        base = (char*)base + size;
    }
 finally:

    return result;
}

static bool find_status(
                    struct Ont_connection const *const ont,
                    enum Ont_status const *const status)
{
    return ont->status == *status;
}

static bool find_time(
                    const struct Ont_connection *const ont,
                    const time_t *const time)
{
    return ont->link_up >= *time;
}

/** Функция получения карточек по одной ONT с фильтром.
 * 
 * При успешном выполнении, функция возвращает указатель на 
 * массив типа Ont_connection, содержащий копию данных связанных с 
 * нужной ont.
 * При наличии ошибки, функция возвращает код, соответствующий ошибке.
*/
int ont__get_card_filter(
    uint32_t const num_port,
    uint32_t const num_ont,
    void *const key,
    struct Ont_connection * const ont_connection,
    enum Card_filter const filter)
{
    int errors = NO_ERRORS;
    uint32_t index = 0;
    void *data = NULL;
    struct Ont_records records = {0};

    errors = ont__get_index(num_port, num_ont, &index);

    if(errors < 0)
    {
        goto finally;
    }

    records = ont_records[index]; 

    errors = pthread_rwlock_rdlock(&lock);
    if (errors < 0)
    {
        errors = MUTEX_ERROR;
        goto finally;
    }

    switch (filter)
    {
        case FIND_STATUS:
        {     
            data = find(records.ont_connection, key, records.count_element, sizeof(struct Ont_connection),
                            (bool (*)(const void *, const void *))find_status);
            break;
        }
        case FIND_TIME:
        {    
            data = find(records.ont_connection, key, records.count_element, sizeof(struct Ont_connection),
                            (bool (*)(const void *, const void *))find_time);
            break;
        }
        default:
        {
            errors = NOT_FOUND_ERROR;
            pthread_rwlock_unlock(&lock);
            goto finally;
        }
    }

    if(NULL == data)
    {
        errors = NOT_FOUND_ERROR;
        pthread_rwlock_unlock(&lock);
        goto finally;
    }

    *ont_connection = *((struct Ont_connection *)data);

    errors = pthread_rwlock_unlock(&lock);
    if (errors < 0)
    {
        errors = MUTEX_ERROR;
        goto finally;
    }
    
 finally:

    return errors;
}


static int list__init(struct Ont_records *const list)
{
    int errors = NO_ERRORS;
    if(NULL == list)
    {
        errors = LIST_NULL_ERROR;
        goto finally;
    }

    list->cur_index_of_event = 0;
    list->count_element = 0;
    
 finally:
    
    return errors;
}

static int list__get_size(
    struct Ont_records *const list,
    uint32_t *const count)
{
    int errors = NO_ERRORS;

    if(NULL == list)
    {
        errors = LIST_NULL_ERROR;
        goto finally;
    }

    if(NULL == count)
    {
        errors = NULL_PTR_ERROR;
        goto finally;
    }
    
    *count = ( NUM_OF_RECORDS < list->count_element) ? NUM_OF_RECORDS : list->count_element;
    
 finally:
    
    return errors;
}

static int list__add_element(
    struct Ont_connection *const element,
    struct Ont_records *const list)
{   
    int errors = NO_ERRORS;
    uint32_t index_add = 0;

    if(NULL == element)
    {
        errors = VALUE_NULL_ERROR;
        goto finally;
    }

    if(NULL == list)
    {
        errors = LIST_NULL_ERROR;
        goto finally;
    }

    index_add = list->cur_index_of_event; 

    strncpy(list->ont_connection[index_add].eq_id,
            element->eq_id, ONT_EQ_ID_SIZE);
    strncpy(list->ont_connection[index_add].fw_version,
            element->fw_version, ONT_FW_VERSION_SIZE);
    strncpy(list->ont_connection[index_add].serial,
            element->serial, ONT_SERIAL_SIZE);

    list->ont_connection[index_add].link_down = element->link_down;
    list->ont_connection[index_add].link_up = element->link_up;
    list->ont_connection[index_add].status = element->status;

    list->cur_index_of_event++;
    
    list->count_element++;
    errors = list__get_size(list, &(list->count_element)); 

    if(0 > errors)
    {
        errors = NULL_PTR_ERROR;
        goto finally;
    }

    list->cur_index_of_event %= NUM_OF_RECORDS;

 finally:

    return errors;
}
