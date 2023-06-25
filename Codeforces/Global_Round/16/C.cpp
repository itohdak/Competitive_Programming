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
  string s, t; cin >> s >> t;
  int ans = 0;
  int l = 0;
  int carry = 0;
  while(l < n) {
    int sum = s[l]+t[l]-2*'0';
    if(sum == 0) {
      if(carry) {
        ans += 2;
        carry = 0;
      } else if(l == n-1) {
        ans += 1;
        carry = 0;
      } else {
        int next = s[l+1]+t[l+1]-2*'0';
        if(next == 0 || next == 1) {
          ans += 1;
          carry = 0;
        } else {
          ans += 2;
          l++;
          carry = 0;
        }
      }
    } else if(sum == 1) {
      ans += 2;
      carry = 0;
    } else {
      carry = 2;
    }
    l++;
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
