#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

/* Like fileReadLine, but provides a prompt and reads from standard input. */
void readLine(char* prompt, char* text, int maxChars);


/* Reads a line of text from a file, up to a maximum number of characters.
   Unlike fgets():
   * If the max character limit is reached, the rest of the line is discarded
   * The newline character is *not* returned.
*/
void fileReadLine(FILE* file, char* text, int maxChars);


/* Reads an int from standard input, then skips to the next line
   (unlike scanf() by itself). */
int readInt(char* prompt);


/* Reads a character from standard input, then skips to the next line
   (unlike scanf() by itself). */
char readChar(char* prompt);


/* Read and discard all characters from a given file until the next
   end-of-line. */
void discardExcessInput(FILE* file);


/* Strips the line break from a string, such as read by fgets(). (This will
   also remove everything *after* the line break, so this should only be used
   on single-line strings.) */
void stripNewline(char* str);

#endif