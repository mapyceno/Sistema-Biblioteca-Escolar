//Marcelo Vinícios Melo Martins

#include <stdio.h>
#include <stdlib.h>

#define A 100 //define um macro para quantidade de alunos
#define L 50 //define um macro para qunatidade de livros
#define _c 0x87 //ç
#define _o 0xE4 //õ
#define _a 0xC6 //ã
#define o_ 0xA2 //ó
#define i_ 0xA1 //í
#define a_ 0xA0 //á
#define e_ 0x82 //é
#define u_ 0xA3 //ú

int cont_aluno = 0;
int cont_livro = 0;
int cont_exemplar = 0;

//Estrutura Aluno
struct Aluno
{
    int matricula;
    char nome[50];
    char logradouro[100];
    int numero;
    char CEP[10];
    char cidade[50];
    int historico;
};

//Estrutura Exemplares
struct Exemplares
{
    int codigolivro;
    int emprestado; // 1  = não disponivel . 0 = disponivel
    int alunoresponsavel; //Guarda a matrícula do aluno responsavel pelo livro
};

//Estrutura Livro
struct Livro
{
    int codigo;
    char nome[50];
    char editora[50];
    int quant_livro;
    Exemplares listaDeExemplares[10];
};

//Protótipo das Funções
int valida_matricula(struct Aluno *aluno,int mat);
int valida_livro(struct Livro *livro, int cod);
int valida_livro2(struct Livro *livro, int cod);
void exibe_aluno(struct Aluno *aluno, int mat);
void cadastro_aluno(struct Aluno *aluno);
void cadastro_livro(struct Livro *livro);
void exibe_livro(struct Livro *livro, int l1, int l2);
void zerolivro(struct Livro *livro);
void zero(struct Aluno *aluno );
int pesquisal(struct Livro *livro, int mat);
int pesquisae(struct Livro *livro, int mat);
void biblioteca();
void continuar(int opcao);
void emprestimo_livro(struct Aluno *a, struct Livro *l);

