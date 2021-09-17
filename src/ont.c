#include "ont.h"
#include "list.h"
#include <stdlib.h>

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
