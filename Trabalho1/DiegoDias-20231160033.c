// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Diego Dias Lopes
//  email: diego87dlopes@gmail.com
//  Matrícula: 20231160033
//  Semestre: 2023.2

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "DiegoDias-20231160033.h" // Substitua pelo seu arquivo de header renomeado
#include <stdlib.h>
#include <string.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  	int datavalida = 1;
	int contDia = 0;
	int contMes = 0;
	int contAno = 0;
	int dia = 1; int mes = 0; int ano = 0;
	char sAno[5] = {0};
	char sMes[3] = {0};
	char sDia[3] = {0};
	int iAno = 0, iMes = 0, iDia = 0;	

	 //quebrar a string data em strings sDia, sMes, sAno
	for(int i = 0; data[i] != '\0'; i++){
		if(data[i] >= '0' && data[i] <= '9' && dia == 1){
			sDia[contDia] = data[i];
			contDia++;
		}else if(data[i] == '/' && dia == 1){
			dia = 0;
			mes = 1;
		}else if(data[i] >= '0' && data[i] <= '9' && mes == 1){
			sMes[contMes] = data[i];
			contMes++;
		}else if(data[i] == '/' && mes == 1){
			mes = 0;
			ano = 1;
		}else if(data[i] >= '0' && data[i] <= '9' && ano == 1){			
			sAno[contAno] = data[i];
			contAno++;
		}
		
	}

	iAno = atoi(sAno);
	iMes = atoi(sMes);
	iDia = atoi(sDia);
	
	if(contAno == 2){		
		iAno = iAno + 2000;
	}

	if(iAno % 4 != 0 && iMes == 2 && iDia > 28){
		datavalida = 0;
	}else if(iMes == 2 && iDia > 29){
		datavalida = 0;
	}

	if(iMes < 1 || iMes > 12){
		datavalida = 0;
	}else if((iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11) && (iDia < 1 || iDia > 30)){
		datavalida = 0;
	}else if(iDia < 1 || iDia > 31){
		datavalida = 0;
	}

	if(contDia < 1 || contDia > 2){datavalida = 0;}
	if(contMes < 1 || contMes > 2){datavalida = 0;}
	if(contAno < 2 || contAno > 4){datavalida = 0;}

  //DataQuebrada dataQuebrada = quebraData(data);
  //if (dataQuebrada.valido == 0) return 0;

  //printf("%s\n", data);

  if (datavalida)
      return 1;
  else
      return 0;
}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
DiasMesesAnos q2(char datainicial[], char datafinal[])
{
	int contDia = 0;
	int contMes = 0;
	int contAno = 0;
	int dia = 1; int mes = 0; int ano = 0;
	char sAno[5] = {0};
	char sMes[3] = {0};
	char sDia[3] = {0};
	int iAnoinicial = 0, iMesinicial = 0, iDiainicial = 0;
	int iAnofinal = 0, iMesfinal = 0, iDiafinal = 0;
	int valorAnoinicial, valorAnofinal, diferenca;

	
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      //verifique se a data final não é menor que a data inicial
		for(int i = 0; datainicial[i] != '\0'; i++){
			if(datainicial[i] >= '0' && datainicial[i] <= '9' && dia == 1){
				sDia[contDia] = datainicial[i];
				contDia++;
			}else if(datainicial[i] == '/' && dia == 1){
				dia = 0;
				mes = 1;
			}else if(datainicial[i] >= '0' && datainicial[i] <= '9' && mes == 1){
				sMes[contMes] = datainicial[i];
				contMes++;
			}else if(datainicial[i] == '/' && mes == 1){
				mes = 0;
				ano = 1;
			}else if(datainicial[i] >= '0' && datainicial[i] <= '9' && ano == 1){			
				sAno[contAno] = datainicial[i];
				contAno++;
			}
		}

		iAnoinicial = atoi(sAno);
		iMesinicial = atoi(sMes);
		iDiainicial = atoi(sDia);
			
		if(contAno == 2){iAnoinicial = iAnoinicial + 2000;}
	
		valorAnoinicial = ((iAnoinicial * 10000) + (iMesinicial * 100)) + iDiainicial;

		 contDia = 0; contMes = 0; contAno = 0;
		 dia = 1; mes = 0; ano = 0;
		
		for(int i = 0; datafinal[i] != '\0'; i++){
			if(datafinal[i] >= '0' && datafinal[i] <= '9' && dia == 1){
				sDia[contDia] = datafinal[i];
				contDia++;
			}else if(datafinal[i] == '/' && dia == 1){
				dia = 0;
				mes = 1;
			}else if(datafinal[i] >= '0' && datafinal[i] <= '9' && mes == 1){
				sMes[contMes] = datafinal[i];
				contMes++;
			}else if(datafinal[i] == '/' && mes == 1){
				mes = 0;
				ano = 1;
			}else if(datafinal[i] >= '0' && datafinal[i] <= '9' && ano == 1){			
				sAno[contAno] = datafinal[i];
				contAno++;
			}
		}

		iAnofinal = atoi(sAno);
		iMesfinal = atoi(sMes);
		iDiafinal = atoi(sDia);
			
		if(contAno == 2){iAnofinal = iAnofinal + 2000;}
	
		valorAnofinal = ((iAnofinal * 10000) + (iMesfinal * 100)) + iDiafinal;

		diferenca = valorAnofinal - valorAnoinicial;

		if(diferenca < 0){
			dma.retorno = 4;
			return dma;
		}	 
		
		//calcule a distancia entre as datas
		int diasdosMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
		int acumMes = iMesinicial;
		int k = iDiainicial;
		int acumDia = 0;
		int acumAno = iAnoinicial;

		while((acumDia < iDiafinal) || (acumMes < iMesfinal) || (acumAno < iAnofinal)){
			if(acumAno == iAnofinal && acumMes == iMesfinal){
				for(int g = 0; g < iDiafinal; g++){
					dma.qtdDias++;
				}
				break;
			}
			
			k = 1;
			while(k < diasdosMeses[acumMes - 1]){
				k++;
			}
			if(acumMes < 12 ) {
				if(acumAno == iAnofinal && acumMes < iMesfinal){
					dma.qtdMeses++;
				}
				acumMes++;
			}else{
				acumMes = 1;
				acumAno++;
				dma.qtdAnos++;
			}
		}
		
		
		//se tudo der certo
		dma.retorno = 1;
		return dma;
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

	int txt_tam = strlen(texto);
	char aux[250];

	if(isCaseSensitive != 1){
		if(c > 'A' && c < 'Z'){
			c += 32;
		}
		strcpy(aux, texto);
		for(int i = 0; i < txt_tam; i++){	
			if(aux[i] >= 'A' && aux[i] <= 'Z'){
				aux[i] += 32; 
			}
		}
		for(int i = 0; i < txt_tam; i++){	
			if(aux[i] == c){
				qtdOcorrencias++; 
			}
		}
	}else{
		for(int i = 0; i < txt_tam; i++){	
			if(texto[i] == c){
				qtdOcorrencias++; 
			}
		}
	}
		
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
	int cont = 0;
	int j = 0;
	int m = 0;
	int flag = 0;
	int k;
	int ajuste = 0;
	int diac = 0;
	
	while(strBusca[cont] != '\0'){
		if(strBusca[cont] == -61){
			diac++;    
		}
		cont++;
	}

	for(int i = 0; strTexto[i] != '\0'; i++){
		k = 0;
		j = i;
		flag = 0;
	
		while(strTexto[j] == strBusca[k]){

		    if(strTexto[j] == strBusca[0] && k == 0){

		        posicoes[m] = i + 1 - ajuste;
		        m++;
		    }

			flag++;
			j++;
			k++;
		}
		if(flag == cont){
		    ajuste += diac;
			posicoes[m] = j - ajuste;
			m++;					
			qtdOcorrencias++;
			j--;
			i = j;
		}else if(flag > 0 && flag < cont){
		    m--;
		}
		if(strTexto[i] == -61){ 
			ajuste++;
		}
	}
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
	int div = num;
	int cont = 0;
	int res;
	int exp = 1;

	while(div/10 != 0){
		div /= 10; 
		cont++;	
	}
	cont++;
	
	int numero[cont];
	
	for(int i = 0; i < cont; i++){
    		numero[i] = num%10;
    		num /= 10;
    		if(i > 0){
    			exp *= 10;
    		}
    	}
    	num = 0;
    	for(int i = 0; i < cont; i++){
    		if(numero[0] != 0){
    			num += numero[i]*exp;
    			exp /= 10;
    		}else{
    		    exp /= 10;
    		    num += numero[i+1]*exp;
    		}
    	}
    	
	
	
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
	int tam = 10;
	char str_numBase[tam];
	char str_numBusca[tam];
	int flag = 0;
	int t;

	sprintf(str_numBusca,"%d",numerobusca);
	sprintf(str_numBase,"%d",numerobase);

	int cont = 0;
	while(str_numBusca[cont]!= '\0'){
		cont++;	
	}

	for(int i = 0; str_numBase[i] != '\0'; i++){
		t = 0;
		flag = 0;
		for(int j = i; t < cont; j++){
			if(str_numBase[j] == str_numBusca[t]){
				flag++;
			}
			t++;
		}
		if(flag == cont){
			qtdOcorrencias++;
		}
	}
	
    return qtdOcorrencias;
}