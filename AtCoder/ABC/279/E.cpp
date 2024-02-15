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
  vector<int> A(m);
  rep(i, m) {
    cin >> A[i];
    A[i]--;
  }
  vector<int> B1(n), B2(n);
  vector<int> pos(n);
  iota(all(B1), 0);
  iota(all(B2), 0);
  iota(all(pos), 0);
  rrep(i, m) {
    if(i > 0) {
      swap(B2[A[i]], B2[A[i]+1]);
    }
  }
  rep(i, m) {
    cout << B2[pos[0]]+1 << endk;
    swap(pos[B1[A[i]]], pos[B1[A[i]+1]]);
    swap(B1[A[i]], B1[A[i]+1]);
    if(i+1 < m) swap(B2[A[i+1]], B2[A[i+1]+1]);
  }
  return 0;
}
