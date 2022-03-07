
#include <iostream>
#include <string>

using namespace std;

class GameState {
private:
	string target;
	string guesses[5]{ "", "", "", "", "" };
	int guessCount = 0;
public:
	string setTargetWord(string word) {
		return target = word;
	}
	string getTargetWord() {
		return target;
	}
	// adds to the guesses array also check if guess limit have been reached
	bool canAddGuess(string guess) {
		if (guessCount >= 5)
		{
			return false;
		}
		guesses[guessCount] = guess;
		guessCount++;
		cout << guessCount << " " << guess << endl;
		for (size_t i = 0; i < 5; i++)
		{
			cout << guesses[i] << endl;
		}
		return false;
	}
	/*string getGuesses(){
		return guesses;
	}*/
};