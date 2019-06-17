
#include <bits/stdc++.h>
#include <thread> 

using namespace std;

void thread_func(){
	cout<<"Tnside thread id = "<<this_thread::get_id()<<"\n";
}

int main(){
	thread th1(thread_func);
	thread th2(thread_func);

	cout<<th1.get_id()<<"\n";
	cout<<th2.get_id()<<"\n";

	th1.join();
	th2.join();
	return 0;
}

