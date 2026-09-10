/* 
    Algoritmo de Dijkstra é um algoritmo que busca o menor caminho a partir de uma determinada origem. 

    Abaixo está o pseudocódigo do algoritmo de Dijkstra que será implementado em C Ansi: 

Dijkstra(G, w, s, t) -> G(Graph) é o grafo, w(weight) é o peso das arestas, s(source) é o vértice de origem e t(target) é o destino
 1  para cada vértice v ∈ V[G] faça //Conjunto de todos os vértices do grafo G -> Quantidade de elementos = a ordem do grafo
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


O grafo que será utilizado para fim de execução será este: 

    'A': {'B': 10, 'C': 15, 'D': 20},
    'B': {'A': 10, 'C': 35, 'D': 25},
    'C': {'A': 15, 'B': 35, 'D': 30},
    'D': {'A': 20, 'B': 25, 'C': 30}




*/


#include <stdio.h>

int matrizAdjacencia[100][100]; //Grafo 

void Dijkstra(int ordem, int matrizAdjacencia[100][100],  int origem, int destino){

    /* Se comecarmos com a matriz de adjacencia com zero a chamada da funcao main com os valores do grafo e apagada
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            matrizAdjacencia[i][j] = 0; //Inicialização da variável de matriz de adjacência 
            pesoArestas[i][j] = 0; //Inicialização da variável de pesos
        }
    }
    */
    int distancia[100];
    int predecessor[100];
    int naoVisitados[100];

    //O -1 significa infinito -> Não conheço nenhum caminho para chegar a este vértice
    for(int vertice=0; vertice<ordem; vertice++){
        distancia[vertice] = -1;
        predecessor[vertice] = 0; 
        //naoVisitados poderia vir aqui para otimizar o trabalho 
    }
    distancia[origem] = 0;
    
    for(int vertice=0; vertice<ordem; vertice++){
        naoVisitados[vertice] = 1; 
    }

    while(1){
        int u = -1; 
        int menorDistancia = -1; 

            for(int vertice = 0; vertice < ordem; vertice++){
                if(naoVisitados[vertice] == 1){ //Foi visitada? 
                    if(distancia[vertice] != -1){ //Consigo chegar nela? 
                        if(menorDistancia == -1 || distancia[vertice] < menorDistancia){ //Se a menor distancia for a primeira cidade com -1 ou se a distancia do vértice for menor do que a variavel menorDistancia acontece abaixo 
                            menorDistancia = distancia[vertice];
                            u = vertice;
                        }
                    }
                }
            }

            if(u == -1 || distancia[u] == -1 || u == destino)
                break; 
            
            naoVisitados[u] = 0;

            for(int vizinho = 0; vizinho < ordem; vizinho++){
                if(matrizAdjacencia[u][vizinho] != 0){ //Tem ligação? 
                    if(naoVisitados[vizinho] == 1){ //Ele não foi visitado? Sim - entra; Não - sai. 
                        if(distancia[vizinho] == -1 || distancia[u] + matrizAdjacencia[u][vizinho] < distancia[vizinho]){ //É primeiro caminho que achei ou o novo caminho é melhor? 
                            distancia[vizinho] = distancia[u] + matrizAdjacencia[u][vizinho];
                            predecessor[vizinho] = u; 
                        }
                }
                }

            }
    }


    return distancia[destino];

    
}



int main() {

    int ordem; //Ordem do grafo 
    printf("Digite a ordem do grafo: ");
    scanf("%d", &ordem); 

    int grafo[100][100]; //Grafo

   /* Todas as ligações de A */ 
    grafo[0][1] = 10;
    grafo[0][2] = 15;
    grafo[0][3] = 20; 

   /* Todas as ligações de B */
   grafo[1][0] = 10; 
   grafo[1][2] = 35;
   grafo[1][3] = 25;

    /*  Todas as ligações de C */    
    grafo[2][0] = 15;
    grafo[2][1] = 35;
    grafo[2][3] = 30;

    /* Todas as ligações de D */
    grafo[3][0] = 20;
    grafo[3][1] = 25;
    grafo[3][2] = 30;



    /* Imprime a matriz de adjacência do grafo */
    for(int i=0; i<ordem; i++){
        for(int j=0; j<ordem; j++){
            printf("%d ", grafo[i][j]);
        }
        printf("\n");
    }
    /* Fim da implementação da impressão da matriz de adjacência */

    

    return 0; 

}

//Quando for instalar o compilador do C no Visual Studio Code, você vai instalar a extensão e instalar o MSYS2 e colocar o caminho do compilador no PATH do sistema. 
// Depois disso, você poderá compilar e executar programas em C diretamente no Visual Studio Code.