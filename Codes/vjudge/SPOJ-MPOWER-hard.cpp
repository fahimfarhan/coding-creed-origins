#include<bits/stdc++.h>
#include <ios>
#include <iostream>
using namespace std;

#define ll long long int

inline bool isOddNumber(const string& input) {
  int len = input.size() - 1;
  char ch = input[len];
  return (ch == '1');
}

inline string removeInitialZeroes(const string& input) {
  if(input.size() == 0) {
    return "0";
  }
  string output = "";
  int index = 0;
  int zeroCount = 0;
  for(int i=0; i<input.size(); i++) {
    if(input[i] == '0') {
      index = i;
      zeroCount++;
    }else{
      break;
    }
  }

  // cerr<<"input1 "<<input<<" zeroKount "<<zeroCount<<"\n";
  if(zeroCount > 0) {
    output = input.substr( (index+1) );
  }else{
    output = input;
  }
  if(output.size() == 0) {
      output = "0";
  }    
  return output;
}

inline string divideByTwo(const string& input) {
  string output = "";
  int n = 0;
  for(char ch: input) {
    n = n * 10 + (ch - '0');
    //cerr<<n<<"\n";
    int m = (n >> 1);
    output = output + (char)(m + '0');
    //cerr<<"output "<<output<<"\n";
    n = n & 1;
  }
  output = removeInitialZeroes(output);
  return output;
}

inline string divideByTen(const string& input) {
  if(input.size() <= 1) {
    return "0";
  }
  int len = input.size() - 1;
  string output = input.substr(0, len);

  return output;
}

inline string decimalToBinary(const string& input) {
  string output = "";

  string number = input;
  while (number != "0") {
    //cerr<<"number1 "<<number<<"\n";
    char last = number[number.size() - 1];
    int m = last - '0';
    m = m&1;
    //cerr<<"m = "<<m<<"\n";
    char x = (char)(m + '0');
    //cerr<<"x = "<<x<<"\n";
    
    output = x + output;
    number = divideByTwo(number);
    //cerr<<"number2 "<<number<<"\n";
    //cerr<<"output = "<<output<<"\n";
  }
  return output;
}

inline ll calcPower(const ll& base, const string& power, const ll& mod) {
  if( (power == "0") || (power == "") ) {
    return 1;
  }
  if(power == "1") {
    return base;
  }
  
  ll result = 1;
  string p = divideByTen(power);   // divideByTwo(power);
  result = calcPower(base, p, mod);
  result = (result * result) % mod;
  if(isOddNumber(power)){
    result = (result * base) % mod;
  }
  return result;
}

void start() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cin.tie(0);

  ll T, base, mod;
  string power;
  cin>>T;
  
  while(T--) {
    cin>>base>>power>>mod;
    power = decimalToBinary(power);
    cout<<calcPower(base, power, mod)<<"\n";
  }
}

void test() {

  cout<<isOddNumber("1")<<"\n";
  cout<<isOddNumber("2")<<"\n";
  cout<<isOddNumber("11")<<"\n";
  cout<<isOddNumber("12")<<"\n";
  // cout<<calcPower(10, "0", 1000000000)<<"\n";
  // cout<<calcPower(10, "1", 1000000000)<<"\n";
  // cout<<calcPower(10, "2", 1000000000)<<"\n";
  // cout<<calcPower(10, "3", 1000000000)<<"\n";
  // cout<<calcPower(10, "4", 1000000000)<<"\n";
  // cout<<calcPower(10, "5", 1000000000)<<"\n";
}

int main() {
  start();
  // test();
  return 0;
}