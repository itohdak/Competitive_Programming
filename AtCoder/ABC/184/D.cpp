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

ld memo[101][101][101];
bool done[101][101][101];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a, b, c; cin >> a >> b >> c;
  rep(i, 101) rep(j, 101) rep(k, 101) {
    memo[i][j][k] = 0;
    done[i][j][k] = false;
  }
  auto f = [&](auto f, int i, int j, int k) -> ld {
    if(i == 100 || j == 100 || k == 100) return 0;
    if(done[i][j][k]) return memo[i][j][k];
    if(i+1 <= 100) memo[i][j][k] += (f(f, i+1, j, k) + 1) * i / (i+j+k);
    if(j+1 <= 100) memo[i][j][k] += (f(f, i, j+1, k) + 1) * j / (i+j+k);
    if(k+1 <= 100) memo[i][j][k] += (f(f, i, j, k+1) + 1) * k / (i+j+k);
    done[i][j][k] = true;
    // cout << i << ' ' << j << ' ' << k << ' ';
    // cout << memo[i][j][k] << endk;
    return memo[i][j][k];
  };
  cout << fixed << setprecision(20) << f(f, a, b, c) << endk;
  return 0;
}
