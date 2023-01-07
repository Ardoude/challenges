/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 27/02/2021 15:38:42
Ordem de Complexidade:
*******************************************************************************/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    string input, output;
    string frases[10000];
    string retorno[10000];
    int meio, aux, qtdTestes;

    cin >> qtdTestes;
    cin.ignore();

    for(int i=0; i<qtdTestes; i++){
        getline(cin, input);

        meio = input.size()/2;
        aux = meio-1;

        for(int j=0; j<meio; j++){
                output+= input[aux--];
        }

        aux = input.size()-1;

        for(int j=meio; j<input.size(); j++){
                output += input[aux];
                aux--;
        }
        retorno[i] = output;
        output = "";

    }

    for(int i=0; i<qtdTestes; i++)
            cout<<retorno[i]<<endl;

    return 0;
}