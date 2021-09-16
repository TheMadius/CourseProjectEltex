#ifndef LIST_H
#define LIST_H

#include "base.h"

void list__add_element(
    Ont_connection *element,
    Ont_records *list);

void list__init(Ont_records *list);

#endif