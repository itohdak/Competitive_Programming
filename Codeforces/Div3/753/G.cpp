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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; ll m; cin >> n >> m;
  vector<ll> A(n), B(n);
  vector<ll> mn(n), mx(n);
  vector<ll> L(n+1), R(n+1);
  rep(i, n) {
    cin >> A[i] >> B[i];
    mn[i] = -(2*min(A[i],m)-m);
    mx[i] = -(m-2*min(B[i], m));
    L[0] += A[i]-B[i];
  }
  R[0] = L[0];
  rep(i, n) {
    L[i+1] = L[i] + mn[i];
    R[i+1] = R[i] + mx[i];
  }
  ll ans = 0;
  if(L[n] <= 0 && R[n] >= 0) {
    if(L[n]%2) ans = (L[n]<=-1 ? -1 : 1);
    else ans = 0;
  } else if(R[n] < 0) {
    ans = R[n];
  } else {
    ans = L[n];
  }
  vector<pair<ll, ll>> P(n);
  ll tmp = ans;
  rrep(i, n) {
    ll next = min(R[i], tmp-mn[i]);
    ll diff = -(tmp-next);
    P[i] = {(m+diff)/2, (m-diff)/2};
    assert(P[i].first <= A[i]);
    assert(P[i].second <= B[i]);
    assert(P[i].first >= 0);
    assert(P[i].second >= 0);
    tmp = next;
  }
  ll sumA = 0, sumB = 0;
  rep(i, n) {
    sumA += A[i]-P[i].first;
    sumB += B[i]-P[i].second;
  }
  assert(sumA-sumB == ans);
  cout << abs(ans) << endk;
  rep(i, n) cout << P[i].first << ' ' << P[i].second << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
