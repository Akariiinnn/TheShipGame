#include <SDL.h>
#include <iostream>
#include "app/application.h"
using namespace std;

int main(int argc, char* args[])
{
    Application app;
    cout << "Salut !" << endl;
    cout << "Tu vas bien ?" << endl;
    app.start();

    return 0;
}