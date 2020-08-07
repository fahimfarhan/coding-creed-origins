#include <bits/stdc++.h>
#include <functional> 
#include <mutex>
#include <condition_variable> 

using namespace std;

class Application{
	mutex m;
	condition_variable m_condVar;

	bool m_bDataLoaded;

public:
	Application(){
		m_bDataLoaded = false; 
	}

	void loadData(){
		this_thread::sleep_for(chrono::milliseconds(1000));
		cout<<"Leading data from XML\n";

		lock_guard<mutex> guard(m);

		m_bDataLoaded = true;

		m_condVar.notify_one();

	}

	bool isDataLoaded(){	return m_bDataLoaded;	}
	
	void mainTask(){
		cout<<"Do some handshake\n";
		unique_lock<mutex> mlock(m);
		
		m_condVar.wait(mlock, bind(&Application::isDataLoaded, this) ); 
		
		cout<<"Do processing on loaded Data\n";
	}

};

int main(){
	
	Application app;
	thread th1(&Application::mainTask, &app);
	thread th2(&Application::loadData, &app);
	
	th2.join();
	th1.join();
	return 0;
}
