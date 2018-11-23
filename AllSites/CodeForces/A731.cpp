#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

class A731{
private:
	string s;
	int *c, *n;
	int ans, curr_pos, clockwise, anticlockwise;
public:
	A731(){
		cin>>s;
		c = new int[s.length()];
		n = new int[26];
		
		for(int i=0; i<26; i++){
			n[i] = i;
		}
		//for(int i=0; i<26; i++) cout<<n[i];
		//cout<<endl;
		for(int i = 0; i<s.length(); i++ ){
			c[i] = s[i] - 'a';
		}
		//for(int i = 0; i<s.length(); i++ ) cout<<c[i];
		ans = 0; curr_pos = 0; 
		for(int i=0; i<s.length(); i++){
			//if(c[i]<13 && curr_pos<13){ ans = ans+mod(c[i] - curr_pos);	}
			//else if(c[i]>=13 && curr_pos>=13){ ans = ans+mod(c[i] - curr_pos);	}
			//clockwise
			//clockwise = abs(c[i] - curr_pos);
			//anticlockwise = abs(26-c[i]+curr_pos);
			
			clockwise = c[i]-curr_pos; 
			if(clockwise<0) clockwise+=26;
			if(clockwise>25)clockwise-=26; 
			
			anticlockwise = (25-c[i])+curr_pos+1; 
			if(anticlockwise<0) anticlockwise+=25;
			if(anticlockwise>25)anticlockwise-=26;
			
			if(clockwise<anticlockwise) ans+=clockwise;
			else ans+=anticlockwise;
			// after all if-else 
			curr_pos = c[i];
		}
		
		cout<<ans<<"\n";
	
	}
	
	~A731(){
		if(c!=NULL) delete[] c;
		if(n!=NULL) delete[] n;
	}
};

int main()
{
	A731 a;
	return 0;
}







