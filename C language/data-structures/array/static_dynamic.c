/*

Statik Dizi (Static Array)
    Tanımı: Boyutu derleme zamanında belirlenir ve değiştirilemez.
    Bellek: Stack (yığın) bölgesinde tutulur.
    Avantaj: Hızlı erişim, kolay kullanım.
    Dezavantaj: Boyut sabit, büyük dizilerde stack taşması riski.

Dinamik Dizi (Dynamic Array)
    Tanımı: Boyutu çalışma zamanında belirlenir, gerektiğinde değiştirilebilir.
    Bellek: Heap (yığın) bölgesinde tutulur.
    Avantaj: Esnek boyut, büyük veri saklanabilir.
    Dezavantaj: Bellek yönetimi (malloc/free) gerekir, erişim biraz daha yavaştır.

Stack ve Heap Nedir?
    Stack: Fonksiyon çağrıları, yerel değişkenler burada tutulur. Otomatik yönetilir.
    Heap: Programın çalışma süresince dinamik olarak ayrılan bellek burada tutulur. Programcı tarafından yönetilir (malloc/free).




    -- Statik dizide örneğin bir dizi tanımladık 
    int dizi[] = {1,2};

    daha sonra yeni bir int değişken oluşturduk
    int a = 10;

    Sonra bu satırda dizinin eleman sayısını güncellemek istedik
    dizi = {1,2,3};

    şimdi kesin olmamakla birlikte dizinin 3. elemanı ile int a değişkeni
    stack bellekte aynı yere yazılmaya çalışılmış olabilir
    Bu da hata vermesi demektir
    Stack belleği derlemeden önce yerleri ayırır, değişkenleri yerleştirir vs.

    Fakat Heap kısmını dinamik bellek ile kullanırsak
    Dinamik bellekte yer ayırma işlemi çalışma anında belirlenir bu sayede sadece boş yerler seçilebilir


*/



#include <stdio.h>
#include <stdlib.h>



int main() {
    // Statik dizi (stack'te)
    int static_array[5] = {1, 2, 3, 4, 5};
    printf("Statik dizi:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", static_array[i]);
    }
    printf("\n");

    // Dinamik dizi (heap'te)
    int n = 5;
    int *dynamic_array = (int*)malloc(n * sizeof(int));
    if (dynamic_array == NULL) {
        printf("Bellek ayrilamadi!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        dynamic_array[i] = i + 1;
    }
    printf("Dinamik dizi:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n");

    free(dynamic_array); // Heap'ten ayrılan belleği serbest bırakmak şart
    return 0;
}


