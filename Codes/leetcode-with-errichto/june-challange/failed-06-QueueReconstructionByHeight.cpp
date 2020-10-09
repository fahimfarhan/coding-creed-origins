/* Author : Qazi Fahim Farhan (@fahimfarhan) */
/* May the CodeForces be with you! */

#include <iostream>
#include <climits>  // this includes INT_MIN, INT_MAX, ... ...
// #include <sstream>
// #include <cstdio>
// #include <cmath>
// #include <cstring>
// #include <cctype>
// #include <string>
#include <vector>
// #include <list>
// #include <set>
// #include <map>
// #include <queue>
// #include <stack>
#include <algorithm>
// #include <functional>
#include <iomanip>      // std::setprecision


using namespace std;

#define PI 2*acos(0)

//typedef long long int ll;
 #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MOD = 1e9+7;

// int n,m;
vector<int> *g;
bool *isvisited;


class Solution {
public:
    bool static sortOrder(const vector<int>& v1,const vector<int>& v2) {
        if(v1[1] == v2[1]) {
            return v1[0] > v2[0];
        }
        return v1[1] < v2[1];
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), sortOrder);
        return people;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    std::cout << std::fixed;
    std::cout << std::setprecision(10);
    cout << num1 << endl;
    ---------- Interactive problems ---------

    on each interactive questions' end, add `cout.flush()`
    say, cout<<"some weirdo question";
    cout<<"\n"; // end of question
    cout.flush(); // <-- just like this

    if still confusing, check out 1363D.cpp
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int> > v = {  {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}  };
    // [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
    Solution s;
    vector<vector<int> > u = s.reconstructQueue(v);
    for(int i=0; i<u.size(); i++) {
        cout<<"["<<u[i][0]<<" , "<<u[i][1]<<"] ";
    }
    return 0;
}

