#ifndef COMPRO_EXTGCD
#define COMPRO_EXTGCD

// a*x + b*y = gcd(a,b) を解く。返り値はgcd(a,b)でx,yに解が代入されている
template <class T> T extgcd(T a, T b, T &x, T &y) {
  T g = a;
  if (b != T(0)) {
    g = extgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = T(1);
    y = T(0);
  }
  return g;
}
#endif
