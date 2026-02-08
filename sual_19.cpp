//Zeller dusturu 
#include <iostream>

// Zeller Alqoritmi: Tarixi ver, günü al.
// 0 = Şənbə, 1 = Bazar, 2 = Bazar ertəsi ... 
int zeller_day_of_week(int day, int month, int year) {
    // Zeller qaydası: Yanvar (1) və Fevral (2) 
    // keçmiş ilin 13 və 14-cü ayları kimi hesablanır.
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    int K = year % 100; // İlin son iki rəqəmi (məsələn 99)
    int J = year / 100; // Əsr (məsələn 19)

    // Düsturun C++ tətbiqi
    int h = (day + (13 * (month + 1)) / 5 + K + (K / 4) + (J / 4) + (5 * J)) % 7;
    
    return h;
}

int main() {
    std::cout << ">>> PROJECT EULER 19: COUNTING SUNDAYS <<<" << std::endl;
    std::cout << "Metod: Zeller Konqruensiyası (Riyazi Düstur)" << std::endl;

    int sunday_count = 0;

    // Şərt: 1 Yanvar 1901-dən 31 Dekabr 2000-ə qədər
    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            // Hər ayın 1-ci günü yoxlanılır
            int day_of_week = zeller_day_of_week(1, month, year);
            
            // Zellerdə 1 = Bazar günü (Sunday)
            if (day_of_week == 1) {
                sunday_count++;
            }
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "AYIN 1-nə DÜŞƏN BAZAR GÜNLƏRİ: " << sunday_count << std::endl;
    
    // Doğrulama (Cavab 171 olmalıdır)
    if (sunday_count == 171) std::cout << "STATUS: ✅ DÜZGÜN CAVAB!" << std::endl;

    return 0;
}