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
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> B(n); rep(i, n) cin >> B[i];
  vector<int> ans(n);
  vector<int> id;
  set<int> st;
  rep(i, n) st.insert(i+1);
  rep(i, n) {
    if(A[i] == B[i]) {
      ans[i] = A[i];
      st.erase(ans[i]);
    } else {
      id.push_back(i);
    }
  }
  if(st.size() == 2) {
    int p1 = *st.begin();
    int p2 = *(++st.begin());
    if(int(p1 != A[id[0]]) + int(p1 != B[id[0]]) == 1 && int(p2 != A[id[1]]) + int(p2 != B[id[1]]) == 1) {
      ans[id[0]] = p1, ans[id[1]] = p2;
    } else {
      ans[id[0]] = p2, ans[id[1]] = p1;
    }
  } else if(st.size() == 1) {
    ans[id[0]] = *st.begin();
  } else {
    assert(false);
  }
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
