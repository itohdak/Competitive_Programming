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
  vector<vector<int>> A(9, vector<int>(9));
  rep(i, 9) rep(j, 9) cin >> A[i][j];
  bool ok = true;
  rep(i, 9) {
    set<int> st;
    rep(j, 9) st.insert(A[i][j]);
    if(st.size() != 9) ok = false;
  }
  rep(j, 9) {
    set<int> st;
    rep(i, 9) st.insert(A[i][j]);
    if(st.size() != 9) ok = false;
  }
  for(int i=0; i<9; i+=3) {
    for(int j=0; j<9; j+=3) {
      set<int> st;
      rep(ii, 3) rep(jj, 3) st.insert(A[i+ii][j+jj]);
      if(st.size() != 9) ok = false;
    }
  }
  cout << (ok ? "Yes" : "No") << endk;
  return 0;
}
