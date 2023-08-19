#include "../lib/ConsoleColor.h"
#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::string;
using std::getline;

bool isSymbol(char c) {
  string symbols = "!?,.\"\':;[]+=-_#{}@$<>?/\\|`~%^()*&";
  return symbols.find(c) != string::npos;
}

void run_startup(const bool customized) {
  if(customized == true) {
    c_draw_text_box(7, 'x', '*', '=', "   Random Password Generator   ");
  }
  else {
    cout << "   Random Password Generator   \n";
  }
  cout << "\n\n\n";
}


bool is_valid_number(const string num) {

  

  const size_t digits_in_number = num.size();

  if(digits_in_number == 0 || num.empty()) {
    return false;
  }

  bool more_than_zero = false;

  for(size_t i = 0; i < digits_in_number; i++) {
    if(!isdigit(num[i])) {
      return false;
      break;
    }
    if(num[i] != '0') {
      more_than_zero = true;
    }
  }

  return more_than_zero;
}


bool is_valid_boolean(const string boolean) {

  const size_t size_of_boolean = boolean.size();

  if(size_of_boolean == 0 || boolean.empty()) {
    return false;
  }

  if(size_of_boolean == 1) {
    if(boolean[0] == 'y' || boolean[0] == 'Y' || boolean[0] == 'n' || boolean[0] == 'N') {
      return true;
    }
    return false;
  }

  return false;
}

int main (int argc, char *argv[]) {
  srand(time(NULL));

  run_startup(true);

  bool include_lowercase_b, include_uppercase_b, include_space_b, include_digits_b, include_symbols_b;
  
  string length = "_", include_lowercase = "_", include_uppercase = "_", include_space = "_", include_digits = "_", include_symbols = "_";



  get_length:

  do {
    cout << "Enter length of password [positive]: ";
    getline(cin, length);
  } while(!is_valid_number(length));


  if(!is_valid_number(length)) {
    length = "_";
    goto get_length;
  }
  


  do {
    cout << "Include lowercase letters[y/n]: ";
    getline(cin, include_lowercase);
  } while(!is_valid_boolean(include_lowercase));
  
  do {
    cout << "Include uppercase letters[y/n]: ";
    getline(cin, include_uppercase);
  } while(!is_valid_boolean(include_uppercase));

  do {
    cout << "Include digits[y/n]: ";
    getline(cin, include_digits);
  } while(!is_valid_boolean(include_digits));

  do {
    cout << "Include space[y/n]: ";
    getline(cin, include_space);
  } while(!is_valid_boolean(include_space));

  do {
    cout << "Include symbols[y/n]: ";
    getline(cin, include_symbols);
  } while(!is_valid_boolean(include_symbols));

  string passwd = "";

  if(include_lowercase[0] == 'y' || include_lowercase[0] == 'Y') {
    include_lowercase_b = true;
  }
  else {
    include_lowercase_b = false;
  }

  if(include_uppercase[0] == 'y' || include_uppercase[0] == 'Y') {
    include_uppercase_b = true;
  }
  else {
    include_uppercase_b = false;
  }

  if(include_digits[0] == 'y' || include_digits[0] == 'Y') {
    include_digits_b = true;
  }
  else {
    include_digits_b = false;
  }

  if(include_space[0] == 'y' || include_space[0] == 'Y') {
    include_space_b = true;
  }
  else {
    include_space_b = false;
  }

  if(include_digits[0] == 'y' || include_digits[0] == 'Y') {
    include_digits_b = true;
  }
  else {
    include_digits_b = false;
  }

  if(include_symbols[0] == 'y' || include_symbols[0] == 'Y') {
    include_symbols_b = true;
  } 
  else {
    include_symbols_b = false;
  }




  for(int i = 0; i < stoi(length); i++) {
    char current;

    select:

    do {
      current = (char)rand();
    } while(!isprint(current));

    if(isdigit(current) && !include_digits_b) {
      goto select;
    }
    else if(current == ' ' && !include_space_b) {
      goto select;
    }
    else if (isSymbol(current) && !include_symbols_b) {
      goto select;
    }
    else if(isalpha(current) && tolower(current) == current && !include_lowercase_b) {
      goto select;
    }
    else if(isalpha(current) && toupper(current) == current && !include_uppercase_b) {
      goto select;
    }


    

    passwd += current;

  } 

  cout << '\n' << passwd << '\n';

  return 0;
}
