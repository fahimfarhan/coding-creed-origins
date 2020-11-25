# Primality Test
Normal cpp code:
```c++
    bool isPrime(int N) {
        for(int i=2; i<N; i++) {
            if(N%i == 0) {
                return false;
            }
        }
        return true;
    }
```

Complexity `O(N)`

We need to reduce 