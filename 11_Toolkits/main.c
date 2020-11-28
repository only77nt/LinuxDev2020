#include <stdio.h>
#include <string.h>
#include <glib.h>

#define BUFFER_SIZE 80

int main(int argc, char* argv[argc]) {
    FILE* input;
    switch (argc)
    {
    case 1:
        input = stdin;
        break;
    case 2:
        input = fopen(argv[1], "r");
		if (!input) {
			printf("Error: Cant open file %s\n", argv[0]);
			return 1;
		}
        break;
    default:
        printf("Error: write filename or nothing as a program params\n");
        return 1;
    }

    gchar buffer[BUFFER_SIZE+1];
    gchar** words;

    while (fgets(buffer, BUFFER_SIZE+1, input)) {
        buffer[strlen(buffer) - 1] = '\0';
		words = g_strsplit(buffer, " ", BUFFER_SIZE);
    }

    for (int i = 0; i < sizeof(words); i++) {
        printf("%s\n", (char*)words[i]);
    }

    return 0;
}