//Função Principal
int main(void)
{
    system("color f9");

    //cria uma instância da estrutura Aluno
    Aluno a[A];

    zero(a);

    //cria uma instância da estrutura Livro
    Livro l[L];

    zerolivro(l);

    int opcao;
    int opc;
    int mat;
    int cod;
    int code;
    do
    {
        biblioteca();
        printf("~~~~~Sistema Biblioteca\n");
        printf("\n");
        printf("Menu de op%c%ces:\n",_c,_o);
        printf("\n");
        printf("\t1. Cadastro de Alunos\n");
        printf("\t2. Cadastro de Livros\n");
        printf("\t3. Emprestimo de Livros\n");
        printf("\t4. Devolu%c%co de Livros\n",_c,_a);
        printf("\t5. Consultar Informa%c%ces\n",_c,_o);
        printf("\t0. Sair\n");
        printf("\n");
        printf(" Escolha uma op%c%co: ",_c,_a);
        scanf("%d%*c", &opcao );
        printf ("\n");
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            biblioteca();
            printf("~~~~~~~~~Cadastro Aluno\n");
            printf("\n");
            cadastro_aluno(a);
            break;
        case 2:
            biblioteca();
            printf("~~~~~~~~~Cadastro Livro\n");
            printf("\n");
            cadastro_livro(l);
            break;
        case 3:
            biblioteca();
            emprestimo_livro(a,l);
            break;
        case 4:
            biblioteca();
            printf("~~~~Devolu%c%co de Livros\n",_c,_a);
            printf("\n");
            printf("\tC%cdigo do livro: ",o_);
            scanf("%d*c", &cod);
            if(cod == 0)
                break;
            if(valida_livro(l,cod) == -2)
            {
                printf(" C%cdigo Inv%clido, digite novamente!\n",o_,a_);
                printf(" 0 - Voltar ao Menu Principal\n");
            }
            else
            {
                if (l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].emprestado == 1)
                {
                    printf("Confirma a devolu%c%co!!\n",_c,_a);
                    printf(" 1. Para Sim.\n 2. Para N%co\n",_a);
                    printf(" %c ",0x10);
                    scanf("%d*c", &opc);
                    if (opc == 1)
                    {
                        l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].emprestado = 0;
                        l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].alunoresponsavel = 0;
                    }
                    else
                        break;
                }
                else
                {
                    printf("Inconscistencia de dados!\n");
                    scanf("%*c");
                }
            }
            break;
        case 5:
            do
            {
                biblioteca();
                printf("~~Consultar Informa%c%ces\n",_c,_o);
                printf("\n");
                printf("Menu de op%c%ces:\n",_c,_o);
                printf("\n");
                printf("\t1. Exemplares locados por um aluno\n");
                printf("\t2. Informa%c%ces de um exemplar\n",_c,_o);
                printf("\t3. Total de exemplares dispon%cveis por livro\n",i_);
                printf("\t4. Quantos empr%cstimos cada um dos alunos realizou\n",e_);
                printf("\t0. Voltar ao menu Principal\n");
                printf("\n");
                printf(" Escolha uma op%c%co: ",_c,_a);
                scanf("%d%*c", &opc );
                printf ("\n");
                switch(opc)
                {
                case 0:
                    break;
                case 1:
                    printf("--------------------------------\n");
                    printf(" Exemplares locados por um aluno\n");
                    printf("--------------------------------\n");
                    printf("\n");
                    printf("Matr%ccula do Aluno: ",i_);
                    scanf("%d%*c", &mat);
                    if(valida_matricula(a,mat) == -1)
                    {
                        printf("\n\n");
                        printf(" Matr%ccula Inv%clida",i_,a_);
                        printf("\n\n");
                    }
                    else
                    {
                        exibe_aluno(a,valida_matricula(a,mat));
                        if(l[pesquisal(l,mat)].listaDeExemplares[pesquisae(l,mat)].codigolivro == 0 )
                            printf("\n\n No momento n%co existe nenhum exemplar vinculado ao aluno!\n\n",_a);
                        else
                            exibe_livro(l,pesquisal(l,mat),pesquisae(l,mat));
                    }
                    continuar(opc);
                    break;
                case 2:
                    printf("------------------------------\n");
                    printf(" Informa%c%ces de um exemplar\n",_c,_o);
                    printf("------------------------------\n");
                    printf("\n");
                    printf("C%cdigo do Livro: ",o_);
                    scanf("%d%*c", &cod);
                    if(valida_livro(l,cod) == -2)
                    {
                        printf("\n\n C%cdigo do livro Inv%clido!\n\n",o_,a_);
                    }
                    else
                    {
                        printf("\n\n");
                        exibe_livro(l,valida_livro(l,cod),valida_livro(l,cod));
                        if(l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].alunoresponsavel == 0)
                            printf("\n\n No momento esse exemplar encontra-se disponivel!\n\n",_a);
                        else
                        {
                            int aux2 = l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].alunoresponsavel;
                            exibe_aluno(a,valida_matricula(a,aux2));
                        }
                    }
                    continuar(opc);
                    break;
                case 3:
                    printf("-------------------------------------------\n");
                    printf(" Total de exemplares dispon%cveis por livro\n",i_);
                    printf("-------------------------------------------\n");
                    printf("\n");
                    for (int i = 0; i < L; i++)
                    {
                        int temp = 0;
                        int empre = 0;
                        for (int j = 0; j < 10; j++)
                        {
                            if (l[i].listaDeExemplares[j].codigolivro != 0)
                            {
                                temp++;
                            }
                            if (l[i].listaDeExemplares[j].emprestado == 1)
                            {
                                empre++;
                            }
                        }
                        if (l[i].codigo != 0)
                        {
                            printf(" %s, %s, Quant. Exemplares %d, disponiveis %d.",l[i].nome,l[i].editora,temp,temp-empre);
                            printf("\n");
                        }
                    }
                    continuar(opc);
                    break;
                case 4:
                    printf("---------------------------------\n");
                    printf("Exemplares locados por cada aluno\n");
                    printf("---------------------------------\n");
                    printf("\n");

                    if (cont_aluno == 0)
                        printf("\n\nN%co h%c alunos cadastrados!\n\n",_a,a_);
                    else
                    {
                        for (int i = 0; i < A; i++)
                        {
                            if (a[i].matricula != 0)
                            {
                                printf(" %s, realizou %d empr%ctimos.",a[i].nome,a[i].historico,e_);
                                printf("\n");
                            }
                        }
                    }
                    continuar(opc);
                    break;
                default:
                    printf("Op%c%co inv%clida!\n",_c,_a,a_);
                }
            }
            while (opc != 0);
            break;
        default:
            printf("Op%c%co inv%clida!\n",_c,_a,a_);
        }
        continuar(opcao);
    }
    while (opcao != 0);
    printf("\nObrigado pela visita e bons estudos!\n\n");
    system("PAUSE");
    return 0;
}

