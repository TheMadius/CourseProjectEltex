#include "ont.h"

/// Базовая структура для хранения информации об ONT соединений
static struct Ont_records ont_records[NUM_OF_ONT_CONNECTIONS] = {0};

void _init() 
{
    for(int i = 0; i < NUM_OF_ONT_CONNECTIONS; i++) 
    {
        list__init(&ont_records[i]);
    }
}

void _fini() 
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
 * При наличии ошибки, функция возвращает код, соответсвующий ошибке.
*/
int ont__get_index(
    unsigned int const num_port, 
    unsigned int const num_ont,
    unsigned int *const index)

{
    enum Errors errors = NO_ERRORS;
    bool is_num_port_in_range = (num_port < 0) || (num_port >= NUM_OF_PORTS);
    bool is_num_ont_in_range = (num_ont < 0) || (num_ont >= NUM_OF_ONT_ON_PORT);

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

    if (NULL == index)
    {
        errors = NULL_PTR_ERROR;
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
 * При наличии ошибки, функция возвращает код, соответсвующий ошибке.
*/
int ont__add_card(struct Ont_info const *const ont_info)
{
    enum Errors errors = NO_ERRORS;
    unsigned int index = 0;
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

    errors = list__add_element(&ont_connection, &ont_records[index]);

     finally:
    return errors;
}

// Функция получения карточек по одной ONT
int get_card(
    unsigned int const num_port,
    unsigned int const num_ont,
    struct Ont_records *const ont_record)
{
    enum Errors errors = NO_ERRORS;
    unsigned int index = 0;

    errors = ont__get_index(num_port, num_ont, &index);

    if (errors < 0)
    {
        goto finally;
    }

    *ont_record = ont_records[index];

     finally:
    return errors;
}


void* find(
    void *base,
    void *const key,
    size_t num,
    size_t size,
    bool (*compare)(const void *, const void *))
{
    void *result = NULL;
    for(int i = 0; i < num; i++)
    {
        if(compare(base, key))
        {
            result = base;
            goto finally;
        }
        base += size;
    }
     finally:

    return result;
}

static bool find_status(
                    const struct Ont_connection * ont,
                    const enum Ont_status * status)
{
    return ont->status == *status;
}

static bool find_time(
                    const struct Ont_connection * ont,
                    const time_t * time)
{
    return ont->link_up >= *time;
}

// Функция получения карточек по одной ONT с фильтром
int get_card_filter(
    uint32_t const num_port,
    uint32_t const num_ont,
    void *const key,
    struct Ont_connection * const ont_connection,
    enum Card_filter filter)
{
    int error = NO_ERRORS;
    unsigned int index = 0;
    struct Ont_records records = {0};

    error = ont__get_index(num_port, num_ont, &index);

    if(error < 0)
    {
        goto finally;
    }

    records = ont_records[index]; 

    switch (filter)
    {
        case FIND_STATUS:
        {
            void *data = find(records.ont_connection, key, records.count_element, sizeof(struct Ont_connection),
                            (bool (*)(const void *, const void *))find_status);
            if(NULL == data)
            {
                error = NULL_PTR_ERROR;
                goto finally;
            }
            *ont_connection = *((struct Ont_connection *)data);
            break;
        }
        case FIND_TIME:
        {
            void *data = find(records.ont_connection, key, records.count_element, sizeof(struct Ont_connection),
                            (bool (*)(const void *, const void *))find_time);
            if(NULL == data)
            {
                error = NULL_PTR_ERROR;
                goto finally;

            }
            *ont_connection = *((struct Ont_connection *)data);
            break;
        }
        default:
        {
            error = NOT_FOUND_ERROR;
            goto finally;
        }
    }
    
     finally:

    return error;
}


int list__init(struct Ont_records *const list)
{
    int error = NO_ERRORS;
    if(NULL == list)
    {
        error = LIST_NULL_ERROR;
        goto finally;
    }

    list->cur_index_of_event = 0;
    list->count_element = 0;
    
     finally:
    
    return error;
}

static int list__get_size(struct Ont_records *const list)
{
    int count = 0;
    
    if(NULL == list)
    {
        count = LIST_NULL_ERROR;
        goto finally;
    }
    
    count = ( NUM_OF_RECORDS < list->count_element) ? NUM_OF_RECORDS : list->count_element;
    
     finally:
    
    return count;
}

int list__add_element(
    struct Ont_connection *const element,
    struct Ont_records *const list)
{   
    int error = NO_ERRORS;

    if(NULL == element)
    {
        error = VALUE_NULL_ERROR;
        goto finally;
    }

    if(NULL == list)
    {
        error = LIST_NULL_ERROR;
        goto finally;
    }

    int index_add = list->cur_index_of_event; 

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
    list->count_element = list__get_size(list); 

    list->cur_index_of_event %= NUM_OF_RECORDS;

     finally:

    return error;

}
