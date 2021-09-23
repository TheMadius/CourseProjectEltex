#include "tap.h"
#include "../include/ont.h"

int test1_ont__add_card(struct Ont_info const *const ont_info)
{  
    enum Errors errors = NO_ERRORS;

    errors = ont__add_card(ont_info);

    return errors;
}


int test2_ont__add_card(unsigned int const num_port)
{
    enum Errors errors = NO_ERRORS;
    struct Ont_info ont_info = {0};

    ont_info.num_port = num_port;
    errors = ont__add_card(&ont_info);

    return errors;
}


int test3_ont__add_card(unsigned int const num_ont)
{
    enum Errors errors = NO_ERRORS;
    struct Ont_info ont_info = {0};

    ont_info.num_ont = num_ont;
    errors = ont__add_card(&ont_info);

    return errors;
}

int test1_ont__get_card(
    uint32_t const num_port,
    uint32_t const num_ont)
{
    enum Errors errors = NO_ERRORS;
    struct Ont_connection ont_connection[NUM_OF_RECORDS];
    memset(ont_connection, 0, sizeof(struct Ont_connection) * NUM_OF_RECORDS);

    errors = ont__get_card(num_port, num_ont, ont_connection, NUM_OF_RECORDS);

    return errors;
}

int test2_ont__get_card()
{
    enum Errors errors = NO_ERRORS;

    errors = ont__get_card(0, 0, NULL, NUM_OF_RECORDS);

    return errors;
}

int test3_ont__get_card(
    uint32_t const num_port,
    uint32_t const num_ont)
{
    enum Errors errors = NO_ERRORS;

    struct Ont_info ont_info = {0};
    ont_info.num_port = num_port;
    ont_info.num_ont = num_ont;
    snprintf(ont_info.serial, ONT_SERIAL_SIZE, "123456");

    errors = ont__add_card(&ont_info);
    if (0 > errors )
    {
        goto finally;
    }

    struct Ont_connection ont_connection[NUM_OF_RECORDS];
    memset(ont_connection, 0, sizeof(struct Ont_connection) * NUM_OF_RECORDS);
    errors = ont__get_card(num_port, num_ont, ont_connection, NUM_OF_RECORDS);
    if (0 > errors )
    {
        goto finally;
    }

    if (0 != strcmp(ont_connection[0].serial, ont_info.serial))
    {
        errors = WRONG_VALUE_ERROR;
        goto finally;
    }

 finally:
    return errors;
}

int test_ont__get_card_filter(
    uint32_t const num_port,
    uint32_t const num_ont,
    uint32_t const num_port_fun,
    uint32_t const num_ont_fun,
    enum Ont_status status,
    enum Ont_status status_fun)
{
    enum Errors errors = NO_ERRORS;
    struct Ont_info ont_info = {0};
    struct Ont_connection ont_connection = {0};

    ont_info.status = status;
    ont_info.num_ont = num_ont;
    ont_info.num_port = num_port;

    errors = ont__add_card(&ont_info);

    if (0 > errors )
    {
        goto finally;
    }

    errors = ont__get_card_filter(num_port_fun, num_ont_fun, &status_fun, &ont_connection,FIND_STATUS);
    
    if (0 > errors )
    {
        goto finally;
    }

 finally:

    return errors;
}

void print_ont_info(struct Ont_info *const card)
{
    printf("Serial: %s \n", card->serial);
    printf("Eq_id: %s \n", card->eq_id);
    printf("Fw_version: %s \n", card->fw_version);
    printf("Link-up: %ld \n", card->link_up);
    printf("Link-down: %ld \n", card->link_down);
    switch (card->status)
    {
        case 0:
        {
            printf("Status: Activation \n");
            break;
        }
        case 1:
        {
            printf("Status: Working \n");
            break;
        }
        case 2:
        {
            printf("Status: Cfgfail \n");
            break;
        }
        case 3:
        {
            printf("Status: Block \n");
            break;
        }
        default:
        break;
    }
    printf("\n");
}

void print_ont_connection(struct Ont_connection *const card)
{
    printf("Serial: %s \n", card->serial);
    printf("Eq_id: %s \n", card->eq_id);
    printf("Fw_version: %s \n", card->fw_version);
    printf("Link-up: %ld \n", card->link_up);
    printf("Link-down: %ld \n", card->link_down);
    switch (card->status)
    {
        case 0:
        {
            printf("Status: Activation \n");
            break;
        }
        case 1:
        {
            printf("Status: Working \n");
            break;
        }
        case 2:
        {
            printf("Status: Cfgfail \n");
            break;
        }
        case 3:
        {
            printf("Status: Block \n");
            break;
        }
        default:
        break;
    }
    printf("\n");
    
}

