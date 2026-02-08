#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Faktorialları əvvəlcədən hesablayaq
long long fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
long long total_grand_sum = 0;
vector<long long> found_numbers;

// Ədədin rəqəmlərinin tezliyini (neçə dənə 0, 1, 2... var) hesablayan funksiya
void get_digit_counts(long long n, int counts[]) {
    for (int i = 0; i < 10; i++) counts[i] = 0;
    if (n == 0) { counts[0]++; return; }
    while (n > 0) {
        counts[n % 10]++;
        n /= 10;
    }
}

// 2. Kombinasiya Süzgəci (Rekursiv)
void solve(int remaining_digits, int start_digit, long long current_fact_sum, int current_combo[]) {
    if (remaining_digits == 0) {
        // Təkcə 1! və 2! daxil deyil
        if (current_fact_sum < 3) return;

        // Alınan cəmin rəqəmlərini yoxlayırıq
        int sum_counts[10];
        get_digit_counts(current_fact_sum, sum_counts);

        // Əsas Süzgəc: Cəmin faktorialları cəmi özünə bərabərdirmi?
        long long check_val = 0;
        for (int i = 0; i < 10; i++) {
            check_val += (long long)sum_counts[i] * fact[i];
        }

        if (check_val == current_fact_sum) {
            // Təkrar tapmamaq üçün (çünki sıfırlar fərqli kombinasiya yarada bilər)
            if (find(found_numbers.begin(), found_numbers.end(), current_fact_sum) == found_numbers.end()) {
                found_numbers.push_back(current_fact_sum);
                total_grand_sum += current_fact_sum;
            }
        }
        return;
    }

    for (int d = start_digit; d <= 9; d++) {
        current_combo[d]++;
        solve(remaining_digits - 1, d, current_fact_sum + fact[d], current_combo);
        current_combo[d]--;
    }
}

int main() {
    int combo[10] = {0};
    
    // 7 rəqəmli ədədlərə qədər yoxlayırıq (7*9! = 2.5 milyon)
    // Sənin metodun cəmi 11,440 kombinasiya yoxlayacaq
    solve(7, 0, 0, combo);

    cout << "Tapilan ededler: ";
    for (long long n : found_numbers) cout << n << " ";
    cout << "\n----------------------------" << endl;
    cout << "Butun ededlerin cemi: " << total_grand_sum << endl;

    return 0;
}