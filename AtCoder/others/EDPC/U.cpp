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
  vector<vector<ll>> A(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];
  vector<ll> score(1<<n);
  rep(i, 1<<n) {
    rep(j, n) REP(k, j+1, n) {
      if((i>>j)&1 && (i>>k)&1) score[i] += A[j][k];
    }
  }
  REP(i, 1, 1<<n) {
    for(int j=i; --j&=i; ) {
      chmax(score[i], score[i^j]+score[j]);
    }
  }
  cout << score.back() << endk;
  return 0;
}