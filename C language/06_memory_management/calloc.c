#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Dizinin eleman sayisini girin: ");
    scanf("%d", &n);

    // calloc ile bellek tahsisi (sıfırlanmış)
    int *dizi = (int *)calloc(n, sizeof(int));
    if (dizi == NULL) {
        printf("Bellek tahsis edilemedi!\n");
        return 1;
    }

    // İlk birkaç elemanı değiştir
    for (int i = 0; i < n && i < 3; i++) {
        dizi[i] = (i + 1) * 10; // Örnek: 10, 20, 30
    }

    // Diziyi yazdır
    printf("Dizi elemanlari: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    // Belleği serbest bırak
    free(dizi);
    dizi = NULL;

    return 0;
}
