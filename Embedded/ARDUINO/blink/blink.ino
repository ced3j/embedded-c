#include <avr/io.h>      // AVR register tanımları için
#include <util/delay.h>  // Gecikme fonksiyonları için

int main(void) {
    // PB5 (Pin 13) çıkış olarak ayarla
    DDRB |= (1 << DDB5);

    while (1) {
        // LED'i yak (PB5'i yüksek yap)
        PORTB |= (1 << PORTB5);
        _delay_ms(3000); // 1 saniye bekle
        // LED'i söndür (PB5'i düşük yap)
        PORTB &= ~(1 << PORTB5);
        _delay_ms(3000); // 1 saniye bekle
    }
    return 0;
}