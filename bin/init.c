#include <string.h>
#include "base.h"

/// Базовая структура для хранения информации об ONT соединений
static struct Ont_records ont_records[NUM_OF_ONT_CONNECTIONS];

void init(void) {
    memset(ont_records, 0, sizeof(struct Ont_records)*NUM_OF_ONT_CONNECTIONS);
}

void close_dll(void) {
    // Пока нечего очищать
}

// Функция получения карточек по одной ONT
Ont_records* get_map(int num_port, int num_ont) {
    if (num_port < 0 || num_port >= NUM_OF_PORTS) {
        return NULL;
    }
    if (num_ont < 0 || num_ont >= NUM_OF_ONT_ON_PORT) {
        return NULL;
    }
    return &ont_records[get_index(num_port, num_ont)];
}