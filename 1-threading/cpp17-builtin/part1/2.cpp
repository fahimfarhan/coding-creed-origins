// thread using function object 

#include <bits/stdc++.h>

#include <thread>

using namespace std;

class DisplayThread{
	public:
	void operator()(){
		for(int i=0; i<10; i++){
			cout<<"Display thread "<<i<<"\n";	
		}
	}
};

int main()
{
	thread th( (DisplayThread()) );

	for(int i=0; i<10; i++){
		cout<<"main thread\n";
	}
	
	th.join();
	cout<<"exiting from main\n";
	return 0;
}





