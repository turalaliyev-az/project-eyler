#include <iostream>

// Kombinezon hesablamaq üçün sadələşdirilmiş yol
// C(n, k) = (n * (n-1) * ... * (n-k+1)) / k!
// Burada n=40, k=20.
// Biz C++ "unsigned long long" (64-bit) istifadə edəcəyik.
// Cavab təxminən 137 Milyarddır, bura rahat sığır.

unsigned long long lattice_paths(int n) {
    unsigned long long result = 1;
    // n x n qəfəs üçün bizə C(2n, n) lazımdır.
    // Yəni C(40, 20).
    
    // Alqoritmik Hiylə: Vurma və Bölməni paralel aparırıq ki, ədəd çox şişməsin
    for (int i = 1; i <= n; i++) {
        // Düstur: result = result * (n + i) / i
        // Məsələn: 21/1, sonra *22/2, sonra *23/3...
        
        result = result * (n + i) / i;
    }
    return result;
}

int main() {
    int gridSize = 20;
    std::cout << ">>> PROJECT EULER 15: LATTICE PATHS <<<" << std::endl;
    std::cout << "Grid: " << gridSize << "x" << gridSize << std::endl;
    std::cout << "Məntiq: Kombinatorika C(40, 20)" << std::endl;
    
    unsigned long long routes = lattice_paths(gridSize);
    
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "MÜMKÜN YOLLARIN SAYI: " << routes << std::endl;
    
    return 0;
}