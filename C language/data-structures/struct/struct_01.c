// typedef kullanımı

#include <stdio.h>

typedef struct {
    char* name;
    int age;
} Person;

void displayPerson(Person p);

int main(){

    Person p1;
    p1.name = "John Wick";
    p1.age = 45;

    displayPerson(p1);


    return 0;
}

void displayPerson(Person p){
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}