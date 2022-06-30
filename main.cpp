#include <SDL.h>
#include <iostream>
#include "app/application.h"
#include <windows.h>
using namespace std;

int main(int argc, char* args[])
{
    int difficulty;
    cout << "Enter the amount of meteorites (max: 5) : " << endl;
    cin >> difficulty;
    Application app(difficulty);
    cout << "Salut !" << endl;
    cout << "Tu vas bien ?" << endl;

    HWND console = GetConsoleWindow();
    //hide console
    //ShowWindow(console, SW_HIDE);
    app.start();

    return 0;
}