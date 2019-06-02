#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;



int main()
{
  double n,u,v;
  cin>>n;
  n--;
  for(int i=0; i<n;i++){
    cin>>u>>v;
  }

  //cout<<setprecision(15)<<n/2<<"\n";
  cout<<n/2<<"\n";

  return 0;
}
