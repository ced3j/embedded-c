#include <stdio.h>
#include <stdlib.h>


int main(){

	int n;
	printf("Dizinin eleman sayisini girin: ");
	scanf("%d", &n);
	
	
	// malloc ile bellek tahsisi
	int *dizi = (int *)malloc(n * sizeof(int));
	if(dizi == NULL){
		printf("Bellek tahsis edilemedi!");
		return 1;
	}
	
	for(int i = 0; i < n; i++){
		printf("Eleman %d: ", i + 1);
		scanf("%d", &dizi[i]);
	} 
	
	printf("Dizi elemanlari: ");
	for(int i = 0; i < n; i++){
		printf("%d ", dizi[i]);
	}
	
	printf("\n");
	
	
	// Belleği serbest bırak
	free(dizi);
	dizi = NULL;
	
	return 0;
}
