#include <bits/stdc++.h>
#include <print.hpp>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define ll long long
#define ld long double
#define REP(i,m,n) for(int i=(int)(m); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define RREP(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define rrep(i,n) RREP(i,(n)-1,0)
#define all(v) v.begin(), v.end()
#define endk '\n'
const int inf = 1e9+7;
const ll longinf = 1LL<<60;
const ll mod = 1e9+7;
const ll mod2 = 998244353;
const ld eps = 1e-10;
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b){if(a>b) a=b;}
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b){if(a<b) a=b;}

struct Ad {
  int x0, y0, x1, y1; // (x0, y0), (x1, y1)
  int r; // required

  Ad(int a, int b, int c, int d, int _r) {
    x0 = a, y0 = b, x1 = c, y1 = d;
    r = _r;
  }
  int area() {
    return (x1-x0)*(y1-y0);
  }
  double score() {
    int s = area();
    return 1 - pow((1 - 1.0 * min(r, s) / max(r, s)), 2);
  }
  double scoreDiff(char edge, int delta) {
    if(edge == 'L') {
      int ynew = y0 + delta;
      assert(ynew < y1);
    } else if(edge == 'R') {
    } else if(edge == 'U') {
    } else if(edge == 'D') {
    } else {
      assert(false);
    }
  }
};

struct AdsBoard {
  int sz;
  vector<int> occupied;
  vector<Ad> Ads;

  AdsBoard(int n, vector<int>& X, vector<int>& Y, vector<int>& R, int _sz=10000) {
    sz = _sz;
    occupied.assign(sz*sz, -1);
    rep(i, n) {
      Ads.push_back(Ad(X[i], Y[i], X[i]+1, Y[i]+1, R[i]));
      occupied[X[i]*sz+Y[i]] = i;
    }
  }
};

int sz = 10000;
int n;
vector<int> X, Y, R;
vector<int> A, B, C, D;
vector<int> occupied(sz*sz, -1);
map<string, vector<int>> mp = {{"left",  { 0, -1, 0, 0}},
                               {"right", { 0,  0, 0, 1}},
                               {"up",    {-1,  0, 0, 0}},
                               {"down",  { 0,  0, 1, 0}}};
