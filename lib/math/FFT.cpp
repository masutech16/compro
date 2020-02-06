#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

vector<complex<double>> fft(vector<complex<double>> a, bool inverse = false) {
  int n = a.size();
  int h = 0; // 高さ
  for (int i = 0; (1 << i) < n; i++) {
    h++;
  }

  // bit reverseしてfftする前の配列の並びをいい感じにする
  for (int i = 0; i < n; i++) {
    int j = 0;
    for (int k = 0; k < h; k++)
      j |= (i >> k & 1) << (h - 1 - k);
    if (i < j)
      swap(a[i], a[j]);
  }

  // b: ブロックサイズの半分
  for (int b = 1; b < n; b *= 2) {
    for (int j = 0; j < b; j++) {
      complex<double> w =
          polar(1.0, -(2 * M_PI) / (2 * b) * j * (inverse ? 1 : -1));
      for (int k = 0; k < n; k += b * 2) {
        complex<double> s = a[j + k];
        complex<double> t = a[j + k + b] * w;
        a[j + k] = s + t;
        a[j + k + b] = s - t;
      }
    }
  }
  if (inverse)
    REP(i, n) { a[i] /= n; }
  return a;
}

vector<complex<double>> fft(vector<double> a, bool inverse = false) {
  vector<complex<double>> a_complex(a.size());
  REP(i, a.size()) a_complex[i] = complex<double>(a[i], 0);
  return fft(a_complex, inverse);
}

vector<double> convolve(vector<double> a, vector<double> b) {
  int s = a.size() + b.size() - 1;
  int t = 1;
  while (t < s)
    t *= 2;
  a.resize(t);
  b.resize(t);
  vector<complex<double>> A = fft(a);
  vector<complex<double>> B = fft(b);
  for (int i = 0; i < t; i++) {
    A[i] *= B[i];
  }
  A = fft(A, true);
  a.resize(s);
  for (int i = 0; i < s; i++)
    a[i] = A[i].real();
  return a;
}

// verify: AtCoder Typical Contest 001 - C
int main() {
  int n;
  cin >> n;
  vector<double> a(n + 1, 0), b(n + 1, 0);
  REP(i, n) { cin >> a[i + 1] >> b[i + 1]; }
  auto c = convolve(a, b);

  FOR(i, 1, 2 * n + 1) { cout << (int)(c[i] + 0.5) << endl; }
}
