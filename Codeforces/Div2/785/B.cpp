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
  string s; cin >> s;
  int n = s.size();
  vector<vector<int>> pos(26);
  vector<vector<int>> sum(26, vector<int>(n+1));
  rep(i, 26) pos[i].push_back(-1);
  rep(i, n) {
    pos[s[i]-'a'].push_back(i);
    sum[s[i]-'a'][i+1] += 1;
  }
  rep(i, 26) pos[i].push_back(n);
  rep(i, 26) {
    rep(j, n) sum[i][j+1] += sum[i][j];
  }
  rep(i, 26) {
    if(pos[i].size() == 2) continue;
    rep(j, pos[i].size()-1) {
      int l = pos[i][j]+1, r = pos[i][j+1];
      bool ok = true;
      rep(k, 26) {
        if(i == k) continue;
        if(sum[k][r]-sum[k][l] >= 2) ok = false;
      }
      if(!ok) {
        // cout << i << ' ' << l << ' ' << r << endk;
        cout << "NO" << endk;
        return;
      }
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
