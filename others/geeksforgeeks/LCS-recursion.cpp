#include <bits/stdc++.h>
using namespace std;

string lcs(string s1, string s2){
    if(s1 == "" || s2==""){ return "";  }
    string ret = "";
    if(s1[s1.size()-1]== s2[s2.size()-1]){
        ret = ret+lcs(s1.substr(0, s1.size()-1),s2.substr(0, s2.size()-1) )+s1[s1.size()-1];
    }else{
        string r1  = lcs(s1.substr(0, s1.size()-1), s2);
        string r2 = lcs(s1, s2.substr(0, s2.size()-1));
        if(r1.size()>r2.size()){    ret = r1;   }
        else{   ret = r2;   }
    }
    return ret;
}

int main(){
    string s1 = "acbaed";
    string s2 = "abcadf";

    string s3 = lcs(s1,s2);
    cout<<s3<<"\n";
    
    return 0;
}