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
  vector<ll> X(n), Y(n);
  rep(i, n) {
    cin >> X[i] >> Y[i];
  }
  vector<int> idx(n), idy(n);
  iota(all(idx), 0);
  iota(all(idy), 0);
  sort(all(idx), [&](int i, int j) {
    return X[i] < X[j];
  });
  sort(all(idy), [&](int i, int j) {
    return Y[i] < Y[j];
  });
  map<pair<int, int>, ll> mp;
  rep(i, n) {
    if(i > 0) chmax(mp[{min(idx[i], idx[0]), max(idx[i], idx[0])}], abs(X[idx[i]]-X[idx[0]]));
    if(i > 1) chmax(mp[{min(idx[i], idx[1]), max(idx[i], idx[1])}], abs(X[idx[i]]-X[idx[1]]));
    if(i < n-1) chmax(mp[{min(idx[i], idx[n-1]), max(idx[i], idx[n-1])}], abs(X[idx[i]]-X[idx[n-1]]));
    if(i < n-2) chmax(mp[{min(idx[i], idx[n-2]), max(idx[i], idx[n-2])}], abs(X[idx[i]]-X[idx[n-2]]));
    if(i > 0) chmax(mp[{min(idy[i], idy[0]), max(idy[i], idy[0])}], abs(Y[idy[i]]-Y[idy[0]]));
    if(i > 1) chmax(mp[{min(idy[i], idy[1]), max(idy[i], idy[1])}], abs(Y[idy[i]]-Y[idy[1]]));
    if(i < n-1) chmax(mp[{min(idy[i], idy[n-1]), max(idy[i], idy[n-1])}], abs(Y[idy[i]]-Y[idy[n-1]]));
    if(i < n-2) chmax(mp[{min(idy[i], idy[n-2]), max(idy[i], idy[n-2])}], abs(Y[idy[i]]-Y[idy[n-2]]));
  }
  priority_queue<ll> q;
  for(auto [_, d]: mp) q.push(d);
  q.pop();
  cout << q.top() << endk;
  return 0;
}
