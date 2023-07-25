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
  int n, k; cin >> n >> k;
  vector<int> A(n); rep(i, n) cin >> A[i];
  vector<vector<int>> tmp;
  tmp.push_back(vector<int>());
  rep(i, n) tmp.back().push_back(i);
  rrep(i, k) {
    vector<vector<int>> next;
    for(auto v: tmp) {
      vector<int> P, Q;
      for(auto a: v) {
	if((A[a]>>i)&1) P.push_back(a);
	else Q.push_back(a);
      }
      if(P.size() > 1) {
	next.push_back(P);
      }
      if(Q.size() > 1) {
	next.push_back(Q);
      }
    }
    if(next.empty()) {
      continue;
    } else {
      tmp = next;
    }
  }
  // cout << tmp << endk;
  int ans = 0;
  auto v = tmp[0];
  int a = A[v[0]], b = A[v[1]];
  rrep(i, k) {
    if(((a>>i)&1) == ((b>>i)&1)) {
      ans |= (!((a>>i)&1))<<i;
    }
  }
  cout << v[0]+1 << ' ' << v[1]+1 << ' ' << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
