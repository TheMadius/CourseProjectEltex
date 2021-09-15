 #include <time.h>

 /* Число символов для обозначения серийного номера ONT в текстовом формате. */
int const   ONT_SERIAL_NUM_SIZE = 16;   
 /* Число символов для обозначения наименования ONT в текстовом формате. */     
int const   ONT_EQ_ID_SIZE = 18;  
/* Число символов для обозначения версии прошивки ONT в текстовом формате. */            
int const   ONT_FW_VERSION_SIZE = 32;  
 /* Число записей для одного ONT соединения. */       
int const   NUM_OF_RECORDS = 10;       
 /* Число ONT соединений. */
int const   NUM_OF_ONT_CONNECTIONS = 2048;    

/* Статусы ONT соединения. */
typedef enum Ont_status
{
    /* Активация. */
    Activation = 0, 
     /* Успешная конфигурация Ont. */
    Working,  
     /* Ошибка конфигурации.*/     
    CfgFail,       
    Block
}   Ont_status;

/* Структура записи, информация которой приходит извне. */
typedef struct Ont_connection
{
    /* Серийный номер ONT в текстовом формате. */
    char* serial; 
    /* Наименование ONT в текстовом формате. */       
    char* eq_id;   
    /* Версия прошивки ONT в текстовом формате. */    
    char* fw_version;    
    /* Время активации. День, год, час, минута, секунда. */
    time_t link_up;   
    /* Время деактивации. День, год, час, минута, секунда. */      
    time_t link_down;   
    /* Статус ONT. Возможные статусы: Activation, Working, CfgFail, Block. */    
    enum Ont_status status; 

} Ont_connection;

/* Входная информация об ONT соединении. */
typedef struct Ont_input_info
{
    /* Номер порта */
    int num_port;
    /* Номер устройства  */
    int num_ont;
    /* Серийный номер ONT в текстовом формате. */
    char* serial; 
    /* Наименование ONT в текстовом формате. */       
    char* eq_id;   
    /* Версия прошивки ONT в текстовом формате. */    
    char* fw_version;    
    /* Время активации. День, год, час, минута, секунда. */
    time_t link_up;   
    /* Время деактивации. День, год, час, минута, секунда. */      
    time_t link_down;   
    /* Статус ONT. Возможные статусы: Activation, Working, CfgFail, Block. */    
    enum Ont_status status; 
} Ont_input_info;

/* Список записей на массиве.  */
typedef struct Ont_records
{
    int cur_index_of_event; 
    struct Ont_connection* records;
} Ont_records;

