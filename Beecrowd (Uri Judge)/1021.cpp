/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 04/05/2021 08:10:20
Ordem de Complexidade: O(n3) para cada caso de teste, sendo N a quantidade de fatores primos
*******************************************************************************/
#include <iostream>

using namespace std;

int* solve(double value){
    int nota = 0, moeda = 0, centavos;
    int* retorno = (int*) malloc(12*sizeof(int));
    
    // NOTAS
    retorno[0] = (value-nota)/100;
    nota+= retorno[0]*100;

    retorno[1] = (value-nota)/50;
    nota+= retorno[1]*50;

    retorno[2] = (value-nota)/20;
    nota+= retorno[2]*20;

    retorno[3] = (value-nota)/10;
    nota+= retorno[3]*10;

    retorno[4] = (value-nota)/5;
    nota+= retorno[4]*5;

    retorno[5] = (value-nota)/2;
    nota+= retorno[5]*2;
    
    
    // MOEDAS
    centavos = (value-nota)*100;
    
    retorno[6] = (centavos-moeda)/100;
    moeda+= retorno[6]*100;

    retorno[7] = (centavos-moeda)/50;
    moeda+= retorno[7]*50;

    retorno[8] = (centavos-moeda)/25;
    moeda+= retorno[8]*25;

    retorno[9] = (centavos-moeda)/10;
    moeda+= retorno[9]*10;

    retorno[10] = (centavos-moeda)/5;
    moeda+= retorno[10]*5;

    retorno[11] = (centavos-moeda)/1;
    moeda+= retorno[11]*1;

    return retorno;
}

int main(){
    double N;
    double valores[10000];
    int qtdTestes = 0;

    // Input
    while( cin >> N ){
        valores[qtdTestes++] = N;
    }


    // Output
    for(int i=0; i<qtdTestes; i++){
        int* arr;
        arr = solve(valores[i]);

        cout <<
        "NOTAS:\n"<<
        arr[0]  << " nota(s) de R$ 100.00\n" <<
        arr[1]  << " nota(s) de R$ 50.00\n"  <<
        arr[2]  << " nota(s) de R$ 20.00\n"  <<
        arr[3]  << " nota(s) de R$ 10.00\n"  <<
        arr[4]  << " nota(s) de R$ 5.00\n"   <<
        arr[5]  << " nota(s) de R$ 2.00\n"   <<
        "MOEDAS:\n" <<
        arr[6]  << " moeda(s) de R$ 1.00\n"  <<
        arr[7]  << " moeda(s) de R$ 0.50\n"  <<
        arr[8]  << " moeda(s) de R$ 0.25\n"  <<
        arr[9]  << " moeda(s) de R$ 0.10\n"  <<
        arr[10] << " moeda(s) de R$ 0.05\n"  <<
        arr[11] << " moeda(s) de R$ 0.01"  <<
        endl;
    }
}