 /* Число символов для обозначения серийного номера ONT в текстовом формате. */
const ONT_SERIAL_NUM_SIZE  16   
 /* Число символов для обозначения наименования ONT в текстовом формате. */     
const ONT_NAME_SIZE  18  
/* Число символов для обозначения версии прошивки ONT в текстовом формате. */            
const ONT_FW_VERSION_SIZE 32   
 /* Число записей для одного ONT соединения. */       
const NUM_OF_RECORDS 10       
 /* Число ONT соединений. */
const NUM_OF_ONT_CONNECTIONS 2048    

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
    char serial[ONT_SERIAL_NUM_SIZE]; 
    /* Наименование ONT в текстовом формате. */       
    char eq_id[ONT_NAME_SIZE];   
    /* Версия прошивки ONT в текстовом формате. */    
    char fw_version[ONT_FW_VERSION_SIZE];    
    /* Время активации. День, год, час, минута, секунда. */
    time_t link_up;   
    /* Время деактивации. День, год, час, минута, секунда. */      
    time_t link_down;   
    /* Статус ONT. Возможные статусы: Activation, Working, CfgFail, Block. */    
    enum Ont_status status; 

} Ont_connection;

/* Список записей на массиве.  */
typedef struct Ont_records
{
    int cur_index_of_event; 
    struct Ont_connection records[NUM_OF_RECORDS];
} Ont_records;
