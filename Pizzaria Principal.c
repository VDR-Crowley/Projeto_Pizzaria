#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>
//#include <conio.h>                                        //biblioteca responsavel pela fun��o getch
//#include <ncurses.h>										// igual a conio so que para o linux
#endif

#include "Registrados.h"
#include "Mercadoria.h"


/*Aqui � onde as variaveis globais da nossa estruturas s�o criadads e ser�o usadas mais ha frente*/

void logo()
{
	setlocale(LC_ALL,"");
	puts ("\t\t\t\t\t|---------------------------------------------------|\n");
	puts ("\t\t\t\t\t|		THE KING OF PIZZA     	    	    |\n");
	puts ("\t\t\t\t\t|---------------------------------------------------|");
}
 void versao()
 {
 	setlocale(LC_ALL,"");
 	printf ("\t\t\t\t\t\tVers�o 1.3");
 }
//inicando as estruturas


typedef struct pedido
{
    char namePed[200];
    char CPF[20];
    char numPed[200];                   //essa estrutura  que utilizamos para os pedidos.
    char qtdPed[200];
    char valorped[200];
    char bebidaped[200];
    char bordas[200];
    char sabor[200];
    int cod,vaz;

}logP[200];

 struct cadastro
{
    char CPF[20];
    char telefone[15];
    char nome[200];                            //essa � Responsavel pelo cadastro.
    char endereco[200];
    char data[15];
    int vazio,cod;
    struct pedido clientePed;
}logC[200];



//AQUI DECLARO AS FUN��ES A SEREM USADAS
void excluirPedido(void);
int verifica_pos(void);
int verifica_cod( int cod );
int opt;
void cadastroP();
void list();
void cadastroPedido();
void consultaCod ();
void excluirCliente();
void menu();
void edite();
void bebida();


/*Aqui � onde todas as funcoes vao rodar
cada uma com as sua especifica�oes. */


int main(){ 	///INICIO DO MAIN.


	setlocale (LC_ALL, "Portuguese");
 	///INICIO DA FUN�AO DE LOGIN.

	   char c, login[50], senha[50],acesso_login[50],acesso_senha[50];

	   int a = 0, b = 1, d = 3;    // d controlar� a quantidade de erros ao logar no sistema

		system("color 60");
	   printf("\t\t\tCADASTRO DO NOVO LOGIN\n\nNOVO LOGIN:");
       fflush(stdin);                     //Limpando o buffer do teclado
       gets(login);
       printf("\nNOVA SENHA:");
       do{
           c = getch();
           if(isprint(c)){       //Analisa se o valor da vari�vel c � imprimivel
           senha[a] = c;  //Se for, armazena o caractere
           a++;
           printf("*");          //imprime o * Anterisco
           }
           else if(c == 8 && a){    //8 � o caractere BackSpace na tabela ASCII, && a analisa se a � diferente de 0

		   senha[a]='\0';
           a--;
     		printf("\b \b");
           }
       }while(c!=13);             //13 � o valor de ENTER na tabela ASCII
       senha[a]='\0';
       system("cls");
       printf("\n\t\t\t\t\t\tCadastro efetuado com sucesso...\n\n");
       system ("cls");
       do{
           printf("\n\n\n\n\n\n\n\t\t\t\t\t\tLOGIN:");
           fflush(stdin);      //Limpando o buffer do teclado
           gets(acesso_login);
           printf("\t\t\t\t\t\tSENHA:");
           a = 0;
               do{
                   c=getch();
                   if(isprint(c)){      //Analisa se o valor de c � imprim�vel
                   acesso_senha[a]=c;
                   a++;
                   printf("*");      //Imprimindo apenas o asterisco *
                   }
                   else if(c == 8 && a){
                   acesso_senha[a]='\0';
                   a--;
                   printf("\b \b");     //Apagando os caracteres digitados
                   }
               }while(c != 13);           //13 � o valor de ENTER na tabela ASCII
               acesso_senha[a]='\0';

               if(!strcmp(login,acesso_login)&&!strcmp(senha,acesso_senha)){               //strcmp retorna 0 se as vari�veis forem iguais. !strcmp � o mesmo que strcmp==0
               printf("\n\n\n\n\t\t\t\t\t\t\aLOGADO COM SUCESSO...\n\n"); system("color 62");
               b = 0;	
               system("cls");
               logo ();
               menu();
               }
               else {
               system("cls");
               d--;          //Quando d for iguala a 0, o sistema bloqueia por 3 erros consecutivos
               if (d)
			   printf("\n\n\n\t\t\t\t\t\tLOGIN OU SENHA INV�LIDOS, TENTE NOVAMENTE...");system("color 64");
               }
       }while(b && d);                      //Enquanto b e d forem diferente de zero 0
       if(d == 0)
	   printf("\a\n\n\t\tTENTE MAIS TARDE. VOC� ERROU 3 VEZES CONSECUTIVAS...\n\n");
       //Analisa se a pessoa errou 3 vezes a senha. !d � o mesmo que d==0
       system("cls");
system("pause");


return 0;
} ///FIM DO MAIN.


