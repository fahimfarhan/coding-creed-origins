#include <bits/stdc++.h>
#include <thread> 

using namespace std;

void threadcallback(int x, string s){
	cout<<"passed num = "<<x<<"\n";
	cout<<"passed str = "<<s<<"\n";
}


int main(){
	int n=5;
	string str = "Hello there!";
	thread th( threadcallback , n, str);
	th.join();
	return 0;
}
