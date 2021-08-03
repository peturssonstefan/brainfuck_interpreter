// Solution to https://www.codewars.com/kata/5ef9ca8b76be6d001d5e1c3e

#include <string>
#include <algorithm>    // std::sort
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>
#include <bitset>
using namespace std;

string char_to_str(char ch)
{
    bitset<8> temp(ch);
    return temp.to_string();
}

// convert a group of 8 digits to a character
char str_to_char(string group)
{
    bitset<8> temp(group);
    return temp.to_ulong();
}


std::string encode(std::string text)
{
    string s = ""; 
    for (const auto &c : text){
      string byte = char_to_str(c); 
      for (const auto &b : byte){
        s += std::string(3, b);
      }
    } 
    return s; 
}

std::string decode(std::string bits)
{
    int count = 0; 
    string current = ""; 
    string text = ""; 
    for(int i = 0; i < bits.length(); i += 3){
      int a = bits[i] - '0'; 
      int b = bits[i+1] - '0';
      int c = bits[i+2] - '0';  

      if(count % 8 == 0 && current != ""){
        text += str_to_char(current); 
        current = ""; 
      }
      current += (a + b + c) > 1 ? "1" : "0"; 
      count++; 
    }
    
    text += str_to_char(current); 
    return text;
}
