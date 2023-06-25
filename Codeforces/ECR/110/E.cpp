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

void solve() {
  int q; cin >> q;
  vector<int> A(q+1), C(q+1);
  vector<vector<int>> par(q+1, vector<int>(21, -1));
  cin >> A[0] >> C[0];
  auto ascend = [&](int p, int q) {
    assert(q < (1<<21));
    rrep(k, 21) {
      if(p == -1) break;
      if((q>>k)&1) p = par[p][k];
    }
    return p;
  };
  auto bsearch = [&](int v) {
    auto test = [&](int m) {
      int asc = ascend(v, m);
      return asc != -1 && A[asc] != 0;
    };
    int ok = -1, ng = 1000005;
    while(abs(ok-ng) > 1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  REP(i, 1, q+1) {
    int t; cin >> t;
    if(t == 1) {
      cin >> par[i][0] >> A[i] >> C[i];
      REP(j, 1, 21) {
        if(par[i][j-1] == -1) break;
        par[i][j] = par[par[i][j-1]][j-1];
      }
    } else {
      int v, w; cin >> v >> w;
      int worg = w;
      int tmp = bsearch(v);
      ll ans = 0;
      while(w > 0 && tmp >= 0) {
        int asc = ascend(v, tmp);
        if(w <= A[asc]) {
          ans += 1LL * C[asc] * w;
          A[asc] -= w;
          w = 0;
        } else {
          ans += 1LL * C[asc] * A[asc];
          w -= A[asc];
          A[asc] = 0;
          tmp--;
        }
      };
      cout << worg-w << ' ' << ans << endl;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  // cin >> T;
  while(T--) solve();
  return 0;
}
