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

vector<vector<ll>> prod(vector<vector<ll>>& R1, vector<vector<ll>>& R2) {
  assert(R1[0].size() == R2.size());
  vector<vector<ll>> ret(R1.size(), vector<ll>(R2[0].size()));
  rep(i, R1.size()) rep(k, R1[0].size()) rep(j, R2[0].size()) {
    ret[i][j] += R1[i][k] * R2[k][j];
  }
  return ret;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> X(n), Y(n);
  rep(i, n) cin >> X[i] >> Y[i];
  int m; cin >> m;
  vector<vector<vector<ll>>> R(m+1, vector<vector<ll>>(3, vector<ll>(3)));
  R[0] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  rep(i, m) {
    int t; cin >> t;
    vector<vector<ll>> tmp(3, vector<ll>(3));
    ll p = 0;
    if(t == 3 || t == 4) cin >> p;
    if(t == 1)      tmp = {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}};
    else if(t == 2) tmp = {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}};
    else if(t == 3) tmp = {{-1, 0, 2*p}, {0, 1, 0}, {0, 0, 1}};
    else            tmp = {{1, 0, 0}, {0, -1, 2*p}, {0, 0, 1}};
    R[i+1] = prod(tmp, R[i]);
  }
  // rep(i, m+1) cout << R[i] << endk;
  int q; cin >> q;
  vector<int> A(q), B(q);
  rep(i, q) {
    cin >> A[i] >> B[i];
    B[i]--;
    vector<vector<ll>> P = {{X[B[i]]}, {Y[B[i]]}, {1}};
    auto ret = prod(R[A[i]], P);
    cout << ret[0][0] << ' ' << ret[1][0] << endk;
  }
  return 0;
}
