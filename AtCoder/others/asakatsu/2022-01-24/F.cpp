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
  vector<int> A(k); rep(i, k) cin >> A[i];
  vector<int> ans;
  set<int> st;
  rep(i, n) st.insert(i+1);
  rep(i, k) {
    if(i == k-1) {
      vector<int> tmp;
      for(auto s: st) tmp.push_back(s);
      reverse(all(tmp));
      for(auto s: tmp) ans.push_back(s);
    } else {
      if(*st.begin() == A[i]) {
        ans.push_back(A[i]);
        st.erase(A[i]);
      } else {
        ans.push_back(A[i]);
        ans.push_back(*st.begin());
        st.erase(A[i]);
        st.erase(*st.begin());
      }
    }
  }
  assert((int)ans.size() == n);
  rep(i, n) cout << ans[i] << ' '; cout << endk;
  return 0;
}
