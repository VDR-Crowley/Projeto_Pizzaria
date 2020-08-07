#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <ncurses.h>
#include <locale.h>
#include <string.h>

typedef struct data DATA;
struct data{
	int dia;
	int mes;
	int ano;
};
typedef struct registro REGISTRO;
struct registro{
	char nome[30];
	char RG[25];
	char CPF[25];
	char fone[15];
	char endereco[40];
	char cargo[100];
	char estado_civil[10];
	char nacionalidade[100];
	int quat, nummero_registro;
	DATA Regdata;
};

void funcionarios();
void pesquisar();
void registroData();
void lista_de_funcionarios();
void funcionario_do_mes();
void remover();

void funcionarios() {

	setlocale(LC_ALL,"");
	int opcao;

	do{
		system("cls");
		printf(" __________________________\n");
		printf("|1 - Cadastrar funcionário |\n");
		printf("|2 - Remover funcionário   |\n"); //por letra inicial
		printf("|3 - Mostrar funcionários  |\n");
		printf("|4 - Pesquisar funcionário |\n");
		printf("|5 - Fincionário do mês    |\n");
		printf("|6 - Sair                  |\n");
		printf("|__________________________|\n\n");
		printf("Selecione uma opção: ");
		scanf("%d",&opcao);

		switch(opcao){
			case 1:
			registroData();
				break;
			case 2:
				system("cls");
				remover();
				break;
			case 3:
				system("cls");
				lista_de_funcionarios();
				break;
			case 4:
				system("cls");
				pesquisar();
				break;
			case 5:
				system("cls");
				funcionario_do_mes();
				break;
			case 6:
				system("cls");
				system("exit");
				getch();
				break;
			default:
				printf("Opção não encontrada!");
				getch();
				break;
		}

	}while(opcao != 6);


}

void registroData(){

	FILE* arquivo;
	REGISTRO ctt;

	arquivo = fopen("Registro de funcionário.txt","ab"); //Abre o arquivo em binario

 	if(arquivo == NULL){
 		printf("Problemas na abertura do arquivo!");
	 }else{
	 	do{
		 	system("cls");
			fflush(stdin);
	 		printf("Nome:");
	 		gets(ctt.nome);

	 		fflush(stdin);
	 		printf("Digite a Nacionalidade:");
	 		gets(ctt.nacionalidade);

	 		fflush(stdin);
	 		printf("Estado civil:");
	 		gets(ctt.estado_civil),

	 		fflush(stdin);
	 		printf("Endereço:");
	 		gets(ctt.endereco);

			fflush(stdin);
	 		printf("RG:");
	 		gets(ctt.RG);

			fflush(stdin);
	 		printf("CPF:");
	 		gets(ctt.CPF);

	 		fflush(stdin);
	 		printf("Telefone:");
	 		gets(ctt.fone);

	 		fflush(stdin);
	 		printf("Cargo Destinado:");
	 		gets(ctt.cargo);

	 		printf("Data de registro:");
	 		scanf("%d  %d  %d", &ctt.Regdata.dia, &ctt.Regdata.mes, &ctt.Regdata.ano);

	 		fwrite(&ctt, sizeof(REGISTRO), 1, arquivo);
			
			fflush(stdin);
	 		printf("Deseja continuar?[S/N]\n");
			
		 }while(getche() != 'n');
		 fclose(arquivo);
	 }

}

void lista_de_funcionarios(){
	
	setlocale(LC_ALL,"");
	
	FILE* arquivo;
	REGISTRO ctt;

	arquivo = fopen("Registro de funcionário.txt", "rb"); //Arquivo para a leitura em binario

 	if(arquivo == NULL){
 		printf("Problemas na abertura do arquivo!");
	 }else{
	 	while(fread(&ctt, sizeof(REGISTRO),1, arquivo)==1 ){
	 		system("cls");
			printf("Nome: %s\n", ctt.nome);
	 		printf("Nacionalidade:%s\n", ctt.nacionalidade);
	 		printf("Estado civil:%s\n", ctt.estado_civil);
	 		printf("Endereço:%s\n", ctt.endereco);
	 		printf("RG:%s\n", ctt.RG);
	 		printf("CPF:%s\n", ctt.CPF);
	 		printf("Telefone:%s\n", ctt.fone);
	 		printf("Cargo destinado:%s\n", ctt.cargo);
	 		printf("Registrado:%d %d %d\n", ctt.Regdata.dia, ctt.Regdata.mes, ctt.Regdata.ano);
	 		printf("\n--------------------------------------------------\n\n");
		 }

	 }
	 fclose(arquivo);
	 getch(); //da uma parada
	 system("cls");
}

