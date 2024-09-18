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
#include <math.h>

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
  string num = "153";
  string answer;
  char first = 'F';
  int value;

  value = hexCharToInt (first);

  first = getBase (num);

  answer = decimalToBinary (num);

  cout << first << ": " << answer << endl; 
  
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
  string number;
  cout << prompt;
  cin >> number;
  return number;
}

void printTitle (const string &myTitle) {
  const string STAR_LINE = "**************************************";
  const string STARS = "*****";
  cout << STAR_LINE << endl
       << STARS << myTitle << STARS << endl
       << STAR_LINE << endl;
}

string binaryToDecimal (const string& strNumber) {
  double digits = strNumber.length() - 2;
  double decimalNum = 0;
  for (double index = 0; index < strNumber.length() - 2; index++) {
    if (strNumber[index + 2] == '1') {
     decimalNum += (pow (2, digits - index - 1));
    }
  } 

  return to_string (static_cast<int> (decimalNum));
}

string decimalToBinary (const string& strNumber) {
  string binaryNum = "0b";
  string binary = "";
  int decimal = stoi (strNumber);

  while (decimal != 0) {
    if (decimal % 2 == 1) {
      binary.append ("1");
    }
    else{ 
      binary.append ("0");
    }
    decimal /= 2;
  }

  for (int index = binary.length(); -1 < index; index--) {
    binaryNum += binary[index];
  }

  return binaryNum;
}

string decimalToHex (const string& strNumber) {
  
}