#include <bits/stdc++.h>

using namespace std;

class RS490{
private:
    string str[100];
public:
    RS490(){
        /*for(int i=0; i<100; i++){
            for(int j=0; j<100; j++)
                //A[i][j]=' '; // by default space
        }*/


    }
    ~RS490() {}
};

int main()
{
    string s="";
    int count = 0;
    while (getline(cin, s))
    {
        count++;
    }
    cout<<s<<endl;
    cout<<count<<endl;
    return 0;
}
/*
int main()
    string s;
    int count = 0;
    while(getline(cin, s))
    {
        // do something with s
        count++;
    }
    return 0;
}
*/