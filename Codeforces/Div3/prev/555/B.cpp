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
  map<char, char> mp;
  rep(i, 9) {
    int f; cin >> f;
    mp[char(i+'1')] = char(f+'0');
  }
  bool flag = false;
  rep(i, n) {
    if(!flag) {
      if(mp[s[i]] <= s[i]) continue;
      else {
        flag = true;
        s[i] = mp[s[i]];
      }
    } else {
      if(mp[s[i]] < s[i]) break;
      else s[i] = mp[s[i]];
    }
  }
  cout << s << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
