// iç içe struct kullanımı

#include <stdio.h>

typedef struct Person{
    char* name;
    int age;
} Person;

typedef struct Student{
    int ogrNo;
    struct Person p;
} Student;


void displayStudent(Student s);


int main(){

    Student s1;

    s1.ogrNo = 1001;
    s1.p.name = "Ali Veli";;
    s1.p.age = 20;

    displayStudent(s1);

    return 0;
}



void displayStudent(Student s){
    printf("Ogrenci no %d\n: ", s.ogrNo);
    printf("Ogrenci ismi %s\n: ", s.p.name);
    printf("Ogrenci yasi %d\n: ", s.p.age);
}
