#include <iostream>
#include "LucasSequence.h"
typedef unsigned long long ull;

ull sumLucasMultiples(LucasSequence lucas, unsigned factor, unsigned maxVal) {
    ull multipleSum = 0;
    for (unsigned ni = lucas.next(); ni <= maxVal; ni = lucas.next()) {
        multipleSum += ni * (ni % factor == 0);
    }
    return multipleSum;
}

int main() {
    unsigned n0, n1, m, N;
    std::cout   << "This program will generate a Lucas Sequence (n0, n1, n2 = n0 + n1, n3 = n2 + n1, ...) and sum all ni such that m | ni and ni <= N.\n"
                << "Please enter the desired n0: ", std::cin >> n0;
    std::cout   << "Please enter the desired n1: ", std::cin >> n1;
    std::cout   << "Please enter the desired m: " , std::cin >> m ;
    std::cout   << "Please enter the desired N: " , std::cin >> N ;
    
    LucasSequence lucas(n0, n1);
    std::cout   << sumLucasMultiples(lucas, m, N) << std::endl;
    return 0;
}