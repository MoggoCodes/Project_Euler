#include <iostream>
#include <stdexcept>
typedef unsigned long long ull;

bool checkFactorAndDivideOut(ull& n, ull d) {
    if (n % d != 0) return false;
    do {n /= d;} while (n % d == 0);
    return true;
}

ull largestPrimeFactor(ull n) {
    // Key: All primes (except 2 and 3) take the form of 6k + 1 or 6k - 1 for some natural number k
    // Furthermore, for any natural number k, there exists some prime p and natural number j such that 6k + 1 = jp. (Similar result holds for 6k - 1)
    // It follows that if we start checking primes at the bottom and dividing it out completely from n if it isa factor, any value of the form 6k +- 1 that divides n is prime
    //      (i.e. n = 8875 = 5^3 * 71^1)
    //      1. 5 divides 8875 -> n = 8875 / 5^3 = 71.
    //      2. k = 4, We check 6k + 1 = 25 (p = 5, j = 5). *Note that this is not a prime because j > 1*
    //          Since we divided 5 out we are checking if it is a divisor of 71 now.
    //          *This works because we are guaranteed to have already checked the k that results in p^1 so, p^j will not divide our new n even if checked later*.

    ull largestPrimeFactor;
    if (checkFactorAndDivideOut(n, 2)) largestPrimeFactor = 2;
    if (checkFactorAndDivideOut(n, 3)) largestPrimeFactor = 3;
    for (ull i = 5; i * i <= n; i += 6) {
        if (checkFactorAndDivideOut(n, i)) largestPrimeFactor = i;
        if (checkFactorAndDivideOut(n, i + 2)) largestPrimeFactor = i + 2;
    }

    if (n > 2) largestPrimeFactor = n;
    return largestPrimeFactor;
}

int main() {
    ull n;
    std::cout   << "This program outputs the largest prime factor of n\n"
                << "Please input the desired n: ", std::cin >> n;

    std::cout   << largestPrimeFactor(n) << std::endl;
    return 0;
}