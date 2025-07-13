#include <stdio.h>


int main(){


	// --------- FOR ------------
	
	int sum = 0; 
	
	for(int i = 1; i < 5; i++){
		sum += i;
	}
	
	printf("Sum: %d\n", sum);
	
	
	
	// --------- WHILE ------------
	int count = 1;
	while (count <= 5){
		count++;
	}
	printf("While count results: %d\n", count);
	
	
	return 0;
}
