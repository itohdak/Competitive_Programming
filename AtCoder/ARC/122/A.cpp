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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<ll>> cum(n+1, vector<ll>(2));
  vector<vector<ll>> cnt(n+1, vector<ll>(2));
  rep(i, n) {
    if(i == 0) {
      cnt[i+1][0]++;
      cum[i+1][0] += A[i];
    } else {
      (cnt[i+1][0] += cnt[i][0] + cnt[i][1]) %= mod;
      (cnt[i+1][1] += cnt[i][0]) %= mod;
      (cum[i+1][0] += cum[i][0] + A[i] * cnt[i][0]) %= mod;
      (cum[i+1][0] += cum[i][1] + A[i] * cnt[i][1]) %= mod;
      (cum[i+1][1] += cum[i][0] - A[i] * cnt[i][0]) %= mod;
    }
  }
  cout << (cum[n][0] + cum[n][1] + mod) % mod << endk;
  return 0;
}