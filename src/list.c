#include "list.h"
#include "ont.h"
#include <stdio.h>
#include <string.h>

int list__init(struct Ont_records *const list)
{
    if(NULL == list)
    {
        return LIST_NULL_ERROR;
    }

    list->cur_index_of_event = 0;
    list->count_element = 0;
}

static int list__get_size(struct Ont_records *const list)
{
    if(NULL == list)
    {
        return LIST_NULL_ERROR;
    }

    return ( NUM_OF_RECORDS < list->count_element) ? NUM_OF_RECORDS : list->count_element;
}

int list__add_element(
    struct Ont_connection *const element,
    struct Ont_records *const list)
{   
    int errno = NO_ERROR;

    if(NULL == element)
    {
        errno = VALUE_NULL_ERROR;
        goto end_function;
    }

    if(NULL == list)
    {
        errno = LIST_NULL_ERROR;
        goto finally;
    }

    int index_add = list->cur_index_of_event; 

    strncpy(list->ont_connection[index_add].eq_id,
            element->eq_id, ONT_EQ_ID_SIZE);
    strncpy(list->ont_connection[index_add].fw_version,
            element->fw_version, ONT_FW_VERSION_SIZE);
    strncpy(list->ont_connection[index_add].serial,
            element->serial, ONT_SERIAL_NUM_SIZE);

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


