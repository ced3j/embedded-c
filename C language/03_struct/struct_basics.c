#include <stdio.h>
#include <string.h>

struct Student{
	char name[50];
	int age;
	float gpa;
};



// Nested structs

struct Date{
	int day, month, year;
};

struct University{
	char name[50];
	struct Date birthdate;
};



	// passing struct to a function
	
void printStudent(struct Student x){
	printf("\n[passingstructtoafunc]\nName: %s, Age: %d, GPA: %.2f\n", x.name, x.age, x.gpa);
}



int main(){
	
	struct Student s1;
	
	strcpy(s1.name, "Alice");  // strcpy sagdakini sola kopyalar
	s1.age = 20;
	s1.gpa = 3.7;
	
	printf("Name: %s\n", s1.name);
	printf("Age: %d\n", s1.age);
	printf("GPA: %.2f\n", s1.gpa);
	
	
	// initializing struct
	struct Student s2 = {"Betel", 26, 3.9};
	
	
	// array of structs
	struct Student class[3];
	
	strcpy(class[0].name, "Alice");
	class[0].age = 21;
	class[0].gpa = 3.1;
	
	
	// function with struct
	printStudent(s2);
	
	

	return 0;
}


	

