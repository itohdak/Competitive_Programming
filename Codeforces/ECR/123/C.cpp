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
  int n; int x; cin >> n >> x;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<int> cum(n+1); rep(i, n) cum[i+1] = cum[i]+A[i];
  vector<int> mx(n+1, INT_MIN);
  rep(i, n+1) REP(j, i, n+1) {
    chmax(mx[j-i], cum[j]-cum[i]);
  }
  multiset<int> st;
  rep(i, n+1) st.insert(mx[i]);
  int tmp = 0;
  rep(i, n+1) {
    cout << max(tmp, *(--st.end())+x*i) << ' ';
    st.erase(st.find(mx[i]));
    chmax(tmp, mx[i]+x*i);
  }
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
