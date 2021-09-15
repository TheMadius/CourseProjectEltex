#include "base.h"

/// Функция расчитывает уникальный индекс для индексации внутри базовой структуры 
int get_index(
    int num_port, 
    int num_ont)
{
    return (num_port * 128 + num_ont);
}

/// Добавление нового события в базовую структуру
void add_new_element(Ont_info *ont_info)
{
    int index = get_index(ont_info->num_port, ont_info->num_ont);
    int cur_index_of_event = ont_records[index].cur_index_of_event;
    Ont_connection *ont_connection = &(ont_records[index].ont_connection[cur_index_of_event]);

    strcpy(ont_connection->serial, ont_info->serial);
    strcpy(ont_connection->eq_id, ont_info->eq_id);
    strcpy(ont_connection->fw_version, ont_info->fw_version);
    ont_connection->link_up = ont_info->link_up;
    ont_connection->link_down = ont_info->link_down;
}
