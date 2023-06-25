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
  ll norig = n;
  vector<ll> fib(88);
  fib[0] = fib[1] = 1;
  REP(i, 2, 88) fib[i] = fib[i-1] + fib[i-2];
  int s = upper_bound(all(fib), n) - begin(fib);
  s--;
  n -= fib[s];
  set<int> inc;
  inc.insert(0);
  rep(i, s) {
    if(fib[s-i] <= n) {
      inc.insert(i);
      n -= fib[s-i];
    }
  }
  vector<int> ans;
  if(s&1) {
    rep(i, s+1) {
      if(i) ans.push_back(i&1 ? 3 : 4);
      if(inc.count(i)) ans.push_back(i&1 ? 1 : 2);
    }
  } else {
    rep(i, s+1) {
      if(i) ans.push_back(i&1 ? 4 : 3);
      if(inc.count(i)) ans.push_back(i&1 ? 2 : 1);
    }
  }
  ll x = 0, y = 0;
  for(int a: ans) {
    if(a == 1) x++;
    else if(a == 2) y++;
    else if(a == 3) x += y;
    else y += x;
  }
  assert(x == norig);
  assert(ans.size() <= 130);
  cout << ans.size() << endk;
  for(int a: ans) cout << a << endk;
  return 0;
}
