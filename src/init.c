#include <string.h>
#include <stdlib.h>
#include "ont.h"
#include "list.h"

void init(void) 
{
    for(int i = 0; i < NUM_OF_ONT_CONNECTIONS; i++) 
    {
        list__init(&ont_records[i]);
    }
}

void close_dll(void) 
{
    for(int i = 0; i < NUM_OF_ONT_CONNECTIONS; i++) 
    {
        list__init(&ont_records[i]);
    }
}

// Функция получения карточек по одной ONT
Ont_records* get_map(
    int num_port,
    int num_ont)
{
    if  (0 > num_port 
        || NUM_OF_PORTS <= num_port)
    {
        return NULL;
    }
    
    if  (0 > num_ont
        || NUM_OF_ONT_ON_PORT <= num_ont)
    {
        return NULL;
    }

    return &ont_records[get_index(num_port, num_ont)];
}

Ont_records* get_map_by_time(
    time_t t1,
    time_t t2,
    Ont_records *new_list,
    Ont_records *list)
{
    int len_list = list__get_size(list);

    for(int i = 0; i < len_list; i++)
    {
        if(list->ont_connection[i].link_up >= t1 
            && list->ont_connection[i].link_up <= t2)
        {
            list__add_element(&list->ont_connection[i], new_list);
        }
    }
}

Ont_records* get_map_by_status(
    enum Ont_status status,
    Ont_records *new_list,
    Ont_records *list)
{
    int len_list = list__get_size(list);

    for(int i = 0; i < len_list; i++)
    {
        if(list->ont_connection[i].status == status)
        {
            list__add_element(&list->ont_connection[i], new_list);
        }
    }
}

Ont_records* get_map_filter(
    int num_port,
    int num_ont,
    char * fmt,
    ...)
{
    if  (0 > num_port 
        || NUM_OF_PORTS <= num_port
        || NULL == fmt
        || 0 > num_ont
        || NUM_OF_ONT_ON_PORT <= num_ont)
    {
        return NULL;
    }
    
    Ont_records *new_list = malloc(sizeof(Ont_records));
    Ont_records *list = &ont_records[get_index(num_port, num_ont)];

    int len = strlen(fmt);
    char *str = fmt;

    for( ;*str;str++)
    {
        if('-' == *str)
        {
            str++;
            break;
        }
    }

    if('t' == *str)
    {
        time_t t1;
        time_t t2;

        str = fmt;
        str += len + 1;

        t1 = *((time_t *)str);
        str += sizeof(time_t);
        t2 = *((time_t *)str);  

        get_map_by_time(t1, t2, new_list, list);
                
    } else if ('s' == *str)
    {
        str = fmt;
        str += len + 1;

        enum Ont_status status = *((Ont_status *)str);
        get_map_by_status(status,new_list,list);        
        
    } else
    {
        return NULL;
    }
    
    return new_list;
}
