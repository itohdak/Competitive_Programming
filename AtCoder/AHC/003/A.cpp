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

#define SIZE 30
double LR = 1.0;
vector<vector<double>> EX(SIZE, vector<double>(SIZE, 5000));
vector<vector<double>> EY(SIZE, vector<double>(SIZE, 5000));
std::random_device RND;
std::mt19937 MT((int)time(0));
std::uniform_real_distribution<> RAND(0, 1);
std::uniform_real_distribution<> RAND_DELTA(-1, 1);
double SCALE_DELTA = 10; // 1000;
double SCALE_HEURISTIC = 1; // 1000;

struct Node {
  int x, y, tx, ty;
  double cost, h;
  Node(int _x, int _y, int _tx, int _ty, double _cost): x(_x), y(_y), tx(_tx), ty(_ty), cost(_cost) {
    // h = sqrt((tx-x)*(tx-x)+(ty-y)*(ty-y));
    h = (abs(tx-x) + abs(ty-y)) * SCALE_HEURISTIC;
  }
public:
  bool operator>(const Node& other) const {
    return cost + h > other.cost + other.h;
  }
  bool operator<(const Node& other) const {
    return cost + h < other.cost + other.h;
  }
};

string Astar(int si, int sj, int ti, int tj) {
  priority_queue<Node, vector<Node>, greater<Node>> q;
  vector<bool> vis(SIZE*SIZE);
  vector<double> dist(SIZE*SIZE, inf);
  vector<int> par(SIZE*SIZE, -1);
  q.push(Node(si, sj, ti, tj, 0));
  dist[si*SIZE+sj] = 0;
  // ほぼダイクストラ
  while(q.size()) {
    auto curNode = q.top(); q.pop();
    int x = curNode.x, y = curNode.y;
    int cur = x*SIZE+y;
    if(vis[cur]) continue;
    if(dist[cur] < curNode.cost) continue;
    if(cur == ti*SIZE+tj) break;
    vis[cur] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    rep(k, 4) {
      int nx = x+dx[k], ny = y+dy[k];
      int ne = nx*SIZE+ny;
      if(nx < 0 || nx >= SIZE || ny < 0 || ny >= SIZE) continue;
      if(vis[ne]) continue;
      double cost = RAND_DELTA(MT)*SCALE_DELTA;
      if(dx[k] == 1) cost += EX[y][x];
      else if(dx[k] == -1) cost += EX[y][x-1];
      else if(dy[k] == 1) cost += EY[x][y];
      else if(dy[k] == -1) cost += EY[x][y-1];
      if(dist[ne] > curNode.cost+cost) {
        dist[ne] = curNode.cost+cost;
        par[ne] = cur;
        q.push(Node(nx, ny, ti, tj, curNode.cost+cost));
      }
    }
  }
  // 経路復元
  assert(par[ti*SIZE+tj] != -1);
  string path = "";
  int tmp = ti*SIZE+tj;
  while(par[tmp] != -1) {
    int diff = tmp-par[tmp];
    if(diff == 1) path += 'R';
    else if(diff == -1) path += 'L';
    else if(diff == SIZE) path += 'D';
    else if(diff == -SIZE) path += 'U';
    else assert(false);
    tmp = par[tmp];
  }
  reverse(all(path));
  return path;
}

string build_path(int si, int sj, int ti, int tj) {
  return Astar(si, sj, ti, tj);
}

double calc_expect(int si, int sj, int ti, int tj, string path) {
  double sum = 0;
  int x = si, y = sj;
  for(char c: path) {
    if(c == 'D') {
      sum += EX[y][x];
      x++;
    } else if(c == 'U') {
      sum += EX[y][x-1];
      x--;
    } else if(c == 'R') {
      sum += EY[x][y];
      y++;
    } else if(c == 'L') {
      sum += EY[x][y-1];
      y--;
    }
  }
  assert(x == ti && y == tj);
  return sum;
}

bool update_expect(int si, int sj, int ti, int tj, string path, double response, double expected) {
  int x = si, y = sj;
  double delta = (response - expected) / expected * LR;
  for(char c: path) {
    if(c == 'D') {
      EX[y][x] *= (1+delta);
      x++;
    } else if(c == 'U') {
      EX[y][x-1] *= (1+delta);
      x--;
    } else if(c == 'R') {
      EY[x][y] *= (1+delta);
      y++;
    } else if(c == 'L') {
      EY[x][y-1] *= (1+delta);
      y--;
    }
  }
  assert(x == ti && y == tj);
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  rep(t, 1000) {
    int si, sj, ti, tj; cin >> si >> sj >> ti >> tj;
    auto path = build_path(si, sj, ti, tj);
    cout << path << endl;
    ll res; cin >> res;
    double exp = calc_expect(si, sj, ti, tj, path);
    update_expect(si, sj, ti, tj, path, res, exp);
    LR -= 0.0001;
  }
  return 0;
}
