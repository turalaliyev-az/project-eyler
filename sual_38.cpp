#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// 1. Standart Sadə Ədəd Yoxlaması (Sənin sevdiyin sürətli metodla)
bool isPrime(long long n) {
    if (n < 2) return false;
    if (n < 4) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

// 2. Soldan Kəsilmə Süzgəci
bool isLeftTruncatable(long long n) {
    string s = to_string(n);
    for (size_t i = 1; i < s.length(); i++) {
        if (!isPrime(stoll(s.substr(i)))) return false;
    }
    return true;
}

int main() {
    // Sağdan kəsilə bilən sadə ədədləri yığmaq üçün "növbə" (Queue)
    vector<long long> rightTruncatable = {2, 3, 5, 7};
    vector<long long> results;
    int head = 0;

    // Sənin "İnşaat" məntiqin: Sadə ədədləri sonuna rəqəm artıraraq böyüdürük
    while (head < rightTruncatable.size()) {
        long long current = rightTruncatable[head++];
        
        int digits[] = {1, 3, 7, 9};
        for (int d : digits) {
            long long nextNum = current * 10 + d;
            if (isPrime(nextNum)) {
                rightTruncatable.push_back(nextNum);
                
                // Əgər həm də soldan kəsilə biləndirsə, nəticəyə əlavə et
                if (isLeftTruncatable(nextNum)) {
                    results.push_back(nextNum);
                }
            }
        }
    }

    long long sum = 0;
    cout << "Tapilan 11 eded: ";
    for (long long r : results) {
        cout << r << " ";
        sum += r;
    }

    cout << "\n----------------------------" << endl;
    cout << "Butun ededlerin cemi: " << sum << endl;

    return 0;
}