#include <iomanip>
#include <iostream>
#include <vector>

// PARAMETRLƏR
const long long LIMIT = 1000000;
const long long START_CHECK = 500001; // Qayda 1: Yarısından aşağıya baxmırıq

// DÜZƏLİŞ: Sərhəd (Barrier) ləğv edildi.
// Artıq heç bir ədəd "çox böyüdü" deyə silinmir.
long long check_collatz_system(long long n) {
  long long length = 1;
  long long current = n;

  while (current != 1) {
    if (current % 2 == 0) {
      current /= 2;
    } else {
      current = 3 * current + 1;
    }
    length++;
  }
  return length;
}

int main() {
  // Qayda 2: Matrisin Yaradılması (5 Sətir: 1, 3, 5, 7, 9)
  std::vector<std::vector<long long>> matrix(5);
  long long total_candidates = 0;

  std::cout << ">>> SİSTEM BAŞLADILIR (SƏRHƏDSİZ REJİM)..." << std::endl;
  std::cout << "1. Mərhələ: Cütlər və Yarısından kiçiklər atılır..."
            << std::endl;

  // MATRİSİN DOLDURULMASI
  for (long long i = START_CHECK; i < LIMIT; i += 2) {
    int last_digit = i % 10;
    int row_index = (last_digit - 1) / 2;
    matrix[row_index].push_back(i);
    total_candidates++;
  }

  std::cout << "2. Mərhələ: " << total_candidates
            << " ədəd Matrisə yerləşdirildi." << std::endl;
  std::cout << "3. Mərhələ: Hesablama Başlayır...\n" << std::endl;

  long long global_winner_num = 0;
  long long global_winner_len = 0;

  std::cout << std::left << std::setw(10) << "QRUP" << std::setw(15)
            << "NAMİZƏD SAYI" << std::setw(15) << "LOCAL QALİB" << std::setw(15)
            << "UZUNLUQ" << std::endl;
  std::cout << "--------------------------------------------------------"
            << std::endl;

  // MATRİSİN İŞLƏNMƏSİ
  int endings[] = {1, 3, 5, 7, 9};

  for (int i = 0; i < 5; i++) {
    long long local_max_len = 0;
    long long local_winner = 0;

    for (long long num : matrix[i]) {
      long long len = check_collatz_system(num); // Artıq -1 qaytarmır

      if (len > local_max_len) {
        local_max_len = len;
        local_winner = num;
      }
    }

    // Hesabat
    std::cout << "Sonu " << endings[i] << "    " << std::setw(15)
              << matrix[i].size() << std::setw(15) << local_winner
              << std::setw(15) << local_max_len << std::endl;

    // Qlobal müqayisə
    if (local_max_len > global_winner_len) {
      global_winner_len = local_max_len;
      global_winner_num = local_winner;
    }
  }

  std::cout << "--------------------------------------------------------"
            << std::endl;
  std::cout << "\n>>> YEKUN HESABAT <<<" << std::endl;
  std::cout << "MÜTLƏQ QALİB: " << global_winner_num << std::endl;
  std::cout << "ZƏNCİR UZUNLUĞU: " << global_winner_len << std::endl;

  return 0;
}