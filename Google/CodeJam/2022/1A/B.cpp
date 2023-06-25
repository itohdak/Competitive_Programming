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

vector<ll> A;
void solve() {
  int n; cin >> n;
  rep(i, 100) cout << A[i] << ' ';
  cout << endl;
  vector<ll> B(n);
  rep(i, n) cin >> B[i];
  ll sum = accumulate(all(A), 0LL) + accumulate(all(B), 0LL);
  sum /= 2;
  vector<ll> C;
  rep(i, 100) C.push_back(A[i]);
  rep(i, 100) C.push_back(B[i]);
  sort(all(C));
  vector<ll> ans;
  rrep(i, 200) {
    if(sum >= C[i]) {
      ans.push_back(C[i]);
      sum -= C[i];
    }
  }
  assert(sum == 0);
  rep(i, ans.size()) cout << ans[i] << ' ';
  cout << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  {
    set<ll> st;
    ll i = 1;
    while(1) {
      A.push_back(i);
      st.insert(i);
      if(i > 1000000000/2) break;
      i *= 2;
    }
    vector<ll> tmp;
    i = 1000000000;
    while(A.size()+tmp.size() < 100) {
      while(st.count(i)) i--;
      st.insert(i);
      tmp.push_back(i--);
    }
    reverse(all(tmp));
    for(auto i: tmp) A.push_back(i);
    assert(A.size() == 100);
  }
  int t; cin >> t;
  rep(i, t) {
    solve();
  }
  return 0;
}
