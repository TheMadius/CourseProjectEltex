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


int main () 
{
    cmp_ok(test1_ont__add_card(NULL), "==", NULL_PTR_ERROR, 
        "Проверка функции ont__add_card при передаче в нее NULL.");
    cmp_ok(test2_ont__add_card(16), "==", NUM_PORT_ERROR,
        "Проверка функции ont__add_card на ввод порта вне допустимого диапозона.");
    cmp_ok(test3_ont__add_card(128), "==", NUM_ONT_ERROR,
        "Проверка функции ont__add_card на ввод номера ont вне допустимого диапозона.");

    done_testing();
}
