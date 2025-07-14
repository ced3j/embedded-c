#include <stdio.h>


int main(){

	int matris[3][3] = {
		{1,2,5},
		{5,3,1},
		{8,1,2}
	};
	
	printf("3x3 matris: \n");
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			printf("%d ", matris[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
