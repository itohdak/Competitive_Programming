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
  string s, t; cin >> s >> t;
  vector<vector<int>> cnt(26);
  int n = s.size();
  rep(i, n) {
    cnt[s[i]-'a'].push_back(i);
  }
  int m = t.size();
  vector<int> mapping(m+2);
  mapping[0] = -1;
  mapping[m+1] = n;
  rep(i, m) {
    mapping[i+1] = *lower_bound(all(cnt[t[i]-'a']), mapping[i]+1);
  }
  int mx = 0;
  rep(i, m+1) {
    chmax(mx, mapping[i+1]-mapping[i]);
  }
  rrep(i, m) {
    mapping[i+1] = *(--upper_bound(all(cnt[t[i]-'a']), mapping[i+2]-1));
    chmax(mx, mapping[i+1]-mapping[i]);
  }
  cout << mx-1 << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
