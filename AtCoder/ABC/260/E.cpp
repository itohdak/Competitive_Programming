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
  int n, m; cin >> n >> m;
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  vector<ll> sum(m+2);
  vector<int> id(n);
  iota(all(id), 0);
  sort(all(id), [&](int i, int j) {
    return A[i] < A[j];
  });
  int lb = 0, ub = m;
  rep(i, n) {
    chmax(lb, A[i]);
    chmin(ub, B[i]);
  }
  int j = 0;
  REP(i, 1, ub+1) {
    int l = lb, h = m; // l-i+1 , h-i+1
    sum[l-i+1]++; sum[h-i+1+1]--;
    // cout << i << ' ' << l << ' ' << h << endk;
    while(j < n && A[id[j]] == i) {
      chmax(lb, B[id[j]]);
      j++;
    }
  }
  rep(i, m+1) sum[i+1] += sum[i];
  REP(i, 1, m+1) cout << sum[i] << ' ';
  cout << endk;
  return 0;
}
