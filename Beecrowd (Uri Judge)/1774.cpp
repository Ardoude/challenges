/******************************************************************************
Nome: Eduardo Pereira Costa
Submissão: 14/03/2021 21:07:37
Ordem de Complexidade:
*******************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Manipula matriz quadrada como um vetor
template <typename T>
class Matriz{
	int size, row, column;
	T* dados;

	public:

	Matriz(){ }

	Matriz(int linha, int coluna){
		row = linha;
		column = coluna;
		size = row*column;
		dados = new T[size];
	}

	void set(int linha, int coluna, int valor){
		if(linha>-1 && linha<row && coluna >-1 && coluna<column){
			dados[ (linha*column) + coluna ] = valor;
			dados[ (coluna*column) + linha ] = valor;
		}
	}

	T get(int linha, int coluna){
		T r;
		if(linha>-1 && linha<row && coluna >-1 && coluna<column)	
			r = dados[linha*column + coluna];
		return r;
	}

	void fill(T valor){
		for(int i=0; i<size; i++)
			dados[i] = valor;
	}

	void print(){
		for(int i=0; i<row; i++){
			for(int j=0; j<column; j++)
				cout << "[" << dados[(i*row) + j] << "]";
			cout << endl;
		}
	}

	void free(){
		if(dados != NULL)
			delete(dados);
		size = 0;
		row = 0;
		column = 0;
	}
};


class No{

	public:
	int v1, v2;
	int peso;
	No* prox;

	No(){
		v1 = 0;
		v2 = 0;
		peso = 0;
		prox = NULL;
	}

	No(int v1, int v2){
		this->v1 = v1;
		this->v2 = v2;
		peso = 0;
		this->prox = NULL;
	}

	No(int v1, int v2, int peso){
                this->v1 = v1;
		this->v2 = v2;
                this->peso = peso;
                this->prox = NULL;
        }

	void free(){
		v1 = 0;
		v2 = 0;
		peso = 0;
		prox = NULL;
	}
};


class Fila{
	No* topo;
	No* ultimo;
	int size;

	public:

	Fila(){
		topo = new No();
		ultimo = topo;
		size = 0;
	}

	void add(int v1, int v2){
		ultimo->prox = new No(v1, v2);
		ultimo = ultimo->prox;
		size++;
	}

	int getSize(){
		int tamanho=0;
		for(No* aux = topo->prox; aux!=NULL; aux = aux->prox)
			tamanho++;
		return tamanho;
	}

	void add(int v1, int v2, int peso){
                ultimo->prox = new No(v1, v2, peso);
                ultimo = ultimo->prox;
                size++;
        }

	int* getMenor(){
		int vizinhoMaisProximo = -1;
		int menor = 99999;
		int *retorno = new int[3];
		No* aux;
		No* anterior;

		if(topo != ultimo){
			for(anterior=topo, aux=anterior; aux->prox!=NULL; aux=aux->prox){
				if(aux->prox->peso>0 && aux->prox->peso < menor){
					menor = aux->prox->peso;
					anterior = aux;
				}
			}
			if(anterior->prox == ultimo)
				ultimo = anterior;
	
			retorno[0] = anterior->prox->v1;
			retorno[1] = anterior->prox->v2;
			retorno[2] = anterior->prox->peso;
			aux = anterior->prox;
			anterior->prox = anterior->prox->prox;
			aux->free();
		}
		size--;
		return retorno;
	}

	void print(){
		No* aux;
		cout<<"Topo -> ";
		for(aux = topo->prox; aux!= NULL; aux = aux->prox)
			cout << "[" << aux->v1+1 << "/" << aux->v2+1 << ":"<< aux->peso << "]";

		cout << endl;
	}
};


class Grafo{
	Matriz<int> matrizAdjacencia;
	Fila filaPrioridade;
	int numVertices;
	public:

	Grafo(){ }

	Grafo(int ordem){
		numVertices = ordem;
		matrizAdjacencia = Matriz<int>(ordem, ordem);
		matrizAdjacencia.fill(0);

		filaPrioridade = Fila();
	}

	void setAresta(int linha, int coluna, int valor){
		matrizAdjacencia.set(linha, coluna, valor);
	}

	int getAresta(int linha, int coluna){
		return matrizAdjacencia.get(linha, coluna);
	}

	void addFilaPrioridade(int vertice){	
		for(int i=0; i<numVertices; i++)
			if( matrizAdjacencia.get(vertice, i) > 0 ){
				//cout<<"\n\n Adicionando "<<vertice+1<<"|"<<i+1<<" a FP;"<<endl;
				filaPrioridade.add( vertice, i, matrizAdjacencia.get(vertice, i) );
			}
	}

	int* getMenorAresta(){
		return filaPrioridade.getMenor();
	}

	void print(){
		matrizAdjacencia.print();
	}

	void printFilaPrioridade(){
		filaPrioridade.print();
	}
};


void solve(Grafo grafo, int qtdVertices){
	Grafo agm = Grafo(qtdVertices);
	int T[qtdVertices];
	int soma = 0;
	int contador;
	int *aux;
	bool estaNaFila = false;
	int counter = 0;
	int manual;

	grafo.addFilaPrioridade(0);
	T[0] = 0;

	for(contador=1; contador!=qtdVertices; contador++){
		aux = grafo.getMenorAresta();
		
		for(int i=0; i<contador; i++){
			if(T[i] == aux[1])
				estaNaFila = true;
		}

		if(!estaNaFila){
			agm.setAresta(aux[0], aux[1], aux[2]);
			T[contador] = aux[1];
			soma+=grafo.getAresta(aux[0], aux[1]);
			grafo.addFilaPrioridade(aux[1]);
		}else
			contador--;
		estaNaFila = false;
	}	

	cout << soma<<endl;
}


int main(){
	Grafo grafo;
	int qtdVertices, qtdArestas;
	int v1, v2, peso;

	cin >> qtdVertices;
	cin >> qtdArestas;

	grafo = Grafo(qtdVertices);

	for(int i=0; i<qtdArestas; i++){
		cin >> v1;
		cin >> v2;
		cin >> peso;
		grafo.setAresta(v1-1, v2-1, peso);
	}
	
	solve(grafo, qtdVertices);
	
	return 0;
}

