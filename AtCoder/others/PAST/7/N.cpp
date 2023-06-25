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
  int q; cin >> q;
  vector<int> A(q), B(q), C(q), D(q);
  vector<int> row, col;
  rep(i, q) {
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    A[i]--; B[i]--;
    row.push_back(A[i]);
    row.push_back(C[i]);
    col.push_back(B[i]);
    col.push_back(D[i]);
  }
  sort(all(row));
  row.erase(unique(all(row)), end(row));
  auto idr = [&](int a) {
    return lower_bound(all(row), a) - begin(row);
  };
  sort(all(col));
  col.erase(unique(all(col)), end(col));
  auto idc = [&](int a) {
    return lower_bound(all(col), a) - begin(col);
  };
  return 0;
}
