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
        //int random = rand_r() & 8597;
        //srand(time(0));
        srand(time(NULL));// reset random nr?, - not 1st one... https://www.cplusplus.com/reference/cstdlib/srand/
        int random = rand()%8597;
         
        int index = 0;
        //https://www.systutorials.com/how-to-process-a-file-line-by-line-in-c/
        while (getline(inFile, str)) {
            //cout << str << " indexp: " << index << "\n";
            if (random == index)
            {
                cout << str << " index: plop" << index << "\n";
                return str;
            }
            index++;
        }
        return str;
    }
};
// http://www.cplusplus.com/forum/beginner/141904/
