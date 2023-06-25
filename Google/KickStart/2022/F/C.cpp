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
  ll d;
  ll n, x; cin >> d >> n >> x;
  vector<ll> Q(n), L(n), V(n);
  rep(i, n) cin >> Q[i] >> L[i] >> V[i];
  vector<ll> id(n);
  iota(all(id), 0);
  sort(all(id), [&](ll i, ll j) {
    return L[i] < L[j];
  });
  priority_queue<pair<ll, ll>> q;
  ll l = 0;
  ll ans = 0;
  while(l < n) {
    ll r = l;
    while(r < n && L[id[l]] == L[id[r]]) {
      q.push({V[id[r]], Q[id[r]]});
      r++;
    }
    ll nx = (r==n ? d: L[id[r]]);
    ll rem = (nx-L[id[l]])*x;
    while(q.size() && rem) {
      auto top = q.top();
      q.pop();
      if(top.second <= rem) {
        ans += top.second * top.first;
        rem -= top.second;
      } else {
        ans += rem * top.first;
        top.second -= rem;
        rem = 0;
        q.push(top);
      }
    }
    l = r;
  }
  cout << ans << endk;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(i, T) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  return 0;
}
