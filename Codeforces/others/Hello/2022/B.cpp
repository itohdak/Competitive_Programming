#include <bits/stdc++.h>
#include <print.hpp>
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
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; cin >> n;
  vector<int> L(n), R(n);
  vector<ll> C(n);
  vector<ll> ans(n);
  ll mn = inf, mx = -inf;
  map<pair<ll, ll>, ll> mp;
  map<ll, ll> mp_mn, mp_mx;
  rep(i, n) {
    cin >> L[i] >> R[i] >> C[i];
    L[i]--; R[i]--;
    chmin(mn, L[i]);
    chmax(mx, R[i]);
    if(!mp.count({L[i], R[i]})) mp[{L[i], R[i]}] = longinf;
    chmin(mp[{L[i], R[i]}], C[i]);
    if(!mp_mn.count(L[i])) mp_mn[L[i]] = longinf;
    chmin(mp_mn[L[i]], C[i]);
    if(!mp_mx.count(R[i])) mp_mx[R[i]] = longinf;
    chmin(mp_mx[R[i]], C[i]);
    ll cost = longinf;
    if(mp.count({mn, mx})) chmin(cost, mp[{mn, mx}]);
    assert(mp_mn.count(mn) && mp_mx.count(mx));
    chmin(cost, mp_mn[mn]+mp_mx[mx]);
    cout << cost << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
