#include <bits/stdc++.h>

using namespace std;

#define WHITE 'w'
#define GRAY  'g'
#define BLACK 'b'


class Vertex{
public:
	int n;
	char color;
	int pi;/*Vertex pi failed! :'( */
	int d,f; /*discovery time and finishing time! */

	Vertex(){	n=0; pi=-1; color = WHITE; d = 0; f = 0; }
};

class Graph{
public:
	 vector<int> *A;
		 Vertex *vertex;
		 vector<int> result;
		int V,E;
		int time;

		Graph(int v=0, int e=0){
				this->V = v;
				this->E = e;
				A = new vector<int>[V];// check here!
				vertex = new Vertex[V];// check here!
				for(int i=0; i<V; i++){ vertex[i].n = i; }
				time = 0;

			}
		~Graph(){
				vector<int>::iterator j;
				for(int i=0; i<V; i++){
					while(!A[i].empty()){ A[i].pop_back(); }
				} cout<<"All A[i] chain deleted!";
				/*for(int i=0; i<V; i++){
					if(vertex[i].pi!=NULL) vertex[i].pi = NULL;
				} */

				delete []A;
				cout<<"GLL deleted!\n";
				delete []vertex;
				cout<<"vertex deleted!\n";
			}

		void DFS(){
				for(int u=0; u<V; u++){
					if(vertex[u].color==WHITE) DFS_VISIT(u);
				}
			}

		void DFS_VISIT(int u){
				result.push_back(u);

				/*Algorithm!*/
				time++;
				vertex[u].d = time;
				vertex[u].color = GRAY;

				vector<int>::iterator v;
				for(v = A[u].begin(); v!=A[u].end(); v++){
					if(vertex[*v].color==WHITE){
						//vertex[*v].pi=&vertex[u];
						vertex[*v].pi = u;
						DFS_VISIT(*v);
					}
				}
				vertex[u].color = BLACK;
				time++;
				vertex[u].f = time;
			}

		/*Needs modification!*/
			void DFSResult(){
				cout<<"n  d  f  pi\n";
				for(int i=0; i<V; i++){
					cout<<vertex[i].n<<" "<<vertex[i].d<<" "<<vertex[i].f<<" "<<vertex[i].pi<<"\n";
				}
			}

			void DFSTraversal(){
					cout<<"DFS Traversal result:\n";
					vector<int>::iterator j;
					for(j=result.begin(); j!=result.end();j++){
						cout<<*j<<"->";
					}
					cout<<"NULL\n";
				}

			void LLGPrinter(){
					vector<int>::iterator j;
					for(int i=0; i<V; i++){
						cout<<"A["<<i<<"]->";
						for(j=A[i].begin(); j!=A[i].end(); j++){
							cout<<*j<<"->";
						}cout<<"NULL\n";
					}
				}
};



int main()
{
	int E, V;
	cout << "Enter V,E:\n";
	cin >> V >> E;
	Graph g(V, E);
	cout << "Enter the Edges:\n";
	int u, v;
	for (int i = 0; i<E; i++) {
		cin >> u >> v;
		g.A[u].push_back(v);
		g.A[v].push_back(u);
	}

	g.LLGPrinter();

	g.DFS();
	g.DFSResult();
	g.DFSTraversal();

	return 0;
}