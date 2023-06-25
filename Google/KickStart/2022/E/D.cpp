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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, p, m, sx, sy;
  cin >> n >> p >> m >> sx >> sy;
  sx--; sy--;
  vector<char> D = {'N', 'E', 'W', 'S'};
  int dx[4] = {-1, 0, 0, 1};
  int dy[4] = {0, 1, -1, 0};
  vector<char> Op(4);
  vector<int> K(4);
  rep(i, 4) cin >> Op[i] >> K[i];
  vector<int> X(p), Y(p), C(p);
  map<int, int> mp;
  rep(i, p) {
    cin >> X[i] >> Y[i] >> C[i];
    X[i]--; Y[i]--;
    mp[X[i]*n+Y[i]] = i;
  }
  auto calc = [&](char op, ll v, int c) -> ll {
    if(op == '+') {
      return v+c;
    } else if(op == '-') {
      return v-c;
    } else if(op == '*') {
      return v*c;
    } else {
      if(v < 0) {
        return (v-c+1)/c;
      } else {
        return v/c;
      }
    }
  };
  vector<vector<vector<ll>>> dp(m+1, vector<vector<ll>>(n*n, vector<ll>(1<<p, -longinf)));
  dp[0][sx*n+sy][0] = 0;
  rep(i, m) {
    rep(j, n*n) {
      int x = j/n, y = j%n;
      rep(k, 1<<p) {
        if(dp[i][j][k] == -longinf) continue;
        chmax(dp[i+1][j][k], dp[i][j][k]);
        if(mp.count(j) && !((k>>mp[j])&1)) {
          chmax(dp[i+1][j][k|(1<<mp[j])], dp[i][j][k]+C[mp[j]]);
        }
        rep(d, 4) {
          int nx = x+dx[d], ny = y+dy[d];
          if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          int ne = nx*n+ny;
          chmax(dp[i+1][ne][k], calc(Op[d], dp[i][j][k], K[d]));
          if(mp.count(ne) && !((k>>mp[ne])&1)) {
            chmax(dp[i+1][ne][k|(1<<mp[ne])], calc(Op[d], dp[i][j][k], K[d])+C[mp[ne]]);
          }
        }
      }
    }
  }
  ll ans = -longinf;
  rep(i, n*n) chmax(ans, dp[m][i][(1<<p)-1]);
  if(ans == -longinf) {
    cout << "IMPOSSIBLE" << endk;
  } else {
    cout << ans << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
