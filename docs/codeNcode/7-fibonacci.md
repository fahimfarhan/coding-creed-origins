```
  F1 = A * F0
  F2 = A^2 * F0
  --- --- ---
  --- --- ---
  FN = A^N * F0
```
```
|f2|  =  |a  b| |f1|
|f1|     |c  d| |f0|
```
=>
```
f2 = af1 + bf0   --- --- --- (1)
f1 = cf1 + df0   --- --- --- (2)
```
Intuitively, c = 1, d = 0 satisfies eqn (2).

Since f2 = f1 + f0 (by definition), therefore, eqn (1) can be true if a = 1 and b = 1.
```
Therefore A = |1  1|
              |1  0|
```