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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int a, b; cin >> a >> b;
  int ans = inf;
  rep(i, b-a+1) {
    int tmpa = a + i;
    int tmpb = b;
    int sum = i;
    int tmp = 0;
    rep(j, 32) {
      int bita = ((tmpa>>j)&1), bitb = ((tmpb>>j)&1);
      if(bita && !bitb) {
        tmpb += (1<<j)-tmp;
        sum += (1<<j)-tmp;
        tmp = 0;
      } else if(!bita && bitb) {
        tmp += 1<<j;
      }
    }
    if(tmpa != tmpb) sum++;
    chmin(ans, sum);
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
