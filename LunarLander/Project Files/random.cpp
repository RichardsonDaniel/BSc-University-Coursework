#include<cstdlib>
#include<ctime>

double random(double min, double max){
static bool seeded=false;
   if(!seeded){
      srand((unsigned)time(NULL));
      seeded = true;
   }
   return (double)rand()/RAND_MAX * (max-min) + min;
}
