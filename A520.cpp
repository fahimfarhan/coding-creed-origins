#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;

class A520{
private:
	char *c; int n;
public:
	A520();
	~A520();
};

A520::A520(){
	cin>>n;
	c = new char[n] ;
	for(int i=0; i<n; i++){  cin>>c[i];	}
	
	if(n<26){ cout<<"NO\n";	}
	else{
		for(int i=0; i<n; i++){
			if(c[i]<'a'){	}
			else c[i] = c[i]-'a'+'A';
		}
		
		sort(c,c+n);
		bool b = true;
		
		//cout<<c[n-1]<<endl;
		if(c[0]!='A'){
			cout<<"NO\n"; exit(0);
		}
		
		if(c[n-1]!='Z'){
			//b = false;
			cout<<"NO\n"; exit(0);
		}
		
		//for(int i=0; i<n; i++){  cout<<c[i]; 	}
		for(int i=1; i<n; i++){
			if(c[i]-c[i-1]>1){
				b = false;
				break;
			} 
		}
		
		if(b == true) cout<<"YES\n";
		else cout<<"NO\n";
			
		
	}
	
	
	
	
}

A520::~A520(){
	if(c!=NULL) delete[] c;
}
int main()
{
	A520 a;
	return 0;
}

