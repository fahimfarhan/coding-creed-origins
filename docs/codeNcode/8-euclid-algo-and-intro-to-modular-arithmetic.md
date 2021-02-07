## Euclid Division lemma
For positive integers A and B, there exist integers q and r such that
```
  A = q*B + r   , where 0 <= r < B
```
We need this to lamma to prove other formulas.

## Understanding Modular Arithmetics
```
(N1 + N2)% M = (N1%M + N2%M) % M        --- --- ---(1)
(N1 * N2)% M = ((N1%M) * (N2%M)) % M    --- --- ---(2)
```

Why does this work?
Let N1 = a1*M + r1, N2 = a2*M+r2

Then, from eqn (1),
```
  LHS = (N1 + N2) % M
      = (a1*M + r1 + a2*M+r2) % M
      = (r1 + r2) % M
```
And
```
RHS = (N1%M + N2%M) % M
    = ( (a1*M + r1)%M + (a2*M+r2)%M) % M
    = (r1 + r2) % M
```
Therefore, LHS == RHS.

For eqn(2),
```
LHS = (N1 * N2)% M
    = ((a1*M + r1) * (a2*M+r2)) % M
    = (a1a2M^2 + a1r2M + a2r1M + r1r2) % M
    = (r1 * r2) % M
```
And,
```
RHS = ((N1%M) * (N2%M)) % M
    = ((a1*M + r1)%M * (a2*M+r2)%M ) % M
    = (r1 * r2) % M
```
Therefore, LHS == RHS.

## Euclid Division Algorithm
Euclid's algorithm can be used to calc GCD / HCF (greatest common divisor / highest common factor) of two numbers, say A and B.

The recursive definition,
```
  gcd(a,b) = a, if b == 0
           | gcd(b, a % b)  otherwise
```

So cpp version:
```cpp
int calcGcd(int a, int b) {
  if(b == 0)  
    return a;
  else   
    return calcGcd(b, (a % b));
}
```

## Some Observations
```
1.      gcd(A,0) == gcd(0,A) == A
```
Greatest common divisor of A is A itself. 0 cannot divide anything. Any number can divide 0. So 1,2,...A all divides 0. So the greatest number on bothsides is A.
Therefore, gcd = A.

```
2.      gcd(A,B) == gcd(B,A)
```
Cz the ordering of the numbers donot change / affect the greatest common divisor.

```
3.      gcd(A,B) = gcd(A-B,B) = gcd(A,B-A)  ***important one!***
        gcd(A,B) = gcd(A+B,B) = gcd(A,B+A)
```
Why does observation 3 work?
Let, g = gcd(A,B). Then, A = g*X, B = g*Y
Then, A-B = g*(X-Y),
and,  B-A = g*(Y-X)

So A-B and B-A both are divisible by g and g is the highest common divisor of both A and B. So it doesnot change.

Using these observations, we get this *Repeated Substraction method to find gcd*:

44 = 12 * 3 + 8
12 = 8 * 1 + 4
8 = 4 * 2 + 0

gcd(44, 12)
= gcd(44-12, 12)
= gcd(32, 12)
= gcd(20,12)
***= gcd(8, 12) = gcd(12,8)***  // 3 steps before swap
***= gcd(4,8)   = gcd(8,4)***   // 1 step before swap   
= gcd(4,4)
= gcd(0,4)       // 2 steps... the number of steps == the ratio or quotient
= 4

But the problem is that it takes too long / too many steps. So we use division to find the reminder.

## Homework: Iterative algorithm to find Gcd

```cpp
int iterativeGcd(int a, int b) {
  while( b!=0 ) {
    int b1 = a % b;
    a = b;
    b = b1;
  }
  return a;
}

```

## Gcd queries (CodeChef)
gcd(a0, a1, a2) = gcd( gcd(a0, a1), a2)
Similarly, gcd(a0, a1, ... aN) = gcd(gcd(a0, a1, ..., aN-1), aN)

So using this knowledge, we can calculate prefixGcd and suffixGcd arrays (kinda gcd version of cummulative frequency).
Then we can use this just like cummulative frequency.

## Modulat Arithmetic 1

***Understanding Modular Congruences***
A and B are congruent to each other under Modulo N if they leave the same remainder when divided by N.

the congruent sign is 3 dashes.
```
    A == B (mod N)
```

13 == 41 (mod 7)
cz 13 % 7 = 6
and 41 % 7 = 6

Usages: (13 + 35 + 5) % 7 = 53 % 7 = 4
        (41 + 35 + 5) % 7 = 81 % 7 = 4

1st line e 13 ke amra 41 diye kingba wnd line e 41 ke amra 13 diye replace korte pari.

(13 * 4) % 7 = 52 % 7 = 3,
(31 * 4) % 7 = 124 % 7 = 3

So why does it work?
(13 + 35 + 5) % 7
= (13 % 7 + 35 % 7 + 5 % 7) % 7
= (6 + 0 + 5) % 7
= 11 % 7 
= 4

Similarly, (41 + 35 + 5) % 7
= (41 % 7 + 35 % 7 + 5 % 7) % 7
= (6 + 0 + 5) % 7
= 11 % 7 
= 4

## Important observation
```
If A == B (mod N)
=> A-B == 0 (mod N)
```

This means, A-B is divisible by N

Why dows it work?
`A = aN + r, B = bN + r`. Both have same remainder r cz `A == B (mod N)`.
then `A-B = N(a-b)`, which is dibisible by N.

```
A - B = N(a-b) = Nk
=> A = Nk + B  --- --- --- --- (1)
```
This means, we can convert A into B or B into A with help of some int k.

13 - 41 = -28 = 7*(-4)
41 - 13 =  28 = 7*4

13 = 7*(-4) + 41
41 = 7*(4) + 13

## Multiplication under modulo
If we have 3 numbers a, b, c such that,
```
      a * b = c
```
Then, 
```
    (a % N) * (B % N) = c % N
```

13 == 3 (mod 5)
9  == 4 (mod 5)

 13 * 9 = 117
 (13 % 5) * (9 % 5) == 117 % 5
 3 * 4  == 2
 12 == 2 (modulo 5)  (this is what we get. And 12 == 2 mod 5 is true. So ...)

 ## Proof:
 a * b = c
 
 Let, a = Nk1+r1
 b = Nk2+r2
 c = Nk3+r3

Then, (a mod N) * (b mod N) == (c mod N)
=>        r1 * r2 == r3

Now 
```
a*b = (Nk1+r1)*(Nk2+r2)
        = (k1k2N^2 + k1r2N + k2r1N + r1r2)
        = N(k1k2N + k1r2 + k2r1) + r1r2
```
So 
```
ab = c
=> N(k1k2N + k1r2 + k2r1) + r1r2 = Nk3 + r3
=> N(k1k2N + k1r2 + k2r1 - k3) = r3 - (r1r2)
```

Since lhs is divisible by N, therefore,
```
r3 - r1r2 == 0 (mod N)
=> r1r2 == r3 (mod N)
```
Since this is true, we get,
```
res = a*b
=> res = ((a%N) * (b%N)) % N
```
Similarly we can show this for add, sub.

Find last digit of 2573 * 34268
```
2573 * 34268 % 10
= 2573%10 * 34268%10
= 3 * 8 % 10
= 24 % 10
= 4
```

(142 + 453 + 324 + 781 + 523 + 250 + 313) % 2 = ?
= (142%2 + 453%2 + 324%2 + 781%2 + 523%2 + 250%2 + 313%2) % 2
= (0 + 1 + 0 + 1 + 1 + 0 + 1)%2
= 4%2
= 0

