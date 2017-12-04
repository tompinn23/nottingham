#ifndef COLORS_H
#define COLORS_H

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
void SetColor(int color)
{
    SetConsoleTextAttribute(hConsole, color);
}
#else

#endif

#endif //COLORS_H