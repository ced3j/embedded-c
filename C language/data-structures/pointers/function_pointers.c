#include <stdio.h>


void degistir(int **pp){
    
    static int b = 99;  // static, fonk bitince yok olmasin
    **pp = b;  // pointer'in isaret ettigi yere b'yi atar
}

int main(){

    int a = 5;
    int *p = &a;

    printf("a: %d\n", a); // 5 
    printf("a with pointer: %d\n", *p);  // 5
    degistir(&p);
    printf("a: %d\n\n", a);  // 99 olur

    return 0;
}