bool compare_cards(
    struct Ont_connection *const sended_cards,
    struct Ont_connection *const received_cards,
    int const num_records)
    {
        bool result = true;
        for(size_t i = 0; i < NUM_OF_RECORDS; i++)
        {
            if(sended_cards[num_records - NUM_OF_RECORDS + i].status != received_cards[(num_records + i) % NUM_OF_RECORDS].status)
            {
                result = false;
                goto finally;
            }
        }
 finally:
        return result;
    }

int test_real_work(int const num_records)
{
    srand(time(NULL));
    struct Ont_info ont_info = {0};
    struct Ont_connection received_cards[NUM_OF_RECORDS];
    struct Ont_connection sended_cards[num_records];
    struct Ont_connection filter = {0};
    enum Errors errors = NO_ERRORS;
    bool compare_result = true;
    enum Ont_status status;

    ont_info.num_port = 0;
    ont_info.num_ont = 0;

    strncpy(ont_info.serial, "serial0", ONT_SERIAL_SIZE);
    strncpy(ont_info.eq_id, "eq_id0", ONT_EQ_ID_SIZE);
    strncpy(ont_info.fw_version, "fw_version0", ONT_FW_VERSION_SIZE);

    printf("Отправили 15 карточек на порт 0 и онт 0 \n \n");

    for(size_t i = 0; i < num_records; i++)
    {
        printf("Запись %li \n", i + 1);
         ont_info.link_up = i;
         ont_info.status = rand() % 4;
         print_ont_info(&ont_info);
         sended_cards[i].status = ont_info.status;
         errors = ont__add_card(&ont_info);
         if(errors < 0)
         {
             goto finally;
         }
    }

    printf("Получили 10 последних карточек \n \n");

    errors = ont__get_card(0, 0, received_cards, 10);
    if(errors < 0)
    {
        goto finally;
    }

    for(size_t i = 0; i < NUM_OF_RECORDS; i++)
    {
        printf("Запись %li \n", i + 1);
        print_ont_connection(&(received_cards[i]));
    }

    compare_result = compare_cards(sended_cards, received_cards, num_records);

    compare_result ? printf("Перезапись произошла без ошибок! \n") : printf("Ошибочная перезапись! \n");
    printf("\n");

    status = ACTIVATION;
    errors = ont__get_card_filter(0, 0, &status, &filter, FIND_STATUS);
    
    if (0 > errors )
    {
        goto finally;
    }


    printf("Фильтр по Activation \n");
    printf("\n");
    print_ont_connection(&filter);
    printf("\n");

 finally:
    return errors;
}


int main ()
{
    plan(13);

    cmp_ok(test1_ont__add_card(NULL), "==", NULL_PTR_ERROR,
        "Проверка функции ont__add_card при передаче в нее NULL.");
    cmp_ok(test2_ont__add_card(16), "==", NUM_PORT_ERROR,
        "Проверка функции ont__add_card на ввод порта вне допустимого диапазона.");
    cmp_ok(test3_ont__add_card(128), "==", NUM_ONT_ERROR,
        "Проверка функции ont__add_card на ввод номера ont вне допустимого диапазона.");

    cmp_ok(test1_ont__get_card(16, 0), "==", NUM_PORT_ERROR,
        "Проверка функции ont__get_card на ввод порта вне допустимого диапазона.");
    cmp_ok(test1_ont__get_card(0, 128), "==", NUM_ONT_ERROR,
        "Проверка функции ont__get_card на ввод номера ont вне допустимого диапазона.");
    cmp_ok(test2_ont__get_card(), "==", NULL_PTR_ERROR,
        "Проверка функции ont__get_card при передаче в нее NULL.");
    cmp_ok(test3_ont__get_card(2, 5), "==", NO_ERRORS,
        "Проверка функции ont__get_card на валидность записи.");

    cmp_ok(test_ont__get_card_filter(1, 1, 16, 0, ACTIVATION, WORKING), "==", NUM_PORT_ERROR,
        "Проверка функции ont__get_card_filter на ввод порта вне допустимого диапазона.");
    cmp_ok(test_ont__get_card_filter(1, 1, 0, 128, ACTIVATION, WORKING), "==", NUM_ONT_ERROR,
        "Проверка функции ont__get_card_filter на ввод номера ont вне допустимого диапазона.");
    cmp_ok(test_ont__get_card_filter(1, 1, 1, 1, ACTIVATION, WORKING), "==", NOT_FOUND_ERROR,
        "Проверка функции ont__get_card_filter при разных событиях.");
    cmp_ok(test_ont__get_card_filter(1, 1, 1, 2, ACTIVATION, ACTIVATION), "==", NOT_FOUND_ERROR,
        "Проверка функции ont__get_card_filter при разных событиях ID.");
    cmp_ok(test_ont__get_card_filter(1, 1, 1, 1, ACTIVATION, ACTIVATION), "==", NO_ERRORS,
        "Проверка функции ont__get_card_filter на валидность записи. \n");


    cmp_ok(test_real_work(15), "==", NO_ERRORS,
        "Тест работоспособности библиотеки. \n");

    done_testing();
}