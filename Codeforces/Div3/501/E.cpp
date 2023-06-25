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
  int n, m; cin >> n >> m;
  vector<string> S(n);
  rep(i, n) cin >> S[i];
  vector<vector<int>> cntL(n, vector<int>(m)),
                      cntR(n, vector<int>(m)),
                      cntU(n, vector<int>(m)),
                      cntD(n, vector<int>(m));
  rep(i, n) {
    int cnt = 0;
    rep(j, m) {
      if(S[i][j] == '*') cnt++;
      else cnt = 0;
      cntL[i][j] = cnt;
    }
  }
  rep(i, n) {
    int cnt = 0;
    rrep(j, m) {
      if(S[i][j] == '*') cnt++;
      else cnt = 0;
      cntR[i][j] = cnt;
    }
  }
  rep(j, m) {
    int cnt = 0;
    rep(i, n) {
      if(S[i][j] == '*') cnt++;
      else cnt = 0;
      cntU[i][j] = cnt;
    }
  }
  rep(j, m) {
    int cnt = 0;
    rrep(i, n) {
      if(S[i][j] == '*') cnt++;
      else cnt = 0;
      cntD[i][j] = cnt;
    }
  }
  vector<vector<int>> T1(n, vector<int>(m));
  vector<vector<int>> T2(n, vector<int>(m));
  vector<tuple<int, int, int>> ans;
  rep(i, n) rep(j, m) {
    int mn = min({cntL[i][j], cntR[i][j], cntU[i][j], cntD[i][j]});
    if(mn > 1) {
      T1[i-mn+1][j]++;
      if(i+mn < n) T1[i+mn][j]--;
      T2[i][j-mn+1]++;
      if(j+mn < m) T2[i][j+mn]--;
      ans.push_back({i, j, mn});
    }
  }
  rep(i, n) rep(j, m) if(j) T2[i][j] += T2[i][j-1];
  rep(j, m) rep(i, n) if(i) T1[i][j] += T1[i-1][j];
  rep(i, n) rep(j, m) {
    if((T1[i][j]+T2[i][j]>0)^(S[i][j]=='*')) {
      cout << -1 << endk;
      return 0;
    }
  }
  cout << ans.size() << endk;
  for(auto [x, y, s]: ans) {
    cout << x+1 << ' ' << y+1 << ' ' << s-1 << endk;
  }
  return 0;
}
