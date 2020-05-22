#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)
#define  V Vector 
typedef long long int ll;
// #define ll long long int
// other popular ones=> int64_t, uint64_t => use for 10^18
ll MODULO = 1e9+7;

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;s
vector<int> *g;
bool *isvisited;

class Vector{
	public:
		double a,b,c,d,e; int id;
		Vector(){ a=0; b=0; c=0; d=0; e=0; id=0; } 

		V dot(V v){
			V ret;
			ret.a = (this->a)*(v.a);
			ret.b = (this->b)*(v.b);
			ret.c = (this->c)*(v.c);
			ret.d = (this->d)*(v.d);
			ret.e = (this->e)*(v.e);


		}

};

int main(int argc, char const *argv[])
{
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

    return 0;
}
