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
  int n, x; cin >> n >> x;
  vector<int> L(n), R(n);
  vector<ll> C(n);
  rep(i, n) {
    cin >> L[i] >> R[i] >> C[i];
  }
  vector<int> idl(n), idr(n);
  rep(i, n) idl[i] = idr[i] = i;
  sort(all(idl), [&](int i, int j) {
    return L[i] > L[j];
  });
  sort(all(idr), [&](int i, int j) {
    return R[i] > R[j];
  });
  map<int, ll> mp; // dur, cost
  ll ans = longinf;
  // cout << idl << endk << idr << endk;
  int i = 0, j = 0;
  while(i < n) {
    int tmpr = R[idr[i]];
    while(j < n && L[idl[j]] > tmpr) {
      int l = L[idl[j]];
      int r = R[idl[j]];
      ll cost = C[idl[j]];
      int dur = r-l+1;
      if(!mp.count(dur)) mp[dur] = longinf;
      chmin(mp[dur], cost);
      j++;
    }
    while(i < n && R[idr[i]] == tmpr) {
      int l = L[idr[i]];
      int r = R[idr[i]];
      ll cost = C[idr[i]];
      int dur = r-l+1;
      if(mp.count(x-dur)) chmin(ans, cost+mp[x-dur]);
      i++;
    }
    // cout << i << ' ' << j << ' ' << mp << endk;
  }
  cout << (ans==longinf ? -1 : ans) << endk;
  return 0;
}
