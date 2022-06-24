// Declares a dictionary`s functionality

#ifndef DICTIONAGY_H
#define DICTIONAGY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultrami croscopicsilicovol canoconiosis)
#define LENGTH 45

//Prototypes
bool check(const char *word);
unsigned int hash(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
#endif // DICTIONARY_H
