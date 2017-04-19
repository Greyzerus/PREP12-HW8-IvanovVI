//
// Created by greyzerus on 18.04.17.
//

#ifndef HW8_CLOCALE_DELIMITERS_HPP
#define HW8_CLOCALE_DELIMITERS_HPP

#include <locale>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <sstream>

class clocale_delimiters : public std::ctype<char>
{
    mask locale_delimiters[table_size];
public:
    clocale_delimiters(size_t refs = 0); //TODO read
};


#endif //HW8_CLOCALE_DELIMITERS_HPP










































































/*
http://stackoverflow.com/questions/10376199/how-can-i-use-non-default-delimiters-when-reading-a-text-file-with-stdfstream
 */