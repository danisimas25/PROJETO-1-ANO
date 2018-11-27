#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include <string.h>
#include<locale.h>
#include<windows.h>	
#define MAX 100
// Declaraçâo das variáveis globais
struct livros{
    char Titulo[100];
	char autor[50];
	char cod[20];
	char ano[5];
}dados;
//Declaração das Funções 
void cadastrar();
void menu_principal_livros();
void exibir();
void excluir();
void alterar_livro();
void pesquisar();
void apresentar_linha();
void setinha();
void textura();
void textura_2();
void salvar_alteracao(struct livros *a);
//Variaveis Auxiliares
char acervo[20];
int o;
// Declaração de Arquivos e o ponteiro.

FILE *arq;

//local para armazenamento do arquivo para "facilitar" a compreensão
char url[] = "acervo.txt";

//Função principal, aqui que começa o programa
    void menu_principal_livros() {
        int opcao;
        printf("\n\n\n");
        apresentar_linha();
        printf("\n \t\t\tBEM VINDO AO ACERVO DEKSTHE! ");
        printf("\n");
        printf("\n\t\t\\\\ Uma casa sem livros é um corpo sem alma \\\\\n");
        printf("\n");
        setinha();
        printf("\n\t\t\t\t/// MENU ///\n");
        printf("\n\t\t\t\t1- CADASTRAR LIVROS\n");
        printf("\n\t\t\t\t2- EXIBIR  \n");
        printf("\n\t\t\t\t3- ALTERAR \n");
        printf("\n\t\t\t\t4- EXCLUIR \n");
        printf("\n\t\t\t\t5- PESQUISAR \n");
         printf("\n\t\t\t\t6- MAIS \n");
        printf("\n\t\t\t\t7- SAIR \n\n");
        apresentar_linha();
        setinha();
        printf("\n");
        scanf("%d",  & opcao);
//Opções a serem escolhidas pelos usuários

        system("cls");
        switch (opcao) {
            case 1:
                system("cls");
                textura();
                printf("\n");
                printf("\t\t\t\tOBSERVAÇÕES\n\n");
                textura_2();
                printf("\n");
                printf("\tAo fazer o cadastro do livro, não utilizar o número 0(código).\n\n\t\tAperte qualquer tecla para continuar.");
                printf("\n");
				getch(); 
				system("cls");         
                cadastrar();
                system("cls");
                break;
            case 2:

                exibir();
                system("cls");
                break;
            case 3:
				system("cls");
				alterar_livro();
                break;
            case 4:
                excluir();
                system("cls");
                break;
            case 5:
                pesquisar();
                system("cls");
                break;
            case 7:
                textura();
                printf("\n\n Programa encerrado com sucesso. Obrigada por utilizar o acervo DEKSTHE!\n\n");
                apresentar_linha();
                getch();
                
                exit(7);
                case 6:
                	
                	system("cls");
                	textura();
                	printf("\n");
                    printf("\t\t\t\tMAIS INFORMAÇÕES\n\n");
                    textura_2();
                    printf("\n");
                    printf("\t\t\tProdutores:\n\n\t\t\tSthefany Rodrigues\n\n\t\t\tDaniele Simas\n\n\t\t\tKadson Malpus\n\n\t\t\tErica Medeiros\n\n");
                    apresentar_linha();
                    printf("\n\t\tPara mais informações, entre em contato:\n\n\t\t\tdeksthe@gmail.com\n\n");
                    printf("\t\t:D");
                printf("\n");
				getch();   	
				system("cls");
				menu_principal_livros();

                	
            //Se a opção não existir, uma mensagem é exibida na superior central
            // do programa
            default:
                apresentar_linha();
                printf("\n\t\t\tA OPÇÃO NÃO EXISTE.\n \t\t\t\n\t\tVocê será direcionado ao Menu principal.");
                getch();
                system("cls"); 
                menu_principal_livros();
        }
    }
