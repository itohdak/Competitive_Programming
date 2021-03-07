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
  ll n; int k; cin >> n >> k;
  vector<ll> cnt;
  rep(i, 40) {
    if((n>>i)&1) cnt.push_back(1LL<<i);
  }
  if(k < (int)cnt.size() || k > n) {
    cout << "NO" << endk;
  } else {
    cout << "YES" << endk;
    priority_queue<ll> q;
    for(ll a: cnt) q.push(a);
    while((int)q.size() < k) {
      ll top = q.top();
      q.pop();
      q.push(top/2);
      q.push(top/2);
    }
    assert((int)q.size() == k);
    rep(i, k) {
      cout << q.top() << ' ';
      q.pop();
    }
    cout << endk;
  }
  return 0;
}
