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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int l = n*m/2 - k;
  int norig = n, morig = m;
  vector<string> ans(n, string(m, ' '));
  if(n&1) {
    k -= m/2;
    rep(i, m/2) ans[n-1][2*i] = ans[n-1][2*i+1] = char('a'+24+i%2);
    n--;
  }
  if(m&1) {
    l -= n/2;
    rep(i, n/2) ans[2*i][m-1] = ans[2*i+1][m-1] = char('a'+24+i%2);
    m--;
  }
  if(k < 0 || k&1) {
    cout << "NO" << endk;
    return;
  }
  if(l < 0 || l&1) {
    cout << "NO" << endk;
    return;
  }
  rep(i, n/2) rep(j, m/2) {
    char c1, c2;
    set<char> used;
    if(i > 0) used.insert(ans[i*2-1][j*2]);
    if(i > 0) used.insert(ans[i*2-1][j*2+1]);
    if(j > 0) used.insert(ans[i*2][j*2-1]);
    if(j > 0) used.insert(ans[i*2+1][j*2-1]);
    char tmp = 'a';
    rep(j, 2) {
      while(true) {
        if(!used.count(tmp)) {
          (j ? c2 : c1) = tmp++;
          break;
        } else {
          tmp++;
        }
      }
    }
    if(k > 0) {
      ans[i*2][j*2] = c1; ans[i*2][j*2+1] = c1;
      ans[i*2+1][j*2] = c2; ans[i*2+1][j*2+1] = c2;
      k -= 2;
    } else {
      ans[i*2][j*2] = c1; ans[i*2][j*2+1] = c2;
      ans[i*2+1][j*2] = c1; ans[i*2+1][j*2+1] = c2;
      l -= 2;
    }
  }
  assert(k == 0 && l == 0);
  cout << "YES" << endk;
  rep(i, norig) cout << ans[i] << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
