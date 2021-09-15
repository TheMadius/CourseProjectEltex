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