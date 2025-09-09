#include <stdio.h>

struct Person{
    char* name;
    int age;
};

void display(struct Person p); 

int main(){
    
    struct Person p;
    p.name = "Alice";
    p.age = 30;

    printf("Person's name: %s\n", p.name);
    printf("Person's age: %d\n", p.age); 

    printf("------------------------------------");


    display(p);


    return 0;
}

void display(struct Person p){
    printf("\nPerson's name: %s\n", p.name);
    printf("\nPerson's age: %d\n", p.age);
}