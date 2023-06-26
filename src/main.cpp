/**
 * @mainpage
 * @brief Midday Follower - a dumbed down Midnight Commander clone
 * @author Joshua David Crofts aka cakeman105
 * @date Summer semester 2023
 * @details Project for BI-PA2 Programming and algorithmics 2 at FIT CTU
*/

/**
 * @file main.cpp
*/

#include <cstdlib>
#include <ncurses.h>
#include "graphics.hpp"
#include "files.hpp"
#include <filesystem>

constexpr size_t MAX_DISP_AMOUNT = 28;

int main(int argc, char * argv[])
{
    Graphics gfx;
    Files target;
    
    string path;
    if (argc > 1)
        path = argv[1];
    else
        path = ".";
    
    if (!target.readDirectory(path))
        return EXIT_FAILURE;

    gfx.initialize(path.c_str());
    for (size_t i = 0; i < MAX_DISP_AMOUNT; i++)
    {
        const char * x = target.names[i].name.c_str();
        gfx.displayEntry(0, i, x, target.names[i].type, target.names[i].size, true);
    }

    size_t y = 0;
    int index = 0;
    while(true)
    {
        int c = getch();

        if (c == 'q')
            break;
        
        if (c == KEY_UP && y > 1)
        {
            gfx.move(--y, target.names[index].name.length() + 1);
        }
        else if (c == KEY_DOWN && y < MAX_DISP_AMOUNT)
        {
            gfx.move(++y, target.names[index].name.length() + 1);
            index++;
        }
    }

    gfx.end();
    return EXIT_SUCCESS;
}