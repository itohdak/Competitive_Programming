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
  int n, m; cin >> n >> m;
  vector<ll> S(n-1); rep(i, n-1) cin >> S[i];
  vector<ll> X(m); rep(i, m) cin >> X[i];
  vector<ll> A(n);
  rep(i, n-1) A[i+1] = S[i]-A[i];
  map<ll, int> cnt1, cnt2;
  rep(i, n) {
    if(i%2 == 0) cnt1[A[i]]++;
    else         cnt2[A[i]]++;
  }
  int mx = 0;
  for(auto [k, _]: cnt1) {
    rep(i, m) {
      ll d = X[i]-k;
      int cnt = 0;
      rep(j, m) {
        if(cnt1.count(X[j]-d)) cnt += cnt1[X[j]-d];
        if(cnt2.count(X[j]+d)) cnt += cnt2[X[j]+d];
      }
      chmax(mx, cnt);
    }
  }
  for(auto [k, _]: cnt2) {
    rep(i, m) {
      ll d = k-X[i];
      int cnt = 0;
      rep(j, m) {
        if(cnt1.count(X[j]-d)) cnt += cnt1[X[j]-d];
        if(cnt2.count(X[j]+d)) cnt += cnt2[X[j]+d];
      }
      chmax(mx, cnt);
    }
  }
  cout << mx << endk;
  return 0;
}
