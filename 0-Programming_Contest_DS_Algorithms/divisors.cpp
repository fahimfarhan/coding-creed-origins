#include <bits/stdc++.h>

using namespace std;
/*
        Complexity, C = O(nlogn)
        Proof:
        2 loops, so C = sum i.j

*/
class Divisor{
private:
    int n; 
    vector<int> *divisor;
public:
    Divisor(){
        cin>>n;
        divisor = new vector<int>[n+1];

        for(int i=1; i<=n; i++){
            for(int j=i; j<=n; j+=i){
                divisor[j].push_back(i);
                //cout<<"divisor["<<j<<"].push_back("<<i<<"); \n";
            }
        }

        for(int i=1; i<=n; i++){
            cout<<"divisor["<<i<<"]--> ";
            for(int j=0; j<divisor[i].size(); j++){
                cout<<divisor[i][j]<<" ";
            }cout<<endl;
        }
    }
    ~Divisor(){if(!divisor)delete[] divisor;}
};

int main()
{
    Divisor d;
    return 0;
}