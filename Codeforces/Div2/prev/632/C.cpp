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

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), sum(N+1);
  map<ll, int> mp;
  mp[0] = 0;
  int l = -1;
  ll ans = 0;
  rep(i, N) {
    cin >> A[i];
    sum[i+1] = sum[i] + A[i];
    if(mp.count(sum[i+1])) l = max(mp[sum[i+1]], l);
    mp[sum[i+1]] = i+1;
    ans += i-l;
  }
  cout << ans << endl;
  return 0;
}
