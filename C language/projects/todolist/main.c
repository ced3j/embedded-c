#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define MAX_GOREV 100

struct Gorevler {
    char gorevAdi[50];
    char gorevIcerik[100];
    uint8_t tamamlandi;
};

const char* dosya_adi = "gorevler.txt";

// Görevleri dosyaya kaydet
void veriTabaninaKaydet(struct Gorevler* gorevler, int length) {
    FILE* fp = fopen(dosya_adi, "w");
    if (!fp) {
        printf("Dosya acilamadi!\n");
        return;
    }

    for (int i = 0; i < length; i++) {
        fprintf(fp, "%s|%s|%u\n",
                gorevler[i].gorevAdi,
                gorevler[i].gorevIcerik,
                gorevler[i].tamamlandi);
    }

    fclose(fp);
}

// Dosyadan görevleri oku
int veriTabanindanOku(struct Gorevler* gorevler) {
    FILE* fp = fopen(dosya_adi, "r");
    if (!fp) {
        return 0; // Dosya yoksa kayıt yok
    }

    int length = 0;
    while (fscanf(fp, "%49[^|]|%99[^|]|%hhu\n",
                  gorevler[length].gorevAdi,
                  gorevler[length].gorevIcerik,
                  &gorevler[length].tamamlandi) == 3) {
        length++;
        if (length >= MAX_GOREV) break;
    }

    fclose(fp);
    return length;
}

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
    yeni.gorevAdi[strcspn(yeni.gorevAdi, "\n")] = '\0'; // \n sil

    printf("Gorev icerigi: ");
    fgets(yeni.gorevIcerik, sizeof(yeni.gorevIcerik), stdin);
    yeni.gorevIcerik[strcspn(yeni.gorevIcerik, "\n")] = '\0'; // \n sil

    printf("Tamamlandi mi? (0: hayir, 1: evet): ");
    scanf("%hhu", &yeni.tamamlandi);

    gorevler[*length] = yeni;
    (*length)++;

    veriTabaninaKaydet(gorevler, *length);

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
    veriTabaninaKaydet(gorevler, *length);

    printf("Gorev silindi!\n");
}

int main() {
    struct Gorevler gorevler[MAX_GOREV];
    int length = veriTabanindanOku(gorevler); // program acilirken dosyadan oku
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

