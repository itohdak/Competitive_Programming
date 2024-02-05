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
  int n; cin >> n;
  int dx[] = {-1, 0, 1, 0};
  int dy[] = {0, 1, 0, -1};
  vector<string> S(h, string(w, '.'));
  int x = 0, y = 0;
  int d = 0;
  rep(i, n) {
    if(S[x][y] == '.') {
      S[x][y] = '#';
      (d += 1+4) %= 4;
      (x += dx[d]+h) %= h;
      (y += dy[d]+w) %= w;
    } else {
      S[x][y] = '.';
      (d += -1+4) %= 4;
      (x += dx[d]+h) %= h;
      (y += dy[d]+w) %= w;
    }
  }
  rep(i, h) cout << S[i] << endk;
  return 0;
}
