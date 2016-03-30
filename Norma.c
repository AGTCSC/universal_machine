#include <stdio.h>

/*
	SIMULADOR DA MAQUINA DE NORMA
	As funções basicas da maquina de norma são:
		- SOMA 1
		- SUBTRAI 1
		- COMPARA COM 0
		- !
		- A = 0
		- A = A + X
	Ela possui apenas números naturais, ou seja, não temos números negativos.
Para representa-los utilizaremos uma flag "sin" que aponta se esse é ou não negativo.
*/
#define ETZ(a) a == 0 											//equals to zero
#define NOT(a) ((a == 0)? 1:0) 									//nega o valor do numero
#define print(a) (printf("%d\n", (a.sin == 1)? a.num*-1:a.num)) 	//mostra o numero com ou sem o sinal de negativo

typedef unsigned char bool;										//como C não possui o tipo boolean criamos esse atalho onde 0 = FALSO e 1 = VERDADEIRO

typedef struct coto{ 											//coto é uma estrutura que simula um numero inteiro na maquina
	bool sin;													//e em outra o sinal sinal que quando zero é positivo e quando não negativo
	unsigned int num;											//numerador
	unsigned int den;											//denominador
}coto;

int AND(int a, int  b)
{
	if(NOT(ETZ(a)))
		if(NOT(ETZ(b)))
			return 1;
	return 0;
}
int  OR(int a, int b)
{
	if(ETZ(a))
		if(ETZ(b))
			return 0;
	return 1;
}

int XOR(int a, int b)
{
	if(ETZ(a))
		if(ETZ(b))
			return 0;
		else
			return 1;
	else
		if(ETZ(b))
			return 1;
		else
			return 0;
}
//-----------------------	OPERAÇÕES COM VARIAVEIS ------------------------
void X_0(unsigned int* x)
{
	while(NOT(ETZ(*x)))
	{
		(*x)--;
//		printf("%u\n", *x);
	}
}
void  X_ADD_Y(int* x, int y)
{
	while(NOT(ETZ(y)))
	{
		(*x)++;
		y--;
	}
}
int  X_ADD_Y_USING_Z(int x, int y)
{
	int z = 0; //como não sei qual é o valor do registrador não zerei utilizando X_0
	while(NOT(ETZ(y)))
	{
		x++;
		y--;
		z++;
	}
	X_ADD_Y(&y, z);
	
	return x;
}
int X_SUB_Y(int x, int y)
{
	while(NOT(ETZ(y)))
	{
		x--;
		y--;
	}
	return x;
}
void X_Y(int* x, int y)
{
	while(NOT(ETZ(y)))
	{
		(*x)++;
		y--;
	}
}
bool X_IGUAL_Y(int x, int y)									//compara dois valores naturais
{
	while(NOT(ETZ(x)))											//enquanto meu x não for zero
	{
		x--;													//decremento x
		y--;												 	//e y
	}
	return ETZ(y);												//caso y seja 0 este é igual a x, pois os dois zeraram 	"ao mesmo tempo"
}
int X_MULT_Y(int x, int y)
{
	int soma=0;
	while(NOT(ETZ(x)))
	{
		x--;
		X_ADD_Y(&soma, y);
	}
	return soma;
}
//--------------------------	OPERAÇÕES COM REGISTRADORES ----------------------------
void ADD(coto* a)
{
	if(ETZ((*a).sin))											//Se o numero é positivo simplesmente somamos
		(*a).num++;
	else														//Se negativo
	{
		if(NOT((*a).num))										//E o valor for -1
		{
			(*a).num--;											//subo para 0
			(*a).sin--;											//e mudo sinal para positivo
		}
		else
			(*a).num--;											//senão apenas diminuimos o valor negativo
	}

}
void  SUB(coto* a)
{
	if(ETZ((*a).sin))											//Se o numero é positivo
	{	if(ETZ((*a).num))										//E igual a zero
		{
			(*a).sin++;											//Mudo o sinal para negativo
			(*a).num++;											//E incremento num representando -1.
		}
		else													//Senão simplesmente decremento
			(*a).num--;
	}
	else
		(*a).num++;												//Ou incremento, já que ele é negativo
}
void A_0(coto* a)
{
	X_0(&(*a).num);

	if(NOT(ETZ((*a).sin)))
		(*a).sin--;

	X_0(&(*a).den);
	(*a).den++;
}
void A_B(coto*a, coto* b)
{
	coto c = {0,0,1};
	A_0(a);

	if(ETZ(((*b).sin)))
		while(NOT(ETZ(((*b).num))))
		{
			SUB(b);
			ADD(a);
			ADD(&c);
		}
	else
		while(NOT(ETZ(((*b).num))))
		{
			ADD(b);
			SUB(a);
			SUB(&c);
		}
}

