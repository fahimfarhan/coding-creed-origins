#include <bits/stdc++.h>

using namespace std;
class Seive{
public:
	bool *A;
	vector<int> v;
	Seive(int n){
		A = new bool[n+1];
		for(int i=0; i<=n; i++){ A[i] = true;}
		A[0] = false; A[1] = false;
		//v.push_back(2);
		int stop = (int)sqrt(n);
		// cout<<"Stop = "<<stop<<endl;
		//int curr;
		// eliminate even numbers except 2
		for(int i=4; i<=n; i+=2){ A[i] = false; }
		// eliminate remaining numbers	
		for(int i=3; i<=stop; i++){
			if(A[i]==true){
				//curr = i;
				//v.push_back(i);
				// cout<<"pushed back = "<<i<<endl;
				//int temp = 2*curr;
				for(int j = 3*i; j<=n;j+=2*i){
					A[j]=false;
					// cout<<"j="<<j<<endl;
				}
			}
		}

		for(int i=0; i<=n; i++)
		{ 
			//  cout<<i<<" "<<A[i]<<"\n";
			if(A[i]){v.push_back(i);}	
		}
		
		/* vector<int>::iterator it;
		for(it = v.begin(); it!=v.end(); it++)
		{
			cout<<*it<<" ";
		}
		cout<<endl;
        */

		// t prime
/*		cout<<"The t primes are:\n";
		//vector<int>::iterator it;
		for(it = v.begin(); it!=v.end(); it++)
		{
			int t = (*it)*(*it);
			if(t>n){ break; }
			cout<<t<<" ";
		}
		cout<<endl;
*/

	}
	~Seive(){
		if(!A){
			delete[] A;
		}
	}
};

int main()
{
    clock_t begin = clock();
    int64_t n = 600851475143;
    int m = (int)sqrt(n);

    // cout<<n<<" "<<sqrt_n<<"\n";
    Seive *s = new Seive(m);
    //vector<int>::iterator it;
    //for(it = s->v.end(); it!=s->v.begin(); it--)
    cout<<"\n--------------------------\n";
	for(int i=s->v.size()-1; i>=0; i--)
    	{
			// cout<<*it<<" ";
            // cout<<"????\n";
            int d = s->v[i];
            if(n%d == 0){
                cout<<"ANS = "<<d<<"\n";
                break;
            }
		}
    if(!s)delete s;
    clock_t end = clock(); double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time taken is: %f\n", time_spent);
    return 0;
}