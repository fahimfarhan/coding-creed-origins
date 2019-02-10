#include <bits/stdc++.h>
using namespace std;

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

#define ll long long int

#define sll(x) scanf("%I64d",&x);
#define pll(x) printf("%-I64d\n",x);
/** ALL functions */
bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);
void takeInput();
void mydestructor();
int D(int i);
void KL_Algo(vector<int> const& input);
int getCutSize(vector<int> const& p1, vector<int> const& p2);

/** ALL variables */
int n,m;
vector< int > *g;
bool *isvisited;
//int *inedge, *outedge;
int totalPartition;
string s;
vector<string> vs;
queue< vector <int> > partitions;
// vector< pair< pair<int,int> , int >, pair<int, int> > logTable;

map< pair<int, int> , int > CE;

/** end var */

int klheuristic(int u, int v){  
  int ret;
  // ret = D(u) + D(v) - 2*CE[{u,v}];
  return ret;
}


void takeInput(){
  cin>>totalPartition;
  while(getline(cin, s)){
    if(s!="")
      vs.push_back(s);
  }
  n = vs.size();
  g = new vector<int>[n+1];
  isvisited = new bool[n+1];
  //inedge = new int[n+1];
  //outedge = new int[n+1];

  for(int i=0; i<=n; i++){  isvisited[i] = false; /*inedge[i] = 0; outedge[i] = 0;*/ }

  for(int i=0; i<vs.size(); i++){
      istringstream iss(vs[i]);

      int i1=0;
      string a = "";
      int u,v;
      while(iss >> a){
        i1++;
        if(i1==1){ u = stoi(a); }//cout<<a<<" : ";}
        if(i1>=3){ v = stoi(a); g[u].push_back(v); /*inedge[v]++; outedge[u]++;*/ CE[{u,v}] = 1;  }//cout<<a<<" "; }
        //cout<<a<<" ";

      } //cout<<"\n";
  }
}

void mydestructor(){
  if(!g)delete[] g;
  if(!isvisited)delete[] isvisited;
  //if(!inedge)delete[] inedge;
  //if(!outedge)delete[] outedge;
  cout<<"memory freed!\n";
}

int getCutSize(vector<int> const& p1, vector<int> const& p2){
  int cutsize = 0;
  for(int i=0; i<p1.size(); i++){
    for(int j=0; j<p2.size(); j++){
      
      cutsize += CE[{ p1[i] , p2[j] }];
    }
  }
  return cutsize;
}


