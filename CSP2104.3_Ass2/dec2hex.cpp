#include <iostream>
#include <string>
#include <algorithm> // Required for std::reverse

using namespace std;

// Function to convert a decimal number to hexadecimal
string decToHex(int decimalNum) {
    if (decimalNum == 0) {
        return "0"; // Handle the special case of 0
    }

    string hexString = "";
    while (decimalNum > 0) {
        int remainder = decimalNum % 16;
        char hexChar;

        if (remainder < 10) {
            hexChar = remainder + '0'; // Convert 0-9 to character '0'-'9'
        } else {
            hexChar = remainder - 10 + 'A'; // Convert 10-15 to 'A'-'F'
        }
        hexString += hexChar;
        decimalNum /= 16;
    }

    reverse(hexString.begin(), hexString.end()); // Reverse the string as remainders are collected in reverse order
    return hexString;
}
