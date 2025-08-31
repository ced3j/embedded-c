#include <stdio.h>
#include <stdlib.h>

int main(){

    int *ptr;
    int sutun_sayisi;
    printf("Sutun sayisi girin: ");
    scanf("%d", &sutun_sayisi);

    ptr = (int *)malloc(sizeof(int) * sutun_sayisi);


    printf("Dinamik diziyi doldur: \n");
    for(int i = 0; i < sutun_sayisi; i++){
        printf("%d. eleman: ", (i+1));
        scanf("%d", &ptr[i]);
    }
    printf("\n");

    for(int i = 0; i < sutun_sayisi; i++){
        printf("%d - ", *(ptr + i));

    }

    free(ptr);  // Heap'te belleği serbest bırak

    return 0;
}