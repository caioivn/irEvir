#include <cstdlib>
#include <iostream>

using namespace std;

class intersecoes{
public:
    int visitado;

    intersecoes(){
        visitado = 0;
    }
    
};


/*
 *Método que percorre interseções e seus adjacentes ainda não visitados
 */
int visitaVertice(intersecoes inter[], int **adjacencia, int linha, int coluna){
    int i, j = 0, cont = 0, aux;
	i = 0;
    while(i < linha){
        if(adjacencia[i][j]!=-1){
            //Visitado igual a 0 (interseção ainda não visitada)
            if(inter[j].visitado == 0){
                cont++;
                //Vsisitado igual a 1 (interseção já visitada)
                inter[j].visitado = 1;
            }
            aux = adjacencia[i][j];
            adjacencia[i][j] = -1;
            j = aux;
            i=-1;
        }
        i++;
    }
    return cont;
}

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    while(n!=0 && m!=0){
        intersecoes inter[n];
        int **adjacencia;
        /*
         *Alocação da matriz de adjacencia
         */
        adjacencia = (int **) malloc(m * sizeof(int *));
        for(int i = 0; i < m; i++){
            adjacencia[i] = (int *)malloc(n * sizeof(int));
            for(int j = 0; j < n; j++){
                adjacencia[i][j] = -1;
            }
        }
        for(int i = 0; i < m; i++){
            int inicio, fim, direcao;
            cin >> inicio;
            cin >> fim;
            cin >> direcao;
            if(direcao == 2){
                adjacencia[i][inicio-1] = fim-1;
                adjacencia[i][fim-1] = inicio-1;
            }
            else{
                adjacencia[i][inicio-1] = fim-1;
            }
        }
        if(visitaVertice(inter, adjacencia, m, n) != n){ 
            cout << 0 << endl;
        }
        else{
            cout << 1 << endl;
        }
        cin >> n;
        cin >> m;
    }
    return 0;
}