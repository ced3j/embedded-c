#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_GOREV 100

struct Gorevler {
    char gorevAdi[50];
    char gorevIcerik[100];
    uint8_t tamamlandi;
};

void gorevleriGoster(struct Gorevler* gorevler, int length) {
    if (length == 0) {
        printf("\n--- Hic kayit yok! ---\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        printf("\nGorev: %d\n", i + 1);
        printf("Adi   : %s\n", gorevler[i].gorevAdi);
        printf("Icerik: %s\n", gorevler[i].gorevIcerik);
        printf("Durum : %s\n", gorevler[i].tamamlandi ? "Tamamlandi" : "Yapilacak");
    }
}

void gorevEkle(struct Gorevler* gorevler, int* length) {
    if (*length >= MAX_GOREV) {
        printf("Maksimum kayit sayisina ulasildi!\n");
        return;
    }

    struct Gorevler yeni;

    getchar(); // scanf'ten kalan \n temizleniyor

    printf("Gorev adi: ");
    fgets(yeni.gorevAdi, sizeof(yeni.gorevAdi), stdin);

    printf("Gorev icerigi: ");
    fgets(yeni.gorevIcerik, sizeof(yeni.gorevIcerik), stdin);

    printf("Tamamlandi mi? (0: hayir, 1: evet): ");
    scanf("%hhu", &yeni.tamamlandi);

    gorevler[*length] = yeni;
    (*length)++;

    printf("Yeni gorev eklendi!\n");
}

void gorevSil(struct Gorevler* gorevler, int* length) {
    if (*length == 0) {
        printf("Hic kayit yok, silemezsiniz.\n");
        return;
    }

    int silinecek;
    printf("Silmek istediginiz gorevin numarasini girin (1-%d): ", *length);
    scanf("%d", &silinecek);

    if (silinecek < 1 || silinecek > *length) {
        printf("Gecersiz numara!\n");
        return;
    }

    // Elemanlari kaydir
    for (int i = silinecek - 1; i < *length - 1; i++) {
        gorevler[i] = gorevler[i + 1];
    }

    (*length)--; // toplam kayit sayisini azalt
    printf("Gorev silindi!\n");
}

int main() {
    struct Gorevler gorevler[MAX_GOREV];
    int length = 0; // kayit sayisi
    int secim;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Yeni kayit ekle\n");
        printf("2. Kayitlari listele\n");
        printf("3. Kaydi sil\n");
        printf("0. Cikis\n");
        printf("Seciminiz: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                gorevEkle(gorevler, &length);
                break;
            case 2:
                gorevleriGoster(gorevler, length);
                break;
            case 3:
                gorevSil(gorevler, &length);
                break;
            case 0:
                printf("Programdan cikiliyor...\n");
                return 0;
            default:
                printf("Gecersiz secim!\n");
        }
    }

    return 0;
}



/*

scanf("%hhu", &yeni.tamamlandi); 
	
	Neden hhu?

	tamamlandi degiskeninin tipi "uint8_t"  bu aslinda unsigned char tipine denk gelir
	%d -> int
	%u -> unsigned int
	%hhu -> unsigned char (8bit)
	 



*/












