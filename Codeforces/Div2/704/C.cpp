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
  int n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  vector<int> pos(m);
  map<char, vector<int>> mp;
  rep(i, n) mp[s[i]].push_back(i);
  int l = 0;
  rep(i, m) {
    pos[i] = *lower_bound(all(mp[t[i]]), l);
    l = pos[i]+1;
  }
  int ans = 0;
  rep(i, m-1) chmax(ans, pos[i+1]-pos[i]);
  int r = n-1;
  rrep(i, m) {
    pos[i] = *(--upper_bound(all(mp[t[i]]), r));
    if(i) chmax(ans, pos[i]-pos[i-1]);
    r = pos[i]-1;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
