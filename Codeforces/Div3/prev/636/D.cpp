#include <bits/stdc++.h>
// #include "/home/itohdak/Codeforces/000/print.hpp"
using namespace std;
#define ll long long
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,n-1,0)
#define REPL(i,m,n) for(ll i=(ll)(m); i<(ll)(n); i++)
#define repl(i,n) REPL(i,0,n)
#define all(v) v.begin(), v.end()
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;

void solve() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i, N) cin >> A[i];
  map<ll, int> mp;
  rep(i, N/2) {
    ll mn = min(A[i], A[N-1-i]);
    ll sum = A[i]+A[N-1-i];
    mp[2] += 2;
    mp[mn+1] += -1;
    mp[sum] += -1;
    mp[sum+1] += 1;
    mp[sum+(K-mn)+1] += 1;
  }
  auto itr = mp.begin();
  int tmp = itr->second;
  int ans = tmp;
  itr++;
  while(itr->first <= 2*K && itr != mp.end()) {
    tmp += itr->second;
    ans = min(tmp, ans);
    itr++;
  }
  cout << ans << endl;
}
int main() {
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
