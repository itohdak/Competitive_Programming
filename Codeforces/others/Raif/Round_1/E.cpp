#include <bits/stdc++.h>
// #include <print.hpp>
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
  int n, k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  priority_queue<pair<ll, pair<ll, int>>> q;
  auto calc = [&](ll a, int m) {
    ll mn = a/m, mx = a/m+1;
    int c2 = a%m, c1 = m-c2;
    return mn*mn*c1 + mx*mx*c2;
  };
  ll ans = 0;
  rep(i, n) {
    ll tmp = calc(A[i], 1);
    ll ne = calc(A[i], 2);
    q.push({tmp-ne, make_pair(A[i], 1)});
    ans += tmp;
  }
  rep(i, k-n) {
    auto ele = q.top(); q.pop();
    ans -= ele.first;
    ll tmp = calc(ele.second.first, ele.second.second+1);
    ll ne = calc(ele.second.first, ele.second.second+2);
    q.push({tmp-ne, make_pair(ele.second.first, ele.second.second+1)});
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
