#include <iostream>
#include <vector>

// KONFİQURASİYA (Sənin Yöntəmin)
// 1. Base: 10^9 (Hər blokda 9 rəqəm saxlayırıq -> Yaddaş Sıxlaşdırma)
const unsigned long long BASE = 1000000000ULL; 

// 2. Addım sayı: 2^1000 hesablamaq üçün, 1000 dənə 2 yox, 
// 100 dənə "2^10" (yəni 1024) istifadə edirik.
const int ITERATIONS = 100; 

int main() {
    std::cout << ">>> PROJECT EULER 16: TURAL ALİYEV METODU <<<" << std::endl;
    std::cout << "Metod: Grouping (Base 10^9) + Bitwise Shift (<< 10)" << std::endl;
    
    // Massiv (BigInt) yaradılır. Başlanğıc: 1
    std::vector<unsigned long long> groups;
    groups.push_back(1);

    // ƏSAS HESABLAMA MÜHƏRRİKİ
    for (int i = 0; i < ITERATIONS; i++) {
        unsigned long long carry = 0; // Yadda qalan (Daşma)
        
        // Massivdəki hər bir bloku emal edirik
        for (int j = 0; j < groups.size(); j++) {
            // SƏNİN HİYLƏN: Vurma (*) yox, Sürüşdürmə (<<)
            // 1024-ə vurmaq elə 10 bit sola sürüşdürməkdir.
            // groups[j] * 1024 + carry
            unsigned long long current = (groups[j] << 10) + carry;
            
            // Cari bloku yeniləyirik (son 9 rəqəm)
            groups[j] = current % BASE;
            
            // Növbəti bloka keçəcək hissə (ilk rəqəmlər)
            carry = current / BASE;
        }
        
        // Əgər sona çatdıqdan sonra əlimizdə hələ də rəqəm qalıbsa,
        // yeni blok yaradılır (Array genişlənir)
        while (carry > 0) {
            groups.push_back(carry % BASE);
            carry /= BASE;
        }
    }

    // YEKUN: Rəqəmlərin Cəmi
    unsigned long long sum_digits = 0;
    
    // Hər blokun içindəki rəqəmləri tək-tək çıxarıb toplayırıq
    for (unsigned long long block : groups) {
        unsigned long long temp = block;
        while (temp > 0) {
            sum_digits += temp % 10;
            temp /= 10;
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Blok Sayı (RAM istifadəsi): " << groups.size() << " dənə 'unsigned long long'" << std::endl;
    std::cout << "RƏQƏMLƏRİN CƏMİ: " << sum_digits << std::endl;
    
    // Yoxlama
    if (sum_digits == 1366) {
        std::cout << "STATUS: ✅ DÜZGÜN CAVAB (Sistem mükəmməl işlədi)" << std::endl;
    } else {
        std::cout << "STATUS: ❌ XƏTA" << std::endl;
    }

    return 0;
}