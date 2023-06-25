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
  vector<string> C(h);
  rep(i, h) cin >> C[i];
  rep(i, h) rep(j, w) {
    if(C[i][j] != '.') continue;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    vector<bool> used(5);
    rep(k, 4) {
      int nx = i+dx[k], ny = j+dy[k];
      if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
      if(C[nx][ny] == '.') continue;
      used[C[nx][ny]-'1'] = true;
    }
    // cout << C << endk;
    // cout << i << ' ' << j << ' ' << used << endk;
    int tmp = 0;
    while(tmp < 5 && used[tmp]) tmp++;
    assert(tmp < 5);
    C[i][j] = char('1'+tmp);
  }
  rep(i, h) cout << C[i] << endk;
  return 0;
}
