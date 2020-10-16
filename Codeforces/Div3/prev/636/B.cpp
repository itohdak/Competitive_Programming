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
  if(N % 4 == 0) {
    cout << "YES" << endl;
    ll even=0, odd=0;
    rep(i, N/2) {
      cout << 2*(i+1) << ' ';
      even += 2*(i+1);
    }
    rep(i, N/2-1) {
      cout << 2*(i+1)-1 << ' ';
      odd += 2*(i+1)-1;
    }
    cout << even-odd << endl;
  } else {
    cout << "NO" << endl;
  }

}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
