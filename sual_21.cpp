#include <iostream>
#include <cmath> // sqrt üçün

// Sənin Məntiqin: Bölənlərin Cəmini Tapan Funksiya
int get_divisor_sum(int n) {
    if (n < 2) return 0;
    
    int sum = 1; // 1 hər ədədin bölənidir
    int limit = sqrt(n);

    // Mühəndis Hiyləsi: Yalnız kökaltına qədər yoxlayırıq
    // O(N) əvəzinə O(sqrt(N)) sürəti
    for (int i = 2; i <= limit; i++) {
        if (n % i == 0) {
            sum += i; // i böləndir
            
            // Əgər i ilə n/i eyni deyilsə (məsələn 5*5=25), digərini də əlavə et
            if (i != n / i) {
                sum += (n / i);
            }
        }
    }
    return sum;
}

int main() {
    std::cout << ">>> PROJECT EULER 21: SƏNİN ÜSULUN <<<" << std::endl;
    
    int total_sum = 0;
    int LIMIT = 10000;

    // Sənin Alqoritmin: a -> b -> a
    for (int a = 2; a < LIMIT; a++) {
        int b = get_divisor_sum(a);

        // Şərtlər:
        // 1. b != a (Məsələn 6 mükəmməl ədəddir, 6->6, bu dostluq deyil)
        // 2. b-nin bölənləri cəmi a-ya bərabərdirmi?
        if (b > a && b <= LIMIT) { // b > a yoxlayırıq ki, cütlüyü iki dəfə saymayaq
            int db = get_divisor_sum(b);
            
            if (db == a) {
                std::cout << "Tapıldı: " << a << " <--> " << b << std::endl;
                total_sum += a + b;
            }
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "DOST ƏDƏDLƏRİN CƏMİ: " << total_sum << std::endl;
    
    return 0;
}