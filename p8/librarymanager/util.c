#include <string.h>
#include "util.h"

/* Like fileReadLine, but provides a prompt and reads from standard input. */
void readLine(char* prompt, char* text, int maxChars) {
    fputs(prompt, stdout);
    fileReadLine(stdin, text, maxChars);
}


/* Reads a line of text from a file, up to a maximum number of characters.
   Unlike fgets():
   * If the max character limit is reached, the rest of the line is discarded
   * The newline character is *not* returned.
*/
void fileReadLine(FILE* file, char* text, int maxChars) {
    int length;

    fgets(text, maxChars, file);

    length = strlen(text);
    if(text[length - 1] == '\n') {
        text[length - 1] = '\0';
    }
    else {
        discardExcessInput(file);
    }
}

/* Reads an int from standard input, then skips to the next line
   (unlike scanf() by itself). */
int readInt(char* prompt) {
    int value;

    fputs(prompt, stdout);
    scanf("%d", &value);
    discardExcessInput(stdin);

    return value;
}

/* Reads a character from standard input, then skips to the next line
   (unlike scanf() by itself). */
char readChar(char* prompt) {
    char ch;

    fputs(prompt, stdout);
    scanf(" %c", &ch);
    discardExcessInput(stdin);

    return ch;
}

/* Read and discard all characters until the next end-of-line (or end-of-file). */
void discardExcessInput(FILE* file) {
    char ch;

    do {
        ch = fgetc(file);
    } while(ch != '\n' && ch != EOF);
}

/* Strips the line break from a string, such as read by fgets(). (This will
   also remove everything *after* the line break, so this should only be used
   on single-line strings.) */
void stripNewline(char* str) {
    while(*str != '\0' && *str != '\n') {
        str++;
    }
    *str = '\0';
}
