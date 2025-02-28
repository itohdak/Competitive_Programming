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
  vector<int> cnt(26);
  rep(i, n) cnt[s[i]-'a']++;
  rep(i, n) {
    if(cnt[i] != 1) {
      cout << "NO" << endk;
      return;
    }
  }
  int l = 0;
  rep(i, n) if(s[i] == 'a') l = i;
  int r = l+1;
  rep(i, n) {
    if(i == 0) continue;
    char c = char('a'+i);
    if(l-1 >= 0 && s[l-1] == c) {
      l--;
    } else if(r < n && s[r] == c) {
      r++;
    } else {
      cout << "NO" << endk;
      return;
    }
  }
  cout << "YES" << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
