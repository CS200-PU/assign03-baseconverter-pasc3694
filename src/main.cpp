//******************************************************************************
// File name:   main.cpp
// Author:      Lucas Paschia
// Date:        09/22/2024 (Replace xx/xx/xxxx with month/day/year)
// Class:       CS200 - 01 (Replace xx with your section number)
// Assignment:  base converter
// Purpose:     converts the numbers to each base
// Hours:       2
//******************************************************************************

#include <iostream>
#include <math.h>

using namespace std;

int hexCharToInt (char hexDigit);
char intToHexChar (int num);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle); 
string binaryToDecimal (const string& strNumber); 
string decimalToBinary (const string& strNumber); 
string decimalToHex (const string& strNumber); 
string hexToDecimal (const string& strNumber); 
string hexToBinary (const string& strNumber); 
string binaryToHex (const string& strNumber); 

const char DECIMAL = 'D';
const char BINARY = 'B';
const char HEX = 'H';

/**************************************************************************
 Function: 	 	main

 Description: Runs the functions to output the correct conversions for the user
              input numbers.

 Parameters:	none

 Returned:	 	int - returns success
 *************************************************************************/
int main () {
  const string TITLE = "HEX-DEXIMAL-BINARY CONVERTER";
  const string PROMPT = "Enter your string to convert (q to quit): ";
  const string DEC_CONV = "The decimal conversion is: ";
  const string BIN_CONV = "The binary conversion is: ";
  const string HEX_CONV = "The hexadecimal conversion is: ";
  const char QUIT = 'q';
  string cNum;
  string answer;
  char type;

  printTitle (TITLE);
  do {
    cout << PROMPT;
    cin >> cNum;
    if (QUIT != cNum [0]) {
      type = getBase (cNum);
      if (DECIMAL == type) {
        cout << BIN_CONV << decimalToBinary (cNum) << endl
             << HEX_CONV << decimalToHex (cNum) << endl
             << endl;
      }
      else if (HEX == type) {
        cout << DEC_CONV << hexToDecimal (cNum) << endl
             << BIN_CONV << hexToBinary (cNum) << endl 
             << endl;
      }
      else if (BINARY == type) {
        cout << DEC_CONV << binaryToDecimal (cNum) << endl
             << HEX_CONV << binaryToHex (cNum) << endl
             << endl;
      }
    }
  } while (QUIT != cNum[0]);
  
  return EXIT_SUCCESS;
}

/**************************************************************************
 Function: 	 	hexCharToInt

 Description: changes the hex char into an int

 Parameters:	hexDigit - the char being converted to an int

 Returned:	 	int - the int that relates to value of char
 *************************************************************************/
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

/**************************************************************************
 Function: 	 	intToHexChar

 Description: changes an int to the corresponding char

 Parameters:	num - int being changed into a char

 Returned:	 	char - the char that is converted from int passed in
 *************************************************************************/
char intToHexChar (int num) {
  char hex;
  if (9 < num &&  16 > num) {
    hex = static_cast<char> (num + 55);
  }
  else {
    hex = static_cast<char> (num + 48);
  }
  return hex;
}

/**************************************************************************
 Function: 	  getBase

 Description: gets the string and returns what type it is 

 Parameters:	strNumber - the string that is being checked

 Returned:	 	char - the char corrseponding to what base the string is
 *************************************************************************/
char getBase (const string &strNumber) {
  char base = DECIMAL;

  if ('0' == strNumber[0] && 'x' == strNumber[1]) {
    base = HEX;
  }
  else if ('0' == strNumber[0] && 'b' == strNumber[1]) {
    base = BINARY;
  }
  return base;
}

/**************************************************************************
 Function: 	 	getNumber

 Description: reads in the number from the user input

 Parameters:	prompt - the prompt outputted before the string read in

 Returned:	 	string - the string that was read
 *************************************************************************/
string getNumber (const string &prompt) {
  string number;
  cout << prompt;
  cin >> number;
  return number;
}

/**************************************************************************
 Function: 	 	printTitle

 Description: outputs the title to the terminal

 Parameters:	myTitle - the title that is outputted

 Returned:	 	void
 *************************************************************************/
void printTitle (const string &myTitle) {
  const string STAR_LINE = "**************************************";
  const string STARS = "*****";
  cout << STAR_LINE << endl
       << STARS << myTitle << STARS << endl
       << STAR_LINE << endl;
}

/**************************************************************************
 Function: 	 	binaryToDecimal

 Description: converts the binary string to decimal string

 Parameters:	strNumber - the binary string being converted

 Returned:	 	string - returns the decimal string converted from binary
 *************************************************************************/
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

/**************************************************************************
 Function: 	 	decimalToBinary

 Description: converts the decimal string to a binary string

 Parameters:	strNumber - the decimal string that is being converetd

 Returned:	 	string - returns the binary string
 *************************************************************************/
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

  if (3 == binaryNum.length()) {
    binaryNum += '0';
  }

  return binaryNum;
}

/**************************************************************************
 Function: 	 	decimalToHex

 Description: decimal string is converted to a hex string

 Parameters:	strNumber - the decimal string being converted

 Returned:	 	string - returns the hex converetd string
 *************************************************************************/
string decimalToHex (const string& strNumber) {
  string hexNum = "0x";
  string hex = "";
  int decimal = stoi (strNumber);

  while (decimal != 0) {
    hex += intToHexChar(decimal % 16);
    decimal /= 16;
  }

  for (int index = hex.length(); -1 < index; index--) {
    hexNum += hex[index];
  }

  if (3 == hexNum.length()) {
    hexNum += '0';
  }

  return hexNum;
}

/**************************************************************************
 Function: 	 	hexToDecimal

 Description: converts hex string to a decimal string

 Parameters:	strNumber - the hex string that is being converted

 Returned:	 	string - returns the decimal string
 *************************************************************************/
string hexToDecimal (const string& strNumber) {
  double digits = strNumber.length() - 2;
  double decimalNum = 0;
  for (double index = 0; index < strNumber.length() - 2; index++) {
     decimalNum += (hexCharToInt (strNumber[index+2]) *
                   (pow (16, digits - index - 1)));
  } 

  return to_string (static_cast<int> (decimalNum));
}

/**************************************************************************
 Function: 	 	hexToBinary

 Description: converts the hex string to a binary string

 Parameters:	strNumber - the hex string being converted to binary

 Returned:	 	string - returns the converted binary string
 *************************************************************************/
string hexToBinary (const string& strNumber) {
  string decimal, binary;
  decimal = hexToDecimal (strNumber);
  binary = decimalToBinary (decimal);
  return binary;
}

/**************************************************************************
 Function: 	 	binaryToHex

 Description: converts bianry string to a hex string

 Parameters:	strNumber - the bianry string being converted to hex

 Returned:	 	string - returns the hex string that was converted from binary
 *************************************************************************/
string binaryToHex (const string& strNumber) {
  string decimal, hex; 
  decimal = binaryToDecimal (strNumber);
  hex = decimalToHex (decimal); 
  return hex; 
}