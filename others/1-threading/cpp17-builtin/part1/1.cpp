// creating thread using function pointer

#include <bits/stdc++.h>
#include <thread>

using namespace std;

void f(){
	for(int i=0; i<100; i++)
	{
		cout<<i<<" From thread f: "<<"\n";
	}
}


int main(){
	thread th(f);
	
	for(int i=0; i<100; i++){
		cout<<i<<" From main\n"; 
	}

	th.join();

	cout<<"exiting main function\n";
	return 0;
}
