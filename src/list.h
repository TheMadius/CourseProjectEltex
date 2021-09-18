#ifndef LIST_H
#define LIST_H

#include "ont.h"

///Коды ошибок
typedef enum Error_list
{
    NO_ERROR = 0,
    VALUE_NULL_ERROR = -1,
    LIST_NULL_ERROR = -2,
} Error_list;

int list__add_element(
    struct Ont_connection *const element,
    struct Ont_records *const list);

static int list__get_size(Ont_records *const list);

int list__init(Ont_records *const list);

#endif