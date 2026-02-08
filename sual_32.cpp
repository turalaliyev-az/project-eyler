#include <iostream>
#include <vector>

int main() {
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int target = 200;
    
    // Sənin dediyin "yolların cəmi" massivi
    std::vector<long long> ways(target + 1, 0);
    ways[0] = 1; // 0-ı düzəltməyin 1 yolu var

    for (int coin : coins) {
        // Bu hissə sənin "blokları" bir-birinin üzərinə yığır
        for (int i = coin; i <= target; i++) {
            ways[i] += ways[i - coin];
        }
    }

    std::cout << "200p ucun muxtelif usullarin sayi: " << ways[target] << std::endl;
    return 0;
}