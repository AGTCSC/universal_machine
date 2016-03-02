#include <stdio.h>

/*
	SIMULADOR DA MAQUINA DE NORMA

	As funções basicas da maquina de norma são:
		- SOMA 1
		- SUBTRAI 1
		- COMPARA COM 0
	Ela possui apenas números naturais, ou seja, não temos números negativos.
Para representa-los utilizaremos uma flag "sin" que aponta se esse é ou não negativo.
*/
#define ETZ(a) a == 0 //equals to zero
#define print(num , sin) printf("%d", (sin == 1)? num*-1:num) //mostra o numero com ou sem o sinal de negativo

typedef struct coto{ //coto é uma estrutura que simula um numero inteiro na maquina
	bool sin;		//e em outra o sinal sinal que quando zero é positivo e quando não negativo
	unsigned int  num;//onde em uma variavel temos o número
}coto;

void ADD(coto* a)
{	
	if((*a).sin == 0)	//Se o numero é positivo simplesmente somamos
		(*a).num++;
	else				//Se negativo
	{
		if((*a).num == 1)	//E o valor for -1
		{
			(*a).num = 0;	//subo para 0
			(*a).sin = 0;	//e mudo sinal para positivo 
		}
		else
			(*a).num--;		//senão apenas diminuimos o valor negativo
	}

}

void  SUB(coto* a)
{
	if((*a).sin == 0)		//Se o numero é positivo
	{	if((*a).num == 0)	//E igual a zero
		{
			(*a).sin = 1;	//Mudo o sinal para negativo
			(*a).num++;		//E incremento num representando -1.
		}
		else				//Senão simplesmente decremento
			(*a).num--;
	}
	else
		(*a).num++;			//Ou incremento, deacordo com o sinal
}




int main()
{
	coto a = {1, 3};

	ADD(&a);
	print(a.num, a.sin);
	ADD(&a);
	print(a.num, a.sin);
	SUB(&a);
	print(a.num, a.sin);
	SUB(&a);
	print(a.num, a.sin);
}
