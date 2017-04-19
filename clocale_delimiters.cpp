//
// Created by greyzerus on 18.04.17.
//

#include <climits>
#include "clocale_delimiters.hpp"


clocale_delimiters::clocale_delimiters (size_t refs)
    : std::ctype<char>(&locale_delimiters[0], false, refs)
{
    std::copy_n(classic_table(), table_size, locale_delimiters);
    for (size_t i = 0; i < table_size; i++) {
        if (ispunct(static_cast<char>(i))) {
            locale_delimiters[i] = (mask)space;
        }
    }
}