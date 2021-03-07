MAX_N = 200005

class UnionFind:
    par = [0] * MAX_N
    depth = [0] * MAX_N
    n_group = [0] * MAX_N
    def __init__(self, n: int):
        for i in range(n):
            self.par[i] = i
            self.depth[i] = 0
            self.n_group[i] = 1

    def root(self, x: int):
        if self.par[x] == x:
            return x
        else:
            self.par[x] = self.root(self.par[x])
            return self.par[x]

    def same(self, x: int, y: int):
        return self.root(x) == self.root(y)

    def unite(self, x: int, y: int):
        x = self.root(x)
        y = self.root(y)
        if x == y:
            return
        if self.depth[x] < self.depth[y]:
            self.par[x] = y
            self.n_group[y] += self.n_group[x]
            self.n_group[x] = 0
        else:
            self.par[y] = x
            self.n_group[x] += self.n_group[y]
            self.n_group[y] = 0
            if self.depth[x] == self.depth[y]:
                self.depth[x] += 1
