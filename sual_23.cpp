#include <iostream>
#include <vector>

// Məsələnin şərtində verilən riyazi limit
const int LIMIT = 28123;

int main() {
    std::cout << ">>> PROJECT EULER 23: NON-ABUNDANT SUMS <<<" << std::endl;
    std::cout << "Strategiya: Sieve Method + Boolean Mapping" << std::endl;

    // 1. MƏRHƏLƏ: SİEVE (ƏLƏK) İLƏ BÖLƏNLƏRİN CƏMİ
    // Hər ədəd üçün bölənləri tək-tək axtarmaq əvəzinə, 
    // biz onları "səpələyirik" (daha sürətli).
    std::vector<int> sum_divisors(LIMIT + 1, 0);

    for (int i = 1; i <= LIMIT / 2; i++) {
        for (int j = 2 * i; j <= LIMIT; j += i) {
            sum_divisors[j] += i;
        }
    }

    // 2. MƏRHƏLƏ: BOL ƏDƏDLƏRİN (ABUNDANT) TƏYİNİ
    // Tərif: Bölənlərinin cəmi özündən böyük olanlar.
    std::vector<int> abundants;
    // Təxminən yaddaş ayırırıq (vector-un tez-tez resize olmaması üçün)
    abundants.reserve(7000); 

    for (int i = 1; i <= LIMIT; i++) {
        if (sum_divisors[i] > i) {
            abundants.push_back(i);
        }
    }

    std::cout << "Tapılan Bol Ədəd Sayı: " << abundants.size() << std::endl;

    // 3. MƏRHƏLƏ: BOOLEAN XƏRİTƏNİN QURULMASI
    // can_be_written[i] == true o deməkdir ki, i ədədi iki bol ədədin cəmidir.
    std::vector<bool> can_be_written(LIMIT + 1, false);

    // Bütün bol ədədləri cüt-cüt toplayırıq
    for (size_t i = 0; i < abundants.size(); i++) {
        for (size_t j = i; j < abundants.size(); j++) { // j=i (A+A ola bilər)
            int sum = abundants[i] + abundants[j];
            
            // Limitdən çıxsaq, daxili dövrü dayandırırıq (break)
            // Çünki abundants siyahısı artan ardıcıllıqdadır
            if (sum > LIMIT) break;
            
            can_be_written[sum] = true; // Bayraq sancırıq
        }
    }

    // 4. MƏRHƏLƏ: YAZILA BİLMƏYƏNLƏRİN CƏMİ (FİLTR)
    long long total_sum = 0;
    
    for (int i = 1; i <= LIMIT; i++) {
        // Əgər xəritədə işarələnməyibsə, deməli bu bizim axtardığımız ədəddir
        if (!can_be_written[i]) {
            total_sum += i;
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "YEKUN CAVAB: " << total_sum << std::endl;
    
    // Doğrulama
    if (total_sum == 4179871) {
        std::cout << "STATUS: ✅ DÜZGÜN CAVAB!" << std::endl;
    }

    return 0;
}