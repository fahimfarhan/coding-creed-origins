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

#define si(x) scanf("%d",&x)
#define sf(x) scanf("%f",&x)

#define pi(x) printf("%d\n",x)
#define pf(x) printf("%.4f\n",x)


#define SIZE 10
#define OBS_LEN 4

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

class Soln{
private:
     int n, a[SIZE][SIZE],xi,yi, obsx,obsy, bx,by, obsflag; //, x0,y0; //xi,yi;
    vector< pair<int, int> > v;
    int curr_dir; // 0== forward, 1 = left, 2 = backword, 3 = right 
public:
    bool sonar_ok(){ return !g[gx][gy]; }// if no obstacles, return true. else false
    bool image_ok(){ return !g[gx][gy]; }
    void go_forward(){  printf("forward\n");  }
    void go_backward(){  printf("backward\n");  }
    void rotate_left(){  printf("rotate left\n"); }
    void rotate_right(){  printf("rotate right\n"); }
    void rotate_180_degree(){  printf("rotate 180 degree\n"); }
    
    Soln(){
         xi=0; yi=0;
        obsx = 0; obsy = 0;
        curr_dir = 0; 
        printf("Start\n");
        dsd_visit();
    }

    void dsd_visit(){
        while(true){
            //if direction is front
            if(curr_dir == 0){
                while(sonar_ok() && image_ok() && yi<SIZE){
                    a[xi][yi] = 1;
                    go_forward();
                    yi++;
                    gx = xi; gy = yi;
                }
                // obs / bound detected
                if(!image_ok()){
                    //boundary
                    rotate_right();
                    go_forward();
                    xi++;
                    a[xi][yi]=1;
                    rotate_right();
                    curr_dir =2;
                }
                else if(!sonar_ok())
                {
                    // obstacle detected
                    int obs_len_x = 0;
                    int obs_len_y = 0;
                    while(obs_len_x<OBS_LEN){
                        rotate_right();
                        go_forward();
                        xi++; a[xi][yi]=1;
                        obs_len_x++;
                        rotate_left();
                        if(sonar_ok()) // end of obstacle
                        { break; }
                    }
                    while(obs_len_y<OBS_LEN){
                        go_forward();
                        obs_len_y++;
                        rotate_left();
                        if(sonar_ok()){ break; }
                        else{
                            rotate_right();
                        }
                    }
                    // robot facing left
                    while(obs_len_x--){
                        go_forward();
                        xi--;
                        a[xi][yi]=1;
                    }
                    rotate_right();
                }
                
            }else if(curr_dir == 2){ // bacckward
                while(sonar_ok() && image_ok() && yi>=0){
                    a[xi][yi] = 1;
                    go_forward(); // actually going backwards
                    yi--;
                    gx = xi; gy = yi;
                }
                // obs/boundary detected
                if(!image_ok()){
                    // boundary detected
                    rotate_left();
                    go_forward();
                    xi++;
                    a[xi][yi] = 1;
                    rotate_left();curr_dir = 0;
                }
                else if(!sonar_ok())
                {
                    // obstacle detected
                    int obs_len_x = 0;
                    int obs_len_y = 0;
                    while(obs_len_x<OBS_LEN){
                        rotate_left();
                        go_forward();
                        xi++; a[xi][yi]=1;
                        obs_len_x++;
                        rotate_right();
                        if(sonar_ok()) // end of obstacle
                        { break; }
                    }
                    while(obs_len_y<OBS_LEN){
                        go_forward();
                        obs_len_y++;
                        rotate_right();
                        if(sonar_ok()){ break; }
                        else{
                            rotate_left();
                        }
                    }
                    // robot facing left
                    while(obs_len_x--){
                        go_forward();
                        xi--;
                        a[xi][yi]=1;
                    }
                    rotate_right();
                }

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