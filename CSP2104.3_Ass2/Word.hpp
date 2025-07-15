//
//  Word.hpp
//  Word Class
//
//  Created by Mirhossein (Jay) ZIABARI on 14/4/2024.
//  student number : 10483250
//

#ifndef Word_hpp
#define Word_hpp
#include<string>
using namespace std;

class Word {
public:
    string Type;
    string Definition;
    string Word;
    string input_word;
public:
    friend class Dictionary;
    //print introduction Menue
    void main_menu();
    //getter function, accessing the elements of the Dictionary file
    void getter(string t,string d, string w);
    // display function to access nd prtint the Dictionaey elements
    string printDefinition(string user_word);
    string inputWord(string mode);
};

#endif /* Word_hpp */