/*aqui inicia a fun��o responsavel por levar o menu para a fun��o main nessa fun��o se encontra tudo que o fucionario poderar fazer depois que
realizar o login.*/


void menu()  ///iniciando a fuu�ao. //VOID MENU, Linha:870
{
	setlocale(LC_ALL,"");
	//declarando as variaveis que ser�o usados nessa fun�ao.

    int Opcao,OpcaoCliente,posicao,retorno;
    int codaux;
    do
    {
		system("color 60");
		printf("\n\t\t\t\t\t ___________________________________________________ \n");
    	printf("\t\t\t\t\t|                                                   |\n");
  		printf("\t\t\t\t\t|-------------------SEJA BEM VINDO------------------|\n");
        printf("\t\t\t\t\t|1 - Cadastrar Novo Cliente                         |\n");
        printf("\t\t\t\t\t|2 - Cliente                                        |\n");
        printf("\t\t\t\t\t|3 - Alterar Dados do Cliente                       |\n");
        printf("\t\t\t\t\t|4 - Excluir Dados do Cliente                       |\n");  //menu com as op��es.
        printf("\t\t\t\t\t|5 - Cadastrar Pedido                               |\n");
        printf("\t\t\t\t\t|6 - Cadastrar Bebidas                              |\n");
        printf("\t\t\t\t\t|7 - Excluir Pedido                                 |\n");
        printf("\t\t\t\t\t|8 - Funcion�rios                                   |\n");
        printf("\t\t\t\t\t|9 - Estoque                                        |\n");
        printf("\t\t\t\t\t|10 - Sair                                          |\n");
        printf("\t\t\t\t\t|---------------------------------------------------|\n");
        printf("\t\t\t\t\t|___________________________________________________|\n\n");
		printf("\t\t\t\t\tSelecione uma op��o:");                        
		versao ();
		printf("\n\n");
        scanf("%d", &Opcao);
		getchar();
        if (Opcao == 1)
        {
            printf("NOVO CLIENTE\n");
            posicao=verifica_pos();

                if ( posicao != -1 )
                {

                    printf("\nEntre com c�digo de 1 a 200 para cadastrar novo cliente:");
                    fflush(stdin);
					scanf("%d",&codaux);

                    retorno = verifica_cod( codaux );

                    if ( retorno == 1 )
                        cadastroP( codaux, posicao );
                    else{
                        printf("\nC�digo j� existente ou inv�lido, pressione Enter para voltar ao menu princ�pal\n");
                        getchar();
                        system("cls");
                        menu(); 		//ele retorna pro inicio da fun�ao menu.
                    }

                }
                else
                    printf("\nN�o � poss�vel realizar mais cadastros!\n");

                break;

        } //if.
        else if (Opcao == 2)
        {
            system("cls");
            do{
   	        printf("\n\t\t\t\t\t _______________________________________\n");
            printf("\t\t\t\t\t|                                       |\n");
            printf("\t\t\t\t\t|---------------------------------------|\n");
            printf("\t\t\t\t\t|2 - Clientes                           |\n");
            printf("\t\t\t\t\t|---------------------------------------|\n");
            printf("\t\t\t\t\t|1 - Pesquisar cliente por c�digo       |\n");
            printf("\t\t\t\t\t|2 - Listar de todos os clientes        |\n");
            printf("\t\t\t\t\t|3 - Voltar ao menu princ�pal           |\n");
            printf("\t\t\t\t\t|---------------------------------------|\n");
            printf("\t\t\t\t\t|_______________________________________|\n\n");
            printf("\t\t\t\t\tSelecione uma op��o:");
            fflush(stdin);
            scanf("%d", &OpcaoCliente);
            getchar();
                 if(OpcaoCliente == 1){
                    consultaCod();
                }
                else if(OpcaoCliente == 2){
                    list();
                }
                else if(OpcaoCliente == 3){
                    printf("\nPressione ENTER para voltar a tela princ�pal");
                     fflush(stdin);
					getchar();
                    system("cls");
                }
                else{
                    printf("Op��o Inv�lida\n\n");
            	}
    		} //do.

	while((OpcaoCliente != 3) || (OpcaoCliente > 3) || (OpcaoCliente < 0) || (OpcaoCliente == 0));

	    }else if(Opcao == 3){
			edite();
		}
        else if (Opcao == 4)
        {
            printf("EXCLUS�O DE DADOS DO CLIENTE\n");
            excluirCliente();
        }
        else if (Opcao == 5)
        {
            printf("ENTRADA DE PEDIDO\n");
            cadastroPedido();
        }
        else if(Opcao == 6)
		{
			printf("CADASTRO DE BEBIDAS\n");
			bebida();
		}
        else if (Opcao == 7)
        {
            printf("CANCELAR PEDIDO\n");
			excluirPedido();
        }
		else if (Opcao == 8)
		{
        	printf("FUNCION�RIOS");
			funcionarios();
		}
		else if(Opcao == 9)
		{
			printf("VER ESTOQUE \n");
			estoque();
		}
        else if (Opcao == 10)
        {
            printf("Saindo...\n");
        }
        else{
            printf("Op��o inv�lida, pressione Enter para voltar ao menu princ�pal");
            getchar();
            system("cls");
        }

	} // do while.

	 while (Opcao != 10 || Opcao < 10);

} /// Fim da Fun��o menu.

