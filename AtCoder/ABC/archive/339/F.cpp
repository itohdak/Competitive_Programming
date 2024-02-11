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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<int> mods = {mod, mod2, 1973024803};
  vector<vector<ll>> A(n);
  map<vector<ll>, int> mp;
  rep(i, n) {
    vector<ll> v;
    for(int m: mods) {
      ll pw = 1;
      ll a = 0;
      rrep(j, S[i].size()) {
        (a += 1LL * (S[i][j]-'0') * pw % m) %= m;
        (pw *= 10) %= m;
      }
      v.push_back(a);
    }
    mp[v]++;
    A[i] = v;
  }
  ll ans = 0;
  rep(i, n) rep(j, n) {
    auto ai = A[i];
    auto aj = A[j];
    vector<ll> v;
    rep(k, mods.size()) {
      v.push_back(ai[k] * aj[k] % mods[k]);
    }
    if(mp.count(v)) ans += mp[v];
  }
  cout << ans << endk;
  return 0;
}
