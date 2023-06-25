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
  ll x; cin >> x;
  int ans = 0;
  vector<int> A;
  vector<ll> pw(30);
  pw[0] = 1;
  rep(i, 30) if(i) pw[i] = pw[i-1] * 2;
  while(*lower_bound(all(pw), x+1) != x+1) {
    ll tmp = x;
    int mxi = 0;
    int i = 0;
    while(tmp) {
      if(!(tmp&1)) chmax(mxi, i);
      tmp /= 2;
      i++;
    }
    x ^= (pw[mxi+1]-1);
    A.push_back(mxi+1);
    ans++;
    if(*lower_bound(all(pw), x+1) == x+1) break;
    x++;
    ans++;
  }
  cout << ans << endk;
  for(int a: A) cout << a << ' ';
  if(ans) cout << endk;
  return 0;
}
