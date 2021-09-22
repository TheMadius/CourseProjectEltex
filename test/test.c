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

int test1_ont__get_card(uint32_t const num_port, uint32_t const num_ont)
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

int test3_ont__get_card(uint32_t const num_port, uint32_t const num_ont)
{
    enum Errors errors = NO_ERRORS;

    struct Ont_info ont_info = {0};
    ont_info.num_port = num_port;
    ont_info.num_ont = num_ont;
    snprintf(ont_info.serial, ONT_SERIAL_SIZE, "123456");

    errors = ont__add_card(&ont_info);
    if (errors < 0)
    {
        goto finally;
    }

    struct Ont_connection ont_connection[NUM_OF_RECORDS];
    memset(ont_connection, 0, sizeof(struct Ont_connection) * NUM_OF_RECORDS);
    errors = ont__get_card(num_port, num_ont, ont_connection);
    if (errors < 0)
    {
        goto finally;
    }

    if (strcmp(ont_connection[0].serial, ont_info.serial) != 0)
    {
        errors = WRONG_VALUE_ERROR;
        goto finally;
    }

 finally:
    return errors;
}


int main ()
{
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

    done_testing();
}
