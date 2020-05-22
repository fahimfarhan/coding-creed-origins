#ifdef _WIN32

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

#else

#include <bits/stdc++.h>

#endif

using namespace std;

class Solver{
private:
	long long int m,n,a;
public:

	Solver();
	~Solver();
};


Solver::Solver(){
	scanf("%I64d %I64d %I64d",&n,&m,&a);
	if((n%a )== 0){ n=n/a;}
	else n = n/a+1;
	if((m%a )== 0){ m=m/a;}
	else m = m/a+1;
	a = m*n;
	printf("%I64d", a);
}

Solver::~Solver(){}

int main()
{
	Solver s;
	return 0;
}
