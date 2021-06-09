#include <stdio.h>
#include <stdlib.h>
#include "actionvector.h"
#include "menu.h"
#include "tests.h"



int main(){
    setbuf(stdout, 0);
    test_look();
    test_dell();
    test_push();
    test_search();
    int SIZE, length;
    vector typicalvector;
    printf("How much bait u would like to use:");
    scanf("%d", &SIZE);

    printf("How much elements u would like to use:");
    scanf("%d", &length);
    constructor(&typicalvector, SIZE , length);
    if (SIZE == 1){
        int i = 0;
        char element;
        while(i != length) {
            scanf("%c", &element);
            if (65 <= (int)element && (int)element <= 122){
                *((char*)typicalvector.mus + i * SIZE) = element;
                i++;
            }
        }
    }
    else {
        for (int i = 0; i < length; i++)
            scanf("%lf", ((double *) typicalvector.get_i(&typicalvector, i)));
    }
     menu(&typicalvector);
    }
