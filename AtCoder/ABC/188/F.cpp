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
  ll x, y; cin >> x >> y;
  ll p[] = {2};
  ll c[] = {1, 1};
  priority_queue<ll> q;
  map<ll, ll> mp;
  q.push(y);
  mp[y] = 0;
  while(!q.empty()) {
    ll tmp = q.top(); q.pop();
    ll ne = tmp/2;
    if(!mp.count(ne)) {
      mp[ne] = longinf;
      q.push(ne);
    }
    chmin(mp[ne], mp[tmp]+(tmp-ne*2)*1+1);
    if(!mp.count(ne+1)) {
      mp[ne+1] = longinf;
      q.push(ne+1);
    }
    chmin(mp[ne+1], mp[tmp]+((ne+1)*2-tmp)*1+1);
    chmin(mp[ne+1], mp[ne]+1);
    chmin(mp[ne], mp[ne+1]+1);
    if(mp[tmp]+(tmp-q.top())*1 > 0) {
      chmin(mp[q.top()], mp[tmp]+(tmp-q.top())*1);
    }
  }
  auto lo = mp.lower_bound(x);
  ll ans = longinf;
  if(lo != mp.end()) {
    chmin(ans, abs(lo->first-x)+lo->second);
  }
  if(lo != mp.begin()) {
    lo--;
    chmin(ans, abs(lo->first-x)+lo->second);
  }
  cout << ans << endl;
  return 0;
}
