#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#endif

void setColorRed(){	
#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
#endif	
}

void setColorGreen(){
#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);	
#endif
}

void resetColor(){
#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#endif
}


int main(){

	int opcao, numeroSecreto;
	int tentativas = 3;
	int tentativaAtual = 0;
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("### Jogo de adivinhação ###\n\n");
	
	printf("Adivinhe qual número a máquina está pensando e ganhe um prêmio!\n");
	
	srand(time(NULL));
	
	numeroSecreto = rand() % 10+1;
	
	while(tentativaAtual < tentativas){
		
		printf("\n->Tentativa %d de %d\n", tentativaAtual +1, tentativas);
		printf("\nDigite um número de 1 a 10: ");
		scanf("%d", &opcao);
	
			if (opcao == numeroSecreto){
	#ifdef _WIN32
		setColorGreen();
	#endif
        	printf("\n### Parabéns! Você adivinhou o número secreto! ###\n\n");
    #ifdef _WIN32
    	resetColor();
    #endif
        	break; 
        	system("pause");
        	
    } 
	
	else{
        setColorRed();
            printf("\nVocê errou. Tente novamente!\n\n");
            resetColor();
            tentativaAtual++;
    }
    
    if (tentativaAtual == tentativas){
    	printf("\n### Suas tentativas acabaram. O número secreto era %d. ###\n\n", numeroSecreto);
    	
    	system("pause");
	}
    
    
	}
		
	return 0;
}
