/**
 * @file graphics.cpp
 * @brief class for handling graphics
 * @author Joshua David Crofts
*/

#include <iostream>
#include <ncurses.h>
#include "graphics.hpp"

//82x32

using namespace std;

/**
 * @brief initialize the ncurses terminal
 * @param[in] path path to be opened
*/
void Graphics::initialize(const char * path)
{
    initscr();
    //resize_term(100, 100);
    start_color();
    noecho();
    //colour settings
    init_pair(1, COLOR_WHITE, COLOR_BLACK); 
    init_pair(2, COLOR_BLACK, COLOR_MAGENTA);
    bkgd(COLOR_PAIR(1));
    
    attron(COLOR_PAIR(2));
    mvprintw(0, 0, "MIDDAY FOLLOWER v0.1 - A dumbed down file manager");
    attroff(COLOR_PAIR(2));
    refresh();

    win1 = newwin(30, 40, 1, 1);
    win2 = newwin(30, 40, 1, 41);
    
    //setup for the 2 windows
    keypad(win1, true);
    keypad(win2, true);
    keypad(stdscr, true);
    wbkgd(win1, COLOR_PAIR(1));
    wbkgd(win2, COLOR_PAIR(1));
    box(win1, 0, 0);
    box(win2, 0, 0);
    mvwaddstr(win1, 0, 3, path);
    mvwaddstr(win2, 0, 3, path);
    wrefresh(win1);
    wrefresh(win2);

    attron(COLOR_PAIR(2));
    mvaddstr(31, 0, "Note: press 'q' to exit!");
    attroff(COLOR_PAIR(2));
    wmove(win1, 0, 5);
    refresh();
}

/**
 * @brief end the ncurses terminal
*/
void Graphics::end() const
{
    endwin();
}

/**
 * @brief displays individual file names to the terminal, and changes color on name based on file type
 * @param[in] col column
 * @param[in] row row
 * @param[in] x file name
 * @param[in] type file type
 * @param[in] size file size
*/
void Graphics::displayEntry(const int & col, const int & row, const char * x, const int & type, const uintmax_t & size, bool isSel) const
{
    init_pair(3, COLOR_RED,     COLOR_BLACK);
    init_pair(4, COLOR_GREEN,   COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    
    wattron(win1, COLOR_PAIR(type));
    wattron(win2, COLOR_PAIR(type));
    attron(COLOR_PAIR(type));
    mvwaddstr(win1, row + 1, col + 1, x);
    mvwaddstr(win2, row + 1, col + 1, x);
    wattroff(win2, COLOR_PAIR(type));
    wattroff(win1, COLOR_PAIR(type));
    attroff(COLOR_PAIR(type));
    wrefresh(win1);
    wrefresh(win2);
}

/**
 * @brief moves the cursor up and down the screen
 * @param[in] ycoord y-coordinate to display the cursor on
 * @param[in] length word length
*/
void Graphics::move(const size_t & ycoord, const int & length) const
{
    wmove(win1, ycoord, length);
    wrefresh(win1);
}



