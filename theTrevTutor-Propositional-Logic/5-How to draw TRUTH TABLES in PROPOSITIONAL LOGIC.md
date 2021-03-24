# How to draw TRUTH TABLES in PROPOSITIONAL LOGIC

A truth table shows the truth values of a WFF for each possible assignment of truth value.

val(a) = value of a
if a is true, val(a) = 1
else val(a) = 0

## Negation

A  ~A
1   0
0   1

val(~A) = 1 - val(A)

## Conjunction
val(A^B) = 1 iff (if and only of) val(A) == 1 and val(B) == 1

A    B   A^B
1    1    1   min(1,1)
0    1    0   min(0,1)
1    0    0   min(1,0)
0    0    0   min(0,0)

mathematically, val(A^B) = min(val(A), val(B))  
We can use the mathematical formula when we'll deal with multi-valued truth tables.
eg, we have values between 0 and 1
So, val(A^B) = min(0.3, 0.5) = 0.3 these formulas still hold. So they are important.

## Disjunction
val(AvB) = 1 iff (if and only of) val(A) == 1 or val(B) == 1

A    B   AvB
1    1    1   max(1,1)
0    1    1   max(0,1)
1    0    1   max(1,0)
0    0    0   max(0,0)

mathematically, val(A^B) = max(val(A), val(B))  

## Conditional
val(A->B) = 1 iff val(A) = 0 OR val(B) = 1

A    B   A->B
1    1    1   
1    0    0   
0    1    1   
0    0    1   

mathematically, val(A->B) = 1 iff val(A) <= val(B)
                          = 0 otherwise

                          OR  max(~A, B)

## Biconditional
val(A <-> B) = 1 iff val(A) == val(B)

A    B   A<->B  A->B   B->A   (A -> B) ^ (B -> A)
1    1    1      1      1              1
1    0    0      0      1              0
0    1    1      1      0              0
0    0    1      1      1              1

A <-> B  == (A -> B) ^ (B -> A)

HW:

AxB is true iff both a and b are not true

A  B  AxB   AxA    ~A
0  0   1     1      1
0  1   0     1      1
1  0   0     0      0
1  1   0     0      0

So theoretically, we can use this down arrow operator to replace not(~) operator o.O
We don't do it cz that would make english complex I guess.