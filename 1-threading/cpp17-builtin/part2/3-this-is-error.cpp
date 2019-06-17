#include <bits/stdc++.h>

#include <thread> 

using namespace std;

class WorkThread{
public:
	void operator()(){
		cout<<"Working thread # "<<this_thread::get_id()<<"\n";

	}
};

int main()
{
	vector<thread> threadList;

	for(int i=0; i<3; i++){
		threadList.push_back( thread( WorkThread() ) );
	}

	for(int i=0; i<3; i++){
		cout<<threadList[i].get_id()<<" joining\n";
		threadList[i].detach();
		threadList[i].detach();

		threadList[i].join();
		threadList[i].join();
	}
	return 0;
}