//Função que verifica se a matricula é válida
int valida_matricula(struct Aluno *aluno,int mat)
{
    int num;
    for (int i = 0; i < A; i++)
    {
        if (aluno[i].matricula == mat)
            return(i);
        else
            num = -1;
    }
    return (num);
}

//Função que verifica se o código do livro é válido
int valida_livro(struct Livro *livro, int cod)
{
    int num = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < 10; j++)
        {
            if (livro[i].listaDeExemplares[j].codigolivro == cod)
                return(i);
            else
                num = -2;
        }
    return (num);
}

//Função que verifica se o código do exemplar é válido
int valida_livro2(struct Livro *livro, int cod)
{
    int num = 0;
    for (int i = 0; i < L; i++)
        for (int j = 0; j < 10; j++)
        {
            if (livro[i].listaDeExemplares[j].codigolivro == cod)
                return (j);
            else
                num = -2;
        }
    return (num);
}

//Função que exibe Alunos cadastrados
void exibe_aluno(struct Aluno *aluno, int mat)
{
    printf("\nDados Alunos:\n\n");
    printf("\tMatr%ccula: %d",i_,aluno[mat].matricula);
    printf("\n");
    printf("\tNome: %s",aluno[mat].nome);
    printf("\n");
    printf("   Endere%co: ",_c);
    printf("\n");
    printf("\tLogradouro: %s",aluno[mat].logradouro);
    printf("\n");
    printf("\tN%cmero: %d",u_,aluno[mat].numero);
    printf("\n");
    printf("\tCEP: %s",aluno[mat].CEP);
    printf("\n");
    printf("\tCidade: %s",aluno[mat].cidade);
    printf("\n\n");
}

//Função que cadastra aluno
void cadastro_aluno(struct Aluno *aluno)
{
    if (cont_aluno < A)
    {
        printf("\tMatr%ccula: ",i_);
        scanf("%d%*c", &aluno[cont_aluno].matricula);
        printf("\tNome do aluno: ");
        scanf(" %49[^\n]",aluno[cont_aluno].nome); //lê no máximo 49 caracteres
        getchar();
        printf(" Endere%co do Aluno: \n",_c);
        printf("\tLogradouro: ");
        scanf(" %99[^\n]", aluno[cont_aluno].logradouro);//lê no máximo 99 caracteres
        getchar();
        printf("\tN%cmero: ",u_);
        scanf("%d%*c", &aluno[cont_aluno].numero);
        printf("\tCEP: ");
        scanf(" %9[^\n]", aluno[cont_aluno].CEP);
        getchar();
        printf("\tCidade: ");
        scanf(" %49[^\n]", aluno[cont_aluno].cidade);
        getchar();
        cont_aluno++;
        printf("\n\nCadastrado com Sucesso!\n\n");
    }
    else
    {
        printf("Biblioteca Cheia!\n\n");
    }
}

//Função que cadastra livro
void cadastro_livro(struct Livro *livro)
{
    if (cont_livro < L)
    {
        printf("\tQuantidade de Exemplares: ");
        scanf(" %d%*c", &cont_exemplar);
        if(cont_exemplar <= 10)
        {
            printf("\tC%cdigo do livro: ",o_);
            scanf(" %d%*c", &livro[cont_livro].codigo);
            printf("\tNome do livro: ");
            scanf(" %49[^\n]", livro[cont_livro].nome);
            getchar();
            printf("\tNome da Editora: ");
            scanf(" %49[^\n]", livro[cont_livro].editora);
            getchar();
            for (int i = 0; i < cont_exemplar; i++)
            {
                livro[cont_livro].listaDeExemplares[i].codigolivro = i+1;
            }
            cont_livro++;
            printf("\n\nLivro cadastrado com Sucesso!\n\n");
        }
        else
            printf("\n\nPode cadastrar no Maximo 10 exemplares!\n");
    }
    else
    {
        printf("\n\nForam cadastrados os 50 exemplares!\n\n");
    }
}

