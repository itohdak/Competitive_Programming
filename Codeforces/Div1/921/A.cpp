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
  int n, k, m; cin >> n >> k >> m;
  string s; cin >> s;
  map<int, vector<int>> pos;
  rep(i, m) {
    pos[s[i]-'a'].push_back(i);
  }
  rep(i, k) {
    pos[i].push_back(m);
  }
  vector<vector<int>> dp(n+1, vector<int>(k, -1));
  vector<vector<int>> par(n+1, vector<int>(k, -1));
  rep(i, n) {
    rep(j, k) {
      rep(l, k) {
        int ne = *lower_bound(all(pos[l]), dp[i][j]+1);
        if(ne == m) {
          // cout << i << ' ' << j << ' ' << l << endk;
          string t;
          t += char('a'+l);
          int tmp = j;
          for(int ii=i; ii>0; ii--) {
            t += char('a'+tmp);
            tmp = par[ii][tmp];
          }
          reverse(all(t));
          t += string(n-t.size(), 'a');
          cout << "NO" << endk;
          cout << t << endk;
          return;
        } else {
          if(ne > dp[i+1][l]) {
            chmax(dp[i+1][l], ne);
            par[i+1][l] = j;
          }
        }
      }
    }
    // cout << dp << endk;
  }
  cout << "YES" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
