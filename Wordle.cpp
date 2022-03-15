// Wordle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "ColorChanger.cpp"
#include "GameState.cpp"
#include "FileReader.cpp"

using namespace std;

string guessingLoop();

bool checkWord(string guess, string target);

string transformTarget(string target, char rem);

BackgroundColor searchForCorrect(char guess, int pos, string target);

BackgroundColor checkLetter(char guess, int pos, string target, bool greenSearch);

bool restartGame();

GameState state;

int main()
{
start:
    cout << "Starting 'Wordle' game... finding random word... " << endl;
    state = GameState();
    FileReader fr;
    // Get a random word from list
    string target = state.setTargetWord(fr.getAWord());
    cout << "Got a five letter word now. " << endl;

    bool guessing = true;
    while (guessing)
    {
        string guess = guessingLoop();

        if (checkWord(guess, target) || !state.canAddGuess(guess))
        {
            guessing = false;
        }
    }

    if (restartGame())
    {
        goto start;
    }
}

string guessingLoop() 
{
    string inp = "     ";
    bool valid = false;
    while (!valid)
    {
    reguess:
        cout << "Your guess?" << endl;
        cin >> inp;
        if (inp.size() == 5)
        {
            for (size_t i = 0; i < inp.size(); i++)
            {
                // Is it not a letter?
                if (!isalpha(inp[i]))
                {
                    cout << "Invalid input: only letters allowed, please try again:" << endl;
                    goto reguess;
                }
                inp[i] = toupper(inp[i]);
            }
            valid = true;
        }
        else
        {
            cout << "Invalid input: must be five letters long, please try again:" << endl;
            goto reguess;
        }
    }
    return inp;
}

// todo 
// 
// Must be five letters each
bool checkWord(string guess, string target) {
    string tempGuess = guess;
    BackgroundColor colors[5] { BackgroundColor::Gray, 
        BackgroundColor::Gray, BackgroundColor::Gray, BackgroundColor::Gray,BackgroundColor::Gray };
    // Need to check for correct letters at correct positions first...
    for (size_t i = 0; i < 5; i++)
    {
        BackgroundColor color = checkLetter(guess[i], i, target, true);
        if (color == BackgroundColor::Green)
        {
            colors[i] = color;
            // remove one char from target and guess thats already been matched
            target = transformTarget(target, guess[i]);
            guess = transformTarget(guess, guess[i]);
        }
    }
    // ... then the correct letters at the wrong positions...
    for (size_t i = 0; i < 5; i++)
    {
        BackgroundColor color = checkLetter(tempGuess[i], i, target, false);
        if (color == BackgroundColor::Yellow)
        {
            // avoid overwriting already green ones
            if (colors[i] != BackgroundColor::Green)
            {
                colors[i] = color;
            }
            // remove one char from target thats already been found
            target = transformTarget(target, guess[i]);
        }
    }
    // ... before we print it out to show how correct they are
    for (size_t i = 0; i < 5; i++)
    {
        if (colors[i] == BackgroundColor::Gray)
        {
            cout << FOREGROUND(ForegroundColor::BrightRed, BACKGROUND(BackgroundColor::Gray, tempGuess[i]));
        }
        else
        {
            cout << BACKGROUND(colors[i], tempGuess[i]);
        }
        
    }
    cout << endl;
    if (tempGuess == state.getTargetWord())
    {
        cout << "Correct! " << '"' << state.getTargetWord() << '"' << " is what we were looking for!" << endl;
        return true;
    }
    return false;
}
// Removes a certain char from the string target
string transformTarget(string target, char rem) {
    string newTarget = target;
    for (size_t i = 0; i < 5; i++)
    {
        if (newTarget[i] == rem)
        {
            newTarget[i] = ' ';
    //cout << newTarget << endl;
            return newTarget;
        }
    }
    return newTarget;
}

BackgroundColor checkLetter(char guess, int pos, string target, bool greenSearch) {
    if (target[pos] == guess)// && greenSearch)
    {
        // Correct letter, correct location
        return BackgroundColor::Green;
    }
    if (!greenSearch)
    {
        for (size_t i = 0; i < 5; i++)
        {
            if (target[i] == guess)
            {
                // Correct letter, wrong location
                return BackgroundColor::Yellow;
            }
        }
    }
    // Letter not found in target word
    return BackgroundColor::Gray;
}

bool restartGame() {
    cout << "Out of guesses, the word " << '"' << state.getTargetWord() << '"' << " is what we were looking for." << endl;
    cout << "You want to play again? type 'y' for yay, something else for no" << endl;
    char inp;
    cin >> inp;
    if (inp == 'y' || inp == 'Y')
    {
        return true;
    }
    else
    {
        return false;
    }
}



// inte i ordet: gr� bakgrund
// r�tt bokstav, fel plats: gul bkagrund
// dubbelr�tt: gr�n bakgrund
