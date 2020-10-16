#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];
  map<ll, int, greater<ll> > mp;
  rep(i, N) {
    if(!mp.count(A[i])) mp[A[i]] = 1;
    else mp[A[i]]++;
  }
  int ans = 0;
  for(auto a: mp) {
    ll tmp = a.first;
    ll pair = (ll)pow(2, ceil(log2(tmp))) - tmp;
    if(pair == 0) {
      if(mp[tmp] > 0) {
        int cnt = mp[tmp] / 2;
        mp[tmp] -= 2 * cnt;
        ans += cnt;
      }
    } else {
      if(mp[tmp] > 0 && mp.count(pair) && mp[pair] > 0) {
        int cnt = min(mp[tmp], mp[pair]);
        mp[tmp] -= cnt;
        mp[pair] -= cnt;
        ans += cnt;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

