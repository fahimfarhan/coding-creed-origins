#include<bits/stdc++.h>
    
using namespace std ;
    
void swa ( int x ){
    cout<<"Debug x = "<<x<<endl;
    if ( x == 1 ){
    
        cout << "Finish\n\n" ;
    }
    
    else{
    //x--;
        swa ( x-- ) ;
    
        cout << "X\t=\t" << x << endl << endl ;
    }
}
    
int main(){
    
    int a = 3 ;
    
    swa ( 3 ) ;
}