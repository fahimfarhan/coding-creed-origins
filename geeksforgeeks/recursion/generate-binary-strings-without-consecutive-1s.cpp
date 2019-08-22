#include <bits/stdc++.h>

using namespace std; 

vector<string> v;

void g(string input, int k){
    // base case 
    if(input.size() == k){  v.push_back(input);  return; }
    string next = input;
    
    if(input.size() == 0){
        string next1 = "1"+input;
        g(next1, k);
        string next2 = "0"+input;
        g(next2, k);
    }else{
        if(input[0]=='0'){
            string next1 = "1"+input;
            g(next1, k);
            string next2 = "0"+input;
            g(next2, k);
        }else{
            string next2 = "0"+input;
            g(next2, k);
        }
    }
}

int main()
{
    
    int k;
    string in = "";

    cin>>k;

    g(in,k);
    for(auto x:v){  cout<<x<<"\n";  }
    
    return 0;
}