//Função que realiza o empréstimo
void emprestimo_livro(struct Aluno *a, struct Livro *l)
{
    int mat;
    int cod;
    printf("~~~Empr%cstimo de Livros\n",e_);
    printf("\n");
    do
    {
        printf("\tMatr%ccula: ",i_);
        scanf("%d%*c", &mat);
        if(mat == 0)
            break;
        if(valida_matricula(a,mat) == -1)
        {
            printf(" Matr%ccula Inv%clida, digite novamente!\n",i_,a_);
            printf(" 0 - Voltar ao Menu Principal\n");
        }
        else
        {
            exibe_aluno(a,valida_matricula(a,mat));
            a[valida_matricula(a,mat)].historico++;
            do
            {
                printf("C%cdigo do livro: ",o_);
                scanf("%d*c", &cod);
                if(cod == 0)
                    break;
                if(valida_livro(l,cod) == -2)
                {
                    printf(" C%cdigo Inv%clido, digite novamente!\n",o_,a_);
                    printf(" 0 - Voltar ao Menu Principal\n");
                }
                else
                {
                    if (l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].emprestado == 0)
                    {
                        l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].emprestado = 1;
                        l[valida_livro(l,cod)].listaDeExemplares[valida_livro2(l,cod)].alunoresponsavel = mat;
                        printf("\n");
                        printf("Foi Registrado o empr%cstimo: Exemplar %d vinculado ao Aluno %d.",e_,cod,mat);
                        printf("\n\n");
                        scanf("%*c");
                    }
                    else
                    {
                        printf("\n");
                        printf("O exemplar encontra-se empr%cstado!\n",e_);
                        scanf("%*c");
                    }
                }
            }
            while (valida_livro(l,cod) < 0);
        }
    }
    while (valida_matricula(a,mat) < 0);
}

//Função que exibe livro
void exibe_livro(struct Livro *livro, int l1, int l2)
{
    printf("\tC%cdigo do livro: %d\n",o_,livro[l1].listaDeExemplares[l2].codigolivro);
    printf("\tNome do livro: %s\n",livro[l1].nome);
    printf("\tNome da Editora: %s\n",livro[l1].editora);
}

//Função que inicializa a matrícula do aluno com zero
void zero(struct Aluno *aluno )
{
    for (int i = 0; i < A; i++)
    {
        aluno[i].matricula = 0;
    }
}

//Função que inicializa o código do livro com zero
void zerolivro(struct Livro *livro)
{
    for (int i = 0; i < L; i++)
        for (int j = 0; j < 10; j++)
        {
            livro[i].listaDeExemplares[j].emprestado = 0;
            livro[i].listaDeExemplares[j].codigolivro = 0;
            livro[i].codigo = 0;
        }
}

//Função que pesquisa se existe o livro
int pesquisal(struct Livro *livro, int mat)
{
    for (int i = 0; i < L; i++)
        for (int j = 0; j < 10; j++)
        {
            if (livro[i].listaDeExemplares[j].alunoresponsavel == mat)
                return i;
        }
}

//Função que pesquisa se existe o exemplar
int pesquisae(struct Livro *livro, int mat)
{
    for (int i = 0; i < L; i++)
        for (int j = 0; j < 10; j++)
        {
            if (livro[i].listaDeExemplares[j].alunoresponsavel == mat)
                return j;
        }
}

//Função exibe BIBLIOTECA
void biblioteca()
{
    system("cls");
    printf("______ _ _      _  _       _\n");
    printf("| ___ (_) |    | |(_)     | |\n");
    printf("| |_/ /_  |__  | | _  ___ | |_  ___   ___   ___\n");
    printf("| ___ \\ | '_ \\ | || |/ _ \\| __|/ _ \\ / __\\/ _  |\n");
    printf("| |_/ / | |_| || || | (_) | |_|  __/| (__ .(_| |\n");
    printf("\\____/|_|\\____/|_||_|\\___/ \\__|\\___| \\___/\\__,_|\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~");
}

void continuar(int opcao)
{
    printf ("\n");
    if (opcao != 0)
    {
        printf("Tecle ENTER para continuar ");
        scanf("%*c");
        printf("\n");
    }
    system("cls");
}
