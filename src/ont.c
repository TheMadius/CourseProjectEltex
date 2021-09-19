#include "ont.h"
#include "list.h"
#include <stdlib.h>

void ont__init(void) 
{
    for(int i = 0; i < NUM_OF_ONT_CONNECTIONS; i++) 
    {
        list__init(&ont_records[i]);
    }
}

void ont__close(void) 
{
    for(int i = 0; i < NUM_OF_ONT_CONNECTIONS; i++) 
    {
        list__init(&ont_records[i]);
    }
}

/// Функция расчитывает уникальный индекс для индексации внутри базовой структуры 
int get_index(
    int num_port, 
    int num_ont
    )
{
    if  (num_port < 0
        || num_port >= NUM_OF_PORTS)
    {
        return -1;
    }
    
    if  (num_ont < 0
        || num_ont >= NUM_OF_ONT_ON_PORT)
    {
        return -1;
    }
    return (num_port * NUM_OF_ONT_ON_PORT + num_ont);
}

/// Добавление нового события в базовую структуру
void add_new_element(Ont_info *ont_info)
{
    if(NULL == ont_info)
    {
        return;
    }

    int index = get_index(ont_info->num_port, ont_info->num_ont);

    Ont_connection *ont_connection = malloc(sizeof(*ont_connection));

    strcpy(ont_connection->serial, ont_info->serial);
    strcpy(ont_connection->eq_id, ont_info->eq_id);
    strcpy(ont_connection->fw_version, ont_info->fw_version);
    ont_connection->link_up = ont_info->link_up;
    ont_connection->link_down = ont_info->link_down;
    ont_connection->status = ont_info->status;

    list__add_element(ont_connection, &ont_records[index]);

    free(ont_connection);
}

// Функция получения карточек по одной ONT
int get_card(
    unsigned int const num_port,
    unsigned int const num_ont,
    struct Ont_records const *const ont_record)
{
    enum Errors errors = NO_ERRORS;
    bool range_of_num_port = (num_port < 0)  ||  (num_port >= NUM_OF_PORTS);
    bool range_of_num_ont = (num_ont < 0)  ||  (num_ont >= NUM_OF_ONT_ON_PORT);
    unsigned int index = 0;

    if  (range_of_num_port)
    {
        errors = NUM_PORT_ERROR;
        goto finally;
    }
    
    if  (range_of_num_ont)
    {
        errors = NUM_ONT_ERROR;
        goto finally;
    }

    errors = ont__get_index(num_port, num_ont, &index);

    if (errors < 0)
    {
        goto finally;
    }

    ont_record = &ont_records[index];

     finally:
    return errors;
}