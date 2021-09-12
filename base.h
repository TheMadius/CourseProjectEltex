#define ONT_SERIAL_NUM_SIZE  16         /* Число символов для обозначения серийного номера ONT в текстовом формате. */
#define ONT_NAME_SIZE  18               /* Число символов для обозначения наименования ONT в текстовом формате. */
#define ONT_FW_VERSION_SIZE 32          /* Число символов для обозначения версии прошивки ONT в текстовом формате. */
#define NUM_OF_RECORDS 10               /* Число записей для одного ONT соединения. */
#define NUM_OF_ONT_CONNECTIONS 2048     /* Число ONT соединений. */

/* Статусы ONT соединения. */
typedef enum Ont_status
{
    Activation = 0, /* Активация. */
    Working,        /* Успешная конфигурация Ont. */
    CfgFail,        /* Ошибка конфигурации.*/
    Block
}   Ont_status;



/* Структура записи, информация которой приходит извне. */
typedef struct Ont_connection
{
    char serial[ONT_SERIAL_NUM_SIZE];        /* Серийный номер ONT в текстовом формате. */
    char eq_id[ONT_NAME_SIZE];         /* Наименование ONT в текстовом формате. */
    char fw_version[ONT_FW_VERSION_SIZE];    /* Версия прошивки ONT в текстовом формате. */
    time_t link_up;         /* Время активации. День, год, час, минута, секунда. */
    time_t link_down;       /* Время деактивации. День, год, час, минута, секунда. */
    enum Ont_status status; /* Статус ONT. Возможные статусы: Activation, Working, CfgFail, Block. */

} Ont_connection;

/* Список записей на массиве.  */
typedef struct Ont_records
{
    int cur_index_of_event; 
    struct Ont_connection records[NUM_OF_RECORDS];
} Ont_records;
