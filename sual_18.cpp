#include <iostream>
#include <vector>
#include <algorithm> // std::max üçün

int main() {
    // Sənin verdiyin Piramida (15 Mərtəbə)
    std::vector<std::vector<int>> triangle = {
        {75},
        {95, 64},
        {17, 47, 82},
        {18, 35, 87, 10},
        {20, 4, 82, 47, 65},
        {19, 1, 23, 75, 3, 34},
        {88, 2, 77, 73, 7, 63, 67},
        {99, 65, 4, 28, 6, 16, 70, 92},
        {41, 41, 26, 56, 83, 40, 80, 70, 33},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
        {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
        {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}
    };

    std::cout << ">>> PROJECT EULER 18: REAL DATA TEST <<<" << std::endl;
    std::cout << "Alqoritm: Aşağıdan-Yuxarıya Sıxılma (Bottom-Up Collapsing)" << std::endl;

    // Alqoritm işə düşür
    // triangle.size() - 2 o deməkdir ki, ən sonuncu sətirdən (15-ci) yox, 
    // onun üstündəkindən (14-cü) başlayırıq.
    
    for (int i = triangle.size() - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            // SƏNİN MƏNTİQİN:
            // Cari ədəd = Özü + Aşağıdakı iki ədəddən ən böyüyü
            triangle[i][j] += std::max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "ZİRVƏDƏKİ MAKSİMUM CƏM: " << triangle[0][0] << std::endl;
    
    // Project Euler 18-in rəsmi cavabı 1074-dür.
    if (triangle[0][0] == 1074) {
        std::cout << "STATUS: ✅ DÜZGÜN CAVAB (1074)" << std::endl;
    } else {
        std::cout << "STATUS: ❌ XƏTA" << std::endl;
    }

    return 0;
}