#include <bits/stdc++.h>
#include <thread>
#include <mutex>

using namespace std;

class Wallet{
	int mMoney;
	mutex m;
public:
	Wallet() :mMoney(0){} 
	int getMoney(){	return mMoney; }

	void addMoney(int money){
		//m.lock();
		lock_guard<mutex> lockGuard(m);
		for(int i=0; i<money; i++){
			mMoney++;
		}

		//m.unlock();
	}
};

int testMultithreadedWallet(){
	Wallet wallet;
	vector<thread> v;

	for(int i=0; i<5; i++){
		v.push_back( thread(&Wallet::addMoney, &wallet, 1000 ) );
	}

	for(int i=0; i<v.size(); i++){
		v[i].join();
	}

	return wallet.getMoney();
}

int main()
{

		int val = 0;
	for(int k = 0; k < 1000; k++)
	{
		if((val = testMultithreadedWallet()) != 5000)
		{
			std::cout << "Error at count = "<<k<<"  Money in Wallet = "<<val << std::endl;
			//break;
		}
	}
	return 0;
}

