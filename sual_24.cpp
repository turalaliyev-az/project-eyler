#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::cout << ">>> PROJECT EULER 24: LEXICOGRAPHIC PERMUTATIONS <<<" << std::endl;
    std::cout << "Metod: Factorial Number System (Riyazi Koordinat)" << std::endl;

    // 1. HAZIRLIQ
    // Rəqəmlər siyahısı: {0, 1, 2, ... 9}
    std::vector<int> numbers;
    for (int i = 0; i <= 9; i++) numbers.push_back(i);

    // Hədəf: 1 milyonuncu (İndeks: 999999)
    int target = 1000000 - 1;
    
    // Nəticəni yığacağımız yer
    std::string result = "";

    // Faktorialları əvvəlcədən hesablayaq (9!, 8!, ... 0!)
    // 0! = 1 qəbul edilir
    int factorial[10];
    factorial[0] = 1;
    for (int i = 1; i < 10; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    // 2. HESABLAMA MÜHƏRRİKİ
    // 9! (ən böyük blok) -dan başlayıb aşağı düşürük
    // N = 10 rəqəm var, deməli faktoriallar 9!-dan başlayacaq.
    for (int i = 9; i >= 0; i--) {
        // Hansı blokdayıq? (Tam bölmə)
        int index = target / factorial[i];
        
        // Qalıq nə qədərdir? (Növbəti addım üçün)
        target = target % factorial[i];

        // Seçilən rəqəmi nəticəyə əlavə et
        result += std::to_string(numbers[index]);

        // ƏN VACİB MƏQAM: İstifad olunan rəqəmi siyahıdan silirik!
        // Çünki permutasiyada eyni rəqəm təkrar ola bilməz.
        numbers.erase(numbers.begin() + index);
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "1,000,000-cu PERMUTASİYA: " << result << std::endl;
    
    // Doğrulama (Cavab: 2783915460 olmalıdır)
    if (result == "2783915460") {
        std::cout << "STATUS: ✅ DÜZGÜN CAVAB!" << std::endl;
    }

    return 0;
}