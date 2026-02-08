#include <iostream>
#include <vector>
#include <iomanip>
#include <map>

// 1. MƏRHƏLƏ: YADDAŞ SİSTEMİ (Sənin Qruplaşdırma Metodun)
// Hər blokda 9 rəqəm saxlayırıq. 
// Bu, 158 rəqəmli ədədi cəmi 18 kiçik blokda saxlamağa imkan verir.
const unsigned long long BASE = 1000000000ULL;

// Bu funksiya "Vurma" əməliyyatını yerinə yetirir
// Sənin dediyin kimi: Ədədi 'multiplier' qədər öz üzərinə gəlir.
void multiply_vector(std::vector<unsigned long long>& groups, int multiplier) {
    unsigned long long carry = 0;
    
    for (int i = 0; i < groups.size(); i++) {
        // Blok * vuruq + yadda qalan
        unsigned long long current = groups[i] * multiplier + carry;
        
        groups[i] = current % BASE; // Qalıq blokda qalır
        carry = current / BASE;     // Daşma irəli gedir
    }
    
    // Əgər daşma varsa, yeni blok yaradılır
    while (carry > 0) {
        groups.push_back(carry % BASE);
        carry /= BASE;
    }
}

// 2. MƏRHƏLƏ: LEGENDRE DÜSTURU (Analiz)
// n! içində p sadə vuruğundan neçə dənə olduğunu tapır
int get_prime_count(int n, int p) {
    int count = 0;
    while (n > 0) {
        count += n / p;
        n /= p;
    }
    return count;
}

int main() {
    std::cout << ">>> PROJECT EULER 20: TURAL'S ALGORITHM <<<" << std::endl;
    std::cout << "Metod: Prime Decomposition + Block Arithmetic" << std::endl;

    int target = 100;
    std::vector<unsigned long long> big_number;
    big_number.push_back(1); // Başlanğıc: 1

    // 2-dən 100-ə qədər olan SADƏ ədədləri tapırıq
    // Və onların qüvvətlərini hesablayıb, dərhal işə salırıq.
    
    std::vector<int> primes;
    std::vector<bool> is_prime(target + 1, true);
    
    for (int p = 2; p <= target; p++) {
        if (is_prime[p]) {
            // Sadə ədədi tapdıq, indi digərlərini silək (Sieve)
            for (int i = p * p; i <= target; i += p)
                is_prime[i] = false;

            // 3. MƏRHƏLƏ: SİNTEZ
            // Bu sadə ədəd (p) 100!-in tərkibində neçə dəfə iştirak edir?
            int count = get_prime_count(target, p);
            
            // Həmin say qədər BigInt-i bu ədədə vururuq
            // Məsələn: 2-ni 97 dəfə, 5-i 24 dəfə...
            for (int k = 0; k < count; k++) {
                multiply_vector(big_number, p);
            }
        }
    }

    // 4. MƏRHƏLƏ: NƏTİCƏ
    unsigned long long sum_digits = 0;
    
    // Blokları gəzib rəqəmləri toplayırıq
    for (unsigned long long block : big_number) {
        unsigned long long temp = block;
        while (temp > 0) {
            sum_digits += temp % 10;
            temp /= 10;
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Blok Sayı: " << big_number.size() << std::endl;
    std::cout << "RƏQƏMLƏRİN CƏMİ: " << sum_digits << std::endl;

    if (sum_digits == 648) {
        std::cout << "STATUS: ✅ MƏSƏLƏ HƏLL EDİLDİ!" << std::endl;
    }

    return 0;
}