//Função para cadastramento dos livros

    void cadastrar() {
        arq = fopen("acervo.txt", "a");
        if (arq == NULL) {
            printf("Erro no arquivo");
        }
        textura();
        setlocale(LC_ALL, "Portuguese");
        fflush(stdin);
        printf("\n\t\t\t CADASTRAMENTO DE LIVROS \n\n");
        textura_2();
        printf("\nInsira um código para acessar o livro:");
        
        fflush(stdin);
        fgets(dados.cod, 20, stdin);
        fflush(stdin);
        
        printf("\nTítulo:");
        
        fflush(stdin);
        fgets(dados.Titulo, 100, stdin);
        fflush(stdin);
        
        printf("\nAutor(a):");
        
        fflush(stdin);
        fgets(dados.autor, 50, stdin);
        fflush(stdin);

        printf("\nAno de Publicação:");

        fflush(stdin);
        fgets(dados.ano, 5, stdin);
        fflush(stdin);
    
        // arquivo de cadastro
        fprintf(arq, "%s%s%s%s\n", dados.cod, dados.Titulo, dados.autor, dados.ano);
        fclose(arq);
        
        printf("\n\n");
        setinha();
        printf("\n Cadastro realizado com sucesso.\n\n");
        setinha();
        printf("\n\n");
        system("pause");
        system("cls");
        menu_principal_livros();
    }
//Função para exibir os livros

void exibir() {
    FILE * arq = fopen("acervo.txt", "r");
    setlocale(LC_ALL, "Portuguese");
    if (arq == NULL) {
        textura();
        printf("\n\n");
        printf("Erro ao executar o arquivo. Verifique se é um problema abragente.\n");
        printf("\n\n");
        textura_2();
        printf("\n\n");
        system("pause");
        system("cls");
        menu_principal_livros();
    } else {
        textura_2();
        printf("\n\t\t\t EXIBIÇÃO DOS LIVROS CADASTRADOS \n\n");
        textura_2();
        while(fscanf(arq, "%s%s%s%s", &dados.cod, &dados.Titulo, &dados.autor, &dados.ano) != EOF){
            printf("\n Código:%s\n", dados.cod);
            printf("\n Título:%s\n", dados.Titulo);
            printf("\n Autor(a):%s\n", dados.autor);
            printf("\n Ano de Publicação:%s\n", dados.ano);
            printf("\n");
            setinha();
            printf("\n");
        }
    }
    system("pause");
    setlocale(LC_ALL, "Portuguese");
    fclose(arq);
    system("cls");
    menu_principal_livros();
    }
//Função para exclusão de todo o acervo
void excluir() {
    int k = 0;
    textura_2();
    printf("\n");
    if (arq == NULL) {
        printf("\nInformamos que há um erro na execução do arquivo. Retorne ao Menu Principal.\n\n\n");
        textura_2();
        printf("\n");
        system("pause");
        system("cls");
        menu_principal_livros();
    } else {
        printf("\t\tVOCÊ REALMENTE DESEJA PROSSEGUIR?\n\n\n// Se sim, aperte o número 1 //\n\n// Se não, aperte o número 2 //\n\n Lembrando que essa operação apagará tudo que está salvo no acervo.\n\n");
        textura_2();
        printf("\n\n");
        scanf("%d",  &k);
        if (k == 1) {
            remove("acervo.txt");
            printf("\n\n");
        	setinha();
            printf("\n");
            printf("Acervo excluído com sucesso!\n");
            printf("\n");
            setinha();
            printf("\n\n");
            system("pause");
            system("cls");
            menu_principal_livros();
        } else {
            printf("\n\n");
        }
        setinha();
        printf("\nVocê será direcionado para o Menu Principal.");
        printf("\n\n");
        setinha();
        printf("\n");
        system("pause");
        menu_principal_livros();
    }
	}
