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

void solve() {
  ll N, K;
  cin >> N >> K;
  if(N%2) {
    if(K%2) {
      if(K>N) cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        rep(i, K-1) cout << 1 << ' ';
        cout << N-(K-1) << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  } else {
    if(K%2) {
      if(2*K>N) cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        rep(i, K-1) cout << 2 << ' ';
        cout << N-2*(K-1) << endl;
      }
    } else {
      if(K>N) cout << "NO" << endl;
      else {
        cout << "YES" << endl;
        rep(i, K-1) cout << 1 << ' ';
        cout << N-(K-1) << endl;
      }
    }
  }
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
