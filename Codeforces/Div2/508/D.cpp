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
  vector<int> cnt(3);
  vector<ll> sum(3);
  rep(i, n) {
    if(A[i] == 0) {
      cnt[0]++;
    } else if(A[i] > 0) {
      cnt[1]++;
      sum[1] += A[i];
    } else {
      cnt[2]++;
      sum[2] += A[i];
    }
  }
  if(n == 1) {
    cout << A[0] << endk;
  } else if(cnt[1] == n) {
    cout << sum[1] - 2 * *min_element(all(A)) << endk;
  } else if(cnt[2] == n) {
    cout << 2 * *max_element(all(A)) - sum[2] << endk;
  } else {
    cout << sum[1] - sum[2] << endk;
  }
  return 0;
}
