#include <ncurses.h>

int main(){

	// ncurses'i başlatalım
	initscr();
	
	// Ekrana yazı yaz
	printw("Hello ncurses");
	
	// Ekranı yenile
	refresh();
	
	// Kullanıcı bi tuşa basana kadar bekle
	getch();
	
	// ncurses kapat
	endwin();

	return 0;
}
