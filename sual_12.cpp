// Highly Divisible Triangular Number
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 500;    
    long long triangle = 0;
    for (int i = 1; ; i++) {
        triangle += i;
        int divisors = 0;
        for (int j = 1; j * j <= triangle; j++) {
            if (triangle % j == 0) {
                divisors += (j * j == triangle) ? 1 : 2;
            }
        }
        if (divisors > n) {
            cout << "The first triangular number with more than " << n << " divisors is: " << triangle << endl;
            break;
        }
    }
    return 0;
}