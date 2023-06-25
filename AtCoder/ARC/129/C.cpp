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
  int n; cin >> n;
  vector<ll> cnt(2000);
  rep(i, 2000) cnt[i] = i*(i+1)/2;
  string ans;
  int tmp = n;
  int d = 0;
  vector<int> pw10(1000001);
  pw10[0] = 1;
  rep(i, 1000001) if(i) pw10[i] = (pw10[i-1]*10)%7;
  while(tmp) {
    int len = upper_bound(all(cnt), tmp)-begin(cnt)-1;
    tmp -= cnt[len];
    ans = string(len, '7') + ans;
    d += len;
    if(tmp) {
      int next = -1;
      for(int i=1; i<=6; i++) {
        if(pw10[d]*i%7 == 1) {
          next = i;
          break;
        }
      }
      assert(next != -1);
      ans = string(1, char('0'+next)) + ans;
      d++;
    }
  }
  assert(ans.size() <= 1000000);
  cout << ans << endk;
  return 0;
}
