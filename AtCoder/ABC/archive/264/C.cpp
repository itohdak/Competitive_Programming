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
  int h1, w1; cin >> h1 >> w1;
  vector<vector<int>> A(h1, vector<int>(w1));
  rep(i, h1) rep(j, w1) cin >> A[i][j];
  int h2, w2; cin >> h2 >> w2;
  vector<vector<int>> B(h2, vector<int>(w2));
  rep(i, h2) rep(j, w2) cin >> B[i][j];
  rep(i, 1<<h1) {
    rep(j, 1<<w1) {
      if(__builtin_popcount(i) != h2) continue;
      if(__builtin_popcount(j) != w2) continue;
      vector<int> r, c;
      rep(k, h1) if((i>>k)&1) r.push_back(k);
      rep(k, w1) if((j>>k)&1) c.push_back(k);
      bool ok = true;
      rep(k, h2) rep(l, w2) {
        if(A[r[k]][c[l]] != B[k][l]) ok = false;
      }
      if(ok) {
        cout << "Yes" << endk;
        return 0;
      }
    }
  }
  cout << "No" << endk;
  return 0;
}