/*Fun�ao resposavel pela lista de clientes cadastrados programa. */

void list(){ /// INICIO DA FUN�AO LISTA.
	
	system("cls");
    int i; //Declarando as variaveis dessa fun�ao.
		
		for( i = 0; i < 200; i++){

			if(logC[i].cod != NULL){
				printf("\n============================");
            	printf("\n|C�digo:%d    ",logC[i].cod);
            	printf("\n============================");
				printf("\n|Nome:%s      ", logC[i].nome);
				printf("\n|CPF:%s       ",logC[i].CPF);
				printf("\n|Endere�o:%s  ", logC[i].endereco);
				printf("\n|Telefone:%s  ", logC[i].telefone);
 				printf("\n|Pizza: %s  ", logC[cont].clientePed.namePed);
 				printf("\n|Borda: %s  ", logC[cont].clientePed.bordas);
				printf("\n|Bebida: %s ",logC[cont].clientePed.bebidaped);
				printf("\n|Sabor: %s  ", logC[cont].clientePed.sabor);
				printf("\n============================");
			}
		}
    printf("\nPressione Enter para volta ao menu princ�pal");
    getchar();
    system("cls");

} ///FIM DO LISTA.

/*Responsavel por fazer o cadastro do cliente e do seu pedido dentro do menu. */

void cadastroP(int codigo, int pos)  ///INICIO DA FUN�AO CADASTRO.
{
	system("cls");
	setlocale(LC_ALL,"");
    	do{
    	pos = verifica_pos();
    	logC[pos].cod = codigo;
 		logC[pos].clientePed.cod =	logC[cont].cod ;
			fflush(stdin);
        	printf("\nNome:");
        	gets(logC[pos].nome);
        	printf("\nCPF:");
        	gets(logC[pos].CPF);
        	printf("\nEndere�o:");
        	gets(logC[pos].endereco);
        	printf("\nTelefone:");
        	gets(logC[pos].telefone);
        	logC[pos].vazio = 1;

        printf("\nPressione Enter para efetuar um novo cadastro ou qualquer outra tecla para volar ao menu princ�pal");
        getchar();
        fflush(stdout);
    } while(opt == 1);
    system("cls");
    menu();
    fflush(stdout);

} // FIM DO CADASTRO DE PESSOAS


void edite(int i){                          //INICIO DA FUN�AO 
	
	system("cls");
	setlocale(LC_ALL,"");
	int op;
	int cont;
	
	do{
	printf("\n\t\t\t\t\t _________________________");
	printf("\n\t\t\t\t\t|                         |");
	printf("\n\t\t\t\t\t|-------------------------|");
	printf("\n\t\t\t\t\t|1 - Alterar Nome         |");
	printf("\n\t\t\t\t\t|2 - Alterar o CPF        |");
	printf("\n\t\t\t\t\t|3 - Alterar o Endere�o   |");
	printf("\n\t\t\t\t\t|4 - Alterar o Telefone   |");
	printf("\n\t\t\t\t\t|5 - Sair                 |");
	printf("\n\t\t\t\t\t|_________________________|");
	scanf("%d", &op);
	
	switch(op){
		case 1:
			printf("\nNome do Cliente: %s\n", logC[i].nome);
			printf("\nDigite Novo Nome: ");
			scanf("%s", logC[i].nome);
			break;
		case 2:
			printf("\nCPF do Cliente: %s\n", logC[i].CPF);
			printf("\nDigite o Novo CPF: ");
			scanf("%s", logC[i].CPF);
			break;
		case 3:
			printf("\nEndere�o do Cliente: %s\n", logC[i].endereco);
			printf("\nDigite o Novo Endere�o: ");
			scanf("%s", logC[i].endereco);
			break;
		case 4:
			printf("\nTelefone do Cliente: %s\n", logC[i].telefone);
			printf("\nDigite o Novo Telefone: ");
			scanf("%s", logC[i].telefone);	
	}
	
	
	}while(op != 5);
	
} //FIM DA FUN��O.



