//
//  Dictionary.cpp
//  Dictionary Class
//
//  Created by Mirhossein(Jay) ZIABARI on 26/4/2024.
//  safety critical file

#include "Dictionary.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <numeric>
#include <thread>
using namespace std;

// print main menu
void Dictionary::DictionaryMenu()
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
cout << "| C ) CRC 8 comparison                            |\n";
cout << "| Q ) Quit                                        |\n";
cout << "---------------------------------------------------\n";
}

// loading Dictionary from STL vector & the user file
string Dictionary::LoadDictionary(string dictionary_path)
{
    string result = dictionary_path +" file ok \n \n";
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
    else result ="failed to open the main dictionary_file, will create a new dictionary file\n \n";
    return result;
}

int Dictionary::CompareDictionary_A(string dictionary_path1, string dictionary_path2)
{
    
    //---------- compare number of lines in both files ------------------//
        int c1=0,c2=0;
        string str;
         int j=0;
    
    ifstream dictionary_file1,dictionary_file2;
    dictionary_file1.open(dictionary_path1,ios::binary);
    dictionary_file2.open(dictionary_path2,ios::binary);
    if (!dictionary_file1.is_open() || !dictionary_file2.is_open())
        
    {cout << "input error !";
        j = 1;
        return j;
}
        while(!dictionary_file1.eof())
        {
            getline(dictionary_file1,str);
            c1++;
        }
        dictionary_file1.clear();   //  set new value for error control state  //
        dictionary_file1.seekg(0,ios::beg);
        while(!dictionary_file2.eof())
        {
            getline(dictionary_file2,str);
            c2++;
        }
        dictionary_file2.clear();
        dictionary_file2.seekg(0,ios::beg);
         if(c1 != c2)
        {
            cout << "Different number of lines in files!" << "\n";
            cout << "dictionary1 has " << c1 << " lines and dictionary has "
                         << c2 << " lines" << "\n";
            cout << "Program Halt, exit\n";
            exit(0);
        }
    //---------- compare two files line by line ------------------//
    string string1,string2;
        while(!dictionary_file1.eof())
        {
            getline(dictionary_file1, string1);
            getline(dictionary_file2, string2);
            if(string1.compare(string2) >0  or string1.compare(string2) <0 )
                j++;
        }
            cout << j << " differences between file 1 & file 2" << "\n";
 
    dictionary_file1.close();
    dictionary_file2.close();
    
 return j;
}

// -------------calculate CRC8 for the Dic 1 and Dic 2 files -----//
int Dictionary::CRCDictionary(string dictionary_path1)
{
    // array to store binary number
    ifstream file;
    file.open(dictionary_path1, ios::in);
    int n=0;
    char ch;
    int final_CRC8 =0;
    // Get the current time from the system clock
    auto now = chrono::system_clock::now();

    // Convert the current time to time since epoch
    auto duration = now.time_since_epoch();

    if (file.is_open()) {
        // Read data from the file object and put it into a string.
        while (file.get(ch)) {
            n = int(ch);
            final_CRC8 = final_CRC8 +  CRC8(n);
        }}
    // Convert duration to milliseconds
    auto milliseconds
        = chrono::duration_cast<chrono::milliseconds>(
              duration)
              .count();

    // Print the result
    cout << "Current time in milliseconds is: "
         << milliseconds << endl;
    return final_CRC8;
}
void Dictionary::AmendDictionary(string dictionary_path, string _Type, string _Definition, string _Word)
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

void ImprovedDictonary::palindroms(string input_word) {

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
    
string ImprovedDictonary::rhyme(string rhyme_word, string user_word)
    {
    string rhyme= rhyme_word ;
    rhyme_word.erase(rhyme_word.size() - 1);
    if (user_word.size() >= 3 && rhyme_word.size() >= 3  ) {
        user_word =user_word.substr(user_word.size()-3,3);
        rhyme_word = rhyme_word.substr(rhyme_word.size()-3, 3);
    }
    if(rhyme_word != user_word){
        rhyme = "";}
    return rhyme;
    }
void ImprovedDictonary::guess(string guess_word, string guess_def, string score_file){
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


int Dictionary::CRC8(int n)
{
    // array to store binary number
    int binaryNum[16];
    // initialzing array to ZERO
    memset(binaryNum, 0, 16 * sizeof(binaryNum[0]));
    
    // padding 8 bits for CRC checksum
    n = n << 8;
    // counter for binary array
    int i = 0;
    int sum = 0;
    int dec_CRC8 =0;
    while (n > 0) {
        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;}
    {
        // printing binary array in reverse order
        for (int j = i; j >= 0;j--) {
            
            for ( int k= 15 ; k >=8 ; k--)
            { sum = sum +binaryNum[k];
            }
            if (sum != 0) {
                if (binaryNum[j] == 1 )
                {
                    binaryNum[j]   = binaryNum[j]   ^ 1;
                    binaryNum[j-1] = binaryNum[j-1] ^ 0;
                    binaryNum[j-2] = binaryNum[j-2] ^ 0;
                    binaryNum[j-3] = binaryNum[j-3] ^ 0;
                    binaryNum[j-4] = binaryNum[j-4] ^ 0;
                    binaryNum[j-5] = binaryNum[j-5] ^ 0;
                    binaryNum[j-6] = binaryNum[j-6] ^ 1;
                    binaryNum[j-7] = binaryNum[j-7] ^ 1;
                    binaryNum[j-8] = binaryNum[j-8] ^ 1;
                } sum =0;}
        }}
//    write the CRC checksum to the console , optional code
    for ( int k= 7 ; k >=0 ; k--) {
//        cout << binaryNum[k];
        dec_CRC8 = dec_CRC8 + binaryNum[k] * pow(2,k);}
//        cout << "  " << "dec_CRC = " << dec_CRC8;
 //       cout << "\n";
    return dec_CRC8;

}

