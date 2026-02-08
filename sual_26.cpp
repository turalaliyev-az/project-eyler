#include <iostream>
#include <vector>
#include <algorithm>

int get_cycle_length(int d) {
    // Qalıqların tarixçəsi
    // remainders[r] = r qalığının hansı addımda (mövqedə) çıxdığını saxlayır.
    // d < 1000 olduğu üçün, massiv ölçüsü 1000 bəs edir.
    std::vector<int> position(d, 0); 
    
    int numerator = 1;
    int pos = 1;

    while (numerator != 0) {
        // Qalığı tapırıq (Sütunlu bölmə məntiqi)
        numerator = (numerator % d) * 10;
        
        // Əgər qalıq 0 oldusa, deməli kəsr sonludur (dövr yoxdur)
        if (numerator == 0) return 0;

        // Əgər biz bu qalığı əvvəl görmüşüksə -> DÖVR TAPILDI!
        if (position[numerator % d] != 0) {
            // İndiki mövqedən, o qalığın əvvəlki mövqeyini çıxırıq
            return pos - position[numerator % d];
        }

        // Qalığı və mövqeyini yaddaşa yazırıq
        position[numerator % d] = pos;
        pos++;
    }
    return 0;
}

int main() {
    std::cout << ">>> PROJECT EULER 26: RECIPROCAL CYCLES <<<" << std::endl;
    std::cout << "Metod: Long Division Simulation (Qalıq İzləmə)" << std::endl;

    int max_length = 0;
    int number_with_max_cycle = 0;

    // 1000-dən aşağı doğru yoxlamaq daha məntiqlidir, 
    // çünki böyük dövrlər adətən böyük sadə ədədlərdə olur.
    for (int d = 999; d > 1; d--) {
        // Optimallaşdırma:
        // Əgər qalan ədədlər (d) tapdığımız max_length-dən kiçikdirsə,
        // onlardan daha uzun dövr çıxa bilməz (Maksimum dövr d-1 ola bilər).
        if (max_length >= d) break;

        int len = get_cycle_length(d);
        
        if (len > max_length) {
            max_length = len;
            number_with_max_cycle = d;
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Ən Uzun Dövrə Malik Ədəd: " << number_with_max_cycle << std::endl;
    std::cout << "Dövrün Uzunluğu: " << max_length << std::endl;
    
    // Doğrulama (Cavab 983 olmalıdır)
    if (number_with_max_cycle == 983) {
        std::cout << "STATUS: ✅ DÜZGÜN CAVAB!" << std::endl;
    }

    return 0;
}