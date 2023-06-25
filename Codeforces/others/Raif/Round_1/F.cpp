#include <bits/stdc++.h>
// #include <print.hpp>
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
  map<int, pair<int, int>> mp;
  ll ans = 0, sum = 0;
  vector<ll> cnt(n+1);
  rep(i, n) {
    if(s[i] == '0') {
      ans += sum;
    } else {
      int l = i, r = i;
      while(r < n && s[r] == '1') r++;
      for(int j=l; j<r; j++) {
        sum += j+1-cnt[j-l+1];
        ans += sum;
        cnt[j-l+1] = r-(j-l);
      }
      i = r-1;
    }
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
