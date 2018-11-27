#include <iostream>
#include <cmath>
#include<map>
#include <vector>
#include <sstream>
using namespace std;
vector<int>vectX;
vector<int>vectY;

void gg(int ax,int ay,int bx,int by,int cx,int cy){
int vectx=bx-ax;
int vecty=by-ay;
int dx=vectx+cx;
int dy=vecty+cy; // vectx+dy silo!!! as a result garbage value astisilo. 

//cout<<"dx dy "<<dx<<" "<<dy<<"\n";

if((((ax-cx)^2+(ay-cy)^2)==((bx-dx)^2+(by-dy)^2))&&(((ax-bx)^2+(ay-by)^2)==((cx-dx)^2+(cy-dy)^2))){
        vectY.push_back(dy);
    vectX.push_back(dx);

}
vectx=-vectx;
vecty=-vecty;
dx=vectx+cx;
dy=vecty+cy;
//cout<<"dx dy "<<dx<<" "<<dy<<"\n";
if((((ax-dx)^2+(ay-dy)^2)==((bx-cx)^2+(by-cy)^2))&&(((ax-bx)^2+(ay-by)^2)==((dx-cx)^2+(dy-cy)^2))){

    vectX.push_back(dx);
    vectY.push_back(dy);
}

}
class coordinate{
public:
    coordinate(int x,int y){
    this->x=x;
    this->y=y;
    }
    int x;
    int y;
};
int main(){
int ax,ay,bx,by,cx,cy,dx,dy,vectx,vecty;
cin>>ax>>ay>>bx>>by>>cx>>cy;
gg(ax,ay,bx,by,cx,cy);
gg(ax,ay,cx,cy,bx,by);
gg(bx,by,cx,cy,ax,ay);
int koyta=0;
map<string,bool>gg;
for(int i=0;i<vectX.size();i++){
        std::string out_string;
std::stringstream ss;
ss << vectX[i]<<" "<<vectY[i];
//cout<< vectX[i]<<" "<<vectY[i]<<"\n";
out_string = ss.str();
   if(gg.find(out_string)==gg.end()){
   // cout<<out_string<<endl;
    gg.insert(pair<string,bool>(out_string,true));
    koyta+=1;
   }
}
cout<<koyta<<endl;
for(std::map<string,bool>::iterator iter = gg.begin(); iter != gg.end(); ++iter)
{
string k =  iter->first;
cout<<k<<endl;
//ignore value
//Value v = iter->second;
}
}