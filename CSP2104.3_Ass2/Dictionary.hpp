//
//  Dictionary.hpp
//  Dictionary Class
//
//  Created by Mirhossein(Jay) ZAIABARI on 26/4/2024.
// student number : 10483250

#ifndef Dictionary_hpp
#define Dictionary_hpp

#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Word.hpp"
using namespace std;

class Dictionary {
private:
    fstream myfile;
    string _Type;
    string _Definition;
    string _Word;
    int CRC8(int n);
public:
    friend class ImprovedDictonary;
    vector<Word> v1;
    Word Dictionary1;
    string _empty_line;
    unsigned int _Vector_size;
    unsigned int dictionary_version = 0;
    string LoadDictionary(string dictionary_path);
    int  CompareDictionary_A(string dictionary_path1,string dictionary_path2);
    int  CRCDictionary(string dictionary_path1);
    void AmendDictionary(string dictionary_path,string _Type, string _Definition, string _Word);
    void DictionaryMenu();

};

class ImprovedDictonary {
public:
    Dictionary NewDictionary;
    void palindroms(string input_word);
    string rhyme(string rhyme_word,string rhyme);
    void guess(string guess_word,string guess_def, string score_file);
};


#endif /* Dictionary_hpp */
