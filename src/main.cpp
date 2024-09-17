//******************************************************************************
// File name:   main.cpp
// Author:      CS Faculty
// Date:        xx/xx/xxxx (Replace xx/xx/xxxx with month/day/year)
// Class:       CS150-xx (Replace xx with your section number)
// Assignment:  Hello World
// Purpose:     Display the message Hello World to the screen
// Hours:       0.25
//******************************************************************************

#include <iostream>

using namespace std;

int hexCharToInt (char hexDigit);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle); 
string binaryToDecimal (const string& strNumber); 
string decimalToBinary (const string& strNumber); 
string decimalToHex (const string& strNumber); 
string hexToDecimal (const string& strNumber); 
string hexToBinary (const string& strNumber); 
string binaryToHex (const string& strNumber); 

int main () {
  string num = "0b10";
  char first = 'F';
  int value;

  value = hexCharToInt (first);

  first = getBase (num);

  cout << first << ": " << value << endl; 
  
  return EXIT_SUCCESS;
}

int hexCharToInt (char hexDigit) {
  int value = static_cast<int> (hexDigit);
  if (64 < value && 71 > value) {
    value -= 55;
  }
  else if (47 < value && 58 > value) {
    value -= 48;
  }
  return value;
}

char getBase (const string &strNumber) {
  char base = 'D';
  if ('0' == strNumber[0] && 'x' == strNumber[1]) {
    base = 'H';
  }
  else if ('0' == strNumber[0] && 'b' == strNumber[1]) {
    base = 'B';
  }
  return base;
}

string getNumber (const string &prompt) {
  
}