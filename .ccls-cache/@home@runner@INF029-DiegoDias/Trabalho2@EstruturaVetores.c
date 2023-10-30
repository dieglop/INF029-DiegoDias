#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"

typedef struct {
	int tam;
	int *elementos;
	int qtd;
}vetorAuxiliar;

vetorAuxiliar *vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    int retorno = 0;
	
    // a posicao pode já existir estrutura auxiliar
	if(vetorPrincipal[posicao - 1] != NULL)
    	retorno = JA_TEM_ESTRUTURA_AUXILIAR;
	else
    // se posição não é um valor válido {entre 1 e 10}
	if(posicao < 1 || posicao > 10)
    	retorno = POSICAO_INVALIDA;
	else
    // o tamanho ser muito grande
	if(malloc(tamanho * sizeof(vetorAuxiliar)) == NULL)
		retorno = SEM_ESPACO_DE_MEMORIA;
	else
    // o tamanho nao pode ser menor que 1
	if(tamanho < 1) 
		retorno = TAMANHO_INVALIDO;
	
    // deu tudo certo, crie
	else{
		vetorPrincipal[posicao - 1] = malloc(sizeof(vetorAuxiliar));
		vetorPrincipal[posicao - 1]->elementos = malloc(tamanho * sizeof(vetorAuxiliar));
		vetorPrincipal[posicao - 1]->tam = tamanho;
		vetorPrincipal[posicao - 1]->qtd = 0;
    	retorno = SUCESSO;
	}

    return retorno;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    //int temEspaco = 0;
    int posicao_invalida = 0;

	if(posicao < 1 || posicao > 10) posicao_invalida = 1;
	if(vetorPrincipal[posicao - 1] != NULL) existeEstruturaAuxiliar = 1;
	
	
    if (posicao_invalida)
        retorno = POSICAO_INVALIDA;
    else
    {
        // testar se existe a estrutura auxiliar
        if (existeEstruturaAuxiliar)
        {
			
            if (vetorPrincipal[posicao - 1]->qtd < vetorPrincipal[posicao - 1]->tam)
            {
                //insere
				vetorPrincipal[posicao - 1]->elementos[vetorPrincipal[posicao - 1]->qtd] = valor;
				vetorPrincipal[posicao - 1]->qtd++;
				
                retorno = SUCESSO;
            }
            else
            {
                retorno = SEM_ESPACO;
            }
        }
        else
        {
            retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    }

    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{	
	
    int retorno = 0;
	if(posicao < 1 || posicao > 10) retorno = POSICAO_INVALIDA; 
	else if(vetorPrincipal[posicao - 1] == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
	else if(vetorPrincipal[posicao - 1]->qtd < 1) retorno = ESTRUTURA_AUXILIAR_VAZIA;
	else{
		vetorPrincipal[posicao - 1]->qtd--;
		retorno = SUCESSO;
	}
    return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    int retorno = 0;
	if(posicao < 1 || posicao > 10) retorno = POSICAO_INVALIDA;
	else if(vetorPrincipal[posicao - 1] == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
	else if(vetorPrincipal[posicao - 1]->qtd < 1) retorno = ESTRUTURA_AUXILIAR_VAZIA; 
	else{
		for(int i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++){
			
			if(valor == vetorPrincipal[posicao - 1]->elementos[i]){
				
				for(int j = i; j < vetorPrincipal[posicao - 1]->qtd; j++){
					vetorPrincipal[posicao - 1]->elementos[j] = vetorPrincipal
[posicao - 1]->elementos[j + 1];

				}
				vetorPrincipal[posicao - 1]->qtd--;
				retorno = SUCESSO;
			}
			else{
				retorno = NUMERO_INEXISTENTE;
			}
		}
	}
    return retorno;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) retorno = POSICAO_INVALIDA;
	else if(vetorPrincipal[posicao - 1] == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
	else{
		for(int i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++){
			vetorAux[i] = vetorPrincipal[posicao - 1]->elementos[i];
		}		
		retorno = SUCESSO;
	}
	
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    int retorno = 0;
	int k = 0;
	int key;
	int n;
	
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) retorno = POSICAO_INVALIDA;
	else if(vetorPrincipal[posicao - 1] == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
	else{
				
		for(int i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++){
			vetorAux[k] = vetorPrincipal[posicao - 1]->elementos[i];
			k++;
		}

		for(int j = 1; j < k; j++){
			key = vetorAux[j];
			n = j - 1;

			while(n >= 0 && vetorAux[n] > key){
				vetorAux[n + 1] = vetorAux[n];
				n--;
			}
			vetorAux[n + 1] = key;
		}
		
		retorno = SUCESSO;
	}
    
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
	int cont = 0;
	int cont2 = 0;
	int k = 0;

	for(int i = 0; i < TAM; i++){
		if(vetorPrincipal[i]!= NULL){
			cont++;

			if(vetorPrincipal[i]->qtd < 1){
				cont2++;
			}
		} 
	}

	
	if(cont == cont2) retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	else{
		for(int i = 0; i < TAM; i++){
			if(vetorPrincipal[i] != NULL){
			    for(int j = 0; j < vetorPrincipal[i]->qtd; j++){
				    vetorAux[k] = vetorPrincipal[i]->elementos[j];
				    k++;
			    }
		    }
	    }
		retorno = SUCESSO;
	}
	
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
	int cont = 0;
	int cont2 = 0;
	int k = 0;
	int key;
	int n;

	for(int i = 0; i < TAM; i++){
		if(vetorPrincipal[i]!= NULL){
			cont++;

			if(vetorPrincipal[i]->qtd < 1){
				cont2++;
			}
		} 
	}


	if(cont == cont2) retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	else{
		for(int i = 0; i < TAM; i++){
			if(vetorPrincipal[i] != NULL){
				for(int j = 0; j < vetorPrincipal[i]->qtd; j++){
					vetorAux[k] = vetorPrincipal[i]->elementos[j];
					k++;
				}
			}
		}
		for(int j = 1; j < k; j++){
			key = vetorAux[j];
			n = j - 1;

			while(n >= 0 && vetorAux[n] > key){
				vetorAux[n + 1] = vetorAux[n];
				n--;
			}
			vetorAux[n + 1] = key;
		}
		retorno = SUCESSO;
	}

    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
	int diferenca, tiraElem = 0;
	
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) retorno = POSICAO_INVALIDA;
	else if(vetorPrincipal[posicao - 1] == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
	else if(vetorPrincipal[posicao - 1]->tam + novoTamanho < 1) retorno = NOVO_TAMANHO_INVALIDO;
	else{
		if(novoTamanho < 0){ 
			diferenca = vetorPrincipal[posicao - 1]->tam - vetorPrincipal[posicao - 1]->qtd;
			tiraElem = diferenca + novoTamanho;
		}
		if(tiraElem < 0){
			vetorPrincipal[posicao - 1]->qtd = vetorPrincipal[posicao - 1]->qtd + tiraElem;		
		}

		if(realloc(vetorPrincipal[posicao - 1], vetorPrincipal[posicao - 1]->tam + novoTamanho) == NULL){
			retorno = SEM_ESPACO_DE_MEMORIA;
		}
		else{
			vetorPrincipal[posicao - 1] = realloc(vetorPrincipal[posicao - 1], vetorPrincipal[posicao - 1]->tam + novoTamanho);
			vetorPrincipal[posicao - 1]->tam = vetorPrincipal[posicao - 1]->tam + novoTamanho;
			
			retorno = SUCESSO;
		}
	}
	
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;
	if(ehPosicaoValida(posicao) == POSICAO_INVALIDA) retorno = POSICAO_INVALIDA;
	else if(vetorPrincipal[posicao - 1] == NULL) retorno = SEM_ESTRUTURA_AUXILIAR;
	else if(vetorPrincipal[posicao - 1]->qtd < 1) retorno = ESTRUTURA_AUXILIAR_VAZIA; 
	else retorno = vetorPrincipal[posicao -1]->qtd;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
	No *retorno;
	int vazio = 0;
	int cont = 0;
	int cont2 = 0;
	No *head = NULL;
	No *aux = NULL;

	for(int i = 0; i < TAM; i++){
		if(vetorPrincipal[i]!= NULL){
			cont++;

			if(vetorPrincipal[i]->qtd < 1){
				cont2++;
			}
		} 
	}

	if(cont == cont2) retorno = NULL;
	else{
		
		for(int i = 0; i < TAM; i++){
			if(vetorPrincipal[i] != NULL){
				for(int j = 0; j < vetorPrincipal[i]->qtd; j++){
					No *lista = malloc(sizeof(No));
					lista->conteudo = vetorPrincipal[i]->elementos[j];
					lista->prox = NULL;

					if(head == NULL) {
						head = lista;					
					}else{
						aux = head;
						while(aux->prox != NULL){
							aux = aux->prox;
						}

						aux->prox = lista;
					}
				}
			}
		}
		retorno = head;
	}		
		
	return retorno;
   
}

/*
Objetivo: retorna os números da lista encadeada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
	int totalDados = 0;
    No *lista = inicio;
	
	for(int i = 0; i < TAM; i++){
		if(vetorPrincipal[i] != NULL){
			
			totalDados += vetorPrincipal[i]->qtd;
		}
	}

	for(int j = 0; j < totalDados; j++){
		vetorAux[j] = lista->conteudo;
		lista = lista->prox;
	}
	
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
    No *deleta = *inicio;
	No *aux = deleta;

	while(aux->prox != NULL){
		aux = aux->prox;
		free(deleta);
		deleta = aux;
	}
	
	free(deleta);
	*inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
	for(int i = 0; i < TAM; i++){
		free(vetorPrincipal[i]->elementos);
		free(vetorPrincipal[i]);		
	}
}