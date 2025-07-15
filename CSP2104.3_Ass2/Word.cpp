//
//  Word.cpp
//  Word Class
//
//  Created by Mirhossein Jalali Moghadam on 14/4/2024.
//
#include "Word.hpp"
#include<iostream>
using namespace std;

    //getter function, accessing the elements of the Dictionary file
void Word::getter(string t,string d, string w)
    {
        Type =t.erase(0,6);
        Definition =d.erase(0,12);
        Word = w.erase(0,6); 
    }
    // display function to access nd prtint the Dictionaey elements
string Word::printDefinition(string user_word)
    {
    string return_def="";
        if (user_word +"\r" == Word)
        {
            // cout <<"\nresult for : " << Word <<"\n" << endl;
            //cout << "Type: " << Type <<"\n" << endl;
            return_def = Definition;
           // cout << "Definition: " << return_def<<"\n" << endl;
        }
    return return_def;
}

string Word::inputWord(string mode){
    string result;
    cout << "Enter the "<< mode << ":";
    // The user input will be stored in the str variable.
    getline(cin,input_word);
        //converting string input to lower case as the the fefinition should be returned regardsless to the case
        transform(input_word.begin(), input_word.end(), input_word.begin(), ::tolower);
    return  input_word;
}


