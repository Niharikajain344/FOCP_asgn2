STRINGS AND CHARACTER ARRAYS 

QUE 1 - (Count vowels,consonants, digits,spaces)

#include <stdio.h>
#include <ctype.h>

int main(void) {
    long long vowels = 0;
    long long consonants = 0;
    long long digits = 0;
    long long spaces = 0;

    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == ' ') {
            spaces++;
        } else if (isdigit((unsigned char)ch)) {
            digits++;
        } else if (isalpha((unsigned char)ch)) {
            int lower = tolower((unsigned char)ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
        // Punctuation, '\r', and other symbols are ignored
    }

    printf("%lld %lld %lld %lld\n", vowels, consonants, digits, spaces);
    return 0;
}

QUE 2 - (Run-length code)

#include <stdio.h>

int main(void) {
    int prev = EOF;
    long long count = 0;
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF) {
        if (ch == '\r') {
            continue; // Ignore Windows carriage return
        }

        if (ch == prev) {
            count++;
        } else {
            if (prev != EOF) {
                printf("%c%lld", prev, count);
            }
            prev = ch;
            count = 1;
        }
    }

    if (prev != EOF) {
        printf("%c%lld", prev, count);
    }
    putchar('\n');

    return 0;
}




