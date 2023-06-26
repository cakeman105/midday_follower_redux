/**
 * @file files.hpp
*/

#include <vector>
#include <iostream>
#include <filesystem>

using namespace std;

class Files
{
    public:
        bool readDirectory(const string & path);

        struct Item
        {
            string name;
            int type;
            uintmax_t size;
        };

        vector<Item> names;
    private:
};