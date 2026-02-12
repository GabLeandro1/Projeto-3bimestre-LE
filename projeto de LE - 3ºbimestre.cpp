#include <stdio.h>
#include <string.h>
#include <locale.h>

int Pontosturno[2][4];
int Totalpontos[4];
float Y, Error;
char Nomestime[4][50];
int Cont, Testes;

int main() {
    setlocale(LC_ALL, "Portuguese");

    for (Cont = 0; Cont < 4; Cont++) {
        printf("Digite o nome do %dº time\n", Cont + 1);
        gets(Nomestime[Cont]);
    }
    
printf("\n");
printf("===========================================================\n\n");

    for (Cont=0; Cont<=3; Cont++){
    	printf ("Digite a quantidade de pontos do time %s no 1° turno\n", Nomestime[Cont]);	
         Error = scanf ("%d", &Pontosturno[0][Cont]);
		while ((Pontosturno[0][Cont] < 0) || (Error == 0)){
        	fflush(stdin);
			printf ("Está errado!! Digite novamente a quantidade de pontos do time no 1° turno!\n");
        	Error = scanf ("%d", &Pontosturno[0][Cont]);
		}
	}

	printf ("\n");
    printf ("===========================================================\n\n");
    
    for (Cont=0; Cont<=3; Cont++){
    	printf ("Digite a quantidade de pontos do time %s no 2° turno\n", Nomestime[Cont]);	
         Error = scanf ("%d", &Pontosturno[1][Cont]);  
		while ((Pontosturno[1][Cont] < 0) || (Error == 0)) {
        	fflush(stdin);
			printf ("Está errado!! Digite novamente a quantidade de pontos do time no 1° turno!\n");
        	Error = scanf ("%d", &Pontosturno[1][Cont]);
		}
	}

	for (Cont=0; Cont<=3; Cont++){
		Totalpontos[Cont] = Pontosturno[0][Cont]+Pontosturno[1][Cont];
	}
	printf ("\n");
    printf ("===========================================================\n\n");
    
    for (Cont=0; Cont<=3; Cont++){
    	printf ("O total de pontos do time %s é: %d\n", Nomestime[Cont], Totalpontos[Cont]);
    	printf ("A pontuação do time no 1° turno foi de: %d\n", Pontosturno[0][Cont]);
    	printf ("A pontuação do time no 2° turno foi de: %d\n", Pontosturno[1][Cont]);
    	printf ("\n");
        printf ("===========================================================\n\n");
}

    for (Testes = 4; Testes > 1; Testes--) {
        for (Cont = 0; Cont < Testes - 1; Cont++) {
            if (Totalpontos[Cont] < Totalpontos[Cont + 1]) {
                Y = Totalpontos[Cont];
                Totalpontos[Cont] = Totalpontos[Cont + 1];
                Totalpontos[Cont + 1] = Y;
                
                char tempNome[50];
                strcpy(tempNome, Nomestime[Cont]);
                strcpy(Nomestime[Cont], Nomestime[Cont + 1]);
                strcpy(Nomestime[Cont + 1], tempNome);
            }
        }
    }

    printf("O time campeão é: %s\n", Nomestime[0]);
    printf("O time vice-campeão é: %s\n", Nomestime[1]);
    printf("O pior time é: %s\n", Nomestime[3]);
    printf ("\n");
    printf("===========================================================\n\n");
}

