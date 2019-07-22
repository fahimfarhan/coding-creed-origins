#include <bits/stdc++.h>
using namespace std;


pair<int, int> nCr(int n_ul, int n_ll, int d_ul, int d_ll){
    int numerator=1, denominator=1;
    int n_ul_next, n_ll_next, d_ul_next, d_ll_next, n_mid , d_mid;
    // base case
    if(n_ul < n_ll){    return {1,1};   }
    if(n_ul == n_ll){
        numerator = n_ul; 
        n_mid = n_ul+n_ll;
        n_mid= n_mid>>1;
        //n_ul_next = n_ll_next+1;
    }
    
    if(d_ul < d_ll){    return {1,1};   }
    if(d_ul == d_ll){
        denominator = d_ul; 
        d_mid = d_ul+d_ll;
        d_mid= d_mid>>1;
        //n_ul_next = n_ll_next+1;
    }

    if( (numerator==n_ul) && (denominator == d_ul) ){
        int g = __gcd(numerator, denominator);
        numerator/=g;
        denominator/=g;
        pair<int, int> ret = {numerator, denominator};
        return ret;    
    }

    pair<int, int> p1 = nCr(n_ul, n_mid, d_ul, d_mid );
    pair<int, int> p2 = nCr( (n_mid+1), n_ll,  (d_mid+1), d_ll );

    numerator = p1.first*p2.first;
    denominator = p1.second*p2.second;

    int g = __gcd(numerator, denominator);
    numerator/=g;
    denominator/=g;

    pair<int, int> ret = {numerator, denominator};

    return ret;
}

int main(){

    pair<int,int> p = nCr(1000,(1000-500+1), 500,1);

    int ans = p.first/p.second;
    cout<<ans<<"\n";
    return 0;
}