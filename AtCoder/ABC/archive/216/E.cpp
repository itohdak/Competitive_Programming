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
  int n; ll k; cin >> n >> k;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  auto bsearch = [&]() {
    auto test = [&](ll m) {
      ll need = 0;
      rep(i, n) {
        need += max(0LL, A[i]-m);
      }
      return need <= k;
    };
    ll ok = longinf, ng = -1;
    while(abs(ok-ng)>1) {
      ll mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  ll res = bsearch();
  priority_queue<ll> q;
  ll ans = 0;
  rep(i, n) {
    ll diff = max(0LL, A[i]-res);
    ans += (A[i]+res+1)*diff/2;
    k -= diff;
    if(A[i]-diff>0) q.push(A[i]-diff);
  }
  assert(k >= 0);
  while(k && q.size()) {
    ll tmp = q.top(); q.pop();
    ans += tmp;
    q.push(tmp-1);
    k--;
  }
  cout << ans << endk;
  return 0;
}
