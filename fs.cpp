#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NIVEL_FACIL 20
#define NIVEL_MEDIO 15
#define NIVEL_DIFICIL 6

void jogo(){

        int min = 0;
        int max = 100;
        int numSecreto = min + rand() % (max - min + 1);

        int chute = 0;
        double pontos = 1000.0;
        int i;

        printf("\n***********************************************\n");
        printf("************* JOGO DE ADIVINHA��O *************\n");
        printf("***********************************************\n");

        printf("\nAdivinhe o n�mero secreto!\n\n");

        int nivel, totalDeTentativas, numValido;

        do{
                printf("-----------------------------------------------\n");
                printf("Qual o n�vel de dificuldade?\n");
                printf("(1) F�cil (2) M�dio (3) Dif�cil\n");
                printf("Escolha: ");
                scanf("%d", &nivel);
                
                numValido = nivel > 0 && nivel <=3;

                switch (nivel){
                        case 1:
                                totalDeTentativas = NIVEL_FACIL;
                                break;
        
                        case 2:
                                totalDeTentativas = NIVEL_MEDIO;
                                break;

                        case 3:
                                totalDeTentativas = NIVEL_DIFICIL;
                                break;

                        default:
                                printf("Valor inv�lido\n");
                                break;
                        }

        }while(!numValido);

        printf("-----------------------------------------------\n");
        printf("Voc� tem %d tentativas!\n\n", totalDeTentativas);
        printf("ATEN��O: o n�mero est� entre 1 � 100 ");

        for(i = 1; i <= totalDeTentativas; i++){
                printf("\n-----------------------------------------------\n");
                printf("Qual o seu %d� chute? ", i);
                scanf("%d", &chute);
                printf("Seu %d� chute foi %d\n", i, chute);

                int acerto = chute == numSecreto;
                int menor = chute > numSecreto;

                double pontosPerdidos = abs(chute - numSecreto)/2.0;
                pontos = pontos - pontosPerdidos;


                // resposta inv�lida
                if(chute < 0){
                        printf("Voc� n�o pode chutar n�meros negativos!\n");
                        i--;
                        // impede a mensagem de "menor"
                        continue;
                }

                // pistas
                if(acerto){
                        printf("\nParab�ns! Voc� acertou! (/???)/\n");
                        printf("Voc� fez %.1f pontos\n", pontos);
                        // impede a continua��o do loop
                        break;
                } else if(menor){
                        printf("\nO n�mero secreto � menor ??  :(\n");
                } else{
                        printf("\nO n�mero secreto � maior ??  :(\n");
                }

                // mensagem de encorajamento
                if(i == totalDeTentativas){
                        printf("-----------------------------------------------\n");
                        printf("Voc� perdeu (T_T)\n");
                        printf("O n�mero era %d\n", numSecreto);

                } else if(i == totalDeTentativas - 1){
                        printf("Ultima tentativa!\n");
        
                } else{
                        printf("Tente novamente!\n");
                }

        }

}

int main(){
        system("clear");
        srand(time(0));

        char jogarNovamente;

        do{
                jogo();

                printf("\nDeseja jogar novamente (s/n)? ");
                scanf(" %c", &jogarNovamente);

                switch(jogarNovamente){
                        case 's':
                        case 'S':
                                break;
                        case 'n':
                        case 'N':
                                printf("\nObrigado por jogar!\n");
                                break;
                        default:
                                printf("Valor inv�lido\n");
                                printf("Fechando o jogo...\n");
                                break;
                }

        } while(jogarNovamente == 's' || jogarNovamente == 'S');

    return 0;
}
