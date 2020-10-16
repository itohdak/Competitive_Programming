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
  vector<vector<int>> sum(26, vector<int>(n+1));
  rep(i, n) {
    rep(j, 26) sum[j][i+1] += sum[j][i];
    sum[s[i]-'a'][i+1]++;
  }
  int q; cin >> q;
  rep(i, q) {
    int l, r; cin >> l >> r;
    l--;
    if(l+1 == r || s[l] != s[r-1]) cout << "Yes" << endk;
    else {
      int cnt = 0;
      rep(j, 26) cnt += (sum[j][r]-sum[j][l]>0);
      if(cnt >= 3) cout << "Yes" << endk;
      else cout << "No" << endk;
    }
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
