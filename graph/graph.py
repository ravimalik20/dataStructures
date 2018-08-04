class Queue:
	def __init__(self):
		self.queue = []

	def put(self, elem):
		self.queue.append(elem)

	def get(self):
		val = self.queue[0]
		del (self.queue[0])
		return val

	def __len__(self):
		return len(self.queue)

	def __str__(self):
		return self.queue.__str__()

class Stack:
	def __init__(self):
		self.stack = []

	def put(self, elem):
		self.stack.append(elem)

	def get(self):
		return self.stack.pop()

	def __len__(self):
		return len(self.stack)

	def __str__(self):
		return self.stack.__str__()

class Graph:
	def __init__(self, adj):
		self.adj = adj

	def bfs(self, s):
		visited = set()
		queue = Queue()
		queue.put(s)

		while len(queue) > 0:
			e = queue.get()

			if e in visited:
				continue

			visited.add(e)

			print (e + " ", end = '')

			for v in self.adj[e]:
				if v in visited:
					continue

				queue.put(v)

		print ("")

	def dfs(self, s):
		visited = set()
		stack = Stack()
		stack.put(s)

		while len(stack) > 0:
			e = stack.get()
			if e in visited:
				continue

			visited.add(e)
			print (e, end=' ')

			for v in self.adj[e]:
				stack.put(v)

		print ("")
