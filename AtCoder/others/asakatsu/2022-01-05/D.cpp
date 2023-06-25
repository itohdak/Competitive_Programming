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
  int h, w; cin >> h >> w;
  vector<vector<int>> A(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  vector<tuple<int, int, int, int>> ans;
  rep(i, h) rep(j, w) {
    if(A[i][j]&1) {
      if(i == h-1 && j == w-1) continue;
      if(j == w-1) {
        ans.push_back({i, j, i+1, j});
        A[i][j]--;
        A[i+1][j]++;
      } else {
        ans.push_back({i, j, i, j+1});
        A[i][j]--;
        A[i][j+1]++;
      }
    }
  }
  cout << ans.size() << endk;
  for(auto [x, y, x1, y1]: ans) {
    cout << x+1 << ' ' << y+1 << ' ' << x1+1 << ' ' << y1+1 << endk;
  }
  return 0;
}
