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
  int n; cin >> n;
  map<int, int> mp;
  rep(i, n) {
    int a; cin >> a;
    mp[a]++;
  }
  int q; cin >> q;
  auto check = [](int cnt2, int cnt4, int cnt6, int cnt8) {
    if(!cnt8 && !cnt6 && !cnt4) return false;
    if(cnt8) cnt8--, cnt4++;
    else if(cnt6) cnt6--, cnt2++;
    else if(cnt4) cnt4--;
    if(cnt8 || cnt6 || cnt4) return true;
    else if(cnt2 >= 2) return true;
    else return false;
  };
  int cnt2=0, cnt4=0, cnt6=0, cnt8=0;
  for(auto ele: mp) {
    if(ele.second >= 8) cnt8++;
    else if(ele.second >= 6) cnt6++;
    else if(ele.second >= 4) cnt4++;
    else if(ele.second >= 2) cnt2++;
  }
  rep(i, q) {
    char s; cin >> s;
    int x; cin >> x;
    if(s == '+') {
      if(mp[x] == 7) cnt6--, cnt8++;
      else if(mp[x] == 5) cnt4--, cnt6++;
      else if(mp[x] == 3) cnt2--, cnt4++;
      else if(mp[x] == 1) cnt2++;
      mp[x]++;
    } else {
      if(mp[x] == 8) cnt6++, cnt8--;
      else if(mp[x] == 6) cnt4++, cnt6--;
      else if(mp[x] == 4) cnt2++, cnt4--;
      else if(mp[x] == 2) cnt2--;
      mp[x]--;
    }
    cout << (check(cnt2, cnt4, cnt6, cnt8) ? "YES" : "NO") << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T = 1;
  while(T--) solve();
  return 0;
}
