/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 06/03/2021 17:11:38
Ordem de Complexidade:
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

void solve(int N, int K, int S){
	int index = 0;
    long long array[N];
    long long aux = 0;
    long long teste = 0;
    long long maior = S;
    long long controle = 1;

    array[0] = S;

    for (int i = 1; i < K; ++i)
        array[i] = (1LL*array[i-1]*1103515245 + 12345) % (2147483648LL);

	for(int i=0; i<K; i++)
		if(array[i] > maior){
			maior = array[i];
			index = i;
		}

	aux+= maior;

	for(int i=K; i<N; i++){
		array[i%K] = (1LL*array[(i-1)%K]*1103515245 + 12345) % (2147483648LL);
		if(array[i%K] > maior){
			maior = array[i%K];
			index = i%K;
		}else{
			if(i%K == index){
				maior = 0;
				for(int j=0; j<K; j++)
                			if(array[j] > maior){
                        			maior = array[j];
                        			index = j;
                			}
			}
		}

		aux+= maior;
	}

	cout << aux << endl;

}


int main(){
	
	int qtdTestes = 0;
	int N = 0, K = 0, S = 0;
	
	cin >> qtdTestes;

	int testes[qtdTestes][3];
	
	for(int i=0; i<qtdTestes; i++){
		cin >> testes[i][0];
		cin >> testes[i][1];
		cin >> testes[i][2];	
	}	

	for(int i=0; i<qtdTestes; i++)
		solve(testes[i][0], testes[i][1], testes[i][2]);

	return 0;
}