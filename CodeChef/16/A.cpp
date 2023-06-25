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
  int n; cin >> n;
  string s; cin >> s;
  vector<int> A(n+1);
  A[0] = 0;
  rep(i, n) {
    if(s[i] == 'R') A[i+1] = A[i]+1;
    else            A[i+1] = A[i]-1;
  }
  // cout << A << endk;
  multiset<int> st(all(A));
  bool ok = false;
  rep(i, n) {
    if(*st.begin() <= A[i]-2 || *(--st.end()) >= A[i]+2) ok = true;
    st.erase(st.find(A[i]));
  }
  cout << (ok ? "Yes" : "No") << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
