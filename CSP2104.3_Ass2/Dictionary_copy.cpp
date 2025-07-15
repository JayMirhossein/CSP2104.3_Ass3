//
//  Dictionary_copy.cpp
//  CSP2104.3_Ass2
//
//  Created by Mirhossein Jalali Moghadam on 22/7/2024.
//

#include "Dictionary_copy.hpp"
#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

// print main menu
void Dictionary_copy::DictionaryMenu()
{
cout << "---------------------------------------------------\n";
cout << "|           Dictionary Program                    |\n";
cout << "|CSP2104.3, Assignment 2 , Mirhossein(Jay) ZIABARI|\n";
cout << "|            DICTIONARY MODES                     |\n";
cout << "| P ) Palindrome words                            |\n";
cout << "| R ) Rhyme words                                 |\n";
cout << "| G ) Guess words                                 |\n";
cout << "| A ) Adding words                                |\n";
cout << "| W ) Dictionary Mode                             |\n";
cout << "| G ) Game Mode                                   |\n";
cout << "| M ) Print Main Menu                             |\n";
cout << "| Q ) Quit                                        |\n";
cout << "---------------------------------------------------\n";
}

// loading Dictionary from STL vector & the user file
string  Dictionary_copy::LoadDictionary(string dictionary_path)
{
    
    string result = dictionary_path + " file ok \n \n";
    myfile.open(dictionary_path.c_str(),ios::in);
    if(myfile) {
    // loading dictionary to the STL vector
        while (!myfile.eof())
        {
            // reading the content of dictionary
            getline(myfile,_Type);
            getline(myfile,_Definition);
            getline(myfile,_Word);
            Dictionary1.getter(_Type,_Definition,_Word);
            // inserting objects to vector
            v1.push_back(Dictionary1);
            // read & pass the empty line in Dictionary
            getline(myfile,_empty_line);
        }
        myfile.close();
        _Vector_size = v1.size();
        
    }
    else result ="failed to open the main dictionary_file, will create a new dictionary file\n \n ";
    return result;
}

void Dictionary_copy::AmendDictionary(string dictionary_path, string _Type, string _Definition, string _Word)
{
    {
        myfile.open(dictionary_path,ios::app);
        myfile << "Type: "+_Type+"\r" <<endl;
        myfile << "Definition: "+_Definition+"\r" << endl;
        myfile << "Word: "+_Word+"\r" << endl;
        myfile << _empty_line << endl;
        myfile.close();
        LoadDictionary(dictionary_path);
        cout << "New word added successfully \n";}}

int Dictionary_copy::CompareDictionary_B(string  dictionary_path1, string dictionary_path2)
{
    char c1=0, c2=0;
    int result = 0;
    fstream file1,file2;
    file1.open(dictionary_path1,ios::in);
    file2.open(dictionary_path2,ios::in);
    
    while(((c1!=EOF)||(c2!=EOF))){
        c1=file1.get();
        c2=file2.get();
        if(c1!=c2){
            result++;
            break;
        }
        
    }
        return result;
    }


void ImprovedDictonary_copy::palindroms(string input_word) {

       input_word.erase(input_word.size() - 1);
        const int length = input_word.length();
        int count = 0;
        
        // declaring character array (+1 for null terminator)
        char* char_array = new char[length + 1];
        
        // copying the contents of the
        // string to char array
        strcpy(char_array, input_word.c_str());
        
        for (int i = 0; i < (length/2) ; i++) {
            
            if (char_array[i] == char_array[length-i-1] )
            {count ++;}
            if (count == (length/2)) { cout << input_word << "\n";}
        }
        delete[] char_array;
}
    
string ImprovedDictonary_copy::rhyme(string rhyme_word, string user_word)
    {

        string rhyme= rhyme_word ;
        rhyme_word.erase(rhyme_word.size() - 1);
        if (user_word.size() >= 3 && rhyme_word.size() >= 3  ) {
            user_word =user_word.substr(user_word.size()-3,3);
            rhyme_word = rhyme_word.substr(rhyme_word.size()-3, 3);
        }
        if(rhyme_word != user_word){
            rhyme ="";}
    return rhyme;
    }
void ImprovedDictonary_copy::guess(string guess_word, string guess_def, string score_file){
    int pos =0;
    int j=0;
    int user_score=0;
    int guess_turn =0;
    string word_no4;
    string input_word,score;
    // create the file to save the store of player
    fstream MyFile;
    MyFile.open (score_file, ios::in);
    getline(MyFile,score);
    cout << "Welcome to the guessing game :" <<endl;
    cout << "your score is :" << score << endl;
    cout << "============================" <<endl;
    user_score = stoi(score);
    MyFile.close();
    for (int i=0; i<guess_def.length()-1;i++)
    {
        if(isspace(guess_def[i]))
        { pos++;
            if(pos >=3 )
            {       j=i;
                do {
                    word_no4 = word_no4+ guess_def[j+1];
                    j++;
                } while (!isspace(guess_def[j]));
                if (word_no4.length() > 4 )
                {word_no4.erase(word_no4.size()-1);
                    break;}
                else word_no4 = "";
            }}
    }
    if (pos >=3 ){
        guess_def.replace(j- word_no4.length(),word_no4.length()," [....]");
        cout <<guess_def <<endl;}
    else
    {  cout << "No 4th word exists\n";}
    if (word_no4 !="") {
        do {
            cout << "Enter the missing word in [....]:";
            // The user input will be stored in the str variable.
            getline(cin,input_word);
            if (word_no4 == input_word)
            {user_score ++;
                cout << "your score =" << user_score << endl;
                MyFile.open (score_file,ios::out);
                MyFile << user_score;
                MyFile.close();
                break;}
            else
            {cout<< "err ! an incorrect guess\n";
                guess_turn++;}
        } while(word_no4 != input_word && guess_turn <5);
        cout << "the answer was = " <<word_no4 << endl;
        cout << " the Word was  =" << guess_word << endl;
    }}

