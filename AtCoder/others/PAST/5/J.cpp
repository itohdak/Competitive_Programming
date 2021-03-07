#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  ll x; cin >> x; x--;
  ll cnt = 0; // 何文字あるか
  int i = -1;
  while(cnt <= x) {
    i++;
    if('a' <= s[i] && s[i] <= 'z') cnt++;
    else cnt *= (s[i]-'0'+1);
  }
  while(true) {
    // cout << i << ' ' << cnt << ' ' << x << endk;
    if('a' <= s[i] && s[i] <= 'z') {
      if(cnt-1 == x) {
        cout << s[i] << endk;
        return 0;
      } else {
        cnt--;
      }
    } else {
      assert(cnt % (s[i]-'0'+1) == 0);
      cnt /= (s[i]-'0'+1);
      x %= cnt;
    }
    i--;
  }
  return 0;
}
