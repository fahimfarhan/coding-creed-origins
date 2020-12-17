#include <iostream>
#include <vector>
 
// Multiply a NxN (square) matrix % MOD
std::vector<std::vector<long>> operator*(const std::vector<std::vector<long>>& lhs, 
                                         const std::vector<std::vector<long>>& rhs)
{    
    int N = lhs.size();    
    std::vector<std::vector<long>> res (N, std::vector<long>(N, 0L));
    
    // Multiply -> O(n^3)
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int k = 0; k < N; ++k)
                res[i][j] = (res[i][j] + (lhs[i][k] * rhs[k][j])) % 1000000007;
        
    return res;
}
 
// Binary exponentiation of a square matrix
std::vector<std::vector<long>> power(std::vector<std::vector<long>> base, int exp) // pass by value to work on a copy
{    
    int N = base.size();
    std::vector<std::vector<long>> res (N, std::vector<long>(N, 0L));
    
    // Make res the identity matrix
    for (int i = 0; i < N; ++i)
        res[i][i] = 1;
    
    // Multiply by powers of 2 whose bit is set on exp
    while (exp > 0)
    {
        if (exp & 1)
            res = res * base;
        
        base = base * base;
        exp >>= 1;
    }
    
    return res;
}
 
int main()
{
    int tests;
    std::cin >> tests;
    
    while (tests--)
    {
        int sz, exp;
        std::cin >> sz >> exp;
        
        std::vector<std::vector<long>> mat (sz, std::vector<long>(sz));
        
        for (auto& row: mat)
            for (auto& elem: row)
                std::cin >> elem;
            
        auto res = power(mat, exp);
        
        for (int i = 0; i < sz; ++i)
        {
            for (int j = 0; j < sz; ++j)
            {
                std::cout << res[i][j];
                
                if (j == sz - 1)
                    std::cout << std::endl;
                else
                    std::cout << " ";
            }
        }
    }
    
    return 0;
}