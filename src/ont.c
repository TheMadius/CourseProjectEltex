#include "ont.h"
#include "list.h"



/// Базовая структура для хранения информации об ONT соединений
static struct Ont_records ont_records[NUM_OF_ONT_CONNECTIONS] = {0};

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

    strncpy(ont_connection->serial, ont_info->serial, ONT_SERIAL_SIZE);
    strncpy(ont_connection->eq_id, ont_info->eq_id, ONT_EQ_ID_SIZE);
    strncpy(ont_connection->fw_version, ont_info->fw_version, ONT_FW_VERSION_SIZE);
    ont_connection->link_up = ont_info->link_up;
    ont_connection->link_down = ont_info->link_down;
    ont_connection->status = ont_info->status;

    errors = list__add_element(&ont_connection, &ont_records[index]);

     finally:
    return errors;
}
