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
  if(n == 3) {
    cout << "No" << endk;
  } else if(n%3==2) {
    cout << "No" << endk;
  } else if(n%3==0) {
    cout << "Yes" << endk;
    vector<string> S(n, string(n, ' '));
    for(int step=1; step<=n/2; step++) {
      rep(i, n) {
        S[i][(i+step)%n] = S[(i+step)%n][i] = char('1'+((step-1)+i)%3);
      }
    }
    rep(i, n-1) cout << S[i].substr(i+1) << endk;
    rep(i, n) REP(j, i+1, n) REP(k, j+1, n) {
      cout << i << ' ' << j << ' ' << k << endl;
      assert(S[i][j]-'1' + S[j][k]-'1' + S[i][k]-'1' != 3);
    }
  } else {
    cout << "Yes" << endk;
    assert(false);
  }
  return 0;
}
