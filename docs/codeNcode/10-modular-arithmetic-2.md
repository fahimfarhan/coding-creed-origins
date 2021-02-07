## Divisiblility by 8 and 3

Q: CHeck if the number 4819250393285 is divisible by 9

Observation:
12345 is it divisible by 9?
12345 % 9 = ((1*10^4 + 2*10^3 + 3 * 10^2 + 4*10^1+5*10^0)) % 9
= (1(9999 + 1) + 2(999+1)+3(99)+4(9+1) + 5) % 9
= ((9999+999+99+9) + (1+2+3+4+5))%9
= 1+2+3+4+5 % 9

That's why if the sum of digits is divisible by 9, the number is divisible
by 9 / has the same remainder!

## Exponentiation in modular arithmetic
if a == b (MOD N)
then a^k == b^k (mod N)

Proof:
If a == b (mod N)
Then we can convert a <=> b using a = Nq + b => b = -Nq + a = Np+a
So, 
```
   a == b mod N
   => a = Nq + b
   => a^k = (Nq + b)^k
          = [c0(Nq)^k + c1b(Nq)^k-1 + ... ... ]+ cnb^k
   => a^k = NQ + cn*b^k
```
Therefore, a^k == b^k (mod N)

Q: find 29^10 ( mod 3 )

29 % 3 = 2
so , 29 = 2 (mod 3)
therefore, 
```
29^10 = 2^10 (mod 3)
      = 1024 % 3
      = (1+0+2+4) % 3
      = 7 % 3
      = 1
```

Q: find 2^123456789 % 7 = ?
Hint:
123456789 == 0 mod 3
So, 

2^123456789 = (2^3)^41152263 = 8^41152263

Now 8 % 7 = 1, therefore, 
8 == 1 (mod 7)
So, (8^41152263) % 7 == (1^41152263) % 7 

NOW, 1^41152263 = 1
So,  1^41152263 % 7 = 1 % 7 = 1

