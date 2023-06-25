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
  string s; cin >> s;
  int ans = 10;
  rep(k, 2) {
    vector<int> score(2);
    rep(i, 10) {
      if(s[i] == '1') score[i&1]++;
      else if(s[i] == '?') {
        if((i&1) == k) score[i&1]++;
      }
      int rem1 = 5-(i+2)/2, rem2 = 5-(i+1)/2;
      if((k == 1 && score[0] + rem1 < score[1]) ||
         (k == 0 && score[0] > score[1] + rem2)) {
        chmin(ans, i+1);
        break;
      }
    }
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
