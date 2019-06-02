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

class A601
{
private:
	int n,m,count1, count2, **G;
	vector<int> Stack, train, bus;
	bool *isVisited;
public:
void DFS_bus(){
	if(!isVisited[1])DFS_visit_bus(1);
}
	void DFS_visit_bus(int u){
		isVisited[u]=true;
		Stack.push_back(u);
		if(u==n){
			if(Stack.size()<count2){
				count2=Stack.size();
				bus.clear();
				//cout<<endl;	
				for(int i=0; i<count2; i++){
					bus.push_back(Stack[i]);
					//cout<<Stack[i]<<" ";
				}
				//cout<<endl;
			}
			return;
		}
		for(int v=1; v<=n; v++){
			if((G[u][v]==0) && (isVisited[v]==false)){
				DFS_visit_bus(v);
			}
		}
		Stack.pop_back();

	}

	void DFS_train(){
		//for(int i=1; i<=n; i++){
			if(!isVisited[1])DFS_visit_train(1);
		//}
	}
	void DFS_visit_train(int u){
		isVisited[u]=true;
		Stack.push_back(u);
		if(u==n){
			if(Stack.size()<count1){
				count1=Stack.size();
				train.clear();//for(int i=0; i<train.size(); i++){train.pop_back();}

				for(int i=0; i<count1; i++){
					train.push_back(Stack[i]);
				}
			}
			return;
		}
		for(int v=1; v<=n; v++){
			if((G[u][v]==1) && (isVisited[v]==false)){
				DFS_visit_train(v);
			}
		}
		Stack.pop_back();

	}

	A601(){
		count2=INT_MAX;
		count1=INT_MAX;

		cin>>n>>m;
		G = new int*[n+1];
		isVisited = new bool[n+1];
		for(int i=0; i<=n; i++){ G[i]=new int[n+1];}
		for(int i=0; i<m; i++){
			int x,y;
			cin>>x>>y;
			G[x][y]=1;
		}	
		for(int i=0; i<=n; i++){isVisited[i]=false;}
		DFS_train();
		//cout<<train.size()<<endl;
		for(int i=0; i<=n; i++){isVisited[i]=false;}
		Stack.clear();	
		DFS_bus();
	//cout<<bus.size()<<endl;
		int small;

		if((bus.size()==0) || (train.size()==0)){
			cout<<"-1\n";
			//exit(0);
		}

		else if(bus.size()<train.size()){ 
			small=bus.size();
			//v1.insert(v1.begin()+i, v2[i])
			for(int i=01; i<small-1; i++){
				if(bus[i]==train[i]){
					train.insert(train.begin()+i,-1);
				}
			}
			cout<<train.size()-1<<endl;

		}
		else{ 
			small = train.size(); 
			//v1.insert(v1.begin()+i, v2[i])
			for(int i=01; i<small-1; i++){
				if(bus[i]==train[i]){
					bus.insert(bus.begin()+i,-1);
				}
			}
			cout<<bus.size()-1<<endl;

		}

		
	}
	~A601(){
		for(int i=0; i<=n; i++){
			if(!G[i])delete[] G[i];
		}
		if(!G)delete[] G;
	}
	
};
int main(int argc, char const *argv[])
{
	/* code */
	A601 a601;
	return 0;
}