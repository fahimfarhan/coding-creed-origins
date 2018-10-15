#include <bits/stdc++.h>

using namespace std;

int n, freq[100];

int huffman(){

    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i=0; i<n; i++){
        cin>>freq[i];
        pq.push(freq[i]);
    }

    while(pq.size()!=1){
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        pq.push(a+b);
    }
}

int main()
{

    return 0;
}