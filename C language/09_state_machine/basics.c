/*
State machine - Durum makinesi


Örnek: Bir kahve makinesi

    Kahve makinesi farklı durumlarda olabilir: Kapalı, Isınıyor, Kahve Yapıyor, Hazır.
    Her durumda makine farklı bir şey yapar:
        Kapalı: Hiçbir şey yapmaz, ışıklar kapalı.
        Isınıyor: Suyu ısıtır, bir lamba yanıp söner.
        Kahve Yapıyor: Kahve hazırlar, başka bir lamba yanar.
        Hazır: Kahve hazır, bir ses çıkarır.
    Durumlar arasında geçiş için olaylar gerekir:
        "Açma düğmesine bas" → Kapalı'dan Isınıyor'a geç.
        "Su ısındı" → Isınıyor'dan Kahve Yapıyor'a geç.
        "Kahve bitti" → Kahve Yapıyor'dan Hazır'a geç.
        
        
*/


#include <stdio.h>


typedef enum {
	ALARM_OFF,	// Alarm kapalı
	ALARM_ON,	// Alarm açık
	ALARM_TRIGGERED // Siren çalıyor
} AlarmState;


// Mevcut durumu tutan değişken
AlarmState current_state = ALARM_OFF;


int button_pressed = 0;	// 1 olursa düğmeye basılmış demektir
int door_opened = 0;	// 1 olursa kapı açılmış demektir

/*
	Mesela eğer, button ve door değişkenleri gerçek şartlar altında
	bir sensör vb. donanım ile okunuyor olsaydı "volatile" kullanmak gerekirdi
	
	 

*/


int main(void){


	while(1){
		switch(current_state){
			case ALARM_OFF:
				printf("Alarm Kapalı\n");
				
				if(button_pressed){
					current_state = ALARM_ON;
					button_pressed = 0;
				}
				break;
			case ALARM_ON:
				printf("Alarm açık\n");
				
				if(door_opened){
					current_state = ALARM_TRIGGERED;
					door_opened = 0; // sensörü sıfırla
				}
				
				if(button_pressed){
					current_state = ALARM_OFF;
					button_pressed = 0;
				}
				break;
				
			case ALARM_TRIGGERED:
				printf("Siren çalıyor!\n");
				
				if(button_pressed){
					current_state = ALARM_OFF;
					button_pressed = 0;
				}
				break;
			default:
				current_state = ALARM_OFF;
				break;
		}
		
		
		// Simülasyon için kullanıcıdan input alalım
		
		printf("Düğmeye bas (1), Kapı aç (2), Hiçbir şey yapma (0): \n");
		int input;
		scanf("%d", &input);
		
		if(input == 1) button_pressed = 1;
		if(input == 2) door_opened = 1;
	}
	
	return 0;
}















