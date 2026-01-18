#include <iostream>

using namespace std;

int main() {
  //  a + b + c = 1000
    // a = hui, b = rty, c = jkl
    
    // a üçün dövr (təxminən 1000/3-ə qədər, çünki a ən kiçikdir)
    for (int a = 1; a < 333; a++) {
        
        // b üçün dövr (a-dan böyük olmalıdır)
        for (int b = a + 1; b < 1000; b++) {
            
            
            // Biz c-ni axtarmırıq, cəm 1000 olması üçün c məcburdur ki, belə olsun:
            int c = 1000 - a - b;
            
            
            // 1. a < b < c (a < b onsuz da dövrdə təmin edilib)
            if (b < c) {
                // 2. Pifaqor teoremi: a^2 + b^2 = c^2
                if (a * a + b * b == c * c) {
                    cout << "Tapildi!" << endl;
                    cout << "a = " << a << endl;
                    cout << "b = " << b << endl;
                    cout << "c = " << c << endl;
                    cout << "Hasil (abc): " << (long long)a * b * c << endl;
                    return 0; 
                }
            }
        }
    }
    return 0;
}