int calcArea(int i) {
  return (C[i]-A[i])*(D[i]-B[i]);
}
double calcScore(int r, int s) {
  return 1 - pow((1 - 1.0 * min(r, s) / max(r, s)), 2);
}
ld calcScoreDiff(int i, string direction, string whichEdge, int width=1) {
  // TODO
  auto d = mp[direction];
  vector<int> curCoords = {A[i], B[i], C[i], D[i]};
  vector<int> nextCoords = {A[i]+d[0]*width, B[i]+d[1]*width, C[i]+d[2]*width, D[i]+d[3]*width};
  return 0;
};
bool checkInsideBound(vector<int>& coords) {
  assert(coords.size() == 4);
  REP(k, 0, 2) if(coords[k] < 0 || coords[k] >= sz) return false;
  REP(k, 2, 4) if(coords[k] <= 0 || coords[k] > sz) return false;
  return true;
}
set<int> checkExpandableSub(int xb, int yb, int xe, int ye) {
  set<int> opponent;
  for(int x=xb; x<xe; x++) {
    for(int y=yb; y<ye; y++) {
      if(occupied[x*sz+y] >= 0) {
        opponent.insert(occupied[x*sz+y]);
      }
    }
  }
  return opponent;
}
set<int> checkExpandable(int a, int b, int c, int d, string direction) {
  if(direction == "left") {
    return checkExpandableSub(a, b-1, c, b);
  } else if(direction == "right") {
    return checkExpandableSub(a, d, c, d+1);
  } else if(direction == "up") {
    return checkExpandableSub(a-1, b, a, d);
  } else if(direction == "down") {
    return checkExpandableSub(c, b, c+1, d);
  } else {
    assert(false);
  }
}
void occupySub(int xb, int yb, int xe, int ye, int i) {
  for(int x=xb; x<xe; x++) {
    for(int y=yb; y<ye; y++) {
      occupied[x*sz+y] = i;
    }
  }
}
void occupy(int a, int b, int c, int d, int i, string direction) {
  if(direction == "left") {
    return occupySub(a, b-1, c, b, i);
  } else if(direction == "right") {
    return occupySub(a, d, c, d+1, i);
  } else if(direction == "up") {
    return occupySub(a-1, b, a, d, i);
  } else if(direction == "down") {
    return occupySub(c, b, c+1, d, i);
  } else {
    assert(false);
  }
}
pair<bool, double> costExpand(int i, string direction, int width=1) {
  assert(mp.count(direction));
  auto d = mp[direction];
  vector<int> curCoords = {A[i], B[i], C[i], D[i]};
  vector<int> nextCoords = {A[i]+d[0]*width, B[i]+d[1]*width, C[i]+d[2]*width, D[i]+d[3]*width};

  // check if not out of bounds
  if(!checkInsideBound(nextCoords)) return {false, 0};

  // check if not occupied by other square
  set<int> opponent = checkExpandable(A[i], B[i], C[i], D[i], direction);
  if(opponent.size()) {
    return {false, 0};
  }

  ld scoreDiff = 0;
  scoreDiff += calcScore(R[i], (nextCoords[2]-nextCoords[0])*(nextCoords[3]-nextCoords[1]))
               - calcScore(R[i], (curCoords[2]-curCoords[0])*(curCoords[3]-curCoords[1]));
  for(int op: opponent) {
    // TODO
  }
  return {true, scoreDiff};
};
bool expand(int i, string direction) {
  assert(mp.count(direction));
  auto d = mp[direction];
  vector<int> curCoords = {A[i], B[i], C[i], D[i]};
  vector<int> nextCoords = {A[i]+d[0], B[i]+d[1], C[i]+d[2], D[i]+d[3]};
  if(checkExpandable(A[i], B[i], C[i], D[i], direction).size()) {
    // TODO
    return false;
  }
  // cerr << i << ": " << "expand " << direction << endk;
  occupy(A[i], B[i], C[i], D[i], i, direction);
  A[i] = nextCoords[0];
  B[i] = nextCoords[1];
  C[i] = nextCoords[2];
  D[i] = nextCoords[3];
  return true;
}
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n;
  X.assign(n, 0); Y.assign(n, 0); R.assign(n, 0);
  A.assign(n, 0); B.assign(n, 0); C.assign(n, 0); D.assign(n, 0);
  rep(i, n) {
    cin >> X[i] >> Y[i] >> R[i];
    A[i] = X[i],   B[i] = Y[i];
    C[i] = X[i]+1, D[i] = Y[i]+1;
    occupied[A[i]*sz+B[i]] = i;
  }
  priority_queue<pair<double, tuple<int, string, int>>> q; // {scoreDiff, {id, dir, area}}
  string dir[] = {"left", "right", "up", "down"};
  rep(i, n) {
    for(string d: dir) {
      auto ret = costExpand(i, d);
      if(ret.first) {
        q.push({ret.second, {i, d, calcArea(i)}});
      }
    }
  }
  while(q.size()) {
    // cerr << "size of queue: " << q.size() << endk;
    auto [scoreDiff, info] = q.top(); q.pop();
    auto [i, d, area] = info;
    if(area != calcArea(i)) {
      // cerr << i << ": area in queue doesn't match the current area " << area << " vs " << calcArea(i) << endk;
      continue;
    }
    if(scoreDiff <= 0) {
      // cerr << i << ": score doesn't expected to increase. passing. " << scoreDiff << endk;
      continue;
    }
    // cerr << i << ": expected score increase is " << scoreDiff << endk;
    bool succeed = expand(i, d);
    if(succeed) {
      for(string d: dir) {
        auto ret = costExpand(i, d);
        if(ret.first) {
          q.push({ret.second, {i, d, calcArea(i)}});
        }
      }
    } else {
      // cerr << i << ": expand failed" << endk;
    }
  }
  rep(i, n) {
    cout << A[i] << ' ' << B[i] << ' ' << C[i] << ' ' << D[i] << endk;
  }
  // rep(i, n) {
  //   cerr << i << ": final area is " << calcArea(i) << endk;
  // }
  return 0;
}
