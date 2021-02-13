## Problem to be discussed

ans = (sum_i=1 to N) gcd(i,N)

if N = 5 then ans = gcd(1,5) + gcd(2,5) + gcd(3,5) + gcd(4,5) + gcd(5,5) 

So, from i = 1 to N, let q of then are divisors of N. Then N - q are non divisors.

N = 10. 2, 4, 8 have gcd(i, 10) = 2. 

let there are m numbers such that gcd(im, N) = 1

m = phi(N)
So, sum = phi(N) + X. Then we need to solve the subproblem, X = ?

Observation 1: gcd(i,N) = some divisor d.

Observation 2: Instead of running loop from 1 to N, we can check for each
divisor d of N, how many numbers are there such that gcd(i,N) == d.

Example: N = 12
ans = `1`*4 + `2`*2 + `3`*2 + `4`*2 + `6`*1 + `12`*1 (`d` * count)

Let x1, x2, x3, ... are some numbers such that gdc(xi, N) = d.

gdc(xi, N) = d => gdc(xi/d, N/d) = 1

   1 <= xi <= N
=> 1 <= xi/d <= N/d

the number of integers having gcd d with N = number of integers coprime with d.