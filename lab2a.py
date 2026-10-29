n= int(input("Vertices: "))
e= int (input("Edges: "))

mat=[[0]*(n+1) for _ in range(n+1)]

for _ in range(e):
    u, v, w=map(int, input().split())
    mat[u][v]=w
    mat[v][u]=w

for row in mat:
    print(row)

h=[0]*(n+1)
for i in range(1, n+1):
    h[i]=int(input(f"Heuristic for {i}: "))

start= int(input("Start: "))
goal= int(input("Goal: "))

all_paths=[]

