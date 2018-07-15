/*                                           When Panda is Life !
 
                              _,add8ba,
                            ,d888888888b,
                           d8888888888888b                        _,ad8ba,_
                          d888888888888888)                     ,d888888888b,
                          I8888888888888888 _________          ,8888888888888b
                __________`Y88888888888888P"""""""""""baaa,__ ,888888888888888,
            ,adP"""""""""""9888888888P""^                 ^""Y8888888888888888I
         ,a8"^           ,d888P"888P^                           ^"Y8888888888P'
       ,a8^            ,d8888'                                     ^Y8888888P'
      a88'           ,d8888P'                                        I88P"^
    ,d88'           d88888P'                                          "b,
   ,d88'           d888888'                                            `b,
  ,d88'           d888888I                                              `b,
  d88I           ,8888888'            ___                                `b,
 ,888'           d8888888          ,d88888b,              ____            `b,
 d888           ,8888888I         d88888888b,           ,d8888b,           `b
,8888           I8888888I        d8888888888I          ,88888888b           8,
I8888           88888888b       d88888888888'          8888888888b          8I
d8886           888888888       Y888888888P'           Y8888888888,        ,8b
88888b          I88888888b      `Y8888888^             `Y888888888I        d88,
Y88888b         `888888888b,      `""""^                `Y8888888P'       d888I
`888888b         88888888888b,                           `Y8888P^        d88888
 Y888888b       ,8888888888888ba,_          _______        `""^        ,d888888
 I8888888b,    ,888888888888888888ba,_     d88888888b               ,ad8888888I
 `888888888b,  I8888888888888888888888b,    ^"Y888P"^      ____.,ad88888888888I
  88888888888b,`888888888888888888888888b,     ""      ad888888888888888888888'
  8888888888888698888888888888888888888888b_,ad88ba,_,d88888888888888888888888
  88888888888888888888888888888888888888888b,`"""^ d8888888888888888888888888I
  8888888888888888888888888888888888888888888baaad888888888888888888888888888'
  Y8888888888888888888888888888888888888888888888888888888888888888888888888P
  I888888888888888888888888888888888888888888888P^  ^Y8888888888888888888888'
  `Y88888888888888888P88888888888888888888888888'     ^88888888888888888888I
   `Y8888888888888888 `8888888888888888888888888       8888888888888888888P'
    `Y888888888888888  `888888888888888888888888,     ,888888888888888888P'
     `Y88888888888888b  `88888888888888888888888I     I888888888888888888'
       "Y8888888888888b  `8888888888888888888888I     I88888888888888888'
         "Y88888888888P   `888888888888888888888b     d8888888888888888'
            ^""""""""^     `Y88888888888888888888,    888888888888888P'
                             "8888888888888888888b,   Y888888888888P^
                              `Y888888888888888888b   `Y8888888P"^
                                "Y8888888888888888P     `""""^
                                  `"YY88888888888P'
                                       ^""""""""'
  */

#include <bits/stdc++.h>
using namespace std;

#define SIZE 10
#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)

int g[SIZE][SIZE] = {
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,1,1,0,0,0,0,0},
  {0,0,0,0,0,1,1,1,0,0},
  {1,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,0,1,0,0,0,0},
  {0,0,0,0,1,1,0,0,0,0},
  {0,1,1,0,0,0,0,1,0,0},
  {0,0,0,0,0,0,1,1,0,0},
  {0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0}
};

int  gx, gy;
/*
0 = undiscovered
1 = discovered
2 = obstacle!
*/
class Soln{
private:
    int n, a[SIZE][SIZE], x0,y0,xi,yi;
    vector< pair<int, int> > v;
public:
    Soln(){
      for(int i=0; i<SIZE; i++){for(int j=0; j<SIZE; j++) a[i][j] = 0; }
      x0 = 0; y0=0;
      xi = 0; yi=0;
      DFS();
      printer();

    }
    void go_to(const int &x, const int &y) 
    /*probably  A* / Greedy best first search, since I am keeping some info
    inside array a[][]  */ 
    {}
    

    bool sonar_ok(){ return !g[gx][gy]; }// if no obstacles, return true. else false
    bool image_ok(){ return !g[gx][gy]; }
    void go_forward(){  printf("forward\n");  }
    void go_backward(){  printf("backward\n");  }
    void rotate_left(){  printf("rotate left\n"); }
    void rotate_right(){  printf("rotate right\n"); }
    void rotate_180_degree(){  printf("rotate 180 degree\n"); }

    void DFS(){
      for(int i=0; i<SIZE; i++)
        for(int j=0; j<SIZE; j++) 
          if(a[i][j] == 0){
              go_to(i,j);
              dfs_visit(i,j);
          }
      
    }

    void dfs_visit(const int &xj,const int &yj){
      xi = xj; yi = yj;
     

      gx = xi; gy = yi;
      int temp1 = xj, temp2 = yj;

       pair<int, int> p(temp1,temp2);
      v.push_back(p);

      printf("%d %d\n",xi,yi);
      // chek_forward
      gy++;
      if(gy<SIZE){
          if(sonar_ok() && image_ok()  ){
            if(a[temp1][temp2+1]==0){
                go_forward();
                a[temp1][temp2+1]=1;
                dfs_visit(temp1, temp2+1);
                go_backward();
            }
          
        }else{
          // obstacle detected, save it inside the map
          a[temp1][temp2+1]=2;
        }
      }
      
      gy--;

      // else check left
      gx--;
      if(gx>=0){
        rotate_left();
        if(sonar_ok() && image_ok()  ){

          if( (a[temp1-1][temp2]==0) ){
              go_forward();
            rotate_right();
            a[temp1-1][temp2]=1;
            dfs_visit(temp1-1, temp2);
            rotate_left();
            go_backward();
          }
        }else{
          // obstacle detected, save it inside the map
          a[temp1-1][temp2]=2;
        }
        rotate_right();
      }
      
      gx++;
      //check right
      gx++;
      
      if(gx<SIZE){
        rotate_right();
        if(sonar_ok() && image_ok() ){

          if(a[temp1+1][temp2]==0){
            go_forward();
            rotate_left();
            a[temp1+1][temp2]=1;
            dfs_visit(temp1+1, temp2);
            rotate_right();
            go_backward();
          }
          
        }else{
          a[temp1+1][temp2]=2;
        }
        rotate_left();
      }
      
      gx--;
      // check back
      gy--;
      if(gy>=0){
        rotate_180_degree();
        if(sonar_ok() && image_ok() ){
          if(a[temp1][temp2-1]==0){
            go_forward();
            rotate_180_degree();
            a[temp1][temp2-1]=1;
            dfs_visit(temp1, temp2-1);
            rotate_180_degree();
            go_backward();
            // go_forward();  // eta use korle jhamela cz if else e jhamela hobe :'(
          }
        }
        rotate_180_degree();
      }
      gy++;





    }
    void printer(){
      for(int i=0; i<SIZE; i++)
      {
        for(int j=0; j<SIZE; j++){
          printf("%d ", a[i][j]);
        }printf("\n");
      }printf("\n");printf("\n");

      printf("Travelled path:\n");
      for(int i=0; i<v.size(); i++){
        cout<<"("<<v[i].first<<","<<v[i].second<<")-->";
        if(i%10==0){
          cout<<"\n";
        }
      }

    }
    ~Soln(){}
};

int main(int argc, char const *argv[])
{
	/* code */
	Soln soln;
	return 0;
}