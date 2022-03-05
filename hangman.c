/**
 * @author MS
 * @file hangman.c
 * @brief Defines the functions for the functions to make words uppercase and to read a word from a file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <ctype.h>
#include <sys/unistd.h>
#include <windows.h>
#include "hangman.h"
#include "functions.h"


int gameMode() {

/// \brief this function comes next after main, which allows the user to choose the preferred game mode 
    printf("--------------------------------------------\n");
    printf("| #  #   #   #   #  #### #   #   #   #   # |\n");
    printf("| #  #  # #  ##  # #     ## ##  # #  ##  # |\n");
    printf("| #### ##### # # # #  ## # # # ##### # # # |\n");
    printf("| #  # #   # #  ## #   # #   # #   # #  ## |\n");
    printf("| #  # #   # #   #  ###  #   # #   # #   # |\n");
    printf("--------------------------------------------\n\n");
    printf("\tWhich mode do you prefer ? \n\t -> r : Random word \n\t -> f : From file \n\t -> h : Help \n\t -> q : Quit \n\t "); /*\example Prints the welcome statement*/
    /*
     * \example This part gets the user input
     */

    char ch;
    char stayOrGo ;
    char userChoice[USR_INPUT];
    printf("\n\tInput :\n");
    ch = getchar();





    switch (ch) {
        /// \param ch for switch case
        case 'r':

        printf("\nRandom Word...\n\n");
        sleep(2);
        char filepath[BUF_SIZE] = "C:/Users/asus/Desktop/t.zip/wordlist.txt"; ///\brief file address
        char* word = readWord(filepath);

        guessingFunc(word);
        free(word);
        gameMode();
        break;

        case 'f':
            printf("\nEnter a valid file path & press ENTER.\n\n");
            Beep(400,500);
            char c  = 0;
            fgets(&c, BUF_SIZE, stdin);
            char userInput[BUF_SIZE + 1];
            fgets(userInput, BUF_SIZE, stdin);
            char* randomWord = readWord(userInput);
            guessingFunc(randomWord);
            free(randomWord);
            gameMode();
            break;

        case'h':
            printf("\n\n\n\t\t INSTRUCTIONS \n\n\n\t\t ============");
            printf("\n   1: HANGMAN IS THE GAME WHERE YOU HAVE TO GUESS THE WORD.\n");
            printf("\n   2: YOU WILL HAVE TO GUESS THE RIGHT CHARACTERS.\n");
            printf("\n   3: YOU HAVE THE (n) TRIES, OR THE HANGING PLATFORM WILL BE WAITING:)\n\n\n");
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |  \\|/\n");
            printf("  |    | \n");
            printf("  |   / \\\n");
            printf("__|_________\n\n");
            sleep(10);
            printf("Do you want to return to main menu ?\t [Y]yes or [N]no\n");

            if(stayOrGo == 89 || stayOrGo == 121) {
                gameMode();
                }
            else if(stayOrGo == 110 || stayOrGo == 78){
                printf("Wish you a nice day!");
                return 0;
            }
            else{
                gameMode();
            }


        case 'q':
            printf("\nHave a nice day! :)\n");
            sleep(4);
            return 0;

        default:
        printf("\n\nUnknown error 404 %s\n\n", userChoice);///\alert error
        gameMode();

    }
}
/*
 * \brief UPPERCASE transformation
 */
    void upperCase(char* toTransform) {
    ///\brief This function transforms a passed parameter making it uppercase.

    ///\param replaces the words with UPPERCASE characters

    for(int i = 0; toTransform[i]; i++) {
        toTransform[i] = toupper(toTransform[i]);
            }
    }
/*
 * \definition Reads the word to be guessed from a supplied filepath
 */
    char* readWord(char* filePath) {
    ///\brief This function reads a given file and selects a word randomly.


    /// \param (char* filepath) the file location.

    if(filePath == NULL) {
        fprintf(stderr, "Failure! Invalid filepath.\n");
        printf("error code: %d\n", errno);
        printf("the error message is: %s\n", strerror(errno));
        return NULL;
    }

    if(strchr(filePath, '\n') != NULL) { /*\brief Checks whether the filepath contains newline characters*/
        strtok(filePath, "\n"); /*\brief Separates the filepath from other lines*/
    }

    FILE* fp = fopen(filePath, "r"); ///\brief to see if the file can be open
    ///\brief Checks for errors in the file opening process
    if(fp == NULL) {
        fprintf(stderr, "Fail. Could not open file %s: %s.\n", filePath, strerror(errno)); ///\alert failure when trying to open the file
        printf("error code: %d\n", errno);
        printf("the error message is : %s\n", strerror(errno));
        return NULL;
    }

    int lineCount = 0; //Counts how many lines the file contains
    int randWord; //Gets a random number
    char getC; //To read the word character by character
    ///\definition Reads the file line after line

    while(!feof(fp)) {
        getC = fgetc(fp);
        if(getC == '\n') {
            lineCount++;
        }
    }

    if(lineCount == 0) {///\brief checking for lines in the file
        fprintf(stderr, "Error.\n");
        printf("value of errno: %d\n", errno);
        printf("Error code %s\n", strerror(errno));
        perror("message from perror");
        return NULL;
    }

    srand(time(NULL));///\brief generate a random number based in the time seed
    randWord = rand() % lineCount; /*\brief Limits the random generator to the lines of the file*/

    rewind(fp); ///\brief to go to the start of the file
    while(randWord > 0 && !feof(fp)) {
        getC = fgetc(fp);
        if(getC == '\n') {
            lineCount--;
            randWord--;
        }
    }

    char* word = malloc(BUF_SIZE); ///\brief Allocates the size for the word buffer
        ///\brief we should check for error in the memory allocation process

    if(word == NULL) {
        fprintf(stderr, "Error while allocating memory.\n");
        printf("errno: %d\n", errno);
        printf("Error code : %s\n", strerror(errno));
        perror("perror alert");
        return NULL;
    }

    memset(word, '\0', BUF_SIZE); ///\brief Initializes the string with NULLs, */
    fgets(word, BUF_SIZE, fp); ///\brief gets the word and store in the word buffer*/
    fclose(fp); ///\brief Closes the file*/

    upperCase(word); ///\brief start the upperCase function*/

    return word; /*\brief Returns word*/
    }
