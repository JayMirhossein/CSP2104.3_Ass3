// C++ Dictionary Main Program
//
// AUthor : Mirhossein (Jay) ZIABARI, U65,Off-Campus
// student number : 10483250
//
// CSP2104.3 - Assignment 1 and 2 is create an application that loads an
// English dictionary and then performs certain tasks using that dictionary.
// Dictionary program is created using Object Oriented Programming methid &
// supports the follwoing classes
//
// 1) Dictionary. Use the Dictionary class to encapsulate the data and
//    functionality related to the dictionary.
// 2) ImprovedDictonary, that extends the Dictionary class, and contains
//    new functions, allowing the following
//    tasks to be selected from the program main menu (the menu function
//    should be overridden in the new class so
//    as to allow the new and old functions to be selected):
//
//
// Dictionary Progra supports the following tasks
// Palindrome words :  List all words in the dictionary that are palindromes
//. e.g .”civic”
// Rhyme words Rhyming words – prompt the user to enter a word and print
// all words from the dictionary that end in the same sequence of three
// letters as the entered word.                                |
// Adding words    user can ass new word to the dictionary                              |
// Dictionary Mode user enters the word and get the type and definition
// Game Mode Guess the fourth word – Your program should choose a random
// word from the dictionary, one that has more than 4 words in its definition
// Print Main Menu                             |

#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>
#include "Word.hpp"
#include "Dictionary.hpp"
#include "Dictionary_copy.hpp"
#include "dec2hex.h"
#include <thread>
#include <chrono>
#include <atomic>
#include <future>
using namespace std;

