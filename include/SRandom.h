#ifndef SRANDOM_H
#define SRANDOM_H
#include <random>

class SRandom
{
    public:
      static SRandom& getRandom();
      unsigned nextInt();
      int nextInt(int low, int high);
      int nextOddInt(int low ,int hight);

    private:
        SRandom(int t_seed);
        std::mt19937 mt;


};

#endif // SRANDOM_H
