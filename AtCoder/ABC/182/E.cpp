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
  int h, w, n, m; cin >> h >> w >> n >> m;
  vector<string> board(h, string(w, ' '));
  vector<int> A(n), B(n), C(m), D(m);
  rep(i, n) {
    cin >> A[i] >> B[i];
    A[i]--; B[i]--;
    board[A[i]][B[i]] = '.';
  }
  rep(i, m) {
    cin >> C[i] >> D[i];
    C[i]--; D[i]--;
    board[C[i]][D[i]] = '#';
  }
  // rep(i, h) cout << board[i] << endk;
  set<pair<int, int>> st;
  rep(i, h) {
    int l = 0, r = 0;
    while(l < w) {
      while(l < w && board[i][l] == '#') l++;
      bool ok = false;
      r = l;
      while(r < w && board[i][r] != '#') {
        if(board[i][r] == '.') ok = true;
        r++;
      }
      if(ok) {
        for(int j=l; j<r; j++) {
          st.insert({i, j});
        }
      }
      l = r;
    }
  }
  rep(i, w) {
    int l = 0, r = 0;
    while(l < h) {
      while(l < h && board[l][i] == '#') l++;
      bool ok = false;
      r = l;
      while(r < h && board[r][i] != '#') {
        if(board[r][i] == '.') ok = true;
        r++;
      }
      if(ok) {
        for(int j=l; j<r; j++) {
          st.insert({j, i});
        }
      }
      l = r;
    }
  }
  // cout << st << endk;
  cout << st.size() << endk;
  return 0;
}
