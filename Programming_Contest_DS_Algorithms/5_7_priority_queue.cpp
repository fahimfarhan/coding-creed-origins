/**
 * 
 *  priority queue / heap sort
 * 
*/
#include <iostream>
//#include <bits/stdc++.h>
#include <priority_queue>

using namespace std;



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int> pq;

    pq.push(0);
    pq.push(10);
    pq.pop();
    pq.top();
    return 0;
}