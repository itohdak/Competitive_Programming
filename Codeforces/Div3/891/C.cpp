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
  int m = n*(n-1)/2;
  vector<int> B(m); rep(i, m) cin >> B[i];
  sort(all(B));
  map<int, int> cnt;
  rep(i, m) cnt[B[i]]++;
  vector<int> A(n);
  int i = 0;
  for(auto [k, v]: cnt) {
    while(v) {
      assert(v >= n-i-1);
      A[i] = k;
      v -= (n-i-1);
      i++;
    }
  }
  A[n-1] = 1000000000;
  rep(i, n) cout << A[i] << ' ';
  cout << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}