#include <bits/stdc++.h>
#include "/home/itohdak/Codeforces/000/print.hpp"
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

void find_divisor(ll N, vector<ll>& divisor) {
  for(int i=1; i<=sqrt(N); i++) {
    if(N % i == 0)
      divisor.push_back(i);
  }
  int n = divisor.size();
  for(int i=n-1; i>=0; i--) {
    if(N != (ll)pow(divisor[i], 2))
      divisor.push_back(N / divisor[i]);
  }
}
void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  vector<ll> div;
  find_divisor(k, div);
  vector<int> cnt(26);
  rep(i, n) cnt[s[i]-'a']++;
  int ans = 0;
  for(int d: div) {
    // cout << d << endl;
    for(int i=1; i*d<=n; i++) {
      int tmp = 0;
      rep(j, 26) {
        tmp += cnt[j] / i;
      }
      // cout << i << ": " << tmp << endl;
      if(tmp >= d) {
        ans = max(ans, d*i);
      } else {
        break;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  rep(t, T) solve();
  return 0;
}
