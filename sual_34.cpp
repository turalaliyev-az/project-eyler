#include <iostream>
#include <numeric> // std::gcd üçün

using namespace std;

// Ən böyük ortaq böləni tapmaq üçün funksiya (ixtisar üçün)
int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int final_num = 1;
    int final_den = 1;

    cout << "Tapilan qeyri-trivial kesrler:" << endl;

    // n: surətin qalan rəqəmi
    // d: məxrəcin qalan rəqəmi
    // i: ixtisar olunan (silinən) ortaq rəqəm
    for (int i = 1; i <= 9; i++) {
        for (int n = 1; n <= 9; n++) {
            for (int d = 1; d <= 9; d++) {
                
                // 1. Kəsr 1-dən kiçik olmalıdır: (10n+i) < (10i+d)
                // 2. Sənin dediyin "9nd" süzgəc şərti: i * (10*n - d) == 9 * n * d
                // Qeyd: Bu tənlik surətin sonu ilə məxrəcin əvvəlinin eyni olduğu hal üçündür.
                
                if (n < d && i * (10 * n - d) == 9 * n * d) {
                    int num = 10 * n + i;
                    int den = 10 * i + d;
                    
                    cout << num << "/" << den << " = " << n << "/" << d << endl;
                    
                    final_num *= n;
                    final_den *= d;
                }
            }
        }
    }

    // 4 kəsrin hasilini ixtisar edirik
    int common = gcd(final_num, final_den);
    int simplified_den = final_den / common;

    cout << "----------------------------" << endl;
    cout << "Hasili: " << final_num / common << "/" << simplified_den << endl;
    cout << "Cavab (mexrec): " << simplified_den << endl;

    return 0;
}
