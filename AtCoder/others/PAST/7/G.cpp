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
  ll n; cin >> n;
  ll orgn = n;
  ll pw = 1;
  vector<ll> ans;
  int carry = 0;
  while(n) {
    int tmp = n%3 + carry;
    if(tmp == 0) {
      carry = 0;
    } else if(tmp == 1) {
      ans.push_back(pw);
      carry = 0;
    } else if(tmp == 2) {
      carry = 1;
      // ans.push_back(pw*3);
      ans.push_back(-pw);
    } else if(tmp == 3) {
      carry = 1;
    }
    n /= 3;
    pw *= 3;
  }
  if(carry) ans.push_back(pw);
  assert(accumulate(all(ans), 0LL) == orgn);
  cout << ans.size() << endk;
  for(ll a: ans) cout << a << ' '; cout << endk;
  return 0;
}
