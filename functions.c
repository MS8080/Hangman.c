/**
 * @file functions.c
 * @description this is  the function for the main game
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
#include "functions.h"

/*void mercy(int* lives,char d){

    printf("Do you want extra 5 lives?");
    scanf("%c", &d);
    if (d == 'Y' || 'y'){
        lives  +5;

        }

    } */


void guessingFunc(char* word) {
/// \brief this function will run after gameMode function, here will the guessingFunc function  processed

    FILE* log; //\brief pointer to a file
    log = fopen("C:/Users/asus/Desktop/t.zip/progress.log","a+");/*\location This is the path where the log file is created and accessed. The results will be appended to the file.*/

    //TO INSERT HERE: CHECK, IF FILEPATH EXISTS (For other computers)

    time_t timeStamp; /* \brief Saves what the "time()"-function gets during runtime*/

    char userInput; // the user input
    char* tmpBuff = strdup(word); // To save the word temporarily, so it doesn't get lost while it's being overwritten*/
    int length = 0; // how long the word is
    int tries = 0; // The tires you have to guess the word
    int guesses = 0; // how many times the user has given the character

    /*
     * \explanation Determines how long the word is and saves it in the specified variable
     */
    for (int i = 0; word[i] != '\n' ; i++) {
        if (word[i] == '\r') {
            break;
        }

        length++;
        ++tries; ///\brief I used tries++ (before the add) because when the for loop reach '\r' it won't count it as an extra character 

        }
    /* \explanation
     *  The chances are equal to the word length
     */
    printf("the random word has been chosen, it has %d characters.\nNow try to guess it...\n",
           length);///\alert tells the user the word is ready.

    /* \explanation
     *  this function will save the time from the system and write in it in the log file.
     * This code will be repeated a couple of times below.
     */
    time(&timeStamp);
    fprintf(log,"The show started at: %s\n", ctime(&timeStamp)); ///\alert the beginning of the game

    /*
     * \brief This is where the guessingFunc takes place. It also scans the input and checks whether the input is valid or not
     */
    while (tries > 0 && guesses < length && (userInput = toupper(fgetc(stdin))) != EOF) {

        /*
         * \brief Checks for newlines (ENTER-presses in this case)
         */
        if (userInput == '\n') {
            continue;
        }

        time(&timeStamp);
        fprintf(log, "The user tried character '%c' on %s\n", userInput, ctime(&timeStamp));

        if (userInput < 65 || (userInput > 90 && userInput < 97) || userInput > 122) { /// \brief the user can give characters between A and Z, A is 65 in ASCII , Z is 90 ASCII format
            /* if the user gave other character which not included between A and Z || a and z , there will be an error message
             */
            printf("\nNot valid!\n"); ///\alert error message
            continue;
        }

        int tmpGuessed = guesses; /*\brief temporarily saves the old guesses variable.*/
        /*
         * \explanation here we should modify the copy of the word so the progress can be tracked. Eg: 'hi' is the word --> 'h' is guessed --> modification takes place: '#i'.
         */
        for (int i = 0; tmpBuff[i] != '\0'; i++) { /*\brief Increases the "guesses" variable if the user has guessed the word right*/
            if (tmpBuff[i] == userInput) {
                tmpBuff[i] = '*';
                guesses++;
            }
        }
        /*
         * \example This is interpreted as follows: If the user input doesn't change anything, then the guessed variable remains the same, and therefore the user input was wrong.
         * The user input always needs to change something in order to be right!
         */
        if (tmpGuessed == guesses) { ///\brief If the tmpGuessed still remains like the old guesses , it means the user has not changed the word
            Beep(200,300);///\explanation the program will make a beep sound with 200 Hz and 300 millisecond
            printf("\nWrong guess! You have %d tries left \n", tries);///\alret
            tries--;
        }


        for (int i = 0; tmpBuff[i] !='\n'; i++) {  ///\explanation we use \n here because \0 still gives me a "_" after the entire word
            if (tmpBuff[i] == '*') {
                printf("%c",word[i]);           ///\explanation If the character was right, print it in the place where it is in the original word.
            } else if( tmpBuff[i] == '\r'){    ///because the words are ending with a '\r' (I can see it when debugging), I want the if statement
                                              ///to break if it encountered '\r' so it won't show extra characters */
                break;
            }
            else{                            /// Otherwise there will be an * to mark the un-guessed letters
                printf("*");
            }
        }
        printf("\n");

        ///\explanation to check if the user has tires
         ///
        while (tries >= 3 && tries <= 8){
            printf("  _______\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
            break;
        }
        if (tries == 2){
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |\n");
            printf("  |\n");
            printf("  |\n");
            printf("__|_________\n\n");
        }
        if (tries == 1){
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf("  |    |\n");
            printf("  |    |\n");
            printf("  |\n");
            printf("__|_________\n\n");
        }

        if (tries == 0) {
            printf("\n\nEnd of the show:(\n\tThe word is: %s\n\n",word);///\alert The user has lost
            Beep(200,900);
            printf("  _______\n");
            printf("  |/   | \n");
            printf("  |    O \n");
            printf(" ||   \\|/\n");
            printf("  |    | \n");
            printf("  |   / \\\n");
            printf("__|_________\n\n");
            fprintf(log,"The show ended show\n"); ///\alert Prints the loss statement to the log file
            printf("returning to main menu..\n");
            sleep(5);
        }

        /*
         * \explanation  to check if the user won
         */

}
    if (guesses == length) {
        printf("\n\nYou guessed the word : %s\nCONGRATULATIONS!\n", word);///\alert Prints the win message
        fprintf(log, "Player won.\n\n");///\brief Prints the win to the log file*/
        printf("returning to main menu...\n");
        sleep(5);
    }

    time(&timeStamp);
    fprintf(log, "The show ended at: %s\n\n",ctime(&timeStamp)); /*\brief write when was the game ended in the log file*/
    fclose(log);

    ///\explanation closes the log file
}