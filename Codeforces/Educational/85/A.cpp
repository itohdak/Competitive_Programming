#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
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

void solve() {
  int N;
  cin >> N;
  vector<int> P(N), C(N);
  bool ok = true;
  rep(i, N) {
    cin >> P[i] >> C[i];
    if(P[i]<C[i]) ok = false;
    if(i) {
      if(P[i]-P[i-1]<0 || C[i]-C[i-1]<0) ok = false;
      else if(P[i]-P[i-1]<C[i]-C[i-1]) ok = false;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
