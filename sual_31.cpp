#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. Qüvvətləri saxlayan vektor (Lookup Table)
long long powers[10];
long long total_grand_sum = 0;
vector<long long> results;

// Ədədin rəqəmlərini tezlik massivinə çevirən köməkçi funksiya
void get_digit_counts(long long n, int counts[]) {
    for (int i = 0; i < 10; i++) counts[i] = 0;
    if (n == 0) { counts[0]++; return; }
    while (n > 0) {
        counts[n % 10]++;
        n /= 10;
    }
}

// 2. Rekursiv Kombinasiya Qurma (Sənin dediyin riyazi süzgəc)
void generateCombinations(int remaining_slots, int start_digit, long long current_sum, int combo_counts[]) {
    if (remaining_slots == 0) {
        if (current_sum < 2) return; // 1 daxil deyil

        // Alınan cəmin rəqəmlərini parçalayırıq
        int sum_counts[10];
        get_digit_counts(current_sum, sum_counts);

        // 3. Əsas Yoxlama: Cəmin rəqəmlərinin 5-ci dərəcəli cəmi özünə bərabərdirmi?
        long long check_val = 0;
        for (int i = 0; i < 10; i++) {
            check_val += (long long)sum_counts[i] * powers[i];
        }

        // Əgər cəm öz rəqəmlərinin 5-ci dərəcəli cəminə bərabərdirsə, bu axtardığımızdır!
        if (check_val == current_sum) {
            // Təkrar tapmamaq üçün yoxlayırıq
            if (find(results.begin(), results.end(), current_sum) == results.end()) {
                results.push_back(current_sum);
                total_grand_sum += current_sum;
            }
        }
        return;
    }

    // Təkrarlı kombinasiyalar qururuq
    for (int d = start_digit; d <= 9; d++) {
        combo_counts[d]++;
        generateCombinations(remaining_slots - 1, d, current_sum + powers[d], combo_counts);
        combo_counts[d]--;
    }
}

int main() {
    // 0-dan 9-a qədər 5-ci dərəcəli qüvvətləri vektora yığırıq
    for (int i = 0; i < 10; i++) {
        powers[i] = (long long)i * i * i * i * i;
    }

    int combo_counts[10] = {0};

    // Maksimum 6 rəqəmli kombinasiyaları yoxlayırıq (Çünki 7*9^5 hələ 6 rəqəmlidir)
    generateCombinations(6, 0, 0, combo_counts);

    // Nəticələri çap edirik
    cout << "Tapilan ededler: ";
    for (long long n : results) cout << n << " ";
    
    cout << "\n----------------------------" << endl;
    cout << "Butun uygun ededlerin cemi: " << total_grand_sum << endl;

    return 0;
}