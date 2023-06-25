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

void solve() {
  ll n, k; cin >> n >> k;
  ll al, ar, bl, br; cin >> al >> ar >> bl >> br;
  int type = 0;
  if((al<=bl && br<=ar) || (bl<=al && ar<=br)) type = 0;
  else if(ar<bl || br<al) type = 2;
  else type = 1;
  if(type == 0) {
    ll la = ar-al+1;
    ll lb = br-bl+1;
    ll mx = max(la, lb);
    ll mn = min(la, lb);
    if(mn*n >= k) {
      cout << 0 << "\n";
      return;
    }
    if(mx*n >= k) {
      cout << k-mn*n << "\n";
      return;
    }
  } else if(type == 1) {
    ll mx = max(ar, br)-min(al, bl)+1;
    if((ar<=bl && (ar-bl+1)*n>=k) ||
       (br<=al && (br-al+1)*n>=k)) {
      cout << 0 << "\n";
      return;
    }
    if(mx*n >= k) {
      cout << k-(ar-bl+1)*n << "\n";
      return;
    }
  } else {
    ll mx = max(ar, br)-min(al, bl)+1;
    if(mx*n >= k) {
      ll la = ar-al+1;
      ll lb = br-bl+1;
      ll tmp = k/mx*(mx-la+mx-lb);
      ll cur = k/mx*mx;
      if(cur >= k) {
        cout << tmp << "\n";
        return;
      }
      cout << tmp << " ";
      tmp += min(abs(ar-bl), abs(br-al));
      cout << tmp+(k-cur) << "\n";
      return;
    }
  }
  ll ans = 0;
  ll l = min(al, bl);
  ll r = max(ar, br);
  ans = (r-l+1)*n-(ar-al+1)*n-(br-bl+1)*n;
  ll tmp = (r-l+1)*n;
  ll tmp2 = (k-tmp)/(n*n)*(2*n);
  ans += tmp2;
  tmp += tmp2*(n*n);
  if(k-tmp <= n) {
    ans += k-tmp+1;
  } else {
    ans += n;
    ans += (k-tmp+n-1)/n;
  }
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
