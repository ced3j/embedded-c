#include <stdio.h>

int main(){
    
    int a = 5;
    int *ptr = &a;

    printf("a'nin degeri: %d\n", a);
    printf("a'nin adresi: %p\n", &a);
    printf("ptr'in degeri: %p\n", ptr);
    printf("ptr'in gosterdigi: %d\n", *ptr);
    printf("ptr'in adresi: %p\n", &ptr);


    int *ptr2 = ptr;
    
    printf("ptr2'in degeri: %p\n\n", ptr2);  // ptr2 ptr'nin degerini gosterir
    printf("ptr2'in adresi: %p\n", &ptr2);  // ptr2'in adresi
    printf("ptr2'in gosterdigi: %d\n\n", *ptr2); // 5 

    /*
        
        a'nin degeri: 5
        a'nin adresi: 0x7fffffffd914
        ptr'in degeri: 0x7fffffffd914
        ptr'in gosterdigi: 5
        ptr'in adresi: 0x7fffffffd918
        ptr2'in degeri: 0x7fffffffd914

        ptr2'in adresi: 0x7fffffffd920
        ptr2'in gosterdigi: 5

    */




    return 0;
}