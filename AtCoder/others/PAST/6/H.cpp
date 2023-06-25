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
  int n, m, k; ll q; cin >> n >> m >> k >> q;
  vector<ll> P0, P1;
  rep(i, n) {
    ll p; int t; cin >> p >> t;
    if(t == 0) {
      P0.push_back(p);
    } else {
      P1.push_back(p);
    }
  }
  sort(all(P0));
  sort(all(P1));
  int sz0 = P0.size(), sz1 = P1.size();
  vector<ll> sum0(sz0+1), sum1(sz1+1);
  rep(i, sz0) sum0[i+1] = sum0[i] + P0[i];
  rep(i, sz1) sum1[i+1] = sum1[i] + P1[i];
  ll ans = longinf;
  rep(i, m+1) { // how many to select from P0
    int j = m-i;
    if(sz0 < i || sz1 < j) continue;
    chmin(ans, sum0[i]+sum1[j]+(j+k-1)/k*q);
  }
  cout << ans << endk;
  return 0;
}