int main()
{
    string scorefile = "/Users/mirhossein/Documents/C++/CSP2104_Ass1/game_score.txt";
    string filename = "/Users/mirhossein/Documents/C++/CSP2104_Ass1/dictionary_2024S1.txt";
    string filename_copy = "/Users/mirhossein/Documents/C++/CSP2104.3_Ass2/dictionary_2024S1 copy.txt";
    string str="";
    string _Type;
    string _Definition;
    string _Word;
    string Version_date_time;
    string Dictioary_Version;
    string file_status;
    string word_a;
    string word_b;
    string rhyme;
    int result;
    // Define the interval in seconds

    // Vector of class objects, STL vector of the World Class
    Dictionary NewDictionary;
    Dictionary_copy NewDictionary2;
    // New instantiation of Improved Dictionary Class
    ImprovedDictonary NewImprovedDictionary ;
    ImprovedDictonary_copy NewImprovedDictionary2 ;
    Word NewWord;
    
    //cout << file_exist(filename);
   // cout << file_exist(filename_copy);
    cout << "\033[" << 30 << "m" << "\n" ;
    // load channel 1 dictionary file , if no file exists create new dictionary file
    file_status = NewDictionary.LoadDictionary(filename);
    cout << file_status;
    // load channel 2 dictionary file , if no file exists create new dictionary file
    file_status = NewDictionary2.LoadDictionary(filename_copy);
    cout << file_status;
    
    cout << "/checking the dictionary files....";
    int  dictionary_compare_res = NewDictionary.CompareDictionary_A(filename, filename_copy);
    
    // clasculating CRC8 value for Dictionary 1
    cout << "/Calculating CRC8 for Dic1 and Dic 2... " << "\n \n";
    result = NewDictionary.CRCDictionary(filename);
    cout << "\033[" << 31 << "m" << "\n" ;
    cout << "/File 1 Dictionary CRC8 (Hex) " << decToHex(result) << "\n \n" ;
    result = NewDictionary.CRCDictionary(filename_copy);
    cout << "/File 1 Dictionary CRC8 (Hex) " << decToHex(result) << "\n \n" ;
    cout << "\033[" << 34 << "m" << "\n" ;
    
    // print main menu
    NewDictionary.DictionaryMenu();
    
    // printing the latest verison of Dictionary
    // the version of dictionary adds up everytime a new word is added successfully
    fstream History;
    History.open ("/Users/mirhossein/Documents/C++/CSP2104_Ass1/dictionary_history.txt",ios::in);
    getline (History,Dictioary_Version);
    getline (History,Version_date_time);
    cout << "Dictionary version: " << Dictioary_Version<< endl;
    cout << "date & time: " << Version_date_time << endl;
    cout << "---------------------------------------------------\n";
    History.close();
    
    while (true) {
        while (str != "q") {
            str = NewWord.inputWord("Mode");
            
            // letter m prints the main menu
            if (str == "m")
            {NewDictionary.DictionaryMenu();}
            
            // letter 'r' sets the Rym mode
            if (str == "r")
            { cout << "Rhyme Mode\n";
                str = NewWord.inputWord("Word");
                for (auto& a : NewDictionary.v1) {
                    if( NewImprovedDictionary.rhyme(a.Word,str) == NewImprovedDictionary2.rhyme(a.Word, str))
                     cout << NewImprovedDictionary.rhyme(a.Word,str);
                    else
                        cout << "word missmatch" <<endl;
                }
              }
            
            // letter "p" sets the palindrom mode
            if (str == "p")
            { cout << "palindrom Mode\n";
                for (auto& a : NewDictionary.v1) {
                    NewImprovedDictionary.palindroms(a.Word);}}
            
            // letter g sets the guess mode
            if (str == "g")
            { cout << "Guess Game Mode\n";
                {
                    // Providing a seed value
                    srand((unsigned) time(NULL));
                    int random = (rand() % NewDictionary._Vector_size);
                    NewImprovedDictionary.guess(NewDictionary.v1.at(random).Word, NewDictionary.v1.at(random).Definition,scorefile);
                }}
            // letter a sets the adding new word mode
            if (str == "a")
            {
                cout << "/checking the dictionary files....";
                dictionary_compare_res = NewDictionary.CompareDictionary_A(filename, filename_copy);
                if (dictionary_compare_res > 0)
                { cout << "dictionary comare fails\n";
                    cout << "program exits \n";
                    break;}
                    
                cout << "Adding Word Mode\n";
                cout << "if adding the new word's succeeds, the dictionary version will add up\n";
                do { cout << "Word type can be:  (N)ouns, (a)djectives, (v)erbs, (a)dverbs, (p)repositions, (p)ronouns, (d)eterminers, (c)onjunctions, (i)nterjections\n";
                    _Type = NewWord.inputWord("New Word Type");
                } while ((_Type!= "n") && (_Type!= "a") && (_Type!= "v") && (_Type!= "p") && (_Type!= "d") && (_Type!= "c") && _Type!= "i");
                _Definition = NewWord.inputWord("New Word Definition");
                _Word = NewWord.inputWord("New Word ");
                result = 0;
                
                
                for (auto& a : NewDictionary.v1)
                {
                    if (_Word +"\r" == a.Word) result =1; }
                if (result == 0) {
                    NewDictionary.AmendDictionary(filename,_Type,_Definition,_Word);
                    NewDictionary.AmendDictionary(filename_copy,_Type,_Definition,_Word);
                    
                    // updating and writing dictionary history
                    // current date/time based on current system time and date
                    time_t now = time(0);
                    // convert now to string form the source
                    char* dt = ctime(&now);
                    // print the dictionary verison
                    NewDictionary.dictionary_version = stoi("0"+Dictioary_Version);
                    NewDictionary.dictionary_version = NewDictionary.dictionary_version+1;
                    Dictioary_Version = to_string(NewDictionary.dictionary_version);
                    History.open ("/Users/mirhossein/Documents/C++/CSP2104_Ass1/dictionary_history.txt",ios::out);
                    History << Dictioary_Version <<endl;
                    History << dt << endl;
                    History.close();
                }
                else
                    cout << "Error !, the word already exists\n";
                result =0;
            }
            // letter w sets the normal dictionary mode
            if (str == "w"){
                cout << "Dictionary Mode\n";
                str = NewWord.inputWord("Word");
                for (auto& a : NewDictionary.v1)
                {
                    word_a = a.printDefinition(str);
                    if(word_a != "") break;
                }
                for (auto& a : NewDictionary2.v1)
                {
                     word_b = a.printDefinition(str);
                    if(word_b != "") break;
                }
                if (word_b == word_a) cout << word_a;
                else cout << "word missmatch" << endl;
            }
            
            if (str == "c"){
                // clasculating CRC8 value for Dictionary 1
                cout << " calculating CRC code\n ";
                result = NewDictionary.CRCDictionary(filename);
                cout << "File 1 Dictionary CRC8 =  " << result  << "\n" ;
                result = NewDictionary.CRCDictionary(filename_copy);
                cout << "File 2 Dictionary CRC8 =  " << result  << "\n" ;
            }
        }
        break;  // Exit the loop
    }
        return 0;}
