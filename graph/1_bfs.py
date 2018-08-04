from graph import Graph

adj = {
	"s" : ["a", "b"],
	"a" : ["c", "s"],
	"b" : ["c", "d", "s"],
	"c" : ["a", "b", "d", "e"],
	"d" : ["b", "c", "e"],
	"e" : ["c", "d"]
}

g = Graph(adj)
g.bfs("s")
