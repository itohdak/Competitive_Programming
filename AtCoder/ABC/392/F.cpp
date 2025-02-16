#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
  vector<int> P(n);
  rep(i, n) {
    cin >> P[i];
    P[i]--;
  }
  fenwick_tree<int> bit(n);
  rep(i, n) {
    bit.add(i, 1);
  }
  vector<int> ans(n, -1);
  rrep(i, n) {
    auto bsearch = [&]() -> int {
      auto test = [&](int t) -> bool {
        return bit.sum(0, t) <= P[i];
      };
      int ok = P[i], ng = n;
      while(abs(ok-ng) > 1) {
        int mid = (ok+ng)/2;
        (test(mid) ? ok : ng) = mid;
      }
      return ok;
    };
    int p = bsearch();
    ans[p] = i;
    bit.add(p, -1);
  }
  rep(i, n) cout << ans[i]+1 << ' ';
  cout << endk;
  return 0;
}
