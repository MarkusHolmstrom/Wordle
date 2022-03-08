// Wordle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "ColorChanger.cpp"
#include "GameState.cpp"
#include "FileReader.cpp"

using namespace std;

string guessingLoop();

void checkWord(string guess, string target);

string transformTarget(string target, char rem);

Color checkLetter(char guess, int pos, string target);

bool restartGame();

int main()
{
start:
    cout << FOREGROUND(ForegroundColor::BrightRed, "Hello world!") << endl;
    cout << BACKGROUND(BackgroundColor::BrightRed, "Hello world!") << endl;
    FileReader fr;
    GameState state;
    // Get a random word from list
    string target = state.setTargetWord(fr.getAWord());
    //checkWord("ALBCC", s);
    //fr.getAWord();

    bool guessing = true;
    while (guessing)
    {
        string guess = guessingLoop();
        checkWord(guess, target);

        if (!state.canAddGuess(guess))
        {
            guessing = false;
        }
    }
    // todoo output guesses and right target
    if (restartGame())
    {
        goto start;
    }

    string a = fr.getAWord();
    string b = fr.getAWord();
    fr.getAWord();
    fr.getAWord();
    fr.getAWord();

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
            cout << "Invalid inputmust be five letters long, please try again:" << endl;
            goto reguess;
        }
    }
    cout << inp << endl;
    return inp;
}

// Must be five letters each
void checkWord(string guess, string target) {
    vector<Color> colors;
    for (size_t i = 0; i < 5; i++)
    {
        Color color = checkLetter(guess[i], i, target);
        colors.push_back(color);
        if (color == Color::Yellow)
        {
            // remove one char from target thats already been matched
            target = transformTarget(target, guess[i]);
        }
        //cout << " " << color << endl;
    }
}
// Removes a certain char from the string target
string transformTarget(string target, char rem) {
    string newTarget = target;
    for (size_t i = 0; i < 5; i++)
    {
        if (newTarget[i] == rem)
        {
            newTarget[i] = ' ';
        }
    }
    cout << newTarget << endl;
    return newTarget;
}

Color checkLetter(char guess, int pos, string target) {
    if (target[pos] == guess)
    {
        // Correct letter, correct location

        cout << "Correct letter, correct location"  << endl;
        return Color::Green;
    }
    for (size_t i = 0; i < 5; i++)
    {
        if (target[i] == guess)
        {
            cout << "Correct letter, wrong location" << endl;
            // Correct letter, wrong location
            return Color::Yellow;
        }
    }
        cout << "Letter not found in target word" << endl;
    // Letter not found in target word
    return Color::Gray;
}

bool restartGame() {
    cout << "Game over, wanna play again? type 'y' for yay, else for no";
    char inp;
    cin >> inp;
    if (inp == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}



// inte i ordet: grå bakgrund
// rätt bokstav, fel plats: gul bkagrund
// dubbelrätt: grön bakgrund
