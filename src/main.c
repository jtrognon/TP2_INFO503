#define DEBUG
#include "TriDenombrement.h"
#include "TriRapide.h"
#include "Utils.h"

int main()
{
    /* code */

    #ifdef DEBUG
    test_utils();
    test_denombrement();
    test_rapide();
    #endif

    return 0;
}