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
  int rem = n-k;
  for(int i=1; i<=rem; i++) {
    if(rem <= i+(k-2)*((i-1)/2)) {
      cout << i+1 << endk;
      vector<pair<int, int>> edge;
      int tmp = 1;
      rep(j, i-1) {
        edge.push_back({tmp, tmp-1});
        tmp++;
      }
      rem -= i;
      edge.push_back({tmp++, 0});
      edge.push_back({tmp++, i-1});
      k -= 2;
      for(int j=(i-1)/2; j>=0; j--) {
        while(k && rem >= j) {
          edge.push_back({tmp++, j});
          rep(_, j) {
            edge.push_back({tmp, tmp-1});
            tmp++;
          }
          k--;
          rem -= j;
        }
      }
      assert((int)edge.size() == n-1);
      for(auto [u, v]: edge) cout << u+1 << ' ' << v+1 << endk;
      break;
    }
  }
  return 0;
}
