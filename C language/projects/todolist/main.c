#include <stdio.h>
#include <stdint.h>


struct Gorevler{
	char gorevAdi[50];
	char gorevIcerik[100];
};


int menuScreen(){
	int gorevSay;
	printf("-------- TODOLIST ---------\n");
	printf("Kac gorev kaydetmek istiyorsunuz?\n");
	scanf("%d", &gorevSay);	
	
	return gorevSay;
}


void gorevleriGoster(struct Gorevler* gorevler, int length){
	
	for(int i = 0; i < length; i++){
		printf("Gorev: %d\n", i+1);
		printf("Adi: %s\n", gorevler[i].gorevAdi);
		printf("Icerik: %s\n\n\n", gorevler[i].gorevIcerik);
	}
}


int main(){
	int input = menuScreen();
	struct Gorevler gorevler[input];
	
	
	for(int i = 0; i < input; i++){
		printf("Gorev %d adini girin: ", i+1);
		scanf("%s\n", gorevler[i].gorevAdi);
		
		printf("Gorev %d icerigi girin: ", i+1);
		scanf("%s\n", gorevler[i].gorevIcerik);
	}
	
	
	gorevleriGoster(gorevler, input);
	

	return 0;

}
