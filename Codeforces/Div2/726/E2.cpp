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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  s += string(n, 'z');
  int pos = 0;
  string tmp = s.substr(0, 1);
  REP(i, 1, 2*n) {
    if(tmp[pos] > s[i]) {
      tmp += s[i];
      pos = 0;
    } else if(tmp[pos] == s[i]) {
      tmp += s[i];
      pos++;
    } else {
      string t = s.substr(0, i-pos);
      int len = t.size();
      int times = (k+len-1)/len;
      string ans;
      rep(i, times) ans += t;
      assert((int)ans.size() >= k);
      cout << ans.substr(0, k) << endk;
      return;
    }
  }
  string t = s.substr(0, n);
  int len = t.size();
  int times = (k+len-1)/len;
  string ans;
  rep(i, times) ans += t;
  assert((int)ans.size() >= k);
  cout << ans.substr(0, k) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
