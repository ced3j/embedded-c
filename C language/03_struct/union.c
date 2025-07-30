#include <stdio.h>

union Veri {
    int i;	// 4 byte
    float f;	// 4 byte
    char c;	// 1 byte
    
    // tüm alanlar aynı adreste başlar
    // 
};

int main() {
    union Veri v;

    v.i = 42;
    printf("i: %d\n", v.i); // ✅
    printf("f: %f\n", v.f); // ❌ anlamsız çıktı
    printf("c: %c\n", v.c); // ❌ anlamsız çıktı

    v.f = 3.14;
    printf("f: %f\n", v.f); // ✅
    printf("i: %d\n", v.i); // ❌ şimdi i bozuldu
    
    // Yani union'da birden fazla türü barındırabiliriz fakat
    // Tek seferde sadece tek birini tutabiliriz
    


    return 0;
}

