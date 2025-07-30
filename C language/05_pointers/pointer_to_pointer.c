#include <stdio.h>

int main(){

	int x = 42;
	
	int *p = &x;
	int **pp = &p;
	
	printf("x	= %d\n", x);	// 42
	printf("*p	= %d\n", *p); 	// 42
	printf("**p	= %d\n", **pp);	// 42


	return 0;
}
