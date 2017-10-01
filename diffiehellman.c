#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

/*
FERNANDO COSTA E ANDRE RODRIGUES
TRABALHO 2 - SEGURANCA DA INFORMACAO 2017.2
*/

uint64_t powmod(uint64_t g, uint64_t c, uint64_t p){ //funcao que retorna g^c mod p usando inteiros de 64 bits

    uint64_t res = 1; //inicializa a variavel do resultado
    
    g = g % p; //g se torna o modulo dele mesmo por p
    while (c > 0){
        if (c & 1) //se o bit menos significativo for 1 entao ele sera impar
            res = (res*g) % p;
 
        // y must be even now
        c = c>>1; //usando bitshift retiramos do expoente atual uma potencia de dois tranformando-o em sua metade
        g = (g*g) % p; //fazemos modulo do quadrado do numero
    }
    return res;
}

int main(){

	uint64_t p, g, rand1, rand2, A, B, result1, result2;
	rand1 = 1804289383; //rand();
	rand2 = 846930886; //rand();
	scanf("%"SCNu64,&p);
	scanf("%"SCNu64,&g);
	A = powmod(g, rand1, p);
	B = powmod(g, rand2, p);
	result1 = powmod(A, rand2, p);
	result2 = powmod(B, rand1, p);
	printf("Alice:");
	printf("%\n"SCNu64, A);
	printf("\n");
	printf("Bob:");
	printf("%"SCNu64, B);
	printf("\n");
	printf("Segredo Alice:");
	printf("%"SCNu64, result1);
	printf("\n");
	printf("Segredo Bob:");
	printf("%"SCNu64, result2);
	printf("\n");
	return 0;
}

/*
A = g^a mod p
B = g^b mod p

A^b mod p = B^a mod p
*/