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
  vector<pair<int, int>> range;
  map<pair<int, int>, int> mp;
  int len = 1;
  while(len <= n) {
    rep(i, n) {
      if(i+len > n) break;
      mp[{i, i+len}] = range.size();
      range.push_back({i, i+len});
    }
    len *= 2;
  }
  assert(range.size() <= 50000);
  cout << range.size() << endl;
  for(auto [l, r]: range) {
    cout << l+1 << ' ' << r << endl;
  }
  int q; cin >> q;
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    int len = 1;
    while(len*2 <= r-l) {
      len *= 2;
    }
    assert(mp.count({l, l+len}));
    assert(mp.count({r-len, r}));
    cout << mp[{l, l+len}]+1 << ' ' << mp[{r-len, r}]+1 << endl;
  }
  return 0;
}
