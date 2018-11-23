#include <bits/stdc++.h>

using namespace std;

// Complete the diagonalDifference function below.
int diagonalDifference(vector<vector<int>> arr) {
    int pd = 0; 
    int sd = 0;
    int x  = 0;
    int l = arr.size();
    for(int i=0; i<l; i++){
        pd+=arr[i][i];
    }
    for(int i=0; i<l; i++){
        sd+=arr[i][l-i-1];
    }
    x = pd-sd;
    x = abs(x);
    return x;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = diagonalDifference(arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
