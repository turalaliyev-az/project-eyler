#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

const int LIMIT = 1000000;
vector<bool> is_prime(LIMIT, true);

// 1. Eratosthen Süzgəci: 1 milyona qədər bütün sadə ədədləri tapırıq
void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p < LIMIT; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i < LIMIT; i += p)
                is_prime[i] = false;
        }
    }
}

// 2. Rəqəm Süzgəci: Daxilində 0, 2, 4, 5, 6, 8 olan çoxrəqəmli ədədləri atırıq
bool has_invalid_digits(int n) {
    if (n < 10) return false; // 2 və 5 tək rəqəmli halda keçərlidir
    while (n > 0) {
        int d = n % 10;
        if (d % 2 == 0 || d == 5 || d == 0) return true;
        n /= 10;
    }
    return false;
}

// 3. Rotasiya (Döndərmə) Funksiyası
int rotate(int n) {
    string s = to_string(n);
    rotate(s.begin(), s.begin() + 1, s.end());
    return stoi(s);
}

int main() {
    sieve();
    int circular_count = 0;

    for (int i = 2; i < LIMIT; i++) {
        if (!is_prime[i]) continue;

        // Sənin metodun: Əgər ədədin daxilində cüt rəqəm və ya 5 varsa, dairəvi ola bilməz
        if (i > 10 && has_invalid_digits(i)) continue;

        bool is_circular = true;
        int temp = i;
        int num_digits = to_string(i).length();

        // Bütün rotasiyaları yoxlayırıq
        for (int j = 0; j < num_digits - 1; j++) {
            temp = rotate(temp);
            if (!is_prime[temp]) {
                is_circular = false;
                break;
            }
        }

        if (is_circular) {
            circular_count++;
        }
    }

    cout << "1 milyondan kicik dairevi sade ededlerin sayi: " << circular_count << endl;

    return 0;
}