//
//  Dictionary_copy.hpp
//  CSP2104.3_Ass2
//
//  Created by Mirhossein Jalali Moghadam on 22/7/2024.
//

#ifndef Dictionary_copy_hpp
#define Dictionary_copy_hpp

#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Word.hpp"
using namespace std;

class Dictionary_copy {
private:
    fstream myfile;
    string _Type;
    string _Definition;
    string _Word;
public:
    friend class ImprovedDictonary_2;
    vector<Word> v1;
    Word Dictionary1;
    string _empty_line;
    unsigned int _Vector_size;
    unsigned int dictionary_version = 0;
    string LoadDictionary(string dictionary_path);
    int CompareDictionary_B(string dictionary_path1, string dictionary_path2);
    void AmendDictionary(string dictionary_path,string _Type, string _Definition, string _Word);
    void DictionaryMenu();

};

class ImprovedDictonary_copy {
public:
    Dictionary_copy NewDictionary;
    void palindroms(string input_word);
    string rhyme(string rhyme_word,string rhyme);
    void guess(string guess_word,string guess_def, string score_file);
};


#endif /* Dictionary_copy_hpp */
