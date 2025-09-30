#include <stdio.h>
#include <string.h>




size_t my_strlen(const char *str){
    const char *p = str;
    while(*p){
        p++;
    }

    return p - str;  // pointer farkı bize uzunluğu verir
}




void reverse(char *str){
    char *start = str;
    char *end = str + strlen(str) - 1;
    char temp;


    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;
        
        start++;
        end--;
    }
}





int main(){
    char isim[20] = {'m','e','h','m','e','t','\0'};
    // Ya da şu şekilde: char isim[20] = "mehmet";   aynı şeydir

    char *c;
    c = isim;

    printf("%c\n", *c);  // m yazacak
    printf("%c\n", isim[0]);  // m yazacak



    ////////////////////////////////////////////////////



    char str[] = "Hello";
    char *p = str;

    while(*p != '\0'){
        printf("%c", *p);
        p++;
    }



    ////////////////////////////////////////////////////




    // strlen fonksiyonunu pointer ile yazalım

    char test[] = "Testing";
    printf("\n\nUzunluk: %zu\n", my_strlen(test));





     ////////////////////////////////////////////////////



    // pointer ile string ters çevirme


    char ters[] = "Hello";
    reverse(ters);
    printf("Tersi: %s\n", ters);


    return 0;
}