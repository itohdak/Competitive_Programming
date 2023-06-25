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
  int n, k; cin >> n >> k;
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  map<int, int> mp;
  vector<int> next(n, -1);
  vector<int> ans(n, -2);
  rep(i, n) {
    auto itr = mp.lower_bound(P[i]);
    if(itr == mp.end()) {
      mp[P[i]] = 1;
    } else {
      auto [v, c] = *itr;
      mp.erase(v);
      mp[P[i]] = c + 1;
      next[P[i]] = v;
    }
    if(mp[P[i]] == k) {
      int cur = P[i];
      while(cur != -1) {
        ans[cur] = i;
        cur = next[cur];
      }
      mp.erase(P[i]);
    }
    // cout << mp << endk;
    // cout << ans << endk;
  }
  rep(i, n) {
    cout << ans[i]+1 << endk;
  }
  return 0;
}
