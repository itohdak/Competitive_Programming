#include <bits/stdc++.h>
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
  int N, M, K;
  cin >> N >> M >> K;
  vector<set<int> > obsX(N), obsY(M);
  vector<set<int> > obs[] = {obsX, obsY};
  rep(i, N) { obs[0][i].insert(M); obs[0][i].insert(-1); }
  rep(i, M) { obs[1][i].insert(N); obs[1][i].insert(-1); }
  vector<set<int> > passed(2);
  passed[0].insert(M); passed[0].insert(-1);
  passed[1].insert(N); passed[1].insert(-1);
  rep(i, K) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    obs[0][x].insert(y);
    obs[1][y].insert(x);
  }
  int tmp[2] = {0, 0};
  int direc = 0; // 0, 1, 2, 3
  set<int>::iterator itr, itr2;
  ll prev_cnt = 0;
  ll cnt = 1;
  int ne;
  while(cnt != prev_cnt) {
    prev_cnt = cnt;

    int d1 = direc%2;
    int d2 = 1-d1;
    if(direc < 2) { // 0, 1
      itr = obs[d1][tmp[d1]].lower_bound(tmp[d2]+1);
      itr2 = passed[d2].lower_bound(tmp[d2]+1);
      ne = min(*itr - 1, *itr2 - 1);
    } else { // 2, 3
      itr = obs[d1][tmp[d1]].upper_bound(tmp[d2]-1);
      itr--;
      itr2 = passed[d2].upper_bound(tmp[d2]-1);
      itr2--;
      ne = max(*itr + 1, *itr2 + 1);
    }
    cnt += abs(ne - tmp[d2]);
    tmp[d2] = ne;
    passed[d1].insert(tmp[d1]);
    direc = (direc+1)%4;
  }
  if(cnt + (ll)K == (ll)N * (ll)M) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}

