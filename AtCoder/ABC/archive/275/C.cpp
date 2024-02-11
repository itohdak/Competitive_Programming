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
  vector<int> A;
  int cnt = 0;
  auto dfs = [&](auto dfs, int cur) -> void {
    if(cur == 6) {
      int x1 = A[0], y1 = A[1];
      int x2 = A[2], y2 = A[3];
      int x3 = A[4], y3 = A[5];
      set<pair<int, int>> st;
      st.insert({x1, y1});
      st.insert({x2, y2});
      st.insert({x3, y3});
      if(st.size() < 3) return;
      if(S[x1][y1] == '.' || S[x2][y2] == '.' || S[x3][y3] == '.') return;
      int dx1 = x2-x1, dy1 = y2-y1;
      int dx2 = x3-x1, dy2 = y3-y1;
      if(dy1 != dx2 || -dx1 != dy2) return;
      int x = x2+x3-x1;
      int y = y2+y3-y1;
      if(x < 0 || x >= 9 || y < 0 || y >= 9) return;
      if(S[x][y] == '#') cnt++;
      return;
    }
    rep(i, 9) {
      A.push_back(i);
      dfs(dfs, cur+1);
      A.pop_back();
    }
  };
  dfs(dfs, 0);
  cout << cnt/4 << endk;
  return 0;
}
