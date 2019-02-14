#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int
#define SRC -1 
#define STAR -7
#define HASH -3
#define DES -4

bool myAssert(bool b);
void testDrivenDevelopment();
int start();
void takeInput();
void myDestructor();
bool isValidIndex(int i,int j);
void graphPrinter();
void graphReset();

int n,m,T;
int **g;
vector<pair<int,int> > s;
vector<pair<int,int> > t;
bool **isvisited;
ofstream fout;    
  
bool isValidIndex(int i,int j){
    if((i>=0 && i<n) && (j>=0 && j<n))    return true;
    else return false;
}

bool isValidIndex(pair<int,int> src ){
    if((src.first>=0 && src.first<n) && (src.second >=0 && src.second < n))    return true;
    else return false;
}

void takeInput(){
    cin>>n;
    cin>>m;

    //cout<<"ok1\n";

    g = new int*[n+1];
    isvisited = new bool*[n+1];
    for(int i=0; i<=n; i++)
    {    g[i] = new int[n+1]; isvisited[i] = new bool[n+1];    }
    for(int i=0; i<n; i++)
    { for(int j=0; j<n; j++){isvisited[i][j] = false; g[i][j] = 0;} }
//cout<<"ok2\n";

    int u,v; char ch;
    for(int i=0; i<m; i++){
        cin>>u>>ch>>v;
        g[u][v] = HASH;
    }
//cout<<"ok3\n";

    cin>>T;
    int sx,sy,tx,ty;
    char c1,c2;
    for(int i=0; i<T; i++){
        cin>>sx>>c1>>sy>>tx>>c2>>ty;
        s.push_back({sx,sy});
        t.push_back({tx,ty});
        g[sx][sy]=SRC;
        g[tx][ty]=DES;
    }
  //  cout<<"ok4\n";
}

void myDestructor(){
    for(int i=0; i<=n; i++){    delete[] g[i]; delete[] isvisited[i]; }
    cout<<"memory freed!\n";
}

void graphPrinter(){
    int curr=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;  j++){
            curr = g[i][j];
            if(curr == HASH)      {  cout<<"# "; }
            else if(curr == STAR) {  cout<<"* "; }
            else if(curr == SRC)  {  cout<<"S "; }
            else if(curr == DES)  {  cout<<"T "; }
            else if(curr <  0){  cout<<"! ";   }
            else          {     cout<<curr<<" "; }
        }cout<<"\n";
    }
}

void graphReset(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n;  j++){
            //cout<<g[i][j]<<" ";
            if(g[i][j]>0){   g[i][j] = 0;  }
        }//cout<<"\n";
    }
    for(int i=0; i<T; i++){
        g[s[i].first][s[i].second] = SRC;
        g[t[i].first][t[i].second] = DES;
    }
}

void testDrivenDevelopment(){
    cout<<n<<"\n"<<m<<"\n";
    
    cout<<T<<"\n";
    for(int i=0; i<T; i++){
        cout<<s[i].first<<","<<s[i].second<<"  "<<t[i].first<<","<<t[i].second<<"\n";
    }
    graphPrinter();
    
    cout<<isValidIndex(2,3)<<"\n";
    cout<<isValidIndex(0,3)<<"\n";
    cout<<isValidIndex(-1,3)<<"\n";
    cout<<isValidIndex(2,9)<<"\n";
    cout<<isValidIndex(2,10)<<"\n";
    
   cout<<isValidIndex({1,2})<<"\n";
   cout<<isValidIndex({-1,2})<<"\n";
   cout<<isValidIndex({1,20})<<"\n";
   
}



class Lee{
private:
    queue<pair<int,int> > q;
    void setNumber(pair<int, int> p,int num){
        if(g[p.first][p.second]==0)
            g[p.first][p.second] = num;
    }

    bool canGo(pair<int,int> p){    
        if(g[p.first][p.second]==0) return true;
        else return false;
    }
    
    void myPush(pair<int, int> p){
        if(g[p.first][p.second]==0){
            q.push(p);
            cout<<"Inserted "<<p.first<<" "<<p.second<<"\n";
            //cout<<"pushed "<<temp.first<<" "<<temp.second<<"\n";
        }
    }
public:
    Lee(){}
    void bfs(pair<int,int> src, pair<int,int> des){
        q.push(src);
        g[src.first][src.second] = 0;
        int a1[4] = {1,-1,0,0};
        int a2[4] = {0,0,1,-1};
        int currNum = 0;
        pair<int, int > temp; 
        bool flag1=true;
        bool flag2 = true; // if false, that means we cannot reach destination :'( 
        while(true){
            if(!flag1){     break; }
            // break conditions 
            if(q.empty()){ flag1=false; flag2 = false; break; }
            pair<int, int > f = q.front();
            currNum = g[f.first][f.second];
            q.pop();
            //if(f == des){    break;  }

            for(int i=0; i<4; i++){
                temp.first = f.first+a1[i]; temp.second = f.second+a2[i];
                if(temp == des){  
                    //cout<<temp.first<<" "<<temp.second<<"-->temp\n";
                    //cout<<des.first<<" "<<des.second<<"-->des\n";
                    flag1=false;
                      break;
                }
                if(isValidIndex(temp) && canGo(temp)){
                    q.push(temp);
                    setNumber(temp, (currNum+1) ); //myPush(temp);
                    //cout<<"Set number"<<currNum+1<<"\n";
                }

            }
        }

        if(flag2){
            pair<int, int> w;
            w = des;
            int ccount789 = currNum;
            while(currNum>0){
                ccount789--;
                if(ccount789<0){ break; }
                bool flag123 = true;
                for(int i=0; i<4; i++){
                    if(!flag123){   break;  }
                    int x1, y1;
                    x1 = w.first + a1[i];
                    y1 = w.second + a2[i];
                    if(g[x1][y1] == currNum){
                        g[x1][y1] = STAR;
                        w.first = x1;
                        w.second = y1;
                        currNum--;
                        flag123 = false;
                        
                    }
                }
            }
        }else{
            cout<<"Net ("<<src.first<<","<<src.second<<")->("<<des.first<<","<<des.second<<") cannot be routed.\n";
        }



    }
};



int main(int argc, char const *argv[])
{
	/* code */
  /* Soln soln */
  freopen("routing_input.txt","r",stdin);
  freopen("lee_output.txt","w",stdout);
  fout.open("soukup_output.txt");

  
  /*
  cout << setprecision(8);
  cout << num1 << endl;
  */
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

    takeInput();
    // testDrivenDevelopment();
    
    //lee.start(s[0], t[0]);
    //graphReset();
    //graphPrinter();
     cout<<"Lee's Algorithm\n\n";
    for(int i=0; i<T; i++){
        Lee lee; 
        lee.bfs(s[i], t[i]);
        graphReset();
        
        //cout<<"\n------------------------\n";
    }
    cout<<"\n";
    graphPrinter();
    cout<<"\n \n";
    
    myDestructor();
  return 0;
}

