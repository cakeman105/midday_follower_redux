/**
 * @file files.cpp
 * @brief class for file manipulation
 * @author Joshua David Crofts
*/

#include <filesystem>
#include "files.hpp"
#include <vector>
#include <iostream>

using namespace std;

/**
 * @brief reads the contents of directory supplied in path param
 * @param[in] path path to be read
 * @return true on success, false on fail
*/
bool Files::readDirectory(const string & path)
{
    if (!filesystem::is_directory(path)) //check whether path supplied is valid
    {
        cerr << "Invalid path submitted!" << endl; //output to cerr and end program
        return false;
    }
    
    names.push_back(Item{"../", 3, 0});
    for (const auto & file : filesystem::directory_iterator{path}) //iterate thru directory
    {
        Item item;
        item.name = file.path().filename();

        if (file.is_directory()) //check file type
            item.type = 3;

        else if (file.is_regular_file())
        {
            item.size = file.file_size();
            item.type = 4;
        }

        else if (file.is_symlink())
            item.type = 5;

        names.push_back(item);
    }

    return true;
}

