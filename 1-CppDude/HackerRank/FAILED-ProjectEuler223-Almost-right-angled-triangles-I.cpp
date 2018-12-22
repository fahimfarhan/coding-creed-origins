#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);

class T{
public:
    ll a,b,c;
    T(){a=0;b=0;c=0;}
    T(ll a, ll b, ll c){ this->a = a; this->b=b; this->c=c;    }
};

ll 
A[3][3] = {{1,-2,2},{2,-1,2},{2,-2,3}},
B[3][3] = {{1,2,2},{2,1,2},{2,2,3} },
C[3][3] = {{-1,2,2},{-2,1,2},{-2,2,3}};

priority_queue<ll> pq;
vector<ll> v;
queue<T> t;

ll sum(ll a, ll b, ll c){ ll d = a+b+c; return d; }
void Tree_of_primitive_Pythagorean_triples(){
    t.push(T(1,1,1));
    t.push(T(1,2,2));

    while(!t.empty()){
        T temp(t.front().a, t.front().b, t.front().c);
        t.pop();
        ll S = sum(temp.a, temp.b, temp.c);
        if(S<=50000000){
            pq.push(S);
            // triple 1
            T r1,r2,r3;
            r1.a = A[0][0]*temp.a + A[0][1]*temp.b + A[0][2]*temp.c;
            r1.b = A[01][0]*temp.a + A[01][1]*temp.b + A[01][2]*temp.c;
            r1.c = A[02][0]*temp.a + A[02][1]*temp.b + A[02][2]*temp.c;

            t.push(r1);

            // triple 2
            r2.a = B[0][0]*temp.a + B[0][1]*temp.b + B[0][2]*temp.c;
            r2.b = B[01][0]*temp.a + B[01][1]*temp.b + B[01][2]*temp.c;
            r2.c = B[02][0]*temp.a + B[02][1]*temp.b + B[02][2]*temp.c;
            t.push(r2);
            
            // triple 3
            r3.a = C[0][0]*temp.a + C[0][1]*temp.b + C[0][2]*temp.c;
            r3.b = C[01][0]*temp.a + C[01][1]*temp.b + C[01][2]*temp.c;
            r3.c = C[02][0]*temp.a + C[02][1]*temp.b + C[02][2]*temp.c;

            t.push(r3);
        }
    }

    while(!pq.empty()){
        v.push_back(pq.top());
        pq.pop();
    }
}

int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  // freopen("input.txt","r",stdin);
  // freopen("output.txt","w",stdout);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

	int Q; ll N;
    cin>>Q;
    while(Q--){
        cin>>N;
        int lb = lower_bound(v.begin(), v.end(), N) - v.begin();
        cout<<v[lb]<<"\n";
    }
	return 0;
}
