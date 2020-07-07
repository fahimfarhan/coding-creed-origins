#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


int n,m;
vector<int> *g;
bool *isvisited;

int *BIT, *a;

#define LSB(i) i&(-i)

void update(int i, int val){  // // Adds val to element with index i
    while(i<=n){ // WATCH OUT! EKHANE VUL HOITE PARE!
        BIT[i] += val;
        i += LSB(i);  //  #define LSB(i) i&(-i)
    }
}

int getSum(int i){
    int sum = 0;
    while(i>0){
        sum = sum+BIT[i];
        i -= LSB(i); //  #define LSB(i) i&(-i)
    }
    return sum;
}

int rangeSum(int l,int r) {     return  getSum(r) - getSum(l-1);     }

void constructBIT(){
    for(int i=0; i<=n; i++){    BIT[i] = 0;     }
    for(int i=1; i<=n; i++){    update(i, a[i]);   }
}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);
  /*
  cout << setprecision(8);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    cin>>n;
    /*  1 based indexing !!!*/
    BIT = new int[n+1];
    a = new int[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    constructBIT();
    //cout<<getSum(1)<<"\n";
    cout<<getSum(6)<<"\n";
    update(3,6);
    /* replace version:
        update(3,7-a[3]);

        Formaly, update(i, dx);
        update(i, x-a[i]);
     */
cout<<getSum(6)<<"\n";
cout<<getSum(3)<<"\n";
cout<<rangeSum(4,6)<<"\n";
    delete[] BIT;
    delete[] a;
  return 0;
}

