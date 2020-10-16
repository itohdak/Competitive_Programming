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

bool test(ll t, ll n) {
  return 3*t*(t+1)/2 - t <= n;
}
ll binary_search(ll n) {
  ll ng = sqrt(n)+1, ok = 0;
  while(abs(ok - ng) > 1) {
    ll mid = (ok + ng) / 2;
    if(test(mid, n)) ok = mid;
    else ng = mid;
  }
  // return ok;
  return 3*ok*(ok+1)/2 - ok;
}

void solve() {
  ll N;
  cin >> N;
  ll cnt = 0;
  while(N >= 2) {
    N -= binary_search(N);
    cnt++;
  }
  cout << cnt << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
