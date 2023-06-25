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

ll prime_factorization(ll N) {
  // cout << N << endk;
  if(N == 0) return 0;
  else if(N == 1) return 1;
  ll n = N;
  ll i = 2;
  ll ret = 1;
  while(n >= i * i) {
    ll tmp = 0;
    while(n % i == 0) {
      tmp ^= i;
      n /= i;
    }
    if(i == 2) i++;
    else i += 2;
    ret *= (tmp == 0 ? 1 : tmp);
  }
  if(n != 1) ret *= n;
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  vector<ll> P(n);
  rep(i, n) {
    if(A[i] == 0) {
      P[i] = 0;
    } else {
      ll p = prime_factorization(abs(A[i]));
      P[i] = (A[i] < 0 ? -1 : 1) * p;
    }
  }
  vector<ll> Pcopy(n);
  copy(all(P), begin(Pcopy));
  sort(all(Pcopy));
  Pcopy.erase(unique(all(Pcopy)), end(Pcopy));
  vector<int> Pcomp(n);
  rep(i, n) Pcomp[i] = lower_bound(all(Pcopy), P[i]) - begin(Pcopy);
  // cout << P << endk;
  // cout << Pcomp << endk;
  int zero = lower_bound(all(Pcopy), 0) - begin(Pcopy);
  if(zero == Pcopy.size() || Pcopy[zero] != 0) zero = -1;
  vector<int> ans(n+1);
  rep(i, n) {
    vector<int> cnt(n);
    int cnt_distinct = 0;
    REP(j, i, n) {
      if(Pcomp[j] != zero) {
        cnt[Pcomp[j]]++;
        if(cnt[Pcomp[j]] == 1) cnt_distinct++;
      }
      ans[max(1, cnt_distinct)]++;
    }
  }
  rep(i, n+1) if(i) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