/*Fun�ao responsavel por verificar a posi�ao do cadastro*/ 



int verifica_pos( void )     		//VERIFICADOR DA POSI��O

{
    int cont = 0;

    while ( cont <= 200 )
    {

        if ( logC[cont].vazio == 0 )
            return(cont);

        cont++;

    }

    return(-1);

} // FIM DO VERIFICADOR



/*Fun�ao responssavel por verificar o codigo*/



int verifica_cod( int codigo ) 		// VERIFICADOR DE C�DIGO
{
    int cont = 0;

    while ( cont <= 200 )
    {
        if ( logC[cont].cod == codigo )
            return(0);

        cont++;
    }

    return(1);

} // FIM DO VERIFICADOR



/* A fun��o a seguir � respnsavel por fazer a exclus�o do pedido do cliente 
no qual foi cadastrado */



void excluirPedido(void)  // EXCLUI CLIENTE
{
	setlocale(LC_ALL,"Portuguese");
    
	int codigo, cont = 0;
    char resp;
    printf("\nEntre com o codigo do registro que deseja excluir: \n");
    scanf("%d", &codigo);

    while ( cont <= 200 )
    {

        if ( logC[cont].cod == codigo )
        {

            if (logC[cont].clientePed.vaz == 1 )
            {

				printf("\n==========================");
				printf("\n|Pedido do cliente");
				printf("\n==========================");
				printf("\n|Pizza: %s  ", logC[cont].clientePed.namePed);
				printf("\n|Borda: %s  ", logC[cont].clientePed.bordas);
				printf("\n|Bebida: %s ", logC[cont].clientePed.bebidaped);
				printf("\n|Sabor: %s  " ,logC[cont].clientePed.sabor);
                printf("\n==========================");
				getchar();
                printf("\nDeseja realmente exlucir? s/n: ");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    logC[cont].clientePed.vaz = 0;
                    logC[cont].clientePed.cod = NULL;
                    printf("\nExclusao feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclusao cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 200 )
            printf("\nCodigo nao encontrado\n");

    }

    system("pause");
    system("cls");

}



/*Consulta o primeiro cadastro de cliente via codigo dado pelo funcionario que o registrou
assim mostrando o cliente atraves do numero de cadastro*/



void consultaCod (void) 		///INICIO DA FUN�AO COLSULTA CODIGO. 
{
	setlocale(LC_ALL,"");
    int cont = 0, codigo;

    printf("\nEntre com o c�digo:\n");
    scanf("%d",&codigo);
    fflush(stdin);
    system("cls");

    while ( cont <= 200 )
    {
        if (logC[cont].cod == codigo)
        {
            if (logC[cont].vazio == 1)
            {

                printf("\nC�digo: %d \nNome: %s\nCPF: %s\nEndere�o: %s\nTelefone: %s\n\n", logC[cont].cod,logC[cont].nome,logC[cont].CPF,logC[cont].endereco,logC[cont].telefone);

               system ("pause");

                system("cls");

                break;

            }
        }

        cont++;

        if ( cont > 200 ){
            printf("\nC�digo n�o encontrado, pressione Enter para voltar ao menu princ�pal\n");
            getchar();
            system("cls");
        }

    }

} /// FIM DA FUN��O CONSULTA CODIGO.



/*Aqui inicia a fun�ao responsael por exluir clientes da fun�ao meni.*/



void excluirCliente(void)  ///INICIO DA FUN�AO //VOID ExcluirCliente, Linha: 813
{
	setlocale(LC_ALL,"");
    int cod, cont = 0;
    char resp;
    printf("\nEntre com o c�digo de registro que deseja excluir:\n");
    scanf("%d", &cod );

    while ( cont <= 200 )
    {

        if ( logC[cont].cod == cod )
        {

            if (logC[cont].vazio == 1 )
            {
                printf("\nC�digo:%d\nNome:%s\nCPF:%s\nEndere�o:%s\nTelefone:%s\n\n", logC[cont].cod,logC[cont].nome,logC[cont].CPF,logC[cont].endereco,logC[cont].telefone);
			    getchar();
                printf("\nDeseja realmente excluir?[S/N]:");
                scanf("%s",&resp);

                if ( ( resp == 'S' ) || ( resp == 's' ) )
                {
                    logC[cont].vazio = 0;
                    logC[cont].cod = NULL;
                    printf("\nExclus�o feita com sucesso\n");
                    break;
                }
                else
                {
                    if ( ( resp == 'N' ) || ( resp == 'n' ) )
                    {
                        printf("Exclus�o cancelada!\n");
                        break;
                    }
                }

            }

        }

        cont++;

        if ( cont > 200 )
            printf("\nC�digo n�o encontrado\n");

    }

    system("pause");
    system("cls");

} ///FIM DA FUN�AO EXCLUI



void cadastroPedido() 			//Cadastro dos pedidos
{
    system("cls");
setlocale(LC_ALL,"");
    int i;
    int Option;
    int Recheio;
    int OpcaoPedido;
    char nomeCad[200];

    printf("\nDigite o nome do cliente cadastrado:\n");
    gets(nomeCad);

    for(i = 0;i < 200; i++){
        if(!strcmp(logC[i].nome, nomeCad)){ // ! � igual == 0
                do{
                printf("\nEscolha o pedido:                                                                 \n\n");
                printf("|******************************************************************************************|");
				printf("\n|SABORES TRADICIONAIS!                                                                     |\n");
				printf("|******************************************************************************************|\n");
                printf("|------------------------------------------------------------------------------------------|");
				printf("\n|1- Pizza Mussarela/Calabresa 20,00 | 2- Pizza Portugesa 25,00 | 3- Pizza Marguerita 25,00 |\n");
				printf("|------------------------------------------------------------------------------------------|");
                printf("\n|4- Pizza Calabresa 25,00 | 5- Pizza Quatro queijos 25,00 | 6- Pizza Peperone 25,00        |\n");
                printf("|------------------------------------------------------------------------------------------|");
                printf("\n|7- Pizza Espanhola 25,00 | 8- Pizza Frango catupiry 25,00 | 9- Pizza Bacon 25,00          |\n");
				printf("|__________________________________________________________________________________________|\n\n");

				printf("|******************************************************************************************|");
				printf("\n|SABORES ESPECIAIS!                                                                        |\n");
				printf("|******************************************************************************************| \n");
                printf("|------------------------------------------------------------------------------------------|");
				printf("\n|10- Pizza Mandonna 29,90 | 11- Pizza Sinatra 29,90 | 12- Pizza Cora��o 29,90              |\n");
				printf("|------------------------------------------------------------------------------------------|");
                printf("\n|13 - Pizza Batata Frita 29,90 | 14 - Pizza Lennon 29,90 | 15 - Pizza Vegetariana 29,90    |\n");
                printf("|------------------------------------------------------------------------------------------|\n");
				printf("|__________________________________________________________________________________________|\n\n");

				printf("|*******************************************************************************************|");
				printf("\n|ESPECIAIS DOCE!                                                                            |\n");
				printf("|*******************************************************************************************| \n");
                printf("|-------------------------------------------------------------------------------------------|");
				printf("\n|16 - Pizza Chocolate 25,00 | 17 - Pizza Chiquita Banana 25,00 | 18 - Pizza Sensa��o 25,00  |\n");
				printf("|-------------------------------------------------------------------------------------------|\n");
				printf("|___________________________________________________________________________________________|\n");

				printf("|*******************************************************************************************|");
				printf("\n|PIZZAS INDIVIDUAIS                                                                         |\n");
				printf("|*******************************************************************************************|\n");
                printf("|-------------------------------------------------------------------------------------------|");
				printf("\n|22 - Mini Pizza 7,00 | 23 - Brontinhp 15,00 |                                              |\n");
				printf("|-------------------------------------------------------------------------------------------|\n");
				printf("|___________________________________________________________________________________________|\n");
				scanf("%d", &OpcaoPedido);
                system("cls");
                if(OpcaoPedido == 1){
                    strcpy(logC[i].clientePed.namePed, "Pizza Mussarela/Calabresa");
                    printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nMussarela, Calabresa, Cebolas e azeitonas");
                    printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
                    scanf("%d", &Recheio);
                    	
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
						
                }
				
				else if(OpcaoPedido == 2){
                    strcpy(logC[i].clientePed.namePed, "Pizza Portugesa");
                    printf("\nPedido:%s, adicionado.", logC[i].clientePed.namePed);
                    printf("\nMussarela, Presunto, Ervilha, Milho, Palmito, Cebola, Ovo e catupiry");
                    
                    printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
					
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
						
                }else if(OpcaoPedido == 3){
                    strcpy(logC[i].clientePed.namePed, "Pizza Marguerita");
                    printf("\nPedido:%s, adicionado.", logC[i].clientePed.namePed);
                    printf("\nMussarela, Parmess�o, Catupiry, Tomate e Azeitona");
                    printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
					logC[i].clientePed.vaz = 1;
													
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda: %s, adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
               	}else if(OpcaoPedido == 4){
                	strcpy(logC[i].clientePed.namePed, "Pizza Calabresa");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nCalabresa, Cebola e azeitona");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
													
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
				}else if(OpcaoPedido == 5){
                	strcpy(logC[i].clientePed.namePed, "Pizza Quatro queijo");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela, provolone, Queijo prado, Parmess�o, Catupiry, Tomate e azeitona");
                    printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
									
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
            	}else if(OpcaoPedido == 6){
                	strcpy(logC[i].clientePed.namePed, "Pizza Atum");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nMussarela, atum, Cebola e azeitona");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
													
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
            	}else if(OpcaoPedido == 7){
                	strcpy(logC[i].clientePed.namePed, "Pizza Espanhola");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nMussarela, Presunto, Tomate, Palmito, azeitona e or�gano");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
            	}else if(OpcaoPedido == 8){
                	strcpy(logC[i].clientePed.namePed, "Pizza Frango Catupiry");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("Mussarela, File de frango desfiado temperado e catupiry");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
									
										if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								
            	}else if(OpcaoPedido == 9){
                	strcpy(logC[i].clientePed.namePed, "Pizza Bacon");
					printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nMussarela, bacon, catupiry, tomate e azeitona");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}

            	}else if(OpcaoPedido == 10){
                	strcpy(logC[i].clientePed.namePed, "Pizza Madonna");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela, champgnon e catupiry legitimo");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}

            	}else if(OpcaoPedido == 11){
                	strcpy(logC[i].clientePed.namePed, "Pizza Sinatra");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela, champgnon, calabresa triturada, catupiry e or�gano");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}

            	}else if(OpcaoPedido == 12){
                	strcpy(logC[i].clientePed.namePed, "Pizza Cora��o");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela, cora��o de galinha com tempero especial");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
            	}else if(OpcaoPedido == 13){
                	strcpy(logC[i].clientePed.namePed, "Pizza Batata Frita");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela, presunto, batata frita, parmes�o e oregano");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
            	}else if(OpcaoPedido == 14){
                	strcpy(logC[i].clientePed.namePed, "Pizza Lennon");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela e atum");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
            	}else if(OpcaoPedido == 15){
                	strcpy(logC[i].clientePed.namePed, "Pizza Vegetariana");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela, ervilha, milho verde, tomate, palmito e azeitona");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
            	}else if(OpcaoPedido == 16){
                	strcpy(logC[i].clientePed.namePed, "Pizza Chocolate");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nEscolha o chocolate!\n\n");
                	printf("|*****************|\n");
                	printf("|1 - Preto        |\n");
                	printf("|2 - Branco       |\n");
                	printf("|3 - Preto/Branco |\n");
                	printf("|_________________|\n");
                	scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Preto");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Branco");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Preto/Branco");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}

            	}else if(OpcaoPedido == 17){
                	strcpy(logC[i].clientePed.namePed, "Pizza Chiquita Banana");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nMussarela, banana, a��car");
				    printf("\nEscolha as borda\n\n");
                    printf("|*****************|\n");
                    printf("|1 - Leite mo�a   |\n");
                    printf("|2 - Nutella      |\n");
                    printf("|3 - Doce de leite|\n");
                    printf("|_________________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Leite Mo�a");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Nutella");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Doce de leite");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
		
            	}else if(OpcaoPedido == 18){
                	strcpy(logC[i].clientePed.namePed, "Pizza Sensa��o");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                	printf("\nMussarela, chocolate preto e morango");
					printf("\nEscolha as borda\n\n");
                    printf("|*****************|\n");
                    printf("|1 - Leite mo�a   |\n");
                    printf("|2 - Nutella      |\n");
                    printf("|3 - Doce de leite|\n");
                    printf("|_________________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Leite Mo�a");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Nutella");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Doce de leite");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}

				}else if(OpcaoPedido == 19){
                	strcpy(logC[i].clientePed.namePed, "Mini Pizza");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nMussarela e Calabresa ");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
				}else if(OpcaoPedido == 20){
                	strcpy(logC[i].clientePed.namePed, "Brontinha");
                	printf("\nPedido:%s, adicionado.",logC[i].clientePed.namePed);
                    printf("\nMussarela, Presunto, Tomate e azeitona");
					printf("\nEscolha as borda\n\n");
                    printf("|**************|\n");
                    printf("|1 - Cheddar   |\n");
                    printf("|2 - Requeij�o |\n");
                    printf("|3 - Maionese  |\n");
                    printf("|4 - Catupiry  |\n");
                    printf("|______________|\n");
					scanf("%d", &Recheio);
								if(Recheio == 1){
					
										strcpy(logC[i].clientePed.bordas, "Cheddar");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;
            			}
								else if(Recheio == 2){
            							
										strcpy(logC[i].clientePed.bordas, "Requeij�o");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   			 i++;	
						}
								else if(Recheio == 3){
            				
										strcpy(logC[i].clientePed.bordas, "Maionese");
										printf("Borda Escolhida: %s, Foi adicionado.", logC[i].clientePed.bordas);
					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
								else if(Recheio == 4){
									
										strcpy(logC[i].clientePed.bordas, "Catupiry");
										printf("Borda Escolhida: %s, Foi adicionado", logC[i].clientePed.bordas);
									    
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                    		i++;	
						}
				}
    
		}while(Option == 1);
    system("cls");
			}
		}
	} /// FIM DO CADASTRO DE PEDIDOS.

