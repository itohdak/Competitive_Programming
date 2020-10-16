#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
void solve() {
  ll n, p;
  cin >> n >> p;
  vector<ll> K(n);
  rep(i, n) cin >> K[i];
  if(p == 1) {
    cout << (n%2 ? 1 : 0) << endl;
  } else {
    sort(all(K), greater<ll>());
    ll sum = 0;
    rep(i, n) {
      if(sum == 0) {
        (sum += modpow(p, K[i])) %= mod;
      } else {
        ((sum += mod) -= modpow(p, K[i])) %= mod;
      }
    }
    cout << sum << endl;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
