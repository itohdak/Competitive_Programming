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
  int k; ll n, m; cin >> k >> n >> m;
  vector<ll> A(k); rep(i, k) cin >> A[i];
  priority_queue<pair<ll, int>> q;
  vector<ll> B(k);
  ll rem = m;
  rep(i, k) {
    B[i] = A[i]*m/n;
    rem -= B[i];
    ll base = A[i]*m;
    ll before = base-B[i]*n;
    ll after = (B[i]+1)*n-base;
    q.push({before-after, i}); // 足したらどれだけ減るか
  }
  assert(rem >= 0);
  while(rem) {
    auto [val, i] = q.top(); q.pop();
    B[i]++;
    rem--;
  }
  rep(i, k) cout << B[i] << ' ';
  cout << endk;
  return 0;
}
