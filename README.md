# **Complexidade De Algoritmos - Algoritmo de Dijkstra** 

O algoritmo de Dijkstra é um algoritmo de _Teoria dos Grafos_ utilizado para encontrar o caminho mais curto entre o vértice de origem e os demais vértices existentes com arestas de pesos não negativos. 

```
Dijkstra(G, w, s, t) -> G(Graph) é o grafo, w(weight) é o peso das arestas, s(source) é o vértice de origem e t(target) é o destino
 1  para cada vértice v ∈ V[G] faça 
 2      dist[v] ← ∞
 3      pred[v] ← NIL
 4  dist[s] ← 0
 5  NaoVisitados ← V[G]
 6  enquanto NaoVisitados ≠ ∅ faça
 7      u ← NIL
 8      menorDist ← ∞
 9      para cada vértice v ∈ NaoVisitados faça
10          se dist[v] < menorDist então
11              menorDist ← dist[v]
12              u ← v
13      se u = NIL ou dist[u] = ∞ ou u = t então
14          interrompa
15      NaoVisitados ← NaoVisitados \ {u}
16      para cada vizinho v ∈ Adj[u] faça
17          se v ∈ NaoVisitados então
18              se dist[u] + w(u, v) < dist[v] então
19                  dist[v] ← dist[u] + w(u, v)
20                  pred[v] ← u
21  retorna dist[t]
``` 

