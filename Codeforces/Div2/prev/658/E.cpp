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
  int n, x, y; cin >> n >> x >> y;
  vector<int> B(n);
  rep(i, n) cin >> B[i];
  map<int, deque<int>> mp;
  set<int> st;
  rep(i, n+1) st.insert(i+1);
  rep(i, n) {
    st.erase(B[i]);
    mp[B[i]].push_back(i);
  }
  priority_queue<pair<int, int>> q;
  for(auto ele: mp) {
    q.push({ele.second.size(), ele.first});
  }
  vector<int> tmp(n);
  int rem = n;
  rep(i, x) {
    auto ele = q.top(); q.pop();
    int p = mp[ele.second].back();
    tmp[p] = ele.second;
    mp[ele.second].pop_back();
    ele.first--;
    rem--;
    if(ele.first) q.push({ele.first, ele.second});
  }
  cerr << tmp << endl;
  vector<pair<int, int>> v;
  rep(i, n-y) {
    auto ele = q.top(); q.pop();
    int p = mp[ele.second].front();
    tmp[p] = *st.begin();
    v.push_back({ele.second, p});
    mp[ele.second].pop_front();
    ele.first--;
    rem--;
    if(ele.first) q.push({ele.first, ele.second});
  }
  cerr << tmp << endl;
  assert(rem == y-x);
  bool ok = true;
  while(!q.empty()) {
    auto ele = q.top(); q.pop();
    if(ele.first > n-x-ele.first) ok = false;
    for(int p: mp[ele.second]) {
      tmp[p] = ele.second;
      v.push_back({ele.second, p});
    }
  }
  cerr << tmp << endl;
  if(!ok) {
    cout << "No" << "\n";
    return;
  }
  sort(all(v));
  assert((int)v.size() == n-x);
  vector<int> ans(n);
  copy(all(tmp), ans.begin());
  cerr << v << endl;
  cerr << ans << endl;
  cerr << tmp << endl;
  rep(i, v.size()) {
    ans[v[(i+(n-x)/2)%(n-x)].second] = tmp[v[i].second];
  }
  cerr << ans << endl;
  int x_ = 0;
  rep(i, n) if(ans[i] == B[i]) x_++;
  cerr << x_ << endl;
  if(x_ != x) {
    cout << "No" << "\n";
  } else {
    cout << "Yes" << "\n";
    for(int a: ans) cout << a << ' ';
    cout << "\n";
  }
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
