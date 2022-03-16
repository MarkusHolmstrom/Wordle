
#include <iostream>
#include <string>

using namespace std;

class GameState {
private:
	string target;
	string guesses[6]{ "", "", "", "", "", "" };
	int guessCount = 0;
public:
	GameState() {
		target = "     ";
		guesses->clear();
		guessCount = 0;
	}
	string setTargetWord(string word) {
		return target = word;
	}
	string getTargetWord() {
		return target;
	}
	// adds to the guesses array also check if guess limit have been reached
	bool canAddGuess(string guess) {
		guesses[guessCount] = guess;
		guessCount++;
		// Check to end the while loop in main when 6th guess has been added 
		if (guessCount >= 6)
		{
			cout << "Out of guesses, the word " << '"' << target << '"' << " is what we were looking for." << endl;
			return false;
		}
		return true;
	}
};