/*
Dosya işlemlerinin temeli: FILE yapısı

FILE *fp;

C dilinde dosya işlemleri FILE adlı bir yapı (struct) üzerinden yapılır.
Tüm işlemler bu FILE * pointer'ı üzerinden gerçekleştirilir.





Fonksiyon		Açıklama
fopen()			Dosya açar
fclose()		Dosyayı kapatır
fgetc() / fputc()	Karakter okuma / yazma
fgets() / fputs()	Satır okuma / yazma
fread() / fwrite()	Binary dosya okuma / yazma
fprintf() / fscanf()	Formatlı okuma / yazma



Fonksiyon	Açıklama
feof(fp)	Dosya sonuna gelindi mi?
ferror(fp)	Dosya işlem hatası var mı?
rewind(fp)	Başlangıca dön
ftell(fp)	Mevcut dosya pozisyonunu döndür
fseek(fp, pos, mode)	Dosya imlecini taşı




Mod	Anlamı
"r"	Okumak için aç (dosya yoksa hata)
"w"	Yazmak için aç (dosya varsa silinir)
"a"	Dosyanın sonuna eklemek için aç
"r+"	Hem oku hem yaz (dosya olmalı)
"w+"	Hem oku hem yaz, dosyayı sıfırla
"a+"	Oku ve sona ekle
b	Binary mod (örneğin: "rb")


*/


#include <stdio.h>

int main(){

	// Basit temel bir örnek, dosyaya yazmak
	FILE *fp = fopen("ornek.txt", "w");
	
	
	if(fp == NULL){
		printf("Dosya açılamadı!\n");
		return 1;
	}
	
	
	fprintf(fp, "Merhaba Dünya!\n");
	fprintf(fp, "Bugün harika bir day\n");
	
	fclose(fp);
	
	
	return 0;
}



// Dosyayı okumak istersek:


/*

FILE *fp = fopen("ornek.txt", "r");
char satir[100];

if(fp == NULL){

	printf("Dosya bulunamadı!\n");
	return 1;
}


while(fgets(satir, sizeof(satir), fp)){
	printf("Satır: %s", satir);
}

fclose(fp);

return 0;

*/




/*

Tek karakter yazmak için
	fputc("A", fp);
	
Tek karakter okumak için
	char ch = fgetc(fp);
	
Satır satır yazmak için
	fputs("Bu bir satırdır\n", fp);


*/



