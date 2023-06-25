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
  vector<ll> A(n); rep(i, n) cin >> A[i];
  ll sum = 0;
  rep(i, n-1) sum += abs(A[i+1]-A[i]);
  auto calc = [&]() {
    vector<pair<ll, ll>> P;
    rep(i, n-1) {
      if(A[i] < A[i+1]) P.push_back({A[i], A[i+1]});
    }
    sort(all(P));
    ll ret = -longinf;
    ll mx = -longinf;
    rep(i, P.size()) {
      chmax(ret, min(mx, P[i].second)-P[i].first);
      chmax(mx, P[i].second);
    }
    return 2*ret;
  };
  ll diff = 0;
  rep(i, n) if(i) chmax(diff, abs(A[i]-A[i-1])-abs(A[i]-A[0]));
  chmax(diff, calc());
  reverse(all(A));
  rep(i, n) if(i) chmax(diff, abs(A[i]-A[i-1])-abs(A[i]-A[0]));
  chmax(diff, calc());
  cout << sum-diff << endk;
  return 0;
}
