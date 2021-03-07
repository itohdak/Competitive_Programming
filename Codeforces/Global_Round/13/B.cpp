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
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

void solve() {
  int n; ll u, v; cin >> n >> u >> v;
  vector<ll> A(n);
  set<ll> st;
  rep(i, n) {
    cin >> A[i];
    st.insert(A[i]);
  }
  bool ok = false;
  rep(i, n-1) {
    if(abs(A[i+1]-A[i]) > 1) ok = true;
  }
  if(ok) {
    cout << 0 << endk;
  } else if(st.size() == 1) {
    cout << min(2*v, u+v) << endk;
  } else {
    cout << min(v, u) << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
