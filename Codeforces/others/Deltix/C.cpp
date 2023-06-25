#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

template<typename T>
vector<T> smallest_prime_factors(T n) {
  vector<T> spf(n + 1);
  for(int i=0; i<=n; i++) spf[i] = i;
  for(T i=2; i*i<=n; i++) {
    // 素数だったら
    if(spf[i] == i) {
      for(T j=i*i; j<=n; j+=i) {
        // iを持つ整数かつまだ素数が決まっていないなら
        if(spf[j] == j) {
          spf[j] = i;
        }
      }
    }
  }
  return spf;
}

template<typename T>
vector<T> factorization(T x, vector<T>& spf) {
  vector<T> ret;
  while(x != 1) {
    ret.push_back(spf[x]);
    x /= spf[x];
  }
  sort(ret.begin(), ret.end());
  return ret;
}

constexpr ll MAX = 1000000;
auto spf = smallest_prime_factors(MAX);
void solve() {
  int n, e; cin >> n >> e;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> B(e);
  ll ans = 0;
  rep(s, e) {
    vector<int> tmp;
    for(int i=s; i<n; i+=e) {
      auto p = factorization(A[i], spf);
      tmp.push_back(p.size());
    }
    int m = tmp.size();
    vector<int> cum(m+1);
    rep(i, m) cum[i+1] = cum[i] + tmp[i];
    // cout << tmp << endk;
    // cout << cum << endk;
    rep(i, m+1) {
      int r = upper_bound(all(cum), cum[i]+1) - begin(cum);
      int l = lower_bound(all(cum), cum[i]+1) - begin(cum);
      ans += max(0, (r-max(i+2, l)));
      // cout << i << ' ' << ans << endk;
    }
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