void pesquisar(){
	
	setlocale(LC_ALL,"");
	
	FILE* arquivo;
	REGISTRO ctt;
	char nome[30];

	arquivo = fopen("Registro de funcionário.txt","rb");
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo!\n");
	}else{
		fflush(stdin);
		printf("\nDigite o nome a ser pesquisado: ");
		printf("\n \n");
		gets(nome);

		while(fread(&ctt, sizeof(REGISTRO), 1, arquivo)== 1){
			if(strcmp(nome, ctt.nome )== 0){
				system("cls");
	 		printf("Nome:%s\n", ctt.nome);
	 		printf("Nacionalidade:%s\n", ctt.nacionalidade);
	 		printf("Estado civil:%s\n", ctt.estado_civil);
	 		printf("Endereço: %s\n", ctt.endereco);
	 		printf("RG:%s\n", ctt.RG);
	 		printf("CPF:%s\n", ctt.CPF);
	 		printf("Telefone:%s\n", ctt.fone);
	 		printf("Cargo destinado:%s\n", ctt.cargo);
	 		printf("Registrado:%d %d %d\n", ctt.Regdata.dia, ctt.Regdata.mes, ctt.Regdata.ano);
	 		printf("\n--------------------------------------------------\n\n");
	 	   }
		}
	}
	fclose(arquivo);
	getch();
}

void funcionario_do_mes(){
	setlocale(LC_ALL,"");
	FILE* arquivo;
	REGISTRO ctt;

	arquivo = fopen("Registro de funcionário.txt","rb");
	if(arquivo == NULL){
		printf("Problemas na abertura do arquivo! \n");
	}else{
		int mes;
		printf("Digite o mês:");
		scanf("%d", &mes);

		while(fread(&ctt,sizeof(REGISTRO), 1, arquivo)==1){
			if(mes == ctt.Regdata.mes){
	 		printf("Nome: %s\n", ctt.nome);
	 		printf("Nacionalidade: %s\n", ctt.nacionalidade);
	 		printf("Estado civil: %s\n", ctt.estado_civil);
	 		printf("Endereço: %s\n", ctt.endereco);
	 		printf("RG: %s\n", ctt.RG);
	 		printf("CPF: %s\n", ctt.CPF);
	 		printf("Telefone: %s\n", ctt.fone);
	 		printf("Cargo destinado: %s\n", ctt.cargo);
	 		printf("Registrado: %d  %d  %d\n", ctt.Regdata.dia, ctt.Regdata.mes, ctt.Regdata.ano);
	 		printf("\n--------------------------------------------------\n\n");
			}
		}
	}

	fclose(arquivo);
	getch();
}

void remover(){
setlocale(LC_ALL,"");
 FILE* arquivo;
 FILE* temp;
 REGISTRO ctt;
 char nome[30];

 arquivo = fopen("Registro de funcionário.txt","rb");	//abrir em modo rb leitura binaria
 temp = fopen("Novo registro.txt","wb");	//abrir em modo wb ele limpa e grava binario

 		if(arquivo==NULL&&temp==NULL){
  		printf("Problemas na abertura do arquivo!\n");
  		getch();
 		}else{
  			fflush(stdin);
  			printf("Digite o nome a ser deletado:");
 			gets(nome);
  				while(fread(&ctt,sizeof(REGISTRO),1,arquivo)==1){
   					if(strcmp(nome,ctt.nome)==0){
   						system("cls");
	 				printf("Nome: %s\n", ctt.nome);
	 				printf("Nacionalidade: %s\n", ctt.nacionalidade);
	 				printf("Estado civil: %s\n", ctt.estado_civil);
	 				printf("Endereço: %s\n", ctt.endereco);
	 				printf("RG: %s\n", ctt.RG);
	 				printf("CPF: %s\n", ctt.CPF);
	 				printf("Telefone: %s\n", ctt.fone);
	 				printf("Cargo destinado: %s\n", ctt.cargo);
	 				printf("Registrado: %d  %d  %d\n", ctt.Regdata.dia, ctt.Regdata.mes, ctt.Regdata.ano);
	 				printf("\n--------------------------------------------------\n\n");
   				}else{
    			fwrite(&ctt,sizeof(REGISTRO),1,temp);//gravando os dados no arquivo temp

				}
				}
  						fclose(arquivo);//fechar o arq
 						fclose(temp);//fechar o temp
  						fflush(stdin);
  						printf("Deseja deletar?[S/N]");

				  if(getche()=='s'){	 //vamos remover o arquivo "Registro de funcionario.txt" e renomear o arquivo "Novo registro.txt" para "Registro de funcionario.txt"
   				if(remove("Registro de funcionário.txt")==0 && rename("Novo registro.txt","Registro de funcionário.txt")==0){//verifica se as operacoes foram realizadas com sucesso!
   				 printf("\nOperação realizada com sucesso!");
  				 }else{
    			remove("Novo registro.txt");//remover o arquivo tmp se acondicao foi "n" na hora de deletar
   					 }
  				}

 		}
		fclose(temp);
		fclose(arquivo);
		getch();
}
