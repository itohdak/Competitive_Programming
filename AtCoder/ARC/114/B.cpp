#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
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
// const ll mod = 1e9+7;
const ll mod = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

ll modpow(ll a, ll N) {
  ll ans = 1;
  ll tmp = a;
  while(N > 0) {
    if(N % 2 == 1) (ans *= tmp) %= mod;
    (tmp *= tmp) %= mod;
    N /= 2;
  }
  return ans;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<int> F(n);
  rep(i, n) {
    cin >> F[i];
    F[i]--;
  }
  scc_graph G(n);
  rep(i, n) G.add_edge(i, F[i]);
  auto ret = G.scc();
  ll ans = 1;
  for(auto ele: ret) {
    set<int> st;
    for(auto v: ele) st.insert(F[v]);
    bool ok = true;
    for(auto v: ele) if(!st.count(v)) ok = false;
    if(ok) (ans *= 2) %= mod;
  }
  cout << (ans-1+mod)%mod << endk;
  return 0;
}
