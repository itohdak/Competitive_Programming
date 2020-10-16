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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll k;
  cin >> k;
  string s = "codeforces";
  if(k == 1) {
    cout << s << endl;
    return 0;
  }
  rep(i, 100) {
    if(i == 0) continue;
    ll tmp = pow((ll)i, 10);
    if(tmp >= k) {
      ll tmp2 = pow((ll)(i-1), 10);
      rep(j, 10) {
        if(tmp2 < k) {
          // cout << i << endl;
          cout << string(i, s[j]);
          (tmp2 /= (i-1)) *= i;
        } else {
          // cout << i-1 << endl;
          cout << string(i-1, s[j]);
        }
      }
      cout << endl;
      break;
    }
  }
  return 0;
}
