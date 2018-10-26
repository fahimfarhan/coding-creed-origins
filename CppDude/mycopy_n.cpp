#include <bits/stdc++.h>

using namespace std;
#include <algorithm>
int main()
{
    int mat[3][3]={{1,2,3},{4,5,6},{7,8,9}};
    int matnew[3][3];
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d", matnew[i][j]);
        }printf("\n");
    }

    cout<<"After\n";
    
    memcpy(matnew, mat, sizeof(mat));
    
    //copy(mat, 9, matnew);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d", matnew[i][j]);
        }printf("\n");
    }
    return 0;
}