void bebida()//VOID BEBIDA, Linha: 650
{
    int Option;
    int Refresco;
    int OpcaoPedido;
    int i;
	char nomeCad[200];
system("cls");
setlocale(LC_ALL,"");
    printf("\nDigite nome cadastrado:\n");
    gets(nomeCad);

    for(i = 0;i < 200; i++){
        if(!strcmp(logC[i].nome, nomeCad)){ // ! � igual == 0
                do{
                printf("\n\t\t\t\t\tEscolha uma bebida\n");
              printf("\n\t\t\t\t\t|***************************|\n");
				printf("\t\t\t\t\t|1 - Koca          R$8,00   |\n");
				printf("\t\t\t\t\t|2 - Hanta         R$7,00   |\n");
				printf("\t\t\t\t\t|3 - Bepis         R$7,00   |\n");
				printf("\t\t\t\t\t|4 - CH2O          R$4,50   |\n");
				printf("\t\t\t\t\t|5 - Shuco         R$4,50   |\n");
				printf("\t\t\t\t\t|6 - Chop Trahma   R$6,50   |\n");
				printf("\t\t\t\t\t|7 - Ceveja        R$8,00   |\n");
				printf("\t\t\t\t\t|___________________________|\n");
                scanf("%d", &OpcaoPedido);
                system("cls");
                if(OpcaoPedido == 1){
                    strcpy(logC[i].clientePed.bebidaped, "Koca-kola");
                    printf("\n\t\t\t\t\tPedido:%s, adicionado.",logC[i].clientePed.bebidaped);
                    printf("\n\t\t\t\t\tSABOR:\n\n");
                    printf("\t\t\t\t\t|**************|\n");
                    printf("\t\t\t\t\t|1 - Koca Zero |\n");
                    printf("\t\t\t\t\t|2 - Koca Kaf� |\n");
                    printf("\t\t\t\t\t|______________|\n");
                    scanf("%d", &Refresco);
                    	
                    						if(Refresco == 1){
                    							
												strcpy(logC[i].clientePed.sabor, "Koca Zero");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
					   						else if(Refresco == 2){
                    							
												strcpy(logC[i].clientePed.sabor, "Koca Zero");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
               					
				}else if(OpcaoPedido == 2){
					strcpy(logC[i].clientePed.bebidaped, "Hanta");
					printf("\n\t\t\t\t\tPedido:%s, adicionado.",logC[i].clientePed.bebidaped);
					printf("\n\t\t\t\t\tSABOR:\n\n");
					printf("\t\t\t\t\t|**************|\n");
                    printf("\t\t\t\t\t|1 - Lim�o     |\n");
                    printf("\t\t\t\t\t|2 - Laranja   |\n");
                    printf("\t\t\t\t\t|3 - Uva       |\n");
                    printf("\t\t\t\t\t|______________|\n");
                    scanf("%d", &Refresco);
                    						
											if(Refresco == 1){
                    							
												strcpy(logC[i].clientePed.sabor, "Lim�o");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
					   						else if(Refresco == 2){
                    							
												strcpy(logC[i].clientePed.sabor, "Laranja");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
               					
               								else if(Refresco == 3){
               									
               									strcpy(logC[i].clientePed.sabor, "Uva");
               								printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
               								
									    logC[i].clientePed.vaz = 1;	
               						printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
								}
				}else if(OpcaoPedido == 3){
					
					strcpy(logC[i].clientePed.bebidaped, "Pepis");
					printf("\n\t\t\t\t\tPedido:%s, adicionado.",logC[i].clientePed.bebidaped);
					printf("\n\t\t\t\t\tSABOR:\n\n");
					printf("\t\t\t\t\t|**************|\n");
                    printf("\t\t\t\t\t|1 - Lim�o     |\n");
                    printf("\t\t\t\t\t|2 - Kola      |\n");
                    printf("\t\t\t\t\t|______________|\n");
                    scanf("%d", &Refresco);
											
											if(Refresco == 1){
                    							
												strcpy(logC[i].clientePed.sabor, "Lim�o");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
					   						else if(Refresco == 2){
                    							
												strcpy(logC[i].clientePed.sabor, "Kola");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
               				
               }else if(OpcaoPedido == 4){
					strcpy(logC[i].clientePed.bebidaped, "H2O");
					printf("\n\t\t\t\t\tPedido:%s, adicionado.",logC[i].clientePed.bebidaped);
					printf("\n\t\t\t\t\tSABOR:\n\n");
					printf("\t\t\t\t\t|**************|\n");
                    printf("\t\t\t\t\t|1 - Lim�o     |\n");
                    printf("\t\t\t\t\t|2 - Laranja   |\n");
                    printf("\t\t\t\t\t|______________|\n");
                    scanf("%d", &Refresco);
								
											if(Refresco == 1){
                    							
												strcpy(logC[i].clientePed.sabor, "Lim�o");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
					   						else if(Refresco == 2){
                    							
												strcpy(logC[i].clientePed.sabor, "Laranja");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
  
               }else if(OpcaoPedido == 5){
					strcpy(logC[i].clientePed.bebidaped, "Suco");
					printf("\n\t\t\t\t\tPedido:%s, adicionado.",logC[i].clientePed.bebidaped);
					printf("\n\t\t\t\t\tSABOR:\n\n");
					printf("\t\t\t\t\t|**************|\n");
                    printf("\t\t\t\t\t|1 - Lim�o     |\n");
                    printf("\t\t\t\t\t|2 - Maracuja  |\n");
                    printf("\t\t\t\t\t|3 - Laranja   |\n");
                    printf("\t\t\t\t\t|4 - Morango   |\n");
                    printf("\t\t\t\t\t|5 - Manga     |\n");
                    printf("\t\t\t\t\t|______________|\n");
                    scanf("%d", &Refresco);
											if(Refresco == 1){
                    							
												strcpy(logC[i].clientePed.sabor, "Lim�o");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
					   						else if(Refresco == 2){
                    							
												strcpy(logC[i].clientePed.sabor, "Maracuja");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
               					
               								else if(Refresco == 3){
               									
               									strcpy(logC[i].clientePed.sabor, "Laranja");
               								printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
               								
									    logC[i].clientePed.vaz = 1;	
               						printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
								}
											
											if(Refresco == 4){
                    							
												strcpy(logC[i].clientePed.sabor, "Morango");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
					   						else if(Refresco == 5){
                    							
												strcpy(logC[i].clientePed.sabor, "Manga");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
               					
               }else if(OpcaoPedido == 6){
					
					strcpy(logC[i].clientePed.bebidaped, "Chop Brahma");
					printf("\n\t\t\t\t\tPedido:%s, adicionado.",logC[i].clientePed.bebidaped);
					printf("\n\t\t\t\t\tDeseja continuar\n\n");
					logC[i].clientePed.vaz = 1;
					printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    scanf("%d", &Option);
                   i++;
                   
            	}else if(OpcaoPedido == 7){
					strcpy(logC[i].clientePed.bebidaped, "Ceveja");
					printf("\n\t\t\t\t\tPedido:%s, adicionado.",logC[i].clientePed.bebidaped);
					printf("\n\t\t\t\t\tBEBIBA:\n\n");
					printf("\t\t\t\t\t\t|**************|\n");
                    printf("\t\t\t\t\t\t|1 -PSKOL      |\n");
                    printf("\t\t\t\t\t\t|2 -TRAHMA     |\n");
                    printf("\t\t\t\t\t\t|3 -Original   |\n");
                    printf("\t\t\t\t\t\t|______________|\n");
                    scanf("%d", &Refresco);
											
											if(Refresco == 1){
                    							
												strcpy(logC[i].clientePed.sabor, "PSKOL");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
					   						else if(Refresco == 2){
                    							
												strcpy(logC[i].clientePed.sabor, "TRAHMA");
                    						printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
                    					
										logC[i].clientePed.vaz = 1;
									printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
               					}
               					
               								else if(Refresco == 3){
               									
               									strcpy(logC[i].clientePed.sabor, "Original");
               								printf("\n\t\t\t\t\tSabor Escolhido:%s, Foi adicionado.", logC[i].clientePed.sabor);
               								
									    logC[i].clientePed.vaz = 1;	
               						printf("\n\n1 para continuar pedindo ou 2 para volar ao menu principal: ");
                    			scanf("%d", &Option);
                   				i++;
								}
								
               }
               
    }while(Option == 1);
    system("cls");

		}
	
	}
	
}
 
