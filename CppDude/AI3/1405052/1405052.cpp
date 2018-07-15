#include <bits/stdc++.h>

using namespace std;



class AI{
public:
    double **Gd;
    int n,s,*x,*y;
    bool *isVisited;
    vector<int> v1,v2,v3,v4, v5;

    void resetIsVisited(){
        for(int i=0; i<n; i++){
            isVisited[i] = false;
        }
    }

    double CalculateCost(vector<int> u){
        double cost = 0;
        //cout<<"ok1\n";
        int k,j;
        for(int i=1; i<u.size(); i++){
            k = u[i-1];
            j = u[i];
            cost = cost+Gd[k][j];
        }
        //cout<<"ok2\n";
        cost = cost+Gd[u[j]][u[0]];
        //cout<<"ok3\n";
        return cost;
    }

    void CaseA(){
        printf("\nCase #A Nearest Neighbour:\n");

        v1.push_back(s);
        int pos=0;
        while(pos<n-1){
            int x = v1[pos];
            isVisited[x] = true;
            pos++;
            int temp = INT_MAX;
            int next_node = -1;
            for(int i=0; i<n; i++){
                if( (Gd[x][i]!=0) && (Gd[x][i]<temp) && (isVisited[i]==false) ){
                    temp = Gd[x][i];
                    next_node = i;
                }
            }
            v1.push_back(next_node);
            isVisited[next_node] = true;
        }

        int temp1 = v1[0];
        v1.push_back(temp1);
        // cout<<"temp1 = "<<temp1<<"\n";
        
        /*for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<(int)Gd[i][j]<<" ";
            }
            cout<<"\n";
        }*/

        
        for(int i=0; i<v1.size(); i++){
            cout<<v1[i]<<"-->";
        }cout<<"\n";
        cout<<"Cost = "<<CalculateCost(v1)<<"\n";
        /***************************************************/
        

    }
    void CaseB1(){
        cout<<"\nCase #B1 Nearest Insertion:\n";
        resetIsVisited();
        //Step 1. Start with a sub-graph consisting of node i only.
        v2.push_back(s);
        isVisited[s] = true;
        //Step 2. Find node r such that Cir is minimal and form sub-tour i-r-i.
        double temp2 = INT_MAX;
        int pos2 = -1;
        for(int i=0; i<n; i++){
            if((!isVisited[i]) && Gd[s][i]<temp2){
                    pos2 = i;
                    temp2 = Gd[s][i];
            } 
        }
        v2.push_back(pos2);
        isVisited[pos2] = true;
        //cout<<"ok1\n";
        //Step 3. (Selection step) Given a sub-tour, 
        //find node r not in the sub-tour closest to any node j in the sub-tour;
        // i.e. with minimal Crj

        
        for(int i=0; i<n-2; i++){
            //cout<<"ok2\n";
            double temp2 = INT_MAX;
            int pos2 = -1;
            
            for(int j = 0; j <v2.size(); j++)
            {
                //cout<<"ok3\n";
                for(int r = 0; r <n; r++)
                {
                    //cout<<"ok4\n";
                    if((!isVisited[r]) && Gd[r][j]<temp2){
                        pos2 = j;
                        temp2 = Gd[r][j];
                    }
                }
            }
            isVisited[pos2] = true;
            //cout<<"ok5\n";
            //Step 4. (Insertion step) Find the arc (i, j) in the sub-tour which minimizes Cir + Crj - Cij . 
            
            double temp2_2 = INT_MAX;
            int pos2_2 = -1;
            for(int k=1; k<v2.size();k++){
                int i1 = v2[k-1];
                int j1 = v2[k];
                int r1 = pos2;
                //cout<<"ok6\n";
                double C = Gd[i1][r1]+Gd[r1][j1]-Gd[i1][j1];
                if(C<temp2_2){
                    temp2_2 = C;
                    pos2_2 = k;
                    //cout<<"ok7\n";
                }
            }
            //Insert r between i and j.
            // here r = pos2 , pos between i and j = pos2_2
            v2.insert(v2.begin()+pos2_2, pos2);
            isVisited[pos2] = true;
            
            // Step 5. If all the nodes are added to the tour, stop. Else go to step 3 

            
        }
        
    
        int root = v2[0];
        v2.push_back(root);
        for(int i=0; i<v2.size(); i++){ cout<<v2[i]<<"-->"; }
                cout<<"\nCost = "<<CalculateCost(v2)<<"\n";

    }
    void CaseB2(){
        cout<<"\nCase #B2 Cheapest Insertion:\n";
        resetIsVisited();
        //Step 1. Start with a sub-graph consisting of node i only.
        //cout<<"ok1\n";
        //cout<<"ok2\n";
        v3.push_back(s);
        isVisited[s] = true;
        //Step 2. Find node r such that Cir is minimal and form sub-tour i-r-i.
        double temp = INT_MAX;
        int pos = -1;
        for(int i=0; i<n; i++){
            if((!isVisited[i]) && Gd[s][i]<temp){
                    pos = i;
                    temp = Gd[s][i];
            //        cout<<"ok3\n";
            } 
          //  cout<<"ok4\n";
        }
        //cout<<"ok5\n";
        v3.push_back(pos);
        isVisited[pos] = true;
        //cout<<"ok6\n";
        // Step 3. Find (i, j) in sub-tour and node r,not in the sub-tour,
        //  such that Cir + Crj - Cij is minimal.
        // Insert r between i and j. 

        for(int x123=0; x123<n-2; x123++){
            //cout<<"ok7\n";
            double temp2 = INT_MAX;
            int pos_i=-1, pos_j=-1, pos_r=-1;
            for(int k=1; k<v3.size(); k++){
                //cout<<"ok8\n";
                int i=v3[k-1];
                int j = v3[k];
                //cout<<"ok9\n";
                for(int r = 0; r <n; r++){
                    //cout<<"ok10\n";
                    double C = Gd[i][r]+Gd[r][j]-Gd[i][j];
                    if((!isVisited[r]) && (C<temp2)){
                        temp2 = C;
                        pos_i = i; pos_j = j; pos_r = r;
                    }
                }
            }
            //cout<<"ok11\n";
            //cout<<pos_i<<" "<<pos_j<<" "<<pos_r<<"\n";
            v3.insert(v3.begin()+pos_i, pos_r);
            isVisited[pos_r] = true;
            //cout<<"ok12\n";
        }

        int root = v3[0];
        v3.push_back(root);
        for(int i=0; i<v3.size(); i++){ cout<<v3[i]<<"-->"; }
         cout<<"\nCost = "<<CalculateCost(v3)<<"\n";


        
    }

    void CaseC1(){
       cout<<"\nCase #C1 2-opt heuristic for 2-opt neighborhood search:\n";
       cout<<"\nImprovement heuristic on output from A\n";
       C1AlgorithmWiki(v1);
       cout<<"\nImprovement heuristic on output from B1\n";
       C1AlgorithmWiki(v2);
       cout<<"\nImprovement heuristic on output from B2\n";
       C1AlgorithmWiki(v3); 
    }

    void CaseC2(){

    }

    AI(){
        cin>>n;
        cin>>s;
        
        x = new int[n]; 
        y = new int[n];
        isVisited = new bool[n];
        
        resetIsVisited();

        for(int i=0; i<n; i++){
            cin>>x[i]>>y[i];
        }
        // calculate cost
        Gd = new double*[n];
        for(int i=0; i<n; i++)
        { Gd[i] = new double[n]; }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                double temp = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
                temp = sqrt(temp);
                Gd[i][j] = temp; 
            }
        }
        
        CaseA();
        CaseB1();
        CaseB2();
        CaseC1();


        /*******THE END**********/
        cout<<"\n\n\n";
    }

    
    ~AI(){
        for(int i=0; i<n; i++){
            if(!Gd[i]) delete[] Gd[i];
        }
        if(!Gd) delete[] Gd;
        if(!x) delete[] x;
        if(!y) delete[] y;
    }

    vector<int> twoOptSwap(vector<int> u, int i){
        vector<int> temp;
        for(int j=0; j<i; j++){
            temp.push_back(u[j]);
        }

        int k = u.size()-2;
        for(int j=k; j>=i; j--){
            temp.push_back(u[j]);
        }

        temp.push_back(u[0]);

        for(int j=0; j<temp.size(); j++){
            cout<<temp[j]<<"-->";
        }
        return temp;
    }

    void C1AlgorithmWiki(vector<int> x){
        int count = n-1;
        vector<int> u = x;
        vector<int> best_soln;
        double best_cost;
        while(count--){
            best_cost = CalculateCost(u);
            for(int i=1; i<u.size()-2; i++){
                vector<int> temp_v = twoOptSwap(u,i);
                double new_cost = CalculateCost(temp_v);
                cout<<"new cost = "<<new_cost<<", best cost = "<<best_cost<<"\n";
                if(new_cost<best_cost){
                    best_cost = new_cost;
                    u = temp_v;
                    best_soln = temp_v;
                }
            }
        }

        cout<<"\n ---------- \n\nCost = "<<best_cost<<"\n"; 
        for(int i=0; i<best_soln.size(); i++){
            cout<<u[i]<<" ";
        }cout<<"\n";
    }
};



int main()
{
    AI ai3;
    return 0;
}