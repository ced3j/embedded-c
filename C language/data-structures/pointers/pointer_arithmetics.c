/*

int *p;  // int pointer
char *q;  // char pointer

eger p++ dersen p adresi 4 byte(int boyutu kadar) ilerler
eger q++ dersen q adresi 1 byte(char boyutu kadar) ilerler

yani p+1 bir sonraki int adresi
q+1 bir sonraki char adresi

*/

#include <stdio.h>

int main(){

    char str[] = "Selamun Aleykum Dunya";
    char *p = str;

    while(*p != '\0'){
        printf("%c-", *p);
        p++;
    }
    printf("\n");




    /*-----------------------------------------------------------*/


    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr = numbers;

    printf("%d\n", *(ptr + 0));
    printf("%d\n", *(ptr + 1));


    ++ptr;

    printf("%d\n", *ptr);



    return 0;
}