#include <stdio.h>

int main(){

    int a = 10;
    int *ptr = &a;
    int **ptr2 = &ptr;


    printf("a'nin degeri: %d\n", a); // 10
    printf("ptr'in degeri: %p\n", ptr); // a'in adresi
    printf("ptr2'nin degeri: %p\n", ptr2); // ptr'in adresi
    printf("ptr2'nin gosterdigi: %d\n\n", **ptr2); // once ptr'a gider sonra ptr icine girer. otuput = 10



    // ptr2'yi kullanarak a'nın değerini değiştirelim
    **ptr2 = 20;
    printf("ptr2 ile a'nin degeri degistirildi: %d\n", a); // 20

    // ptr2'yi kullanarak ptr'nin gösterdiği adresi değiştirelim
    int b = 30;
    *ptr2 = &b;
    printf("ptr2 ile ptr'nin gosterdigi adres degistirildi: %p\n", ptr);
    printf("ptr'nin gosterdigi yeni deger: %d\n", *ptr); // 30
    printf("ptr2'nin gosterdigi yeni deger: %d\n", **ptr2); // 30

    // ptr2'nin gösterdiği ptr'nin adresini yazdıralım
    printf("ptr2'nin gosterdigi ptr'nin adresi: %p\n\n", ptr2);


    int ***ptr3 = &ptr2;

    // ptr tekrar a'yı göstersin
    *ptr2 = &a;
    ***ptr3 = 30;

    printf("a son degeri: %d\n\n", a);




    return 0;
}