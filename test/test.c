#include "include/tap.h"
#include "include/ont.h"

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

    errors = ont__get_card(num_port, num_ont, ont_connection);

    return errors;
}

int test2_ont__get_card()
{
    enum Errors errors = NO_ERRORS;

    errors = ont__get_card(0, 0, NULL);

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
    errors = ont__get_card(num_port, num_ont, ont_connection);
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


int main ()
{
    plan(12);

    cmp_ok(test1_ont__add_card(NULL), "==", NULL_PTR_ERROR,
        "Проверка функции ont__add_card при передаче в нее NULL.");
    cmp_ok(test2_ont__add_card(16), "==", NUM_PORT_ERROR,
        "Проверка функции ont__add_card на ввод порта вне допустимого диапозона.");
    cmp_ok(test3_ont__add_card(128), "==", NUM_ONT_ERROR,
        "Проверка функции ont__add_card на ввод номера ont вне допустимого диапозона.");

    cmp_ok(test1_ont__get_card(16, 0), "==", NUM_PORT_ERROR,
        "Проверка функции ont__get_card на ввод порта вне допустимого диапозона.");
    cmp_ok(test1_ont__get_card(0, 128), "==", NUM_ONT_ERROR,
        "Проверка функции ont__get_card на ввод номера ont вне допустимого диапозона.");
    cmp_ok(test2_ont__get_card(), "==", NULL_PTR_ERROR,
        "Проверка функции ont__get_card при передаче в нее NULL.");
    cmp_ok(test3_ont__get_card(2, 5), "==", NO_ERRORS,
        "Проверка функции ont__get_card на валидность записи.");

    cmp_ok(test_ont__get_card_filter(1, 1, 16, 0, ACTIVATION, WORKING), "==", NUM_PORT_ERROR,
        "Проверка функции ont__get_card_filter на ввод порта вне допустимого диапозона.");
    cmp_ok(test_ont__get_card_filter(1, 1, 0, 128, ACTIVATION, WORKING), "==", NUM_ONT_ERROR,
        "Проверка функции ont__get_card_filter на ввод номера ont вне допустимого диапозона.");
    cmp_ok(test_ont__get_card_filter(1, 1, 1, 1, ACTIVATION, WORKING), "==", NOT_FOUND_ERROR,
        "Проверка функции ont__get_card_filter при разных событиях.");
    cmp_ok(test_ont__get_card_filter(1, 1, 1, 2, ACTIVATION, ACTIVATION), "==", NOT_FOUND_ERROR,
        "Проверка функции ont__get_card_filter при разных событиях ID.");
    cmp_ok(test_ont__get_card_filter(1, 1, 1, 1, ACTIVATION, ACTIVATION), "==", NO_ERRORS,
        "Проверка функции ont__get_card_filter на валидность записи.");

    done_testing();
}
