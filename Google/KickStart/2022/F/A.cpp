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
  vector<string> C(n);
  vector<int> D(n);
  vector<int> U(n);
  rep(i, n) cin >> C[i] >> D[i] >> U[i];
  vector<int> id1(n), id2(n);
  iota(all(id1), 0);
  iota(all(id2), 0);
  sort(all(id1), [&](int i, int j) {
    if(C[i] == C[j]) {
      return U[i] < U[j];
    } else {
      return C[i] < C[j];
    }
  });
  sort(all(id2), [&](int i, int j) {
    if(D[i] == D[j]) {
      return U[i] < U[j];
    } else {
      return D[i] < D[j];
    }
  });
  int cnt = 0;
  rep(i, n) {
    if(id1[i] == id2[i]) cnt++;
  }
  cout << cnt << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
