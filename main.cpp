#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <set>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::set;

//Created by Manuel Gordillo on the 20th/Nov/2021, mgordillo11@outlook.com

void guessFunction(string guessInput) {
    //I initialize all of my variables before the guessing begins to avoid future issues
    bool correctAnswer = false;
    bool foundCharacter = false;
    int correctGuesses = 0;
    int incorrectGuesses = 0;
    set<char> correctChars = {};
    set<char> incorrectChars = {};
    set<int> charPositions = {};
    char userGuess = ' ';

    while(!correctAnswer) {
        foundCharacter = false;
        cout << "Guess a letter" << endl;
        cin >> userGuess;

        //Check to see if guess is in the word regardless of being capitalized or not
        for(unsigned int currentCharacter = 0; currentCharacter < guessInput.size(); currentCharacter++) {
            if((guessInput.at(currentCharacter) == userGuess) || (guessInput.at(currentCharacter) == toupper(userGuess)) ||
                    toupper(guessInput.at(currentCharacter)) == toupper(userGuess)) {
                correctChars.insert(userGuess);
                charPositions.insert(currentCharacter);
                correctGuesses++;
                foundCharacter = true;
                break;
            }
        }

        //If the guess is not found, then state that the current guess is invalid and the invalid guesses before as well
        if(!foundCharacter) {
            cout << userGuess << " is not a character in the word" << endl;

            if(incorrectChars.size() != 0) {
                if(incorrectChars.size() == 1) {
                    cout << "So as letter ";
                }
                else {
                    cout << "So as these letters ";
                }

                for(auto const &guess : incorrectChars) {
                    cout << guess << " ";
                }
            }
            cout << endl;
            incorrectChars.insert(userGuess);
            incorrectGuesses++;
        }

        //If found, print out the letters depending on the character positions
        else {
            for(unsigned int character = 0; character < guessInput.size(); character++) {
                bool found = false;
                for(auto const &charNumber : charPositions) {
                    if(charNumber == character) {
                        cout << guessInput.at(charNumber);
                        found = true;
                    }
                }

                if(!found) {
                    cout << "_";
                }
            }
            cout << endl;
        }

        //Checking if the amount of correct guesses is the same as the word size, if so the word has been guesses correctly
        if(correctGuesses == (guessInput.size())) {
            correctAnswer = true;
        }

        cout << "You have a total of " << (correctGuesses + incorrectGuesses) << " guesses, " << correctGuesses
            << " correct and " << incorrectGuesses << " incorrect" << endl << endl;
    }

    cout << "Congrats, you guessed the word!!!" << endl;
}

int main() {
    //Initialized variables to avoid future issues
    bool continueGame = true;
    string userDecision = "";
    string randomString = "";
    int randomNumber = 0;
    vector<string> wordSelection = {"Apple", "Life", "Computer", "BYU", "Thanksgiving", "Christmas", "Hi", "Gospel", "Jukebox", "Strawberry"};
    //5, 4, 8, 3, 12, 9, 2, 6, 7 , 10 (Length of each word, in order of the vector)

    cout << "Welcome user, let the games begin!" << std::endl;

    //Guess as many words as possible, if the user wants to continue more than once
    while(continueGame) {
        //Select random number to pick a word from the word selection
        randomNumber = rand() % 9;
        randomString = wordSelection.at(randomNumber);

        cout << "This word has " << randomString.size() << " letters" << endl;

        //I made a function to guess the word so that the main function can be cleaner looking
        guessFunction(randomString);

        cout << endl << "Would you like to try again? Yes or No?" << endl;
        cin.ignore(); //I include this statement to ignore the newline printed beforehand
        getline(cin, userDecision);

        if(userDecision == "No" || userDecision == "no") {
            continueGame = false;
        }
    }

    cout << "Thank you for playing, have a great day!" << endl;

    //THIS CHALLENGE TOOK ABOUT 1.25 HOURS, AND IT ACTUALLY WAS FUN SOLVING HOW TO DO IT
    //THANK YOU AND HAVE A GOOD DAY

    return 0;
}
