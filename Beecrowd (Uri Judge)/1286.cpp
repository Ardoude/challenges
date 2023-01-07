/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 31/05/2021 11:02:51
Ordem de Complexidade: O(n2), sendo N a quantidade de pizzas e W o máximo de pizzas que podem ser entregues -> O(n*w) = O(n2)
*******************************************************************************/

#include <iostream>
#include <math.h>

using namespace std;

// Resolve o problema da mochila (knapsack) com prog. dinâmica
int solve(int valores[], int pesos[], int qtdItens, int cap){

    // Inicializar tabela
    int tabela[qtdItens+1][cap+1];
 
    for (int j = 0; j <= cap; j++) {
        tabela[0][j] = 0;
    }

    // Encontrar capcidade maxima
    for (int i = 1; i <= qtdItens; i++){

        for (int j = 0; j <= cap; j++){
            // Ignora se j-pesos[i-1] é negativo
            if (pesos[i-1] > j) {

                tabela[i][j] = tabela[i-1][j];

            }else{

                tabela[i][j] = max(tabela[i-1][j], tabela[i-1][ j-pesos[i-1] ] + valores[i-1]);
            }
        }
    }
 
    // Valor maximo
    return tabela[qtdItens][cap];
}


int main(){
    int qtdPedidos, maxPizzas, tempoPedido, pizzasPedido, auxLeitura, qtdTestes;
    int output[9999];

    // Input
    cin >> qtdPedidos;

    while(qtdPedidos != 0){
        int valores[qtdPedidos]; // Tempo totl para ser entregue
        int pesos[qtdPedidos];   // Quantidade de pizzas

        cin >> maxPizzas;

        for(int i=0; i<qtdPedidos; i++){
            cin >> auxLeitura;
            valores[i] = auxLeitura;
            cin >> auxLeitura;
            pesos[i] = auxLeitura;
        }

        output[qtdTestes++] = solve(valores, pesos, qtdPedidos, maxPizzas);
        cin >> qtdPedidos;
        
    }

    // Output
    for(int i=0; i<qtdTestes; i++){
        cout << output[i] << " min." << endl;
    }

}