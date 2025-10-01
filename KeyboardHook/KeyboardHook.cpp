// KeyboardHook.cpp : Keyboard hook program for Windows
//

#include <windows.h>
#include <iostream>
#include <cstring>

using namespace std;
HHOOK hhkLowLevelKybd;
KBDLLHOOKSTRUCT kbdStruct;

const char *Output = "YO DAWG I HERD U LYKE HOOKS ";
int length = strlen(Output);
int index = 0;

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    kbdStruct = *((KBDLLHOOKSTRUCT *)lParam);
    if (nCode < 0 || kbdStruct.flags & 0x10)
        return CallNextHookEx(hhkLowLevelKybd, nCode, wParam, lParam);
    BYTE keyboard_state[256];
    if (nCode >= 0)
    {
        switch (wParam)
        {
        case WM_KEYDOWN:
        {
            if (index >= length)
            {
                index = 0;
            }
            GetKeyboardState(keyboard_state);
            WORD wCharacter = 0;
            ToAscii(kbdStruct.vkCode, kbdStruct.scanCode, keyboard_state, &wCharacter, kbdStruct.flags);
            INPUT newInput;
            newInput.type = INPUT_KEYBOARD;
            newInput.ki.wScan = kbdStruct.scanCode;
            newInput.ki.dwFlags = kbdStruct.flags;
            newInput.ki.dwExtraInfo = kbdStruct.dwExtraInfo;
            newInput.ki.wVk = Output[index];
            SendInput(1, &newInput, sizeof(newInput));
            index++;
            break;
        }
        }
    }
    return 1;
}

int main()
{
    hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);
    MSG msg;
    while (!GetMessage(&msg, NULL, 0, 0))
    { // this while loop keeps the hook
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hhkLowLevelKybd);

    return 0;
}
