#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
    // Pin 13 (PB5) ve Pin 7 (PD7) çıkış olarak ayarla
    DDRB |= (1 << DDB5); // PB5 (Pin 13) çıkış
    DDRD |= (1 << DDD7); // PD7 (Pin 7) çıkış

    while (1) {
        // Her iki LED'i aynı anda yak
        PORTB |= (1 << PORTB5); // Pin 13 yüksek (LED yanar)
        PORTD |= (1 << PORTD7); // Pin 7 yüksek (LED yanar)
        _delay_ms(400); // 400ms saniye bekle

        // Her iki LED'i aynı anda söndür
        PORTB &= ~(1 << PORTB5); // Pin 13 düşük (LED söner)
        PORTD &= ~(1 << PORTD7); // Pin 7 düşük (LED söner)
        _delay_ms(400); // 400ms saniye bekle
    }

    return 0;
}