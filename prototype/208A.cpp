#include <bits/stdc++.h>

using namespace std;

class A208{
private:
    string s;
    int wub_pos;
public:
    A208(){
        cin>>s;
        while(1){
            wub_pos = s.find("WUB");

            //cout<<"wub pos = "<<wub_pos<<endl;
            if(wub_pos==-1){ break; }
            s.erase(wub_pos,3);
            //cout<<s<<endl;
            if(wub_pos!=0){
                s.insert(wub_pos," ");
            }
        }
        cout<<s<<endl;
    }
    ~A208(){}
};

int main()
{
    A208 a208;
    return 0;
}


/*#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin >> s;
	regex p("WUB");
	cout << regex_replace(s, p, " ");
}*/