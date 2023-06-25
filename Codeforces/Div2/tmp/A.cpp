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
  int n; ll m; cin >> n >> m;
  string s; cin >> s;
  vector<int> alive;
  rep(i, n) if(s[i] == '1') alive.push_back(i);
  string ans(n, '0');
  rep(i, n) {
    if(s[i] == '1') ans[i] = '1';
    else {
      REP(j, 1, min((ll)n+5, m+1)) {
        int sum = (i-j >= 0 && s[i-j] == '1') + (i+j < n && s[i+j] == '1');
        if(sum == 1) {
          ans[i] = '1';
          break;
        } else if(sum == 2) {
          break;
        }
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
