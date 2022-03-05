# Compilation

The Compilation should be done with the following command: 
gcc -std=c99 -Wall -Wextra -pedantic -Wno-unused-parameter -o main hangman.h hangman.c main.c

# Execution

  - After the successful compilation, the application could be started ./main without parameters. After this, the following intuitive menu is displayed:
  
  "which mode do you prefer ?"

1. Random word
2. from file
3. help 
4. quit

The possible options of the menu:

  - The player can choose one of the four options.
  - If the player will press key 1, then the game will start in manual mode and the guessed word will have to be introduced from the keyboard
  - If the player will press key 2, then the words which need to be guessed will be random chosen from the input [input file](input.txt) which is inserted from the keyboard. The words needs to be one on a separate line.
Each random chosen word from the [input file](input.txt)  will be marked into the file as already chosen, in order to avoid a subsequent random selection of the same word.
  - If key 3 is pressed, then the marked words will be reset into the [input file](input.txt) which is inserted from the keyboard.
  - If key 4 is pressed, then the game is ended.
  
The game progress is written  into the text file [logFile](logFile.txt)

# Completed Tasks

Following tasks were implemented:
### 1.Main Task (30 points)


- Supply the word to guess on the command line.
- Let the user guess character by character and inform him about the state of the game (cf. below).
- Do not distinguish between lower- and uppercase characters, i.e. use an alphabet of only 26 symbols.
- Write the progress of the game into a log file including the time of the user inputs (cf. time.h).
Clearly mark the start and end of each game and do not overwrite an existing log file.


### 2.Task (15 points)


- Allow the user to directly guess the whole word instead of a single character and end the game immediately afterwards (the player looses if he guesses wrong).

### 3.Task (10 points)


- Support multiple game rounds without restarting the game.
- Supply a new word for each round in a sensible way.

### 4.Task (15 points)
- Instead of supplying the word directly the user has to specify an input file that contains possible words to guess.
- Select any word from that list at random.

### 5.Task (15 points)
- Mark used words persistently in the word input file.
- Exclude previously used words when selecting a random word.
- Allow the user to reset the markers in the file.

