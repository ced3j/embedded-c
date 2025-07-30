#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 4;

    // malloc ile bellek tahsisi
    int *dizi_malloc = (int *)malloc(n * sizeof(int));
    if (dizi_malloc == NULL) {
        printf("malloc: Bellek tahsis edilemedi!\n");
        return 1;
    }

    // calloc ile bellek tahsisi
    int *dizi_calloc = (int *)calloc(n, sizeof(int));
    if (dizi_calloc == NULL) {
        printf("calloc: Bellek tahsis edilemedi!\n");
        free(dizi_malloc);
        return 1;
    }

    // malloc dizisini yazdır
    printf("malloc ile tahsis edilen dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi_malloc[i]);
    }
    printf("\n");

    // calloc dizisini yazdır
    printf("calloc ile tahsis edilen dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi_calloc[i]);
    }
    printf("\n");

    // Belleği serbest bırak
    free(dizi_malloc);
    free(dizi_calloc);
    dizi_malloc = NULL;
    dizi_calloc = NULL;

    return 0;
}
