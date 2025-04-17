#pragma once

//Lucas Sequence generator
class LucasSequence {
    private:
        unsigned i = 0, curr, prev, n0, n1;
    public:
        LucasSequence(unsigned n0, unsigned n1);
        unsigned next();
};