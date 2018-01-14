#include "SRandom.h"
#include <ctime>
#include <limits>

SRandom& SRandom::getRandom()
{
    static SRandom rand(time(0) % 255);
    return rand;
}
unsigned SRandom::nextInt()
{
    return nextInt(0,std::numeric_limits<int>::max());
}
int SRandom::nextInt(int low, int high)
{
    std::uniform_int_distribution<int> distribution(low,high);
    return distribution(mt) ;
}
int SRandom::nextOddInt(int low ,int high)
{
    std::uniform_int_distribution<int> distribution(low,high);
    int res = distribution(mt);
    while(res % 2 == 0)
        res = distribution(mt);
    return res;
}
SRandom::SRandom(int t_seed)
{
   mt.seed(t_seed);

}


