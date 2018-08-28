/***
 * STL Set:
 * math er set er moto same jinish ekadhik bar dhukaleo 1tai count hoy! :o
 * ***/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    set<int> s;

    s.insert(3);
    s.insert(4);
    s.insert(3);
    s.insert(2);

    for(int i=0; i<s.size();i++){
        cout<<(*(s.find(i)))<<" ";
    }
    return 0;
}