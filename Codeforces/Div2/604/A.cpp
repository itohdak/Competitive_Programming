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
  int n = s.size();
  rep(i, n) {
    if(s[i] == '?') {
      if(i == 0) {
        if(i+1 < n && s[i+1] == '?') {
          s[i] = 'a';
        } else {
          s[i] = char('a'+((s[i+1]-'a')+1)%3);
        }
      } else if(i == n-1) {
        s[i] = char('a'+((s[i-1]-'a')+1)%3);
      } else {
        if(s[i+1] == '?') s[i] = char('a'+((s[i-1]-'a')+1)%3);
        else if(s[i-1] == s[i+1]) s[i] = char('a'+((s[i-1]-'a')+1)%3);
        else s[i] = char('a'+(3-(s[i-1]-'a')-(s[i+1]-'a')));
      }
    }
  }
  rep(i, n-1) {
    if(s[i] == s[i+1]) {
      cout << -1 << endk;
      return;
    }
  }
  cout << s << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
