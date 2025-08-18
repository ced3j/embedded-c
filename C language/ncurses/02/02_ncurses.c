#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


int main(){
	char mesg[] = "Merhaba ncurses!";
	int row, col;
	int y, x;
	
	srand(time(NULL));  // Rastgele sayi uretelim
	
	initscr();         // ncurses baslat
	curs_set(0);	  // imleci gizle
	noecho(); 	 // Kullanici girisi ekranda gozukmesin
	getmaxyx(stdscr, row, col);   // Terminal boyutunu al
	
	while(1){
		clear(); // ekrani temizle
		
		// rastgele koordinatlar uret (mesaj tasmasin diye ayarliyoruz)
		y = rand() % (row -1);
		x = rand() & (col - strlen(mesg));
		
		mvprintw(y, x, "%s", mesg);   // Mesaji yeni konuma yaz
		
		
		refresh();  // ekrani guncelle
		napms(300); // 300 ms bekle
		
		// Kullanici tusa bastiysa cik
		timeout(0); // getch()'in beklememesini sagla
		
		if(getch() != ERR){
			break;
		}
			 
	}
	
	endwin();

	return 0;
}


/*


initscr() → ncurses ekranını başlatır.

curs_set(0) → İmleci gizler.

noecho() → Kullanıcının bastığı tuş ekranda görünmez.

getmaxyx(stdscr, row, col) → Terminalin satır (row) ve sütun (col) sayısını alır.
	stdscr == ncurses'in olusturdugu ana pencere
	
	stdscr → “su pencerenin boyutunu olc.” (ana pencere)
	row → Terminalin yüksekligi (satır sayısı) buraya yaz.
	col → Terminalin genisligi (sütun sayısı) buraya yaz.



rand() + % işlemleri → Mesajın rastgele ekranda görünmesi için koordinat üretir.

mvprintw(y, x, mesg) → Mesajı istenilen koordinata yazar.

refresh() → Değişiklikleri ekrana uygular.

napms(ms) → Belirtilen milisaniye kadar bekler.

timeout(0) + getch() → Tuşa basıldığını kontrol eder, basılırsa program biter.


*/







