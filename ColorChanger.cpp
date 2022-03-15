
#include <iostream>
using namespace std;
#define FOREGROUND(color, text) "\x1B[" << static_cast<int>(color) << "m" << text << "\033[0m"
#define BACKGROUND(color, text) "\033[3;42;" << static_cast<int>(color) << "m" << text << "\033[0m"

enum class ForegroundColor : int {
    Red = 31,
    Green = 32,
    Yellow = 33,
    BrightRed = 91,
    BrightGreen = 92,
    BrightYellow = 93
};

enum class Color { //class elr ej?
    Gray, Yellow, Green
};
enum class BackgroundColor : int {
    Red = 41,
    Green = 42,
    Yellow = 43,
    Gray = 47,
    BrightRed = 101,
    BrightGreen = 102,
    BrightYellow = 103
};
//
//void ColorChanger::method() {
//    cout << "h�pp" << endl;
//}