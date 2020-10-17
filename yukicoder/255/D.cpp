#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
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
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  ll a, b, c;
  cin >> a >> b >> c;
  pair<int, int> sign[] = {{1, -1}, {1, 1}, {-1, 1}, {-1, -1}};
  ll same = modpow(3, (n-2)/2);
  int pos = 2*(n-2)%3;
  pair<int, int> s = sign[(n-2)%4];
  vector<ll> coef(3);
  coef[pos] = (mod+s.first*same)%mod;
  coef[(pos+1)%3] = (mod+s.second*same)%mod;
  coef[(pos+2)%3] = (2*mod-coef[pos]-coef[(pos+1)%3])%mod;
  ll abc[] = {a, b, c, a, b, c};
  rep(i, 3) {
    ll ans = 0;
    rep(j, 3) {
      (ans += coef[j] * abc[i+j]) %= mod;
    }
    cout << ans << ' ';
  }
  cout << "\n";
  return 0;
}
