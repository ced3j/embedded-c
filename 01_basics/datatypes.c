#include <stdio.h>


int main(){

	int age = 25;
	char grade = 'A';
	float pi = 3.14;
	double precise_pi = 3.1415926535;


	// Print the values
	printf("Age (int): %d\n", age);
	printf("Grade (char): %c\n", grade);
	printf("Pi (float): %f\n", pi);
	printf("Precise pi (double): %lf\n", precise_pi);


	// Show sizes of data types
	printf("Size of int: %zu bytes\n", sizeof(int));
	printf("Siez of char: %zu bytes\n", sizeof(char));
	return 0;

}
