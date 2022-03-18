#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class FileReader {

public:
    string getAWord() {
        ifstream inFile;

        inFile.open("words.txt");
        if (!inFile) {
            cout << "Unable to open file";
            exit(1); // terminate with error
        }
        string str;

        int random = rand()%8597;
        // reset random nr, expt the 1st one... https://www.cplusplus.com/reference/cstdlib/srand/
        srand(time(NULL));
        int index = 0;
        // Go through textfile line by line:
        // https://www.systutorials.com/how-to-process-a-file-line-by-line-in-c/
        while (getline(inFile, str)) {
            if (random == index)
            {
                return str;
            }
            index++;
        }
        return str;
    }
};
