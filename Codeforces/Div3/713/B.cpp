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
  int n; cin >> n;
  vector<string> S(n); rep(i, n) cin >> S[i];
  vector<pair<int, int>> P;
  rep(i, n) rep(j, n) if(S[i][j] == '*') P.push_back({i, j});
  int xmin = n, xmax = -1, ymin = n, ymax = -1;
  for(auto [x, y]: P) {
    chmin(xmin, x);
    chmax(xmax, x);
    chmin(ymin, y);
    chmax(ymax, y);
  }
  if(xmin == xmax) xmin = (xmin == 0 ? 1 : 0);
  if(ymin == ymax) ymin = (ymin == 0 ? 1 : 0);
  S[xmin][ymin] = S[xmin][ymax] = S[xmax][ymin] = S[xmax][ymax] = '*';
  rep(i, n) cout << S[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
