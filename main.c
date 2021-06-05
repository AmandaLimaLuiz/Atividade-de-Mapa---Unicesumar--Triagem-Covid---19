#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct paciente{
	char nome[80];
	int cpf;
	int idade;
	char sexo[1];
	int pontuacao;
	
};

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	struct paciente cadastro;
	int conf;
	do{
	
		printf("Iniciando a Triagem\n\n");
		
		printf("\nNome: ");
		fflush(stdin);
		fgets(cadastro.nome, 80, stdin);
		printf("\nCPF: ");
		fflush(stdin);
		scanf("%d",&cadastro.cpf);
		printf("\nIdade: ");
		fflush(stdin);
		scanf("%d",&cadastro.idade);
		fflush(stdin);
		printf("\nSexo (m/f): ");
		fflush(stdin);
		fgets(cadastro.sexo, 2, stdin);
		fflush(stdin);
		printf("Confirmar e Prosseguir - Digite (1 = SIM / 2 = N�O)\n");
		scanf("%d",&conf);
	}while(conf!=1);
	fflush(stdin);
	system("cls");
	char res;
	int cont= 0;
	
	printf("Por favor responda ao questionario com (s/n):\n");
	do{
		printf("\nEst� com febre?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+5;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
		printf("\nTem dor de cabe�a?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+1;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
		printf("\nTem secre��o nasal ou espirros?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+1;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
		printf("\nTem dor/irrita��o na garganta? : ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+1;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
			fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
		
	do{
		printf("\nTem tosse seca?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+3;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
	printf("\nTem dificuldade respirat�ria?: ");
	scanf("%c",&res);
		if (res == 's'){
			cont = cont+10;
		}
		if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}	
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
		printf("\nTem dores no corpo?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+1;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
		printf("\nTem diarr�ia?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+1;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}	
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
		printf("\nEsteve em contato, nos �ltimos 14 dias, com um caso diagnosticado com COVID-19?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+10;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	
	do{
	printf("\nEsteve em locais com grande aglomera��o?: ");
		scanf("%c",&res);
			if (res == 's'){
				cont = cont+3;
			}
			if((res!='s')&&(res!='n')){
				printf("Digito Invalido.\nPor favor responda com s para SIM / n para N�O");
			}
		fflush(stdin);
	}while((res != 's')&&(res != 'n'));
	fflush(stdin);
	system("cls"); 	
	
	if(cont<10){
		printf("Dirija-se para a ala de Risco Baixo\n");
	}
	
	if((cont>9)&&(cont<20)){
		printf("Dirija-se para a ala de Risco M�dio\n");
	}
	
	if(cont>19){
		printf("Dirija-se para a ala de Risco Alto\n");
	}
	
	cadastro.pontuacao = cont;
	
	FILE *registro;
	registro = fopen("arquivo.txt","a");
	fprintf(registro,"\nPaciente: %s",cadastro.nome);
	fprintf(registro,"CPF: %d",cadastro.cpf);
	fprintf(registro,"\nIdade: %d",cadastro.idade);
	fprintf(registro,"\nSexo: %s",cadastro.sexo);
	if(cadastro.pontuacao<10){
		fprintf(registro,"\nRisco Baixo: Pontos = %d",cadastro.pontuacao);
	}
	
	if((cadastro.pontuacao>9)&&(cadastro.pontuacao<20)){
		fprintf(registro,"\nRisco M�dio: Pontos = %d",cadastro.pontuacao);
	}
	
	if(cadastro.pontuacao>19){
		fprintf(registro,"\nRisco Alto: Pontos = %d",cadastro.pontuacao);
	}
	fprintf(registro,"\n ----------------------------------\n----------------------------------\n");
	fclose(registro);
	
		
}

