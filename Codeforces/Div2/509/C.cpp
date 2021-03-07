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
  int n; ll m; int d;
  cin >> n >> m >> d;
  vector<ll> A(n); rep(i, n) cin >> A[i];
  map<ll, int> pos;
  set<ll> st;
  rep(i, n) {
    st.insert(A[i]);
    pos[A[i]] = i;
  }
  vector<int> ans(n);
  int i = 1;
  while(st.size()) {
    ll tmp = *st.begin();
    while(true) {
      ans[pos[tmp]] = i;
      st.erase(tmp);
      auto next = st.lower_bound(tmp+d+1);
      if(next == st.end()) break;
      tmp = *next;
    }
    i++;
  }
  cout << *max_element(all(ans)) << endk;
  rep(i, n) cout << ans[i] << ' ';
  cout << endk;
  return 0;
}
