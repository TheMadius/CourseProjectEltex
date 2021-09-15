 #include <time.h>

/// Константы для обозначения размеров полей структы Ont
typedef enum Ont_connection_fields_sizes
{

    ONT_SERIAL_NUM_SIZE = 16,  
    ONT_EQ_ID_SIZE = 18,          
    ONT_FW_VERSION_SIZE = 32,
} Ont_connection_fields_sizes;

/// Константы для обозначения количества элементов базовой структуры
typedef enum Based_structure_elements_num
{
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
    char serial[ONT_SERIAL_NUM_SIZE];    
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
    char serial[ONT_SERIAL_NUM_SIZE];    
    char eq_id[ONT_EQ_ID_SIZE];
    char fw_version[ONT_FW_VERSION_SIZE]; 
    time_t link_up;    
    time_t link_down;   
    enum Ont_status status; 
} Ont_input_info;

/// Структура для хранения событий
typedef struct Ont_records
{
    int cur_index_of_event; 
    struct Ont_connection records[NUM_OF_RECORDS];
} Ont_records;

/// Базовая структура для хранения информации об ONT соединений
static struct Ont_records ont_records[NUM_OF_RECORDS];

