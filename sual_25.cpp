#include <iostream>
#include <cmath> // log10, sqrt, ceil üçün

int main() {
    std::cout << ">>> PROJECT EULER 25: 1000-DIGIT FIBONACCI NUMBER <<<" << std::endl;
    std::cout << "Metod: Binet Düsturu və Loqarifma (Analitik Həll)" << std::endl;

    // 1. Sabitlər
    double phi = (1 + sqrt(5)) / 2; // Qızıl Nisbət (~1.618)
    double target_digits = 1000;
    
    // 2. Düsturun Tətbiqi
    // n = (Digits - 1 + log10(sqrt(5))) / log10(phi)
    // Digits - 1 ona görədir ki, 1000 rəqəmli ilk ədəd 10^999-dur.
    
    double term1 = target_digits - 1;
    double term2 = log10(sqrt(5));
    double denominator = log10(phi);
    
    double n = (term1 + term2) / denominator;
    
    // 3. Nəticə (Yuvarlaqlaşdırma)
    // n kəsr ədəd alınacaq (məsələn 4781.8), bizə növbəti tam ədəd lazımdır.
    int result = ceil(n);

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "FORMULA İLƏ HESABLANDI: " << n << std::endl;
    std::cout << "İNDEKS (CAVAB): " << result << std::endl;

    // Doğrulama (Cavab 4782 olmalıdır)
    if (result == 4782) {
        std::cout << "STATUS: ✅ DÜZGÜN CAVAB!" << std::endl;
    }

    return 0;
}