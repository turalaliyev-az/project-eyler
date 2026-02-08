#include <iostream>

int main() {
    int limit = 1001;
    long long total_sum = 1; // Mərkəzdəki "1" ilə başlayırıq

    for (int n = 3; n <= limit; n += 2) {
        // n*n hər zaman sağ üst küncdür (məs: 9, 25, 49, 81...)
        long long c1 = (long long)n * n
        int step = n - 1;

        long long c2 = c1 - step;         // Sol üst 
        // n*n hər zaman sağ üst küncdür (məs: 9, 25, 49, 81...)
        long long c1 = (long long)n * n; künc
        long long c3 = c2 - step;         // Sol alt künc
        long long c4 = c3 - step;         // Sağ alt künc

        
        // Ən böyük və ən kiçik küncün cəmi, digər iki küncün cəminə bərabər olmalıdır.
        // Məsələn n=9 üçün: (81 + 57) == (73 + 65) -> 138 == 138
        if ((c1 + c4) == (c2 + c3)) {
            total_sum += (c1 + c2 + c3 + c4);
        }
    }

    std::cout << "1001x1001 spirali ucun netice: " << total_sum << std::endl;

    return 0;
}