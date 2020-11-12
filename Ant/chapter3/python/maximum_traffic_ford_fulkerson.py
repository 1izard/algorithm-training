INF = int(1e9)


def ns(f):
    return next(f).strip()


class Edge:
    def __init__(self, v, cap, rev):
        self.v = v
        self.cap = cap
        self.rev = rev


with open("../testset/maximum_traffic/test1.txt", 'r') as f:
    n, m, s, t = map(int, ns(f).split())
    G = [[] for _ in range(n)]
    for _ in range(m):
        u, v, cap = map(int, ns(f).split())
        G[u].append(Edge(v, cap, len(G[v])))
        G[v].append(Edge(u, cap, len(G[u]) - 1))


def dfs(u, t, f, used):
    if u == t:
        return f
    used[u] = True
    for e in G[u]:
        if not used[e.v] and e.cap > 0:
            d = dfs(e.v, t, min(f, e.cap), used)
            if d > 0:
                e.cap -= d
                G[e.v][e.rev].cap += d
                return d
    return 0


res = 0
while True:
    used = [False] * n
    f = dfs(s, t, INF, used)
    if f == 0:
        print(res)
        exit()
    res += f
