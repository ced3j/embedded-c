// struct ve memory

#include <stdio.h>
#include <string.h>


struct Person{
    int id;  // 4 byte
    char grade; // 1 byte
    char name[20]; // 20 byte
};


struct Student{
    int ogrNo;  // 4 byte
    struct Person p; // 25 byte
};


int main(){

    struct Student s1;
    struct Student *ptr = &s1;

    s1.p.id = 1001;
    s1.p.grade = 'A';
    strcpy(s1.p.name, "Mücahit");


    // Normal erişim
    printf("Student id: %d\n", s1.p.id);




    // Pointer üzerinden erişim
    printf("Student id (pointer): %d\n", ptr->p.id);




    // Bellek adreslerini yazdıralım

    printf("\n\n--- Bellek Adresleri ---\n\n");
    printf("Student başlangıç : %p\n", (void*)&s1);
    printf("Student (pointer) : %p\n", (void*)ptr);
    printf("Student ogrNo     : %p\n", (void*)&s1.ogrNo);
    printf("Student p.id      : %p\n", (void*)&s1.p.id);
    printf("Student p.grade   : %p\n", (void*)&s1.p.grade);
    printf("Student p.name    : %p\n", (void*)&s1.p.name);


    printf("\nStruct boyutu: %zu\n byte\n", sizeof(struct Student));

    return 0;
}