from graph import Graph

class TopologicalGraph(Graph):
    def __init__(self, adj):
        Graph.__init__(self, adj)
        self.explored = set()
        self.order = {}        

        self.__index_order = len(self.adj)

    def dfs(self, s):
        self.explored.add(s)

        for v in self.adj[s]:
            if v not in self.explored:
                self.dfs(v)

        self.order[self.__index_order] = s
        self.__index_order -= 1

    def topo_order(self):
        vertices = self.adj.keys()

        for v in vertices:
            if v not in self.explored:
                self.dfs(v)

        return self.order

if __name__ == "__main__":
    adj = {
        "s": ["v", "w"],
        "v": ["t"],
        "w": ["t"],
        "t": []
    }
    g = TopologicalGraph(adj)
    print (g.topo_order())

    adj2 = {
        "5" : ["11"],
        "7" : ["11", "8"],
        "3" : ["8", "10"],
        "11": ["2", "9", "10"],
        "8" : ["9"],
        "2" : [],
        "9" : [],
        "10": []
    }
    g2 = TopologicalGraph(adj2)
    print (g2.topo_order())
