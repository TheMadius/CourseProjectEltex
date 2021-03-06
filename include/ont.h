#ifndef ONT_H
#define ONT_H

#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

/// Константы для обозначения ошибок
typedef enum Errors
{
    NO_ERRORS = 0,
    NUM_PORT_ERROR = -1,
    NUM_ONT_ERROR = -2,
    NULL_PTR_ERROR = -3,
    NOT_FOUND_ERROR = -4,
    VALUE_NULL_ERROR = -5,
    LIST_NULL_ERROR = -6,
    ARRAY_SIZE_ERROR = -7,
    WRONG_VALUE_ERROR = -8,
    MUTEX_ERROR = -9,
} Errors;

/// Константы для обозначения размеров полей структы Ont
typedef enum Ont_connection_fields_sizes
{
    ONT_SERIAL_SIZE = 16,
    ONT_EQ_ID_SIZE = 18,
    ONT_FW_VERSION_SIZE = 32,
} Ont_connection_fields_sizes;

/// Константы для обозначения количества элементов базовой структуры
typedef enum Based_structure_elements_num
{
    NUM_OF_PORTS = 16,
    NUM_OF_ONT_ON_PORT = 128,
    NUM_OF_RECORDS = 10,
    NUM_OF_ONT_CONNECTIONS = 2048,
} Based_structure_elements_num;

/// Константы для обозначения ONT состояний
typedef enum Ont_status
{
    ACTIVATION = 0,
    WORKING,
    CFGFAIL,
    BLOCK,
}   Ont_status;

/// Константы для поиска в get_card_filter
typedef enum Card_filter
{
    FIND_STATUS = 0,
    FIND_TIME,
}  Card_filter ;

/// Структура ONT событий
typedef struct Ont_connection
{
    char serial[ONT_SERIAL_SIZE];
    char eq_id[ONT_EQ_ID_SIZE];
    char fw_version[ONT_FW_VERSION_SIZE];
    time_t link_up;
    time_t link_down;
    enum Ont_status status;

} Ont_connection;

/// Структура с данными об ONT, которая поступает извне
typedef struct Ont_info
{
    uint32_t num_port;
    uint32_t num_ont;
    char serial[ONT_SERIAL_SIZE];
    char eq_id[ONT_EQ_ID_SIZE];
    char fw_version[ONT_FW_VERSION_SIZE];
    time_t link_up;
    time_t link_down;
    enum Ont_status status;
} Ont_info;

/// Добавление нового события в базовую структуру
int ont__add_card(struct Ont_info const *const ont_info);

/// Функция получения карточки по одной ONT
int ont__get_card(
    uint32_t const num_port,
    uint32_t const num_ont,
    struct Ont_connection *const ont_connection,
    size_t const size);

// Функция получения карточек по одной ONT с фильтром
int ont__get_card_filter(
    uint32_t const num_port,
    uint32_t const num_ont,
    void *const key,
    struct Ont_connection * const ont_connection,
    enum Card_filter filter);

#endif //ONT_H
