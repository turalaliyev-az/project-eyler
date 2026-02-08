#include <iostream>
#include <set>
#include <vector>

// Rəqəmləri bitmask vasitəsilə yoxlayan funksiya (ən sürətli üsul)
bool isPandigital(int a, int b, int prod, int& mask) {
    int temp[] = {a, b, prod};
    mask = 0;
    int count = 0;
    for (int num : temp) {
        while (num > 0) {
            int digit = num % 10;
            if (digit == 0) return false; // Pandigitalda 0 olmur
            int bit = 1 << digit;
            if (mask & bit) return false; // Təkrar rəqəm tapıldı
            mask |= bit;
            num /= 10;
            count++;
        }
    }
    return count == 9 && mask == 1022; // 1-9 arası bütün bitlər (1111111110)
}

int main() {
    std::set<int> uniqueProducts;
    
    // Turalın "Minimum İş" diapazonu
    for (int a = 2; a < 100; ++a) {
        for (int b = 100; b < 5000; ++b) {
            
            // Sənin dediyin "Dəqiq Şərt" (Mod 9 süzgəci)
            if (((a + 1) * (b + 1)) % 9 != 1) continue;

            int prod = a * b;
            int mask = 0;
            
            // Əgər riyazi şərt ödənilirsə, pandigital testi et
            if (isPandigital(a, b, prod, mask)) {
                uniqueProducts.insert(prod);
            }
        }
    }

    long long sum = 0;
    for (int p : uniqueProducts) sum += p;

    std::cout << "Pandigital hasillerin cemi: " << sum << std::endl;
    return 0;
}