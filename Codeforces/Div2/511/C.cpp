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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  bool allsame = true;
  ll g = A[0];
  rep(i, n) {
    if(A[i] != A[0]) allsame = false;
    g = __gcd(g, A[i]);
  }
  if(allsame) {
    cout << -1 << endk;
    return 0;
  }
  rep(i, n) A[i] /= g;
  constexpr ll MAX = 15000005;
  auto spf = smallest_prime_factors(MAX);
  map<ll, int> cnt;
  rep(i, n) {
    auto ret = factorization(A[i], spf);
    set<ll> st;
    for(auto p: ret) st.insert(p);
    for(auto p: st) cnt[p]++;
  }
  int ans = n-1;
  for(auto ele: cnt) {
    chmin(ans, n-ele.second);
  }
  cout << ans << endk;
  return 0;
}
