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
  ll n; cin >> n;
  vector<int> d;
  {
    ll m = n;
    while(m) {
      d.push_back(m%10);
      m /= 10;
    }
  }
  int nd = d.size();
  map<int, vector<int>> mp;
  rep(i, nd) mp[d[i]].push_back(i);
  int mn = inf;
  if(mp.count(0) && mp[0].size() >= 2) {
    int f = mp[0][0];
    int s = mp[0][1];
    chmin(mn, f+s-1);
  }
  int a[] = {2, 5, 7};
  int b[] = {5, 0, 5};
  rep(i, 3) {
    if(mp.count(a[i]) && mp.count(b[i])) {
      int f = mp[a[i]][0];
      int s = mp[b[i]][0];
      int cnt = 0;
      rrep(j, nd) {
        if(j == f || j == s) continue;
        if(d[j] != 0) break;
        cnt++;
      }
      chmin(mn, f+s-1+(f<s)+cnt);
    }
  }
  cout << (mn == inf ? -1 : mn) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