// Função de alteração 
void alterar_livro() {
	
	char mod[100];
	char pesquisa[20];
	int op;
	struct livros *livro = NULL;
	
	textura_2();
    printf("\n\t\t\t ALTERAÇÃO DOS LIVROS CADASTRADOS \n\n");
    textura_2();
    
    printf("\nDigite o código do livro a ser alterado: ");
    
    fflush(stdin);
    gets(pesquisa);
    fflush(stdin);
    
    arq = fopen("acervo.txt", "r");
    
    if(arq == NULL){
    	
    	system("cls");
		textura_2();
    	printf("\n\t\t\t ALTERAÇÃO DOS LIVROS CADASTRADOS \n\n");
    	textura_2();
    	printf("\n");
    	printf("Arquivo não existe.\n\n");
		system("pause");
		system("cls");
	}
    else{
    
	    while(fscanf(arq, "%s%s%s%s", &dados.cod, &dados.Titulo, &dados.autor, &dados.ano) != EOF){
	    	if(strcmp(dados.cod, pesquisa) == 0){
	    		livro = (struct livros *) malloc(sizeof(struct livros));
	    		strcpy(livro->cod, dados.cod);
	    		strcpy(livro->Titulo, dados.Titulo);
	    		strcpy(livro->autor, dados.autor);
	    		strcpy(livro->ano, dados.ano);
	    		break;
			}
		}
		
		fclose(arq);
		
		system("cls");
		textura_2();
	    printf("\n\t\t\t ALTERAÇÃO DOS LIVROS CADASTRADOS \n\n");
	    textura_2();
	    
		
		if(livro == NULL){
			printf("\n\tLivro não encontrado.\n\n");
			getch();
			system("pause");
			system("cls");
		}
		else{
			do{
				system("cls");
				textura_2();
	    		printf("\n\t\t\t ALTERAÇÃO DOS LIVROS CADASTRADOS \n\n");
	    		textura_2();
	    		printf("\n\n");
				printf("\t\t\t\t0- VOLTAR AO MENU PRINCIPAL\n");
				printf("\t\t\t\t1- TÍTULO\n");
				printf("\t\t\t\t2- AUTOR(A)\n");
				printf("\t\t\t\t3- ANO DE PUBLICAÇÃO\n\n\t\t\t");
				printf("Aperte a opção que deseja alterar:");
				scanf("%d", &op);
			}while((op < 0) || (op > 4));
			
			system("cls");
			textura_2();
	    	printf("\n\t\t\t ALTERAÇÃO DOS LIVROS CADASTRADOS \n\n");
			
			switch(op){
				case 1:
					printf("Novo título: ");
					
					fflush(stdin);
					gets(mod);
					fflush(stdin);
					
					strcpy(livro->Titulo, mod);
					printf("\n");
					apresentar_linha();
					printf("\n");
					printf("Título alterado com sucesso!\n\n");
					apresentar_linha();
					printf("\n");
					break;
				case 2:
					printf("Novo autor(a): ");
					
					fflush(stdin);
					gets(mod);
					fflush(stdin);
					
					strcpy(livro->autor, mod);
					printf("\n");
					apresentar_linha();
					printf("\n");
					printf("Autor(a) alterado com sucesso!\n\n");
					apresentar_linha();
					printf("\n");
					break;
				case 3:
					printf("Novo ano de publicação: ");
					
					fflush(stdin);
					gets(mod);
					fflush(stdin);
					
					strcpy(livro->ano, mod);
					printf("\n");
					apresentar_linha();
					printf("\n");
					printf("Ano de publicação alterado com sucesso!\n\n");
					apresentar_linha();
					printf("\n");
					break;
			}
			
			salvar_alteracao(livro);
		}
	}
	
	free(livro);
	system("cls");
	menu_principal_livros();
}

