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
  int n, k; cin >> n >> k;
  vector<vector<int>> P(n, vector<int>(3));
  vector<int> sum(n);
  rep(i, n) rep(j, 3) {
    cin >> P[i][j];
    sum[i] += P[i][j];
  }
  vector<int> sum2(n);
  copy(all(sum), begin(sum2));
  sort(all(sum2));
  rep(i, n) {
    if(end(sum2) - lower_bound(all(sum2), sum[i]+300+1) >= k) {
      cout << "No" << endk;
    } else {
      cout << "Yes" << endk;
    }
  }
  return 0;
}
