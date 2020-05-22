#include<bits/stdc++.h>
using namespace std;
double r,ax,ay,bx,by;
int main(){
	cin>>r>>ax>>ay>>bx>>by;
	if (sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))>=r){
		printf("%.9lf %.9lf %.9lf\n",ax,ay,r);
	}else{
		double p=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by))+r;
		p/=2;
		double q=atan2(ay-by,ax-bx);
		double s=bx+cos(q)*p,t=by+sin(q)*p;
		printf("%.9lf %.9lf %.9lf\n",s,t,p);
	}
	return 0;
}