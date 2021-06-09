# L04 : Subsets and BitMasking | Dynamic Programming Course Part 1
set = {A, B, C}

{}    000  0
{A}   001  1
{B}   010  2
{BA}  011  3
{C}   100  4
{CA}  101  5
{CB}  110  6
{ABC} 111  7 

This way, you can generate all the possible subsets of a given set.

# How to check if ith bit is set?

N = 01101011

F = 1 << i
F = 1 << 3
    00001000

if (N&F != 0) {
  ith bit is set
}else{
  ith bit is not set
}

# Generate all the subsets
```cpp
cin>>n;
int tot = 1 << n; 
for(int N = 0; N<tot; N++) {
  for(int i=0; i<n; i++) {
    int F = 1 << i;
    if(N&F != 0) {
      cout<<"ith character"<<"\n";
    } 
  }
}
```