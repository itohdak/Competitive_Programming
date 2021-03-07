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
  string a, b; cin >> a >> b;
  int ans = 0;
  rep(i, (n+1)/2) {
    char a1 = a[i], a2 = a[n-1-i];
    char b1 = b[i], b2 = b[n-1-i];
    if(n % 2 && i == n/2) {
      ans += (a1 != b1);
    } else if(b1 == b2) {
      ans += (a1 != a2);
    } else {
      ans += min({(a1 != b1) + (a2 != b2),
                  (a1 != b2) + (a2 != b1)});
    }
  }
  cout << ans << endk;
  return 0;
}
