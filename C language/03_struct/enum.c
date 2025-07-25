/*
Kod okunabilirliği arttırır
	Sayı yerine anlamlı isimler kullanırız
Sabit değerleri gruplamak ve anlamlandırmak için kullanışlı



enum Gun{
	PAZARTESI,
	SALI,
	CARSAMBA
};

	PAZARTESI = 0
	SALI = 1
	CARSAMBA = 2
	
	
enum Gun bugun = SALI;
if(bugun == SALI){
	printf("Bugün salı!\n");
}

*/



#include <stdio.h>
#include <string.h>


typedef enum{
	AKTIF,
	MEZUN,
	UZAKLASTIRILMIS
} OgrenciDurumu;

typedef struct{
	char name[50];
	int age;
	OgrenciDurumu durum; // enum tipi struct içinde
} Ogrenci;

void ogrenciYazdir(Ogrenci o){
	printf("Adı: %s: ", o.name);
	printf("Yaşı: %d: ", o.age);
	printf("Durumu: %s: ", o.durum);
}

int main(){

	Ogrenci o1 = {"Betel jesed", 10, AKTIF};
	
	ogrenciYazdir(o1);


	return 0;
}
