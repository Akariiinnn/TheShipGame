#include <SDL.h>
#include <iostream>
#include "application.h"
using namespace std;

int main(int argc, char* args[])
{
    Application app;
    cout << "Salut !" << endl;
    app.start();

    return 0;
}