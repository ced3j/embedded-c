// struct pointers

#include <stdio.h>
#include <string.h>

struct Student{
    int id;
    char* name;
};

int main(){

    struct Student s1 = {1, "Ali"};
    struct Student *ptr = &s1;


    // pointer ile erişim ->
    printf("Ogrenci ID: %d\n", ptr->id);
    printf("Ogrenci Ismi: %s\n", ptr->name);


    ptr->id = 2;
    ptr->name = "Esma";

    printf("\nYeni ID: %d, yeni name %s\n\n", s1.id, s1.name);

    return 0;
}
