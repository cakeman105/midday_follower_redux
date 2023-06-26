/**
 * @file graphics.hpp
 * @headerfile 
*/

#include <ncurses.h>

class Graphics
{
    public:
        void initialize(const char * path);
        void end() const;
        void displayEntry(const int & col, const int & row, const char * text, const int & type, const uintmax_t & size, bool isSel) const;
        void move(const size_t & ycoord, const int & length) const;
    private:
        WINDOW * win1;
        WINDOW * win2;
};