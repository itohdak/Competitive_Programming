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
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

#define mint modint998244353

vector<ll> find_divisor(ll N) {
  vector<ll> divisor;
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
  return divisor;
}

mint pw2[100001];
void make() {
  pw2[0] = 1;
  rep(i, 100000) {
    pw2[i+1] = pw2[i] * 2;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  make();
  int n; cin >> n;
  string s; cin >> s;
  auto D = find_divisor(n);
  vector<mint> ans(n+1);
  mint last_ans = 0;
  for(auto d: D) {
    if(d == n) continue;
    set<int> st;
    rep(i, n) {
      if(s[i] == '.') {
	st.insert(i%d);
      }
    }
    int ng = st.size();
    int ok = d-ng;
    ans[d] += pw2[ok];
    last_ans += ans[d];
    for(int j=2*d; j<=n; j+=d) {
      ans[j] -= ans[d];
    }
  }
  cout << last_ans.val() << endk;
  return 0;
}
