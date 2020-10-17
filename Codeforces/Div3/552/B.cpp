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
  vector<int> A(n); rep(i, n) cin >> A[i];
  set<int> st;
  rep(i, n) st.insert(A[i]);
  vector<int> v;
  for(int i: st) v.push_back(i);
  if(v.size() > 3) cout << -1 << endk;
  else if(v.size() == 1) cout << 0 << endk;
  else if(v.size() == 2) {
    if((v[1]-v[0])%2==0) cout << (v[1]-v[0])/2 << endk;
    else cout << v[1]-v[0] << endk;
  }
  else {
    if(v[2]-v[1] != v[1]-v[0]) cout << -1 << endk;
    else cout << v[2]-v[1] << endk;
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
