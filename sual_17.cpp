#include <iostream>

// LOOKUP TABLES (Məlumat Bazası)
// Bizə söz lazım deyil, sözün uzunluğu lazımdır.

// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
// (0 boşdur, çünki "sıfır" deyilmir)
int units[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};

// 10, 11, 12, 13, 14, 15, 16, 17, 18, 19
int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

// 20, 30, 40, 50, 60, 70, 80, 90
// (Index 0 və 1 boşdur, rahatlıq üçün 2-dən başlayırıq)
int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

// Sabitlər
const int HUNDRED = 7;  // "hundred"
const int AND = 3;      // "and"
const int THOUSAND = 8; // "thousand" ("one" ayrıca gəlir)

// PARSER FUNKSİYASI
int get_letter_count(int n) {
  int count = 0;

  // 1. Minlik (1000)
  if (n == 1000) {
    return units[1] + THOUSAND; // "one" + "thousand"
  }

  // 2. Yüzlüklər
  if (n >= 100) {
    count += units[n / 100]; // Məsələn: "three"
    count += HUNDRED;        // "hundred"

    // "AND" qaydası: Əgər tam yüzlük deyilsə (məsələn 300 yox, 342)
    if (n % 100 != 0) {
      count += AND;
    }
  }

  // 3. Son iki rəqəmin analizi (Qalıq)
  int remainder = n % 100;

  if (remainder > 0) {
    if (remainder < 10) {
      // 1-9
      count += units[remainder];
    } else if (remainder < 20) {
      // 10-19 (Xüsusi hal)
      count += teens[remainder - 10];
    } else {
      // 20-99
      count += tens[remainder / 10];  // Onluq (məsələn "forty")
      count += units[remainder % 10]; // Təklik (məsələn "two")
    }
  }

  return count;
}

int main() {
  std::cout << ">>> PROJECT EULER 17: NUMBER LETTER COUNTS <<<" << std::endl;
  std::cout << "Metod: Lookup Tables & Mathematical Parsing" << std::endl;

  long long total_letters = 0;

  // 1-dən 1000-ə qədər hamısını cəmləyirik
  for (int i = 1; i <= 1000; i++) {
    total_letters += get_letter_count(i);
  }

  std::cout << "----------------------------------------" << std::endl;
  std::cout << "YEKUN HƏRF SAYI: " << total_letters << std::endl;

  // Doğrulama (Məlum cavab: 21124)
  if (total_letters == 21124)
    std::cout << "STATUS: ✅ DÜZGÜN CAVAB!" << std::endl;
  else
    std::cout << "STATUS: ❌ SƏHV!" << std::endl;

  return 0;
}