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
  vector<int> R(n, -1);
  rep(i, n) {
    if(s[i] == '?') continue;
    R[i] = ((s[i]-'0') + i) % 2;
  }
  ll ans = 0;
  {
    int l = 0;
    while(l < n) {
      while(l > 0 && R[l-1] == -1) l--;
      int tmp = R[l];
      int r = l;
      while(r < n && (tmp == -1 || R[r] == -1 || R[r] == tmp)) {
        chmax(tmp, R[r]);
        r++;
      }
      ans += 1LL*(r-l)*(r-l+1)/2;
      l = r;
    }
  }
  {
    int l = 0;
    while(l < n) {
      while(l < n && s[l] != '?') l++;
      int r = l;
      while(r < n && s[r] == '?') r++;
      if(l > 0 && r < n && R[l-1] != R[r]) ans -= 1LL*(r-l)*(r-l+1)/2;
      l = r;
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
