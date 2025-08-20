#include <ncurses.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define INPUT_H 3               // Alt giriş alanının yüksekliği (satır)

static void draw_input(WINDOW* win, const char* prompt) {
    werase(win);
    box(win, 0, 0);
    mvwprintw(win, 1, 2, "%s", prompt);
    wrefresh(win);
}

static void append_line(WINDOW* chat, const char* who, const char* text) {
    // chat penceresinde yeni satıra mesaj ekle
    wprintw(chat, "%s: %s\n", who, text);
    wrefresh(chat);
}

static void simple_reply(const char* msg, char* out, size_t outsz) {
    // Basit anahtar kelime tabanlı cevaplayıcı
    char tmp[256];
    size_t n = strlen(msg);
    if (n > sizeof(tmp) - 1) n = sizeof(tmp) - 1;
    for (size_t i = 0; i < n; ++i) tmp[i] = (char)tolower((unsigned char)msg[i]);
    tmp[n] = '\0';

    if (strstr(tmp, "nasılsın") || strstr(tmp, "nasilsin")) {
        snprintf(out, outsz, "İyiyim, sen nasılsın? :)");
    } else if (strstr(tmp, "saat") || strstr(tmp, "time")) {
        time_t t = time(NULL);
        struct tm* lt = localtime(&t);
        char clockbuf[64];
        strftime(clockbuf, sizeof(clockbuf), "%H:%M", lt);
        snprintf(out, outsz, "Şu an saat %s.", clockbuf);
    } else if (strlen(tmp) == 0) {
        snprintf(out, outsz, "(Boş mesaj)");
    } else {
        // Varsayılan olarak yankıla
        snprintf(out, outsz, "Bunu söyledin: %s", msg);
    }
}

int main(void) {
    // --- ncurses başlangıç ---
    initscr();              // ncurses modu
    cbreak();               // satır sonunu bekleme, anında input
    noecho();               // otomatik yankı kapalı (girdi penceresinde açacağız)
    keypad(stdscr, TRUE);   // özel tuşlar (ok tuşları vb.)
    curs_set(1);            // imleci göster

    // --- pencere düzeni ---
    int rows, cols;
    getmaxyx(stdscr, rows, cols);

    WINDOW* chat = newwin(rows - INPUT_H, cols, 0, 0);                 // üstte sohbet alanı
    WINDOW* input = newwin(INPUT_H, cols, rows - INPUT_H, 0);          // altta giriş alanı

    scrollok(chat, TRUE);  // alt satıra gelince kaydırmayı aç

    box(chat, 0, 0);
    mvwprintw(chat, 0, 2, " Sohbet ");
    wrefresh(chat);

    // --- kullanıcı adı al ---
    draw_input(input, "Adınız: ");
    char name[32];
    echo();                          // sadece burada yankıyı açıyoruz ki yazarken görünsün
    wgetnstr(input, name, (int)sizeof(name) - 1);
    noecho();
    if (name[0] == '\0') strcpy(name, "Kullanıcı");

    append_line(chat, "Sistem", "Basit ncurses sohbeti. Çıkmak için 'q' yazın.");

    char greet[128];
    snprintf(greet, sizeof(greet), "Merhaba, %s!", name);
    append_line(chat, "Bot", greet);

    // --- sohbet döngüsü ---
    for (;;) {
        draw_input(input, "Mesaj: ");
        wmove(input, 1, 2 + (int)strlen("Mesaj: "));   // imleci prompt sonuna taşı

        char msg[256];
        echo();
        wgetnstr(input, msg, (int)sizeof(msg) - 1);     // güvenli uzunlukta oku
        noecho();

        if (strcmp(msg, "q") == 0) {
            append_line(chat, name, msg);
            append_line(chat, "Bot", "(Görüşürüz!)");
            break;
        }

        append_line(chat, name, msg);

        char reply[512];
        simple_reply(msg, reply, sizeof(reply));
        append_line(chat, "Bot", reply);
    }

    // --- temizlik ---
    delwin(input);
    delwin(chat);
    endwin();
    return 0;
}

