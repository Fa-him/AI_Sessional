n = int(input("Vertices: "))
e = int(input("Edges: "))

matrix = [[0] * (n + 1) for _ in range(n + 1)]

for _ in range(e):
    u, v, w = map(int, input().split())
    matrix[u][v] = w
    matrix[v][u] = w

for row in matrix[1:]:
    print(row[1:])

h = [0] * (n + 1)
for i in range(1, n + 1):
    h[i] = int(input(f"Heuristic for {i}: "))

start = int(input("Start: "))
goal = int(input("Goal: "))

all_paths = []

def find_paths(node, visited, path, g):
    if node == goal:
        f = g + h[node]
        all_paths.append((path[:], g, f))
        return
    for nxt in range(1, n + 1):
        if matrix[node][nxt] != 0 and nxt not in visited:
            visited.add(nxt)
            path.append(nxt)
            find_paths(nxt, visited, path, g + matrix[node][nxt])
            path.pop()
            visited.remove(nxt)

find_paths(start, {start}, [start], 0)

print("\nAll paths (g, h, f):")
for path, g, f in all_paths:
    print(f"{' -> '.join(map(str, path))}  g={g} h={h[goal]} f={f}")

best_path, best_g, best_f = min(all_paths, key=lambda x: x[2])
print(f"\nBest path (A*): {' -> '.join(map(str, best_path))}")
print(f"g={best_g} h={h[goal]} f={best_f}")
