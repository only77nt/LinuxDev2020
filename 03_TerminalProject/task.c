#include <stdio.h>
#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define DX 3

 void reverse(char s[])
 {
     int i, j;
     char c;

     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
}  

void itoa(int n, char s[])
 {
     int i, sign;

     if ((sign = n) < 0)
         n = -n;
     i = 1;
     do {
         s[i++] = n % 10 + '0';
     } while ((n /= 10) > 0);
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
}  

char* get_slice(char* word, int begin, int end) {
    char* slice = (char*) malloc((end-begin+1)*sizeof(char));
    int j = 0;
    for(int i = begin; i <= end; i++){
        if (word[i] == '\0') {
            slice[j] = word[i];
            return slice;
        }
        slice[j] = word[i];
        j++;
    }
    slice[j] = '\0';

    return slice;
}

char** get_strings(char *file_name, int *file_size) {
    int size = 0;
    FILE *file;
    size_t n;
    char **strings;
    char *buffer = NULL;
    char *size_s = (char*) malloc(sizeof(char*));

    strings = (char**) malloc(sizeof(char*));

    file = fopen(file_name, "r");

    while(!feof(file)) {
        if (getline(&buffer, &n, file) != -1) {
            strings = (char**) realloc(strings, (size+1)*sizeof(char*));
            strings[size] = (char*) malloc(n+1);
            strcpy(strings[size], buffer);
            size++;
        }
    };

    fclose(file);

    *file_size = size;

    return strings;
}

void main(int argc, char **argv) {
    WINDOW *win;
    int c = 0;
    int file_size = 0;

    setlocale(LC_ALL, "");

    char **strings = get_strings(argv[1], &file_size);

    initscr();
    noecho();
    cbreak();
    printw("File: %s; size: %d\n", argv[1], file_size);
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok (win, TRUE);

    int lines;
    if (((LINES-2*DX)/1.2) > file_size) {
        lines = file_size;
    } else {
        lines = (LINES-2*DX)/1.2;
    }

    int cols_begin = 0;
    int cols_end = COLS-2*DX;

    int j = 0;
    do {
        if (c == 32) {
            if (j >= file_size-lines) {
                continue;
            }
            j++;
        }

        if (c == 27) {
            break;
        }

        if (c == KEY_UP) {
            if (j < 1) {
                continue;
            }
            j--;
        }

        if (c == KEY_DOWN) {
            if (j >= file_size-lines) {
                continue;
            }
            j++;
        }

        if (c == KEY_LEFT) {
            if (cols_begin < 1){
                continue;
            }
            cols_begin--;
            cols_end--;
        }

        if (c == KEY_RIGHT) {
            cols_begin++;
            cols_end++;
        }

        if (c == KEY_PPAGE) {
            if (j < 2*lines) {
                j = lines;
            }
            j -= lines;
        }

        if (c == KEY_NPAGE) {
            if (j > file_size-2*lines) {
                j = file_size-2*lines;
            }
            j += lines;
        }

        werase(win);

        for(int i = 0; i < lines; i++) {
            wmove (win, i+1, 5);
            wprintw(win, "%d: ", i+j+1);
            char *word = get_slice(strings[i+j], cols_begin, cols_end);
            wprintw(win, "%s\n", word);
            box(win, 0, 0);
        }
        wrefresh(win);
    } while((c = wgetch(win)));

    endwin();

    for(int j = 0; j < file_size; j++) {
        free(strings[j]);
    }

    return;
}