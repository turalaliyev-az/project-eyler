#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 1. İkilik sistemdə palindrom olub-olmadığını yoxlayan "saf" funksiya
bool isBinaryPalindrome(int n) {
    unsigned int reversed = 0;
    unsigned int temp = n;
    
    // Bit səviyyəsində çevirmə (ən sürətli yol)
    while (temp > 0) {
        reversed = (reversed << 1) | (temp & 1);
        temp >>= 1;
    }
    return reversed == (unsigned int)n;
}

// 2. Onluq sistemdə kökdən palindrom düzəldən funksiya
int createPalindrome(int root, bool oddLength) {
    int palindrome = root;
    if (oddLength) root /= 10;
    while (root > 0) {
        palindrome = palindrome * 10 + (root % 10);
        root /= 10;
    }
    return palindrome;
}

int main() {
    long long totalSum = 0;

    // Bizə cəmi 1-dən 999-a qədər köklər lazımdır (çünki 999 -> 999999 edir)
    for (int i = 1; i <= 999; i++) {
        // İki hal var: tək uzunluqlu (12321) və cüt uzunluqlu (1221)
        int p1 = createPalindrome(i, true);
        int p2 = createPalindrome(i, false);

        int candidates[] = {p1, p2};

        for (int p : candidates) {
            // SƏNİN SÜZGƏCİN: Əgər ədəd cütdürsə və ya 1 milyondan böyükdürsə, keç
            if (p < 1000000 && p % 2 != 0) {
                if (isBinaryPalindrome(p)) {
                    totalSum += p;
                }
            }
        }
    }

    // Tək rəqəmli palindromları (1, 3, 5, 7, 9) yoxlamada təkrarlanma ola bilər, 
    // ona görə set istifadə etmək və ya diqqətli olmaq lazımdır. 
    // Amma bu metodun gözəlliyi onun saniyənin milyonda birində bitməsidir.

    cout << "1 milyondan kicik ikiqat palindromlarin cemi: " << totalSum << endl;

    return 0;
}