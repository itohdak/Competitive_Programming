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
  int n = s.size();
  ll ans = 0;
  rep(i, 1<<n) {
    map<int, int> c1, c2;
    rep(j, n) ((i>>j)&1 ? c1 : c2)[s[j]-'0']++;
    int n1 = 0, n2 = 0;
    {
      int pw = 1;
      for(auto [v, c]: c1) {
        rep(k, c) {
          n1 += v*pw;
          pw *= 10;
        }
      }
    }
    {
      int pw = 1;
      for(auto [v, c]: c2) {
        rep(k, c) {
          n2 += v*pw;
          pw *= 10;
        }
      }
    }
    chmax(ans, 1LL*n1*n2);
  }
  cout << ans << endk;
  return 0;
}
