#include <stdio.h>
#include <libintl.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include "roman.h"

#define _(STRING) gettext(STRING)
#define LOCALE_PATH "."
#define BUFFER 128

char* toRoman(int d) {
	return roman[d-1];
}

int toDecimal(char* r) {
	for (size_t i; i < 100; ++i) {
		if (!strcmp(r, roman[i]))
			return i+1;
	}

	return -1;
}

int main(int argc, char* argv[argc]) {
    int ROMAN = 0;

    for (size_t i = 0 ; i < argc; ++i) {
		if (!strcmp(argv[i], "-r"))
			ROMAN = 1;
	}

    setlocale(LC_ALL, "");
    if (getenv("PO_LOCAL"))
		bindtextdomain("l10n", LOCALE_PATH);
	else
		bindtextdomain("l10n", "usr/share/locale");
	textdomain ("l10n");

    printf(_("Come up with a number between 1 and 100\n"));
    int number;
    scanf("%d", &number);

    char answer[BUFFER];
    int check = 100, result = 0;
    while (check) {
        if (ROMAN)
			printf(_("Your number is greater then %s? \"Yes\" or \"No\"\n"), toRoman(result + check/2));
		else
            printf(_("Your number is greater then %d? \"Yes\" or \"No\"\n"), (result + check/2));
        scanf("%s", answer);
        if (!strcmp(answer, _("Yes"))) {
            check = check/2;
            result += (check%2) ? (check+1) : check ? check: 1;
        } else if (!strcmp(answer, _("No"))) {
             check = check/2;
        } else {
            printf(_("Input Error. Write \"Yes\" or \"No\"\n"));
        }
    }

    if (ROMAN)
		printf(_("Your number is %s\n"), toRoman(result));
	else
        printf(_("Your number is %d\n"), result);

    return 0;
}
