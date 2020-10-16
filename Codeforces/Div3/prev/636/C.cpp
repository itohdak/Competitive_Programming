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
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  ll ans = 0;
  int flag = A[0]>0?1:0;
  ll tmp = -inf;
  rep(i, N) {
    if(flag != (A[i]>0?1:0)) {
      ans += tmp;
      tmp = A[i];
      flag = (A[i]>0?1:0);
    } else {
      tmp = max(A[i], tmp);
    }
    // cout << ans << ' ' << tmp << ' ' << flag << endl;
  }
  ans += tmp;
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
