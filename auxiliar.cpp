#include <auxiliar.h>

bool even_aleatorio(float p)
{
    int num_rand = rand(),x;
    x = p*(RAND_MAX+1)-1;
    return num_rand<=x;
}
