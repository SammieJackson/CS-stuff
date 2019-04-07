#include <iostream>
#include <windows.h>
#include <chrono>
//#include <stdio.h>

using namespace std;

void mess0()
{
    cout << " Hello world!\r";
    Sleep(1000);
    cout << " Time to party!\n";
}

void nums()
{
    for (int i = 0; i < 1001; ++i)
    {
        cout << " Miliseconds passed: " << i << "\r";
        Sleep(50);
    }
}

int main()
{
    ///mess0();
    nums();
    return 0;
}
