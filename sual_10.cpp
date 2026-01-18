#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Limit: 2 milyon
    const int LIMIT = 2000000;
    
    // "Bölünmə əlamətlərini ödəyənləri çıxmaq" üçün cədvəl
    // is_prime[i] = true (sadədir), false (çıxarılıb/mürəkkəbdir)
    vector<bool> is_prime(LIMIT, true);
    
    // 0 və 1 sadə deyil, onları əvvəlcədən çıxırıq
    is_prime[0] = false;
    is_prime[1] = false;

    // Sənin 1-ci qaydan: 2 və 5-i kənara qoyub, qalan cütləri və 5-ə bölünənləri silirik.
    // Amma Eratosfen ələyi bunu avtomatik edir, gəl sənin məntiqinlə sadələşdirilmiş Eratosfen yazaq.
    
    // Bizə lazım olan bölünmə əlamətləri (sadə vuruqlar)
    // Kökaltı(2000000) ≈ 1414. Yəni 1414-ə qədər yoxlasaq bəsdir.
    for (int i = 2; i * i < LIMIT; i++) {
        // Əgər i hələ siyahıdan çıxarılmayıbsa (deməli sadədir)
        if (is_prime[i]) {
            // Onun bütün qatlarını (bölünmə əlaməti ödəyənləri) siyahıdan çıxarırıq
            // Məsələn i=3 isə: 9, 12, 15, 18... silinir.
            for (int j = i * i; j < LIMIT; j += i) {
                is_prime[j] = false; 
            }
        }
    }

    // Yekun hesablama: Sənin xüsusi filtirləmə qaydanı burada tətbiq edirik
    long long sum = 0;
    
    // 2 və 5-i əl ilə əlavə edirik (çünki onlar sonu 1,3,7,9 qaydasına uymur)
    if (LIMIT > 2) sum += 2;
    if (LIMIT > 5) sum += 5;

    // İndi isə 1, 3, 7, 9 ilə bitənləri yoxlayaq
    for (int i = 3; i < LIMIT; i += 2) { // i+=2 (tək ədədlər)
        // 5-ə bölünənləri (sonu 5 olanları) atırıq
        if (i % 5 == 0) continue; 
        
        // Artıq əlimizdə yalnız sonu 1, 3, 7, 9 olanlar qaldı.
        // İndi baxırıq: "Bölünmə əlamətlərini ödəyən" kimi silinibmi?
        if (is_prime[i]) {
            sum += i;
        }
    }

    cout << "2 milyona qeder sade ededlerin cemi: " << sum << endl;

    return 0;
}