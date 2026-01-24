#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// String toplama funksiyası (sənin yazdığın)
std::string addStrings(const std::string& a, const std::string& b) {
    if (a == "0") return b;
    if (b == "0") return a;
    std::string result;
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0) + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

// String vurma funksiyası (Matris üçün lazımdır)
std::string multiplyStrings(std::string num1, std::string num2) {
    if (num1 == "0" || num2 == "0") return "0";
    std::vector<int> res(num1.size() + num2.size(), 0);
    for (int i = num1.size() - 1; i >= 0; i--) {
        for (int j = num2.size() - 1; j >= 0; j--) {
            res[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            res[i + j] += res[i + j + 1] / 10;
            res[i + j + 1] %= 10;
        }
    }
    std::string s = "";
    int i = 0;
    while (i < res.size() && res[i] == 0) i++;
    while (i < res.size()) s.push_back(res[i++] + '0');
    return s;
}

// Matris vurma və Qızıl Nisbətə əsaslanan loqarifmik artım
struct Matrix {
    std::string mat[2][2];
};

Matrix multiply(Matrix A, Matrix B) {
    Matrix C;
    C.mat[0][0] = addStrings(multiplyStrings(A.mat[0][0], B.mat[0][0]), multiplyStrings(A.mat[0][1], B.mat[1][0]));
    C.mat[0][1] = addStrings(multiplyStrings(A.mat[0][0], B.mat[0][1]), multiplyStrings(A.mat[0][1], B.mat[1][1]));
    C.mat[1][0] = addStrings(multiplyStrings(A.mat[1][0], B.mat[0][0]), multiplyStrings(A.mat[1][1], B.mat[1][0]));
    C.mat[1][1] = addStrings(multiplyStrings(A.mat[1][0], B.mat[0][1]), multiplyStrings(A.mat[1][1], B.mat[1][1]));
    return C;
}

std::string fastFibonacci(int n) {
    if (n == 0) return "0";
    if (n == 1) return "1";

    Matrix res = {{{ "1", "0" }, { "0", "1" }}};
    Matrix T = {{{ "1", "1" }, { "1", "0" }}};

    while (n > 0) {
        if (n % 2 == 1) res = multiply(res, T);
        T = multiply(T, T);
        n /= 2;
    }
    return res.mat[0][1];
}

int main() {
    int n = 10001;
    std::string fib = fastFibonacci(n);
    std::cout << "F(" << n << ") rəqəm sayı: " << fib.size() << std::endl;
    // Çox uzun olduğu üçün son 50 rəqəmi göstərək:
    std::cout << "Nəticənin sonu: ..." << fib.substr(fib.size() - 50) << std::endl;
    return 0;
}