#include "list.h"
#include "base.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void list__init(Ont_records *list)
{
    if(NULL == list)
    {
        return;
    }

    list->is_close = false;
    list->cur_index_of_event = 0;
}

void list__add_element(
    Ont_connection *element,
    Ont_records *list)
{   
    if(NULL == element
        || NULL == list)
    {
        return;
    }

    if(list->is_close)
    {
        list__init(list);
    }

    strcpy(list->ont_connection[list->cur_index_of_event].eq_id,
            element->eq_id);
    strcpy(list->ont_connection[list->cur_index_of_event].fw_version,
            element->fw_version);
    strcpy(list->ont_connection[list->cur_index_of_event].serial,
            element->serial); 

    list->ont_connection[list->cur_index_of_event].link_down = element->link_down;
    list->ont_connection[list->cur_index_of_event].link_up = element->link_up;
    list->ont_connection[list->cur_index_of_event].status = element->status;

    if(0 == element->link_up)
    {
        list->is_close = true;
    }

    list->cur_index_of_event++;
    list->cur_index_of_event = ist->cur_index_of_event % NUM_OF_RECORDS ;
}


