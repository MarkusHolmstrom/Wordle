// Wordle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "ColorChanger.cpp"
#include "GameState.cpp"
#include "FileReader.cpp"

using namespace std;

void guessingLoop();

void checkWord(string guess, string target);

string transformTarget(string target, char rem);

Color checkLetter(char guess, int pos, string target);

int main()
{
    cout << FOREGROUND(ForegroundColor::BrightRed, "Hello world!") << endl;
    cout << BACKGROUND(BackgroundColor::BrightRed, "Hello world!") << endl;
    FileReader fr;
    GameState state;
    // Get a random word from list
    string s = state.setTargetWord(fr.getAWord());
    checkWord("ALBCC", s);
    fr.getAWord();
    if (!state.canAddGuess(s))
    {
        // game over
    }
    string a = fr.getAWord();
    string b = fr.getAWord();
    fr.getAWord();
    fr.getAWord();
    fr.getAWord();

}

void guessingLoop() 
{
    while (true)
    {
        cout << "Your guess?" << endl;

    }
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


// inte i ordet: gr� bakgrund
// r�tt bokstav, fel plats: gul bkagrund
// dubbelr�tt: gr�n bakgrund
