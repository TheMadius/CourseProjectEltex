#ifndef ONT_H
#define ONT_H

#include <time.h>
#include <string.h>
#include <stdbool.h>

/// Константы для обозначения ошибок
typedef enum Errors
{
    NO_ERRORS = 0,
    NUM_PORT_ERROR = -1,
    NUM_ONT_ERROR = -2,
    NULL_PTR_ERROR = -3,
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
}   Ont_status;

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
    int num_port;
    int num_ont;
    char serial[ONT_SERIAL_SIZE];  
    char eq_id[ONT_EQ_ID_SIZE];
    char fw_version[ONT_FW_VERSION_SIZE];
    time_t link_up;
    time_t link_down;   
    enum Ont_status status;
} Ont_info;

/// Структура для хранения событий
typedef struct Ont_records
{
    uint32_t cur_index_of_event;
    uint32_t count_element;
    struct Ont_connection ont_connection[NUM_OF_RECORDS];
} Ont_records;

/// Инициализация библиотеки
void ont__init(void);

/// Деинициализация библиотеки
void ont__close(void);

/// Функция получения карточки по одной ONT
int get_card(
    unsigned int const num_port,
    unsigned int const num_ont,
    struct Ont_records const *const ont_record);

/// Функция расчитывает уникальный индекс для индексации внутри базовой структуры 
int ont__get_index(
    unsigned int const num_port,
    unsigned int const num_ont,
    unsigned int *const index
    );

/// Добавление нового события в базовую структуру
int ont__add_element(struct Ont_info const *const ont_info);

#endif //ONT_H