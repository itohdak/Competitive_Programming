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
  vector<vector<ll>> A(n, vector<ll>(5));
  rep(i, n) rep(j, 5) {
    cin >> A[i][j];
  }
  auto bsearch = [&]() {
    auto test = [&](int m) -> bool {
      set<int> st;
      rep(i, n) {
        int tmp = 0;
        rep(j, 5) if(A[i][j] >= m) tmp ^= 1<<j;
        st.insert(tmp);
      }
      for(int i: st) for(int j: st) for(int k: st) {
        if((i|j|k) == (1<<5)-1) return true;
      }
      return false;
    };
    int ok = 1, ng = inf;
    while(abs(ok-ng)>1) {
      int mid = (ok+ng)/2;
      (test(mid) ? ok : ng) = mid;
    }
    return ok;
  };
  cout << bsearch() << endk;
  return 0;
}
