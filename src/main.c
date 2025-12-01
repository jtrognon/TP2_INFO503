#define DEBUG
#include "TriDenombrement.h"
#include "TriRapide.h"
#include "TriRapideHybride.h"
#include "Utils.h"

int main()
{
    /* code */

    #ifdef DEBUG
    test_utils();
    test_denombrement();
    test_rapide();
    test_rapide_hybride();
    #endif

    return 0;
}