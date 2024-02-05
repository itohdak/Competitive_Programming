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
  string s; cin >> s;
  vector<int> W(n); rep(i, n) cin >> W[i];
  vector<int> child, adult;
  rep(i, n) (s[i] == '1' ? adult : child).push_back(W[i]);
  sort(all(child));
  sort(all(adult));
  int ans = 0;
  rep(i, n) {
    int x = W[i];
    auto judge = [&](int x) -> int {
      int c = upper_bound(all(child), x-1) - begin(child);
      int a = end(adult) - lower_bound(all(adult), x);
      return a+c;
    };
    chmax(ans, judge(x-1));
    chmax(ans, judge(x));
    chmax(ans, judge(x+1));
  }
  cout << ans << endk;
  return 0;
}
