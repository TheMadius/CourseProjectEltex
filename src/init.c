#include <string.h>
#include "base.h"
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
    // Пока нечего очищать
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
