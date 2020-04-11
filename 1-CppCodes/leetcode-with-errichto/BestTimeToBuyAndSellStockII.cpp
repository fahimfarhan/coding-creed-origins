#include <bits/stdc++.h>
using namespace std;

int maxProfitByErrichto(vector<int>& prices) {
    int bestWithStock = INT_MIN;
    int bestWithOutStock = 0;

    for(int p : prices){
        bestWithStock = max(bestWithStock, bestWithOutStock - p);
        bestWithOutStock = max(bestWithOutStock, bestWithStock + p);
        cout<<bestWithOutStock<<" "<<bestWithOutStock<<"\n";
    }
    return bestWithOutStock;
}

int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        for(int i=0; i<n-1; i++){
            if(prices[i+1]>prices[i])
                ans+=prices[i+1]-prices[i];
        }
        return ans;
    }

int main(){
    vector<int> v = {7,6,4,3,1};
    cout<<"\n\n"<<maxProfit(v)<<"\n";
    return 0;
}