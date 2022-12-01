#include <tuple>
using namespace std;

template<class T>
tuple<T, T, T> extended_gcd(T a, T b) {
   if (!a) {
       return { b, 0, 1 };
   }

   auto [g, x, y] = extended_gcd(b % a, a);
   return { g, (y - (b / a) * x), x };
}
