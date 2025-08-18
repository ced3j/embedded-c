#include <ncurses.h>
#include <stdlib.h>
#include <time.h>


int main(){
	
	initscr();
	cbreak();  // Klavye girdisini anında al
	noecho();  // Kullanıcının yazdığı karakterleri ekranda gösterme
	
	keypad(stdscr, TRUE); 
	
	srand(time(NULL));
	int hedef_sayi = rand() % 50 + 1; // 1-50 arası rastgele sayı
	int tahmin;
	char input[10];  // Kullanıcı girdisini saklamak için
	int deneme_sayisi = 0;
	
	
	// Oyun döngüsü
	
	while(1){
		// Ekranı temizle
		clear();
		
		
		// Ekrana mesaj yaz
		
		
		
		// mvprintw(y, x, "metin");  koordinatlı sekilde yazar
		
		mvprintw(2, 2, "1-50 arasinda bir sayi tahmin et: ");
		mvprintw(4, 2, "Tahminin: ");
		refresh();  // Ekranı güncelle
		
		
		// Kullanıcıdan tahmin al
		move(4, 12); // Tahmin yazılacak konuma git
		echo(); // Girdiyi ekranda göster
		getnstr(input, sizeof(input));  // String olarak girdiyi al
		noecho(); // Girdiyi tekrar gizle
		
		tahmin = atoi(input); // Stringi sayıya çevir
		deneme_sayisi++;
		
		// Tahmini kontrol et
		if(tahmin == hedef_sayi){
			clear();
			mvprintw(2, 2, "Tebrikler %d sayisini %d denemede buldun!", hedef_sayi, deneme_sayisi);
			mvprintw(4, 2, "Cikmak icin bir tusa bas...");
			refresh();
			getch();
			break;
		}else if(tahmin < hedef_sayi){
			mvprintw(6, 2, "Ipucu: Daha buyuk bir sayi gir!");
		}else {
			mvprintw(6, 2, "Ipucu: Daha kucuk bir sayi gir!");
		}
		
		mvprintw(8, 2, "Devam etmek icin bir tusa bas...");
		refresh();
		getch();
	
	}
	
	endwin();
	
	
	return 0;
}