//Função de salvar a alteração    
void salvar_alteracao(struct livros *a){
	
	FILE *aux = fopen("ops.txt", "w");
	FILE *arq2 = fopen("acervo.txt", "r");
	
	if(arq2 == NULL) printf("O arquivo não pode ser aberto.\n");
	if(aux == NULL) printf("O arquivo não pode ser aberto.\n");
	
	system("pause");
	
	while(fscanf(arq2, "%s%s%s%s", &dados.cod, &dados.Titulo, &dados.autor, &dados.ano) != EOF){
		if(strcmp(a->cod, dados.cod) == 0){
			fprintf(arq, "%s\n", a->cod);
			fprintf(arq, "%s\n", a->Titulo);
			fprintf(arq, "%s\n", a->autor);
			fprintf(arq, "%s\n", a->ano);
		}
		else {
			fprintf(arq, "%s\n", dados.cod);
			fprintf(arq, "%s\n", dados.Titulo);
			fprintf(arq, "%s\n", dados.autor);
			fprintf(arq, "%s\n", dados.ano);
		}
	}
	
	fclose(aux);
	fclose(arq2);
	
	remove("acervo.txt");
	rename("ops.txt", "acervo.txt");
}

//Função de Pesquisar
    void pesquisar() {
        int ih;
        char codigokkk[15];
		arq = fopen("acervo.txt", "r");
        if (arq == NULL) {
            printf("Erro. Não foi possível abrir o arquivo");
            menu_principal_livros();
        }
        textura();
        printf("\n");
        printf("\t\t\t\tCONSULTA DE LIVROS\n\n");
        textura_2();
        printf("\n\n");

        printf("Insira o código do livro:");

        fflush(stdin);
        gets(codigokkk);
        fflush(stdin);

        system("cls");
        
        while(fscanf(arq, "%s%s%s%s", &dados.cod, &dados.Titulo, &dados.autor, &dados.ano)){
        	if(strcmp(dados.cod, codigokkk) == 0){
        		textura_2();
        		printf("\n");
				printf("\t\t\t\tCONSULTA DE LIVROS\n\n");
				textura_2();
				 printf("\n");
				printf("\t\t\t\tLIVRO ENCONTRADO:\n\n");
        		printf("\t\t\t\tCódigo do livro: %s\n", dados.cod);
        		printf("\t\t\t\tTítulo: %s\n", dados.Titulo);
        		printf("\t\t\t\tAutor: %s\n", dados.autor);
        		printf("\t\t\t\tAno de publicação: %s\n", dados.ano);
        		printf("\n");
        		break;
			}else{
				textura_2();
        		printf("\n");
				printf("\t\t\t\tCONSULTA DE LIVROS\n\n");
				textura_2();
				 printf("\n");
				
				printf("\t\tLivro não encontrado. \n\n\t\tVocê será direcionado ao Menu Principal\n\n");
				system("pause");
				menu_principal_livros();
			}
			
		}
        fclose(arq);
        system("pause");
        system("cls");
        menu_principal_livros();
    }
//Interface
    void apresentar_linha() {
        setlocale(LC_ALL, "C");
        int k;
        for (k = 0; k < 80; k++) {
            printf("%c", 205);
        }
        setlocale(LC_ALL, "Portuguese");
    }

    void setinha() {
        setlocale(LC_ALL, "C");
        int j;
        for (j = 0; j < 80; j++) {
            printf("%c", 175);
        }
        setlocale(LC_ALL, "Portuguese");
    }

    void textura() {
        setlocale(LC_ALL, "C");
        int a;
        for (a = 0; a < 80; a++) {
            printf("%c", 178);
        }
        setlocale(LC_ALL, "Portuguese");
    }

    void textura_2() {
        setlocale(LC_ALL, "C");
        int b;
        for (b = 0; b < 80; b++) {
            printf("%c", 176);
        }
        setlocale(LC_ALL, "Portuguese");
    }
int main(){
	system("color 3a");
    menu_principal_livros();
    return 0;
}
