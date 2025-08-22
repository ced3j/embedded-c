#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Pin 13 (PB5) ve Pin 7 (PD7) çıkış olarak ayarla
    DDRB |= (1 << DDB5); // PB5 (Pin 13) çıkış
    DDRD |= (1 << DDD7); // PD7 (Pin 7) çıkış
    // Pin 2 (PD2) giriş olarak ayarla ve pull-up direncini etkinleştir
    DDRD &= ~(1 << DDD2); // PD2 giriş
    PORTD |= (1 << PORTD2); // PD2 için pull-up direnci

    while (1) {
        // Buton durumunu oku (Pin 2, PD2)
        if (!(PIND & (1 << PIND2))) { // Buton basılıysa (PD2 düşük, 0)
            PORTD |= (1 << PORTD7);   // Pin 7'yi yak (PD7)
            PORTB &= ~(1 << PORTB5);  // Pin 13'ü söndür (PB5)
        } else { // Buton basılı değilse veya kablolar sökülmüşse (PD2 yüksek, 1)
            PORTB |= (1 << PORTB5);   // Pin 13'ü yak (PB5)
            PORTD &= ~(1 << PORTD7);  // Pin 7'yi söndür (PD7)
        }
        _delay_ms(100); // 100 ms gecikme (debouncing için)
    }

    return 0;
}