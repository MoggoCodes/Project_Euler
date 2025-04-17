#include "LucasSequence.h"

LucasSequence::LucasSequence(unsigned n0, unsigned n1) : n0(n0), n1(n1), curr(n0) {}

unsigned LucasSequence::next() {
    ++i;
    if (i >= 2) {
        curr += prev;
        prev = curr - prev;
    }
    else if (i == 1) {prev = n0, curr = n1;}
    return curr;
}