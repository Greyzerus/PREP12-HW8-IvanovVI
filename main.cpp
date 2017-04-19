#include "lexical_word_entries.hpp"


/* Написать программу принимающую
 * заданносе слово и имена документов
 * как аргументы командной строки.
 *
 * Посчитать среднее количество вхождений
 * этого слова в документы.
 * Слова разделяются символами такими, что
 * isspace() || ispunct() == true */


int main(int argc, char* argv[]) {
    if (argc <= 2) {
        std::cout << "Enter word for searching and filenames as argues." << std::endl;
        return -1;
    }
    lexical_word_entries entries (argv[1]);
    for (int i=2; i<argc; i++) {
        try {
            entries.process(argv[i]);
        } catch (std::runtime_error &ex) {
            std::cerr << "Error with file " << argv[i]
                      << " : " << ex.what() << std::endl;
            continue;
        }
    }
    std::cout << "Entries mean in " << entries.get_entries_count()
              << " files is: " << entries.get_entries_mean() << std::endl;
    return 0;
}