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
  ll m; int n; cin >> m >> n;
  auto query = [&](ll q) {
    cout << q << endl;
    int ret;
    cin >> ret;
    if(ret == 0) exit(0);
    return ret > 0;
  };
  vector<bool> ret(n);
  rep(i, n) ret[i] = query(1);
  auto test = [&](ll mid) {
    return query(mid);
  };
  ll ok = 0, ng = m+1;
  int i = 0;
  while(abs(ok-ng)>1) {
    ll mid = (ok+ng)/2;
    if(ret[i%n]) (test(mid) ? ok : ng) = mid;
    else         (test(mid) ? ng : ok) = mid;
    i++;
  }
  assert(false);
  return 0;
}
