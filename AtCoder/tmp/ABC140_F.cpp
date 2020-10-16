#include <bits/stdc++.h>
#include "/home/itohdak/AtCoder/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n; cin >> n;
  vector<ll> S(1<<n); rep(i, 1<<n) cin >> S[i];
  sort(all(S), greater<ll>());
  map<ll, int> mp;
  mp[S[0]]++;
  bool ok = true;
  rep(i, n) {
    map<ll, int> cur;
    for(int j=1<<i; j<1<<(i+1); j++) cur[S[j]]++;
    ll mx = cur.rbegin()->first;
    if(cur[mx] > (1<<i)-mp[mx]) {
      ok = false;
      break;
    }
    for(auto ele: cur) mp[ele.first] += ele.second;
  }
  cout << (ok ? "Yes" : "No") << "\n";
  return 0;
}
