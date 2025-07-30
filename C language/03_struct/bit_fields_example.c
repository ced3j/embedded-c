#include <stdio.h>

// 8-bit PORTA register modeli
struct PORTA {
    unsigned int led1     : 1; // Bit 0
    unsigned int led2     : 1; // Bit 1
    unsigned int buzzer   : 1; // Bit 2
    unsigned int motor    : 1; // Bit 3
    unsigned int hata     : 1; // Bit 4
    unsigned int gucModu  : 1; // Bit 5
    unsigned int reset    : 1; // Bit 6
    unsigned int rezerve  : 1; // Bit 7
};

int main() {
    struct PORTA port = {0};  // Tüm bitleri sıfırla

    // Sistemi başlat
    port.led1 = 1;
    port.buzzer = 1;
    port.motor = 1;

    // Durum çıktısı
    printf("LED1:    %d\n", port.led1);
    printf("LED2:    %d\n", port.led2);
    printf("Buzzer:  %d\n", port.buzzer);
    printf("Motor:   %d\n", port.motor);
    printf("Hata:    %d\n", port.hata);

    // Hata oluştu
    port.hata = 1;
    port.buzzer = 0;  // Sessize al

    printf("\n--- Hata Sonrası ---\n");
    printf("LED1:    %d\n", port.led1);
    printf("Hata:    %d\n", port.hata);
    printf("Buzzer:  %d\n", port.buzzer);

    return 0;
}

