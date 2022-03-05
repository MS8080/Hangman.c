/**
 \file
*/
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define BUF_SIZE 256 ///this is the Buffer size. Damit der letzte Charakter, nämlich '/0' oder '/n' auch mitgenommen wird und du keinen off-by-one-error hast
#define USR_INPUT 1 /// the buffer size for the user input. Will only be used at the beginning to limit the possible user input.*/

int gameMode(); /// the function which let the user choose the game mode.*/
void upperCase(char *toTransform); ///to make upper case letter from the user input.*/
char *readWord(char *filePath); /// This function reads a given file and selects a word randomly.*/

#endif
