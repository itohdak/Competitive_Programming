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
  auto calc = [&](int parity) {
    int l = 0, r = n-1;
    int flag = parity;
    int ans = 0;
    while(l < r) {
      while(l < r && s[l] == '0'+(flag+l)%2) l++;
      while(l < r && s[r] == '0'+(flag+r)%2) r--;
      if(l >= r) break;
      assert(s[l] != s[r]);
      ans++;
      flag = 1-flag;
      l++; r--;
    }
    return ans;
  };
  cout << min(calc(0), calc(1)) << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
