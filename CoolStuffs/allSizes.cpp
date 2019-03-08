#include <bits/stdc++.h>
using namespace std;

#define PI 2*acos(0)

#define ll long long int

bool myAssert(bool b);
void testDrivenDevelopment();
int start(int argc=0, char const *argv[] = NULL);


// int n,m;
vector<int> *g;
bool *isvisited;

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

int imin = std::numeric_limits<int>::min(); // minimum value
int imax = std::numeric_limits<int>::max();
  cout<<"int\n";
  cout<<imin<<" "<<imax<<'\n';

  imin = std::numeric_limits<short>::min(); // minimum value
  imax = std::numeric_limits<short>::max();
  cout<<"short\n";
  cout<<imin<<" "<<imax<<'\n';

  imin = std::numeric_limits<long>::min(); // minimum value
  imax = std::numeric_limits<long>::max();
  cout<<"long\n";
  cout<<imin<<" "<<imax<<'\n';

  imin = std::numeric_limits<long long>::min(); // minimum value
  imax = std::numeric_limits<long long>::max();
  cout<<"long long\n";
  cout<<imin<<" "<<imax<<'\n';

  imin = std::numeric_limits<float>::min(); // minimum value
  imax = std::numeric_limits<float>::max();
  cout<<"float\n";
  cout<<imin<<" "<<imax<<'\n';


  imin = std::numeric_limits<double>::min(); // minimum value
  imax = std::numeric_limits<double>::max();
  cout<<"double\n";
  cout<<imin<<" "<<imax<<'\n';

/*
  imin = std::numeric_limits<>::min(); // minimum value
  imax = std::numeric_limits<>::max();
  cout<<"\n";
  cout<<imin<<" "<<imax<<'\n';
*/
  return 0;
}