void KL_Algo(vector<int> const& input){
  vector<int> finalA, finalB,A,B;
  for(int i=0; i<input.size()/2; i++){ int a = input[i];  finalA.push_back(a); A.push_back(a); }
  for(int i=input.size()/2; i<input.size(); i++){ int a = input[i];  finalB.push_back(a); B.push_back(a); }

  int D[n+1];
  bool isUnlocked[n+1];

  for(int i=0; i<=n; i++){  D[i] = 0; isUnlocked[i] = false;  }
  for(int i=0; i<input.size(); i++){  int a = input[i]; isUnlocked[a] = true; }

  // init D
  {
      // init D 
      for(int i=0; i<A.size(); i++){
        int a = A[i];
        for(int j=0; j<B.size(); j++){
          int b = B[j];
          D[a]+=CE[{a,b}];
        }
      }

        for(int i=0; i<B.size(); i++){
          int a = B[i];
          for(int j=0; j<A.size(); j++){
            int b = A[j];
            D[a]+=CE[{a,b}];
          }
        }

        for(int i=0; i<A.size(); i++){
          int a = A[i];
          for(int j=0; j<A.size(); j++){
            int b = A[j];
            D[a] -= CE[{a,b}];
          }
        }

          for(int i=0; i<B.size(); i++){
            int a = B[i];
            for(int j=0; j<B.size(); j++){
              int b = B[j];
              D[a] -= CE[{a,b}];
            }
        }
        //
      
  }
    /*
    cout<<"D values!!!\n";
    
    for(int i=0;i<input.size(); i++){
      int a = input[i];
      cout<<D[a]<<" ";
    }cout<<"\n";*/
  bool outerLoopBool = true;
  int outerLoopCount = 0;
  int prevCutSize = getCutSize(A,B);
  while(outerLoopBool){
    //if(outerLoopCount== 1){ break; }
    outerLoopCount++;
    cout<<"\n\n***********************************\n\n";
    cout<<"Outer Iteration "<<outerLoopCount<<"\n";
    cout<<"\n\n***********************************\n\n";

    for(int i=0; i<A.size(); i++){
      A[i] = finalA[i];
      B[i] = finalB[i];
    }

    int dmax, amax=0, bmax=0, a_index=0, b_index=0;
    dmax = INT_MIN;
    vector<int> gv, cs;
    int c123456 = getCutSize(A,B);
    
    cs.push_back(c123456);
    gv.push_back(0);
    vector<pair <int, int> > tentativeExchange, tentativeExchangeIndex;
    
    tentativeExchange.push_back({-1,-1});
    tentativeExchangeIndex.push_back({-1,-1});

    cout<<"Inner Iteration\n";
      
    for(int k=0; k<input.size()/2; k++){
      for(int i=0; i<A.size(); i++){
        int a = A[i];
        if(isUnlocked[a]){
          for(int j=0; j<B.size(); j++){
            int b = B[j];
            if(isUnlocked[b]){
              int temp = D[a] + D[b] - 2*CE[{a,b}];
              if( temp > dmax ){
                dmax = temp;
                amax = a;
                bmax = b;
                a_index = i;
                b_index = j;
              }
            }
          }
        }
      }


      // tentative exchange
  
      isUnlocked[amax] = false;
      isUnlocked[bmax] = false;
      // update D values!!!
      for(int i=0; i<A.size(); i++){
        int x = A[i];
        if(x!=amax){
          D[x] = D[x] + 2*( CE[{x,amax}] - CE[{x,bmax}] );
        }
      }

      for(int i=0; i<B.size(); i++){
        int y = B[i];
        if(y!=bmax){
          D[y] = D[y] + 2*( CE[{y,bmax}] - CE[{y,amax}] );
        }
      }
      
      //cout<<dmax<<" "<<amax<<" "<<bmax<<" \n";
      gv.push_back(dmax); tentativeExchange.push_back( {amax, bmax} );
      tentativeExchangeIndex.push_back({a_index,b_index});

      dmax = INT_MIN;

    }
    // print table!
    	cout<<"	Step	Pair	G	  Sum-G	  Cutsize\n";
      cout<<"0      - -  -  "<<cs[0]<<"\n";
      
      int prev_gs = 0, prev_cs = cs[0];
      int gmax123 = INT_MIN;
      int kmax = 0;
      int currCutSize = 0;
      for(int i=1; i<gv.size(); i++){
        prev_gs = prev_gs + gv[i];
        prev_cs = prev_cs - gv[i];
        if(prev_gs > gmax123){  currCutSize = prev_cs;  gmax123 = prev_gs; kmax = i; }
        cout<<i<<" ("<<tentativeExchange[i].first<<" , "<<tentativeExchange[i].second<<")  "<<gv[i]<<" "<<prev_gs<<" "<<prev_cs<<"\n";
      }cout<<"\n";
    //permanent exchange!

    outerLoopBool = false;
    if(currCutSize < prevCutSize){
      outerLoopBool = true;
      prevCutSize = currCutSize;
    
      cout<<" Parmanent Exachange: ";
      for(int i=1; i<=kmax; i++){
        int a = tentativeExchangeIndex[i].first; 
        int b = tentativeExchangeIndex[i].second;
        cout<<"( "<<finalA[a]<<" , "<<finalB[b]<<" ) ";
        int swappp = finalA[a];
        finalA[a]  = finalB[b];
        finalB[b]  = swappp;

      }cout<<"\n";
      cout<<"p1 : { ";
      for(int i=0; i<finalA.size(); i++){
        cout<<finalA[i]<<" ";
      }cout<<" }\n";

      cout<<"p2 : { ";
      for(int i=0; i<finalB.size(); i++){
        cout<<finalB[i]<<" ";
      }cout<<" }\n";

      cout<<"CutSize = "<<getCutSize(finalA, finalB);
      

    }else{
      cout<<"\nNo Improvement\n";
      cout<<"\n--------------------------------------------------\n";
      partitions.push(finalA);
      partitions.push(finalB);
      return;
    }
    
  }
}


void testDrivenDevelopment(){
    for(int i=01; i<=n; i++){
    cout<<i<<" --> ";
    for(int j=0; j<g[i].size(); j++){
      cout<<g[i][j]<<" ";
    }cout<<"\n";
  }

  


  vector<int> test ;
  for(int i=1; i<=8; i++){  test.push_back(i);  }
  KL_Algo(test);
  
}



int main(int argc=0, char const *argv[] = NULL)
{
	/* code */
  /* Soln soln */
  try{
    freopen("input_KL.txt","r",stdin);
    freopen("output_KL.txt","w",stdout);

  }catch(exception& x){
    cout<<"Exception!"<<x.what()<<"\n";
  }
  
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  takeInput();

  vector<int> s1;
  for(int i=1; i<=n; i++){
    s1.push_back(i);
  }
  
  partitions.push(s1);

  while(partitions.size()!=totalPartition){
    vector<int> s2 = partitions.front();
    partitions.pop();
    KL_Algo(s2);
    //klalgo(s2);
  }
  
  cout<<"\n**************************************************\n";
  cout<<"Final Partitions:\n";
  int i098 = 1;
while(!partitions.empty()){
  cout<<"p"<<i098<<" : { ";
  i098++;
    vector<int> s2 = partitions.front();
    partitions.pop();
  for(int i=0; i<s2.size(); i++){
    cout<<s2[i]<<" ";
  }
  cout<<" }\n";
}



  //  cout<<"\n***************  TEST ***********************************\n";
  //testDrivenDevelopment();
  

  //cout<<vs.size()<<"\n";
  mydestructor();
  return 0;
}


