//
// Created by greyzerus on 17.04.17.
//

#ifndef HW8_WORD_ENTRIES_HPP
#define HW8_WORD_ENTRIES_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include "clocale_delimiters.hpp"

class lexical_word_entries {
public:
    /*constructors*/
    lexical_word_entries(const std::string &word);
    lexical_word_entries(lexical_word_entries &other);
    lexical_word_entries operator=(lexical_word_entries &other);


    /*getters*/
    std::string get_word();
    size_t get_entries_count();
    size_t get_word_entries (uint num);
    size_t get_entries_mean ();

    int process (const std::string &filename);

private:
    std::string word;
    std::vector <std::pair <std::string ,int>> entries;
    /*A pair of [[filename], [entries_count]]*/
    std::locale puncts_as_spaces;
};

#endif //HW8_WORD_ENTRIES_HPP
