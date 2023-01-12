#include <stdio.h>		//  biblioteca de comunicação com o usuário
#include <stdlib.h>		//  biblioteca de alocação de espaço em memória
#include <locale.h>		//  biblioteca de alocação de texto por região
#include <string.h>		//  biblioteca de manipulação de strings

// cria a função para registro de usuario

int registrar_cadastro()
{
    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem para português

    // criação das variáveis principais

	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];

	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);

	strcpy(arquivo, cpf);		// Função responsável por copiar a string 'cpf' em 'arquivo'

	FILE *file;     // cria o arquivo file
	file = fopen(arquivo, "w");     // comando para abrir o arquivo. w usado para escrever no arquivo
	fprintf(file, "CPF: ");
	fclose(file);       // fecha o arquivo

	file = fopen(arquivo, "a");		// flag "a" atualiza o arquivo 'file'
	fprintf(file, cpf);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);

	printf("Digite o primeiro nome: ");
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);

	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);

    file = fopen(arquivo, "a");     // adiciona um espaço entre nome e sobrenome
	fprintf(file, " ");
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");     // pula uma linha para melhor apresentação
	fprintf(file, "\n");
	fclose(file);

	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);

	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file, "\n");
	fclose(file);

	printf("Cadastro concluído com sucesso! \n");

}

// cria função para consulta de cadastro

int consultar_cadastro()
{
    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[240];     // variável que lê o conteudo do arquivo 'cpf'

    printf("###CONSULTA DE CADASTRO### \n\n\n");

    printf("Digite o cpf a ser consultado: ");      // aceita apenas números, por enquanto
    scanf("%s", cpf);
    printf("\n");

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL) {
        printf("Funcionário não localizado!.\n");
    }

    else {

        printf("Informações do usuário: \n\n");

        while(fgets(conteudo, 240, file) != NULL) {                 // lê uma linha de um arquivo específico enquanto a condição for atendida
            printf("%s", conteudo);
            printf("\n");
        }
    }
}

// cria  a função deletar cadastro

int deletar_cadastro()
{
	char cpf[40];

	setlocale(LC_ALL, "Portuguese");

	printf("###DELETAR CADASTRO### \n\n\n");
	printf("Você escolheu deletar um cadastro. \n");

	printf("Digite o cpf do usuário ser deletado: ");
	scanf("%s", cpf);

	FILE *file;
	file = fopen(cpf, "r");     // lê o arquivo cpf já existente (ou não)

	if(file == NULL) {

        printf("O cadastro não se encontra no sistema. \n");
	}

	else {
        remove(cpf);        // apaga o arquivo com a chave cpf
        printf("Usuário removido com sucesso. \n");
	}

}


int main()
{
	int opcao = 0;		// Definindo a variável de escolha do menu
	int count = 1;		// contador para controle do loop for

	for(count = 1; count = 1;)	// garante a permanência do usuario na tela
	{

        system("clear");		// limpa a tela após a escolha do usuário

		setlocale(LC_ALL, "Portuguese");	//  necessário para incluir os caracteres especiais do português

		printf("#### Cartório da EBAC #### \n\n");
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - Matricular novo usuário \n");
		printf("\t2 - Consultar número de matrícula \n");
		printf("\t3 - Apagar usuário \n\n");
		printf("\t4 - Deseja sair do sistema? \n\n");

		printf("Opção: ");	// encerramento do menu

		scanf("%d", &opcao);	// armazenando a escolha do usuário

		system("clear");		// limpa a tela apção a escolha do usuário

		switch(opcao)
		{
			case 1:
			registrar_cadastro();
			break;

			case 2:
			consultar_cadastro();
			break;

			case 3:
			deletar_cadastro();
			break;

			case 4:
            printf("Saindo do sistema. Obrigado por utilizar o Cartório EBAC!! \n");
            return 0;       // finaliza o programa...
            break;

			default:
			printf("Essa opção não está disponível. Escolha uma opção válida do menu. \n");
			break;
		}
	}
}
