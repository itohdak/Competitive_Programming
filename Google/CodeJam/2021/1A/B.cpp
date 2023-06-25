#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void prime_factorization(ll N, map<ll, int>& res) {
  if(N == 1 || N == 0) return;
  ll n = N;
  ll i = 2;
  while(n >= i * i) {
    while(n % i == 0) {
      if(res.count(i)) res[i]++;
      else res[i] = 1;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
  }
  if(n != 1) res[n]++;
}
void solve() {
  int m; cin >> m;
  ll S = 0, N = 0;
  map<ll, int> mp;
  rep(i, m) {
    int p; ll n; cin >> p >> n;
    S += p * n;
    N += n;
    mp[p] = n;
  }
  if(N > 100) {
    cout << 0 << endk;
    return;
  }
  for(ll i=S; i>=2; i--) {
    map<ll, int> res;
    prime_factorization(i, res);
    bool ok = true;
    ll sum = 0;
    for(auto [p, c]: res) {
      if(!mp.count(p) || mp[p] < c) {
        ok = false;
        break;
      }
      sum += p * c;
    }
    if(ok && i+sum == S) {
      cout << i << endk;
      return;
    }
  }
  cout << 0 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t; cin >> t;
  rep(i, t) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
