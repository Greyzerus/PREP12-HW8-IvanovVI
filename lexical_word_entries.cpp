//
// Created by greyzerus on 17.04.17.
//

#include <fstream>
#include <iomanip>
#include "lexical_word_entries.hpp"


lexical_word_entries::lexical_word_entries(const std::string &word)
        : word(word), entries()
        , puncts_as_spaces(std::locale::classic(), new clocale_delimiters) {}

int lexical_word_entries::process (const std::string &filename) {
    std::ifstream infile(filename);
    infile.imbue(puncts_as_spaces);
    std::string buf;
    uint count = 0;
    while (infile.good()) { //TODO troubles
        infile >> buf;
        if (buf.size()==word.size() && buf.find(word) != std::string::npos )
            count++;
    }
    entries.push_back(std::pair <std::string ,int>(filename, count));
    infile.close();
}


size_t lexical_word_entries::get_entries_count() {
    return entries.size();
}
size_t lexical_word_entries::get_word_entries (uint num) {
    return entries[num].second;
}
size_t lexical_word_entries::get_entries_mean() {
    if (! entries.size())
        return 0;
    size_t sum=0;
    for (int i=0; i<entries.size(); i++) {
        sum+=entries[i].second;
    }
    return sum / entries.size();
}
