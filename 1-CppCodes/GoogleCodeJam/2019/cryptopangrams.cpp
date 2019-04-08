#include <bits/stdc++.h>
using namespace std;


int *primes;
int primes_size;

class Seive{
public:
	bool *A;
	vector<int> v;
	Seive(int n){
		A = new bool[n+1];
		for(int i=0; i<=n; i++){ A[i] = true;}
		A[0] = false; A[1] = false;
		int stop = (int)sqrt(n);
		
        for(int i=4; i<=n; i+=2){ A[i] = false; }
		
        for(int i=3; i<=stop; i++){
			if(A[i]==true){
				for(int j = 3*i; j<=n;j+=2*i){
					A[j]=false;
				}
			}
		}

		for(int i=0; i<=n; i++)
		{ 
			if(A[i]){v.push_back(i);}	
		}
		
	
		// code jam!
        int len = v.size();
        primes_size = len-1;
        primes = new int[len+1];
		for(int i=1; i<v.size(); i++){
			//cout<<v[i]<<", ";
            primes[i-1] = v[i];
		}



	}
	~Seive(){
		if(!A){
			delete[] A;
		}
	}
};



// int combo[26][26];
map<int , char > mp;
map<int, pair<int,int> > combo;
// int n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
    Seive *s = new Seive(10000);
    /* code */
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    /*
    cout << setprecision(8);
    cout << num1 << endl;
    */
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // preprocess
    /*for(int i=0; i<26; i++){
        mp[primes[i]] = 'A'+i;
    }*/

    int temp=0;
    for(int i=0; i<primes_size; i++){
        for(int j=0; j<primes_size; j++){
            temp = primes[i]*primes[j];
            //if(mp.count(temp) == 0)
             combo[temp] = { primes[i] , primes[j] }; 
        }
    }

    int a,first, second, T, N, L;
    cin>>T;

    for(int t=1; t<=T; t++){
        set<int> sortedOrder;
        vector<int> originalOrder;
        

        cin>>N>>L;
        cin>>a;
        
        first = combo[a].first;
        second = combo[a].second;

        cin>>a;

        if( (a%second) != 0 ){
            first = first^second;
            second = first^second;
            first = first^second;
        }
        originalOrder.push_back(first);originalOrder.push_back(second);
        
        sortedOrder.insert(first); sortedOrder.insert(second);

        for(int i=2; i<L; i++){
            first = second;
            cin>>a;
            second = a/first;
            originalOrder.push_back(second);
            sortedOrder.insert(second);
        }

        set<int>::iterator it;
        int pos = 0;
        for(it = sortedOrder.begin(); it!=sortedOrder.end(); it++){
            mp[(*it)] = 'A'+pos; pos++;
        }
        cout<<"Case #"<<t<<": ";
        for(int i=0; i<originalOrder.size(); i++){
            cout<<mp[ originalOrder[i] ];
        }cout<<"\n";
    }


    return 0;
}



