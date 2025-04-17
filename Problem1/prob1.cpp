#include <iostream>
typedef unsigned long long ull;

ull sumOfAllMultiples(unsigned max, std::vector<unsigned> factors) {
    ull sum = 0;
    for (unsigned i = 2; i < max; ++i) {
        for (unsigned factor : factors) {
            if (i % factor == 0) {sum += i; break;}
        }
    }
    return sum;
}

int main() {
    ull N; int n;
    std::cout   << "This program calculates the sum of all natural numbers <= N that are a multiple of at least one of {f1, f2, ..., fn}.\n"
                << "Please input the desired N: ", std::cin >> N;
    std::cout   << "Please input the number of divisors to check (n): " , std::cin >> n;

    std::vector<unsigned> divisors(n);
    for (unsigned i = 0; i < n; ++i) {
        unsigned divisor;
        std::cout   << "Please input divisor " << i + 1 << ": ", std::cin >> divisor;
        divisors[i] = divisor;
    }

    std::cout << sumOfAllMultiples(N, divisors) << std::endl << std::endl;
    
    return 0;
}