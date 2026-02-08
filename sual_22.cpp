#include <iostream>
#include <fstream>  // Fayl oxumaq üçün
#include <vector>
#include <string>
#include <algorithm> // Sort üçün

// Parsing: Fayldan dırnaqları və vergülləri təmizləyib adları çıxarırıq
std::vector<std::string> load_names(const std::string& filename) {
    std::vector<std::string> names;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "XƏTA: names.txt faylı tapılmadı!" << std::endl;
        return names;
    }

    std::string content;
    // Bütün faylı tək bir sətir kimi oxuyaq (yaxud hissə-hissə)
    // Ən sadə yol: char-char oxuyub yığmaq
    char c;
    std::string current_name = "";
    
    while (file.get(c)) {
        if (c >= 'A' && c <= 'Z') {
            current_name += c; // Hərfdirsə, ada əlavə et
        } else if (c == ',' || c == '"') {
            // Ayrıcı simvol gəldi. Əgər ad yığılıbsa, siyahıya at.
            if (!current_name.empty()) {
                names.push_back(current_name);
                current_name = "";
            }
        }
    }
    // Sonuncu ad qalıbsa onu da əlavə et
    if (!current_name.empty()) {
        names.push_back(current_name);
    }
    
    return names;
}

int main() {
    std::cout << ">>> PROJECT EULER 22: NAMES SCORES <<<" << std::endl;
    
    // 1. MƏRHƏLƏ: Parse (Oxuma)
    std::vector<std::string> names = load_names("names.txt");
    std::cout << "Oxunan ad sayı: " << names.size() << std::endl;

    if (names.empty()) return 1;

    // 2. MƏRHƏLƏ: Sort (Əlifba sırası)
    // C++ std::sort lüğət (dictionary) məntiqi ilə mükəmməl işləyir
    std::sort(names.begin(), names.end());

    // 3. MƏRHƏLƏ: Hesablama (Score = Index * LetterSum)
    long long total_score = 0;

    for (int i = 0; i < names.size(); i++) {
        int word_value = 0;
        
        // Adın hərflərini cəmləyirik
        for (char c : names[i]) {
            word_value += (c - 'A' + 1); // 'A'(65) -> 1, 'B'(66) -> 2
        }

        // Sıra nömrəsi (Index 0-dan başlayır, ona görə +1 edirik)
        int position = i + 1;
        
        // Yekun cəmə əlavə edirik
        total_score += (long long)word_value * position;
    }

    std::cout << "----------------------------------------" << std::endl;
    std::cout << "YEKUN XAL CƏMİ: " << total_score << std::endl;

    // Doğrulama
    if (total_score == 871198282) {
        std::cout << "STATUS: ✅ DÜZGÜN CAVAB!" << std::endl;
    }

    return 0;
}