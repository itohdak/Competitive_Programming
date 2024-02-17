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
  int h, w, n; cin >> h >> w >> n;
  string t; cin >> t;
  vector<string> S(h);
  rep(i, h) cin >> S[i];
  vector<pair<int, int>> pos;
  rep(i, h) rep(j, w) if(S[i][j] == '.') pos.push_back({i, j});
  rep(i, n) {
    vector<pair<int, int>> next;
    for(auto [x, y]: pos) {
      int nx = x, ny = y;
      if(t[i] == 'L') {
        ny--;
      } else if(t[i] == 'R') {
        ny++;
      } else if(t[i] == 'U') {
        nx--;
      } else {
        nx++;
      }
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(S[nx][ny] == '.') next.push_back({nx, ny});
    }
    pos = next;
  }
  cout << pos.size() << endk;
  return 0;
}
