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
  int n; ll c; cin >> n >> c;
  vector<ll> A(n), B(n), C(n);
  vector<ll> X;
  rep(i, n) {
    cin >> A[i] >> B[i] >> C[i];
    // A[i]--; B[i]--;
    B[i]++;
    X.push_back(A[i]);
    X.push_back(B[i]);
  }
  sort(all(X));
  X.erase(unique(all(X)), end(X));
  vector<int> a(n), b(n);
  int m = X.size();
  vector<ll> sum(m+1);
  rep(i, n) {
    a[i] = lower_bound(all(X), A[i]) - begin(X);
    b[i] = lower_bound(all(X), B[i]) - begin(X);
    sum[a[i]] += C[i];
    sum[b[i]] -= C[i];
  }
  rep(i, m) sum[i+1] += sum[i];
  // cout << X << endk;
  // cout << a << endk << b << endk;
  // cout << sum << endk;
  ll ans = 0;
  rep(i, m) {
    ans += min(sum[i], c) * (X[i+1]-X[i]);
  }
  cout << ans << endk;
  return 0;
}
