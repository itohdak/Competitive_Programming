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
  int n, s; cin >> n >> s;
  vector<int> D(n); rep(i, n) cin >> D[i];
  ll lb = 0, ub = 0;
  vector<ll> pw10(10);
  pw10[0] = 1;
  rep(i, 10) if(i) pw10[i] = pw10[i-1]*10;
  vector<ll> ans(n);
  rep(i, n) {
    lb += pw10[D[i]-1];
    ub += pw10[D[i]]-1;
    ans[i] = pw10[D[i]-1];
  }
  if(s < lb || ub < s) {
    cout << -1 << endk;
    return 0;
  }
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return D[i] > D[j];
  });
  ll rem = s - lb;
  for(int i: id) {
    if(rem == 0) continue;
    ll avail = pw10[D[i]]-1-pw10[D[i-1]];
    if(rem >= avail) {
      ans[i] += avail;
      rem -= avail;
    } else {
      ans[i] += rem;
      rem = 0;
    }
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
