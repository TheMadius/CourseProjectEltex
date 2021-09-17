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

int list__get_size(Ont_records *list)
{
    if(10 < list->cur_index_of_event)
    {
        return 10;
    }
    else
    {
        return list->cur_index_of_event;
    }
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

    strcpy(list->ont_connection[list->cur_index_of_event % NUM_OF_RECORDS ].eq_id,
            element->eq_id);
    strcpy(list->ont_connection[list->cur_index_of_event % NUM_OF_RECORDS ].fw_version,
            element->fw_version);
    strcpy(list->ont_connection[list->cur_index_of_event % NUM_OF_RECORDS ].serial,
            element->serial); 

    list->ont_connection[list->cur_index_of_event % NUM_OF_RECORDS ].link_down = element->link_down;
    list->ont_connection[list->cur_index_of_event % NUM_OF_RECORDS ].link_up = element->link_up;
    list->ont_connection[list->cur_index_of_event % NUM_OF_RECORDS ].status = element->status;

    if(0 == element->link_down)
    {
        list->is_close = true;
    }

    list->cur_index_of_event++;

}


