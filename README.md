# Captain Hook

A Windows keyboard hook demo in C++. A toy that hooks the keyboard and replaces all typed text with meme text.

**Warning:** This program installs a global hook that replaces all keyboard input with `"YO DAWG I HERD U LYKE HOOKS "`. Run only if you understand the consequences.

## Building

### Script
```batch
.\build.bat
```

### Manual
```bash
# Debug
g++ -std=c++17 -g -Wall -Wextra KeyboardHook\KeyboardHook.cpp -o build\KeyboardHook.exe -luser32 -lgdi32

# Release
g++ -std=c++17 -O3 -s -Wall -Wextra KeyboardHook\KeyboardHook.cpp -o build\KeyboardHook.exe -luser32 -lgdi32
```

## Running
Run as Administrator:

```batch
build\KeyboardHook.exe
```

**Keep Task Manager open to terminate if needed.**

## Customization
Eventually, the program will be able to read the text from a file. For now, edit `KeyboardHook.cpp`:

```cpp
const char* Output = "YOUR CUSTOM TEXT HERE ";
```