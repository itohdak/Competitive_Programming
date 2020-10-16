#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const double pi = 3.14159265358979;


double calc_length(int N) {
  double R = 1.0/(2*sin(pi/(2*N)));
  double angle = pi/(2*N);
  double tmp = 0.5;
  rep(i, (N-1)/2) {
    tmp += R*(sin(angle+pi/N)-sin(angle));
    angle += pi/N;
  }
  return 2*tmp;
}
bool test(double k, int N) {
  double l = calc_length(N);
  return l*cos(k-pi/(2*N)) > l*cos(k);
}
double binary_search(int N) {
  double ng = 0, ok = pi/N;
  while(abs(ok - ng) > 0.000000001) {
    double mid = (ok + ng) / 2;
    if(test(mid, N)) ok = mid;
    else ng = mid;
  }
  return calc_length(N)*cos(ok);
}
void solve() {
  int N;
  cin >> N;
  if(N%2) {
    cout << setprecision(10) << binary_search(N) << endl;
  } else {
    double R = 1.0/(2*sin(pi/(2*N)));
    double angle = pi/(2*N);
    double tmp = 0.5;
    rep(i, N/2-1) {
      tmp += R*(sin(angle+pi/N)-sin(angle));
      angle += pi/N;
    }
    cout << setprecision(10) << 2 * tmp << endl;
  }
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
