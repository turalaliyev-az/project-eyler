/*

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
  */


/*  

#include <iomanip>
#include <iostream>
#include <vector>

// PARAMETRLƏR
const unsigned long long LIMIT = 1000000;
const unsigned long long START_CHECK = 500001;

// SƏNİN TƏLƏBİN: Fibonacci Baryeri
// Lakin F(1000000) kainata sığmadığı üçün, biz C++ dilinin (64-bit)
// qəbul edə biləcəyi ƏN BÖYÜK Fibonacci ədədini götürürük: F(93).
// Dəyəri: 12,200,160,415,121,876,738 (12 Kvintilyon)
const unsigned long long MAX_FIBONACCI_BARRIER = 12200160415121876738ULL;

long long check_collatz_fibonacci(unsigned long long n) {
  long long length = 1;
  unsigned long long current = n;

  while (current != 1) {
    // FIBONACCI BARYERİ (F93)
    // Bu sərhəd "Hardware Limit"inə çox yaxındır.
    if (current > MAX_FIBONACCI_BARRIER) {
      return -1; // Baryeri keçdi, silinir.
    }

    if (current % 2 == 0) {
      current /= 2;
    } else {
      // Daşma (Overflow) yoxlanışı
      // Əgər ədəd o qədər böyükdür ki, 3-ə vuranda sistemi yandıracaq,
      // dayanırıq.
      if (current > (18446744073709551615ULL - 1) / 3)
        return -2;
      current = 3 * current + 1;
    }
    length++;
  }
  return length;
}

int main() {
  std::vector<std::vector<unsigned long long>> matrix(5);

  std::cout << ">>> SİSTEM: FIBONACCI HARWARE LIMIT (F93)" << std::endl;
  std::cout << ">>> BARYER DƏYƏRİ: " << MAX_FIBONACCI_BARRIER << "\n"
            << std::endl;

  // Matrisin doldurulması
  for (unsigned long long i = START_CHECK; i < LIMIT; i += 2) {
    int last_digit = i % 10;
    int row_index = (last_digit - 1) / 2;
    matrix[row_index].push_back(i);
  }

  std::cout << "QRUP             NAMİZƏD         QALİB           UZUNLUQ"
            << std::endl;
  std::cout << "--------------------------------------------------------"
            << std::endl;

  unsigned long long global_winner_num = 0;
  long long global_winner_len = 0;
  long long eliminated_count = 0;
  int endings[] = {1, 3, 5, 7, 9};

  for (int i = 0; i < 5; i++) {
    long long local_max_len = 0;
    unsigned long long local_winner = 0;

    for (unsigned long long num : matrix[i]) {
      long long len = check_collatz_fibonacci(num);

      if (len < 0) {
        eliminated_count++;
      } else {
        if (len > local_max_len) {
          local_max_len = len;
          local_winner = num;
        }
      }
    }

    std::cout << "Sonu " << endings[i] << "        " << std::left
              << std::setw(15) << matrix[i].size() << std::setw(15)
              << local_winner << std::setw(15) << local_max_len << std::endl;

    if (local_max_len > global_winner_len) {
      global_winner_len = local_max_len;
      global_winner_num = local_winner;
    }
  }

  std::cout << "--------------------------------------------------------"
            << std::endl;
  std::cout << "BARYERƏ DƏYİB SİLİNƏNLƏR: " << eliminated_count << std::endl;
  std::cout << "MÜTLƏQ QALİB: " << global_winner_num << std::endl;
  std::cout << "ZƏNCİR UZUNLUĞU: " << global_winner_len << std::endl;

  return 0;
}
  */



  #include <iostream>
#include <vector>
#include <iomanip>

// Daxili (Built-in) funksiya üçün
// Bu funksiya ədədin binary formasına baxır və sonundakı sıfırları sayır.
#define count_zeros(n) __builtin_ctzll(n) 

const unsigned long long LIMIT = 1000000;
const unsigned long long START_CHECK = 500001; 

// KOMPYUTER DOSTU KOLLATS (MAX OPTİMALLAŞDIRMA)
long long check_collatz_binary(unsigned long long n) {
    long long length = 1;
    unsigned long long current = n;

    while (current != 1) {
        // YENİLİK: Binary Analiz
        // Ədəd cütdürsə (sonu 0 ilə bitirsə)
        if ((current & 1) == 0) { 
            // Sənin metodun: Binary koda baxırıq
            // Məsələn: ...101000 (Sonda 3 sıfır var)
            int zeros = count_zeros(current); 
            
            // Həmin sıfırların sayı qədər sürüşdürürük (bir anda tullanırıq)
            current >>= zeros; 
            length += zeros;
        } 
        else {
            // Tək ədəddirsə: 3n + 1
            // (n << 1) + n + 1 əməliyyatı 3n+1 deməkdir.
            // Biz bilirik ki, nəticə cüt olacaq, ona görə dərhal 2-yə bölürük (>> 1)
            current = ((current << 1) + current + 1) >> 1;
            length += 2; // Həm 3n+1 etdik, həm də böldük -> 2 addım
        }
    }
    return length;
}

int main() {
    std::vector<std::vector<unsigned long long>> matrix(5);
    
    std::cout << ">>> SİSTEM: BITWISE & BINARY ANALYSIS (CPU NATIVE)" << std::endl;
    std::cout << ">>> Metod: __builtin_ctzll (Sondakı bitləri sayma)" << std::endl;
    
    // Matrisin doldurulması
    for (unsigned long long i = START_CHECK; i < LIMIT; i += 2) { 
        int last_digit = i % 10;
        int row_index = (last_digit - 1) / 2; 
        matrix[row_index].push_back(i);
    }

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "QRUP             NAMİZƏD         QALİB           UZUNLUQ" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    unsigned long long global_winner_num = 0;
    long long global_winner_len = 0;
    int endings[] = {1, 3, 5, 7, 9};

    for (int i = 0; i < 5; i++) {
        long long local_max_len = 0;
        unsigned long long local_winner = 0;
        
        for (unsigned long long num : matrix[i]) {
            long long len = check_collatz_binary(num);

            if (len > local_max_len) {
                local_max_len = len;
                local_winner = num;
            }
        }

        std::cout << "Sonu " << endings[i] << "        " 
                  << std::left << std::setw(15) << matrix[i].size() 
                  << std::setw(15) << local_winner 
                  << std::setw(15) << local_max_len << std::endl;

        if (local_max_len > global_winner_len) {
            global_winner_len = local_max_len;
            global_winner_num = local_winner;
        }
    }

    std::cout << "--------------------------------------------------------" << std::endl;
    std::cout << "MÜTLƏQ QALİB: " << global_winner_num << std::endl;
    std::cout << "ZƏNCİR UZUNLUĞU: " << global_winner_len << std::endl;
    
    // Yoxlama
    if (global_winner_num == 837799) std::cout << "STATUS: ✅ BINARY HESABLAMA UĞURLU!" << std::endl;
    
    return 0;
}