void A_B_using_C(coto* a, coto* b)
{
	coto c = {0,0,1};
	A_0(a);

	if(ETZ(((*b).sin)))
		while(NOT(ETZ(((*b).num))))
		{
			SUB(b);
			ADD(a);
			ADD(&c);
		}
	else
		while(NOT(ETZ(((*b).num))))
		{
			ADD(b);
			SUB(a);
			SUB(&c);
		}
	A_B(b, &c);
}
void A_SUB_X(coto* a, int x)
{
	while(NOT(ETZ(x)))
	{
		x--;
		SUB(a);
	}
}
void A_ADD_X(coto* a, int x)
{
	while(NOT(x))
	{
		x--;
		ADD(a);
	}
}
void A_ADD_B_using_C(coto* a, coto* b)
{
	coto c = {0,0,1};
	if(ETZ(((*b).sin)))
		while(NOT(ETZ(((*b).num))))
		{
			SUB(b);
			ADD(a);
			ADD(&c);
		}
	else
		while(NOT(ETZ(((*b).num))))
		{
			ADD(b);
			SUB(a);
			SUB(&c);
		}
	A_B(b, &c);
}
void A_SUB_B_using_C(coto* a, coto* b)
{
	coto c = {0,0,1};
	if(ETZ(((*b).sin)))
		while(NOT(ETZ(((*b).num))))
		{
			SUB(b);
			SUB(a);
			ADD(&c);
		}
	else
		while(NOT(ETZ(((*b).num))))
		{
			ADD(b);
			SUB(a);
			SUB(&c);
		}
	A_B(b, &c);
}

void A_MULT_B_using_C(coto* a, coto* b)
{
	coto c = {0, 0, 1};
	A_B(&c, a);

	if(ETZ(((c.sin))))
		while(NOT(ETZ((c.num))))
		{
			A_ADD_B_using_C(a, b);
			SUB(&c);
		}
	else
		while(NOT(ETZ(((c).num))))
		{
			A_SUB_B_using_C(a,b);
			ADD(&c);
		}
}
///////////////////	OPERAÇÃO COM NUMEROS RACIONAIS	///////////////////////////////
coto MULTR(coto a, coto b)
{
	coto c = {0, 0, 0};
	X_Y(&(c.num), X_MULT_Y(a.num, b.num));
	X_Y(&(c.den), X_MULT_Y(a.den, b.den));
	
	if(XOR(a.sin, b.sin))
		c.sin = 1;
	return c;
}
coto ADDR(coto a, coto b) //C :=  A + B using C e D
{
	coto c = {0, X_ADD_Y_USING_Z(X_MULT_Y(a.num, b.den), X_MULT_Y(a.den, b.num)), X_MULT_Y(a.den, b.den)};	
	print (c);	
}

coto SUBR(coto a, coto b) //C :=  A + B using C e D
{
	coto c = {0, X_SUB_Y(X_MULT_Y(a.den, b.num),X_MULT_Y(a.num, b.den)), X_MULT_Y(a.den, b.den)};	
	print (c);	
}

coto DIVR(coto a, coto b) //C :=  A + B using C e D
{
	coto c = {0, X_MULT_Y(a.num, b.den), X_MULT_Y(a.den, b.num)};	
	print (c);	
}

int A_IGUAL_B_R(coto a, coto b)
{
	return X_IGUAL_Y(X_MULT_Y(a.num, b.den), X_MULT_Y(a.den, b.num));
}
int main()
{
	coto a = {0, 6, 4};
	coto b = {0, 3, 2};
	//coto c = ADDR(a, b);
	printf("%d\n", A_IGUAL_B_R(a, b));
	//print(c);
}
