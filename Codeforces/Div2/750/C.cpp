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
  int n; cin >> n;
  string s; cin >> s;
  int ans = inf;
  rep(i, 26) {
    char c = char('a'+i);
    int l = 0, r = n-1;
    bool ok = true;
    int tmp = 0;
    while(l < r) {
      if(s[l] == s[r]) {
        l++, r--;
        continue;
      }
      if(s[l] != c && s[r] != c) {
        ok = false;
        break;
      }
      if(s[l] == c) {
        while(l < r && s[l] == c) {
          tmp++;
          l++;
        }
      } else {
        while(l < r && s[r] == c) {
          tmp++;
          r--;
        }
      }
    }
    if(ok) {
      // cout << c << tmp << endk;
      chmin(ans, tmp);
    }
  }
  cout << (ans==inf ? -1 : ans) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
