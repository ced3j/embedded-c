#include <stdio.h>
#include <stdlib.h>


int main(){

	int *dizi = malloc(3 * sizeof(int));   // 3 elemanlık bellek
	
	if(dizi == NULL){
		printf("Bellek ayrilamadi!\n");
		return 1;
	}
	
	
	dizi[0] = 10;
	dizi[1] = 20;
	dizi[2] = 30;
	
	
	// Belleği büyütelim
	dizi = realloc(dizi, 5 * sizeof(int));
	dizi[3] = 40;
	dizi[4] = 50;
	
	for(int i = 0; i < 5; i++){
		printf("dizi[%d] : %d\n", i, dizi[i]);
	}
	
	// Belleği serbest bırak
	free(dizi);
	dizi = NULL;
	
	
	return 0;
}
