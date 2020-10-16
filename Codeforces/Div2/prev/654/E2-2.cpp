#include <bits/stdc++.h>
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

void solve() {
  int n, p;
  cin >> n >> p;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  sort(all(A));
  ll mx = *max_element(all(A));
  deque<ll> cnt(n);
  rep(i, n) cnt[i] = upper_bound(all(A), mx-n+1+i)-begin(A);
  rep(i, n) cnt[i] -= i;
  multiset<ll> se;
  rep(i, n) se.insert(cnt[i]);
  vector<ll> ans;
  for(ll i=mx-n+1; i<=mx; i++) {
    if(*se.begin() > 0-(i-(mx-n+1)) &&
       *(--se.end()) < p-(i-(mx-n+1))) ans.push_back(i);
    ll front = cnt.front(); cnt.pop_front();
    se.erase(se.find(front));
  }
  cout << ans.size() << "\n";
  for(ll a: ans) cout << a << ' ';
  cout << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
