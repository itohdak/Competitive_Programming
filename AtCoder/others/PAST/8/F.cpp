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
  int n; cin >> n;
  string s; cin >> s;
  vector<vector<int>> A(2);
  rep(i, n) {
    A[s[i]-'0'].push_back(i);
  }
  if(A[0].size() == 1) cout << -1 << endk;
  else {
    vector<int> ans(n);
    rep(i, A[0].size()) {
      ans[A[0][(i+1)%A[0].size()]] = A[0][i];
    }
    rep(i, A[1].size()) {
      ans[A[1][i]] = A[1][i];
    }
    rep(i, n) cout << ans[i]+1 << ' ';
    cout << endk;
  }
  return 0;
}
