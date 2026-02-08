#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // <--- Xətanın həlli buradadır

int main() {
    int N = 100;
    std::vector<bool> used_a(N + 1, false);
    long long total_distinct = 0;

    for (int a = 2; a <= N; ++a) {
        if (used_a[a]) continue; 

        std::vector<int> exponents;
        long long temp_a = a;
        int k = 1;
        
        // Bazanın bütün qüvvətlərini tapırıq (məs: 2, 4, 8, 16...)
        while (temp_a <= N) {
            used_a[temp_a] = true;
            for (int b = 2; b <= N; ++b) {
                exponents.push_back(k * b); 
            }
            
            // Daşmanın (overflow) qarşısını almaq üçün yoxlama
            if (N / a < temp_a) break; 
            temp_a *= a;
            k++;
        }

        // Təkrarları təmizləyirik
        std::sort(exponents.begin(), exponents.end());
        exponents.erase(std::unique(exponents.begin(), exponents.end()), exponents.end());
        
        total_distinct += exponents.size();
    }

    std::cout << "Unikal neticelerin sayi: " << total_distinct << std::endl;
    return 0;
}