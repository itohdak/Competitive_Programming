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
  int n; cin >> n;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  int q; cin >> q;
  vector<ll> W(q); rep(i, q) cin >> W[i];
  vector<ll> B(n, 1);
  map<ll, int> cnt;
  rep(i, n) {
    map<ll, int> res;
    prime_factorization(A[i], res);
    // cout << res << endk;
    for(auto ele: res) {
      if(ele.second%2) B[i] *= ele.first;
    }
    cnt[B[i]]++;
  }
  // cout << B << endk;
  for(ll w: W) {
    // cout << cnt << endk;
    rep(i, min(w, (ll)2)) {
      map<ll, int> next;
      for(auto ele: cnt) {
        if(ele.second%2) {
          next[ele.first] += ele.second;
        } else {
          next[1] += ele.second;
        }
      }
      cnt = next;
      // cout << cnt << endk;
    }
    int ans = 0;
    for(auto ele: cnt) chmax(ans, ele.second);
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
