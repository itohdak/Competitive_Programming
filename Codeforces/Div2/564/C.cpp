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
  int tmp = n-1;
  bool ok = true;
  while(tmp>=0) {
    if(B[tmp] == 1) break;
    if(B[tmp-1]+1 != B[tmp]) {
      ok = false;
      break;
    }
    tmp--;
  }
  if(ok) {
    set<int> st;
    rep(i, n) if(A[i]) st.insert(A[i]);
    int last = B[n-1];
    if(last == n) {
      cout << 0 << endk;
      return 0;
    }
    for(int i=last+1; i<=n; i++) {
      if(st.count(i)) {
        if(i == n) {
          cout << i-last << endk;
          return 0;
        }
      } else {
        break;
      }
      st.erase(i);
      st.insert(B[i-last-1]);
    }
  }
  int ans = 0;
  rep(i, n) {
    if(B[i] == 0) continue;
    chmax(ans, i+1-(B[i]-1));
  }
  cout << n+ans << endk;
  return 0;
}
