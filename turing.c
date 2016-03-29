#include <stdio.h>
/*
5
Q0 # # D a0
Q0 a  a D a0
…
Q0 \0 \0 E a1
*/

typedef struct turing
{
	int i ,f;
	char a, b, dir;
};

void gerarArq()
{
	FILE* arq = fopen("exemplo1.txt", "wt");
	if (arq == NULL) // Se não conseguiu criar
	{
	   printf("Problemas na CRIACAO do arquivo\n");
	   return;
	}
	if(fputs("0 @ @ d 0\n0 a A d 1\n0 B B d 3\n0 _ _ d 4\n1 a a d 1\n1 B B d 1\n2 a a e 2\n2 B B e 2\n2 A A d 0\n3 B B d 3\n3 _ _ e 4\n4 * * * *", arq)== EOF)
	{
		printf("ERRO NA CRIACAO\n");
		return;
	}
	fclose(arq);
	
	arq = fopen("exemplo2.txt", "wt");
	if (arq == NULL) // Se não conseguiu criar
	{
	   printf("Problemas na CRIACAO do arquivo\n");
	   return;
	}
	if(fputs(	"0 @ @ d 0\n0 a a d 0\n0 b b d 0\n0 # # d 0\n"
				"0 _ _ e 1\n1 # _ e 4\n1 b _ e 3\n1 a _ e 2\n"
				"2 a a e 2\n2 b a e 3\n2 # a e 4\n3 b b e 3\n"
				"3 a b e 2\n3 # b e 4\n4 * * * *", arq)== EOF)
	{
		printf("ERRO NA CRIACAO\n");
		return;
	}
	fclose(arq);
	
	arq = fopen("exemplo3.txt", "wt");
	if (arq == NULL) // Se não conseguiu criar
	{
	   printf("Problemas na CRIACAO do arquivo\n");
	   return;
	}
	if(fputs(	"0 @ @ d 0\n0 B B d 0\n0 1 A d 1\n0 _ _ e 3\n1 1 1 d 1\n1 B B d 1\n"
				"1 _ B e 2\n2 1 1 e 2\n2 B B e 2\n2 A A d 0\n3 @ @ d 13\n3 B _ e 4\n"
				"4 B B e 4\n\n4 A A d 5\n5 B C e 6\n5 _ _ e 12\n6 A 1 e 6\n6 C C e 6\n"
				"6 @ @ d 7\n7 1 A d 8\n8 1 A d 9\n8 C C d 11\n9 C C d 9\n9 B B d 9\n"
				"9 1 1 d 9\n9 _ 1 e 10\n10 C C e 10\n10 B B e 10\n10 1 1 e 10\n10 A A d 8\n"
				"11 C C d 11\n11 1 1 e 12\n12 A 1 e 12\n12 C 1 e 12\n12 @ @ d 13\n13 * * * *", arq)== EOF)
	{
		printf("ERRO NA CRIACAO\n");
		return;
	}
	fclose(arq);	
}
struct* turing maquina(int maq)
{
	FILE* arq;
	switch(maq)
	{
		case 1:
			arq = fopen("exemplo1.txt", "rt");
		break;
		
		case 2:
			arq = fopen("exemplo2.txt", "rt");
		break;
		case 3:
			arq = fopen("exemplo3.txt", "rt");
		break;
	}
	
	fclose(arq);
	return arq;
}
void executa(int maq, char* entrada, int pos)
{
	char linha[15];
	int qnt;
	struct* turing t;
	FILE* arq;
	arq = maquina(maq);
	fscanf(arq, "%d", qnt);
	turing = (turing*) malloc (sizeof(turing)*qnt);
	
	while(feof(arq))
	{
		sscanf(arq, "%d %c %c %c %d", t.i, t.a, t.b, t.dir, )
	}
	linha = fgets(arq);
	while()
}
int main()
{
	FILE* arq;
	char in[100];
	gerarArq();
	int maq, pos=0;
	
	do
	{
		printf("Qual maquina deseja simular? ");
		scanf("%d", &maq);
		arq = maquina(maq);
		
		printf("Informe a entrada[Limite de 20 caracteres]: ");
		scanf("%s", in);
		
		printf("\n\nDeseja entrar com outra maquina [SIM - 1] [NAO - 0]\n");
		scanf("%d", &maq);
		
	}while(maq == 1);
}
