#include "base.h"

/// Функция расчитывает уникальный индекс для индексации внутри базовой структуры 
int get_index(
    int num_port, 
    int num_ont)
{
    return (num_port * 128 + num_ont);
}
