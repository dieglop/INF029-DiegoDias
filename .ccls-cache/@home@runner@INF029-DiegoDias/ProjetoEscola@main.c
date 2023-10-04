#include <stdio.h>
#include "Aluno/Aluno.h"
#include "Professor/Professor.h"
#include "Disciplina/Disciplina.h"
#define tam 3

int main(void){
	int op, sair;

	

	while(!sair){
		sair = 0;
		printf("Informe a opcao que deseja: \n\n");
		printf("0 - Sair\n");
		printf("1 - Aluno\n");
		printf("2 - Professor\n");
		printf("3 - Disciplina\n");
		scanf("%d", &op);
		switch(op){
			case 0:
				sair = 1;
				break;
			case 1: 
				//MÓDULO ALUNO
				while(!sair){
					menuAluno();
					switch(opA){
						case 0:
							sair = 1;
							break;
						case 1:
							//CADASTRAR ALUNO
							printf("\n--CADASTRO DE ALUNOS--\n");
							printf("\nInforme o nome: ");
							fgets(alunos[i].nome,nome_tam,stdin);
							printf("\nInforme a data de nascimento: ");
							fgets(alunos[i].dataNasc,data_tam,stdin);
							printf("\nInforme o CPF: ");
							fgets(alunos[i].CPF,cpf_tam,stdin);
							printf("\nInforme o sexo (M/F): ");
							scanf("%c", &alunos[i].sexo);
							getchar();
							break;
						
						case 2:
							break;
					}
				}
				break;
			case 2:
				//MÓDULO PROFESSOR
				while(!sair){
					printf("\nMódulo Professor\n\n");
					printf("0 - Sair");
					printf("1 - ");
				}
				break;
			case 3:
				while(!sair){
					printf("\nMódulo Disciplina\n\n");
					printf("0 - Sair");
					printf("1 - ");
				}
				break;
		}
	}
	
	return 0;
}

