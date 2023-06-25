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
  vector<string> S(9); rep(i, 9) cin >> S[i];
  int cnt = 0;
  rep(i, 9) rep(j, 9) {
    REP(k, -8, 9) REP(l, -8, 9) {
      if(k == 0 && l == 0) continue;
      int i2 = i+k, j2 = j+l;
      int i3 = i2-l, j3 = j2+k;
      int i4 = i3-k, j4 = j3-l;
      auto valid = [&](int x, int y) {
        return 0 <= x && x < 9 && 0 <= y && y < 9 && S[x][y] == '#';
      };
      if(valid(i, j) && valid(i2, j2) && valid(i3, j3) && valid(i4, j4)) {
        cnt++;
      }
    }
  }
  cout << cnt/4 << endk;
  return 0;
}
