#include <iostream>
#include <string>
#include <algorithm>

// İki böyük ədədin string üzərindən toplanması
std::string addStrings(const std::string& a, const std::string& b)
{
    std::string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int x = (i >= 0) ? a[i--] - '0' : 0;
        int y = (j >= 0) ? b[j--] - '0' : 0;

        int sum = x + y + carry;
        result.push_back((sum % 10) + '0');
        carry = sum / 10;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

// Fibonacci hesablayan funksiya
std::string fibonacci(int n)
{
    if (n == 0) return "0";
    if (n == 1) return "1";

    std::string a = "0";
    std::string b = "1";
    std::string c;

    for (int i = 2; i <= n; ++i)
    {
        c = addStrings(a, b);
        a = b;
        b = c;
    }
    return b;
}

int main()
{
    int n = 10001; // Fibonacci ədədi üçün indeks
    std::string fib = fibonacci(n);

    std::cout << "F(" << n << ") =\n";
    std::cout << fib << std::endl;

    std::cout << "\nRəqəm sayı: " << fib.size() << std::endl;
    return 0;
}
