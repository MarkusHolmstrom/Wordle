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

        // reset random nr (source: https://www.cplusplus.com/reference/cstdlib/srand/)
        srand(time(NULL));
        int random = rand()%8597;

        int index = 0;
        // Go through textfile line by line:
        // (source: https://www.systutorials.com/how-to-process-a-file-line-by-line-in-c/)
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
