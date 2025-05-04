#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalho.h"

int main(){

    NoTrens *lista;
    crialistaTrem(&lista);
    printf(" \tBem vindo ao Train's!\n");
    printf("Escolha uma das opções abaixo para continuar: \n 1 - Listar trens disponíveis na plataforma \n 2 - Adicionar trem na plataforma \n 3 - Adicionar vagão em um trem \n 4 - Remover trem da plataforma \n 5 - Remover vagão de um trem \n 6 - Trocar vagões entre trens\n 7 - Sair \n");
    int escolha;
    char c;
    int qtdCarga;
    char nomeTrem[100];
    char nomeVagao[100];
    char nomeTrem2[100];
    char nomeVagao2[100];

    scanf("%d", &escolha);
    
    while (escolha != 7)
    {
        
    
     
        
        
        switch (escolha)
        {
        case 1 :
            printaLista(&lista);
            
            break;
        
        case 2 :
            printf("Digite o nome do trem a ser adicionado:\n");
            scanf("%s", nomeTrem);

            printf("Deseja adicionar em ordem alfabética: \n Digite 's' ou 'n' para sim ou não, respectivamente!\n");
            fflush(stdin);
            scanf("%c", &c);
            if (c == 's')
            {
            adicionarTremOrdenado(&lista, nomeTrem);
            } else if(c == 'n'){
            printf("Deseja adicionar no inicio ou final da lista \n 'f' - Final \n 'i' - inicio \n ");
            fflush(stdin);
            scanf("%c", &c);
            if (c == 'i')
            {
                adicionaTrem(&lista, nomeTrem);
            } else if (c == 'f')
            {
                adicionaTremFinal(&lista, nomeTrem);
            }
            break;
            } 



         break;
        case 3: 
        printf("Digite o nome do trem que receberá o vagão:\n");
        scanf("%s", nomeTrem);
        printf("Digite o tipo de carga do vagão a ser adicionado:\n");
            scanf("%s", nomeVagao);
            printf("Digite a quantidade da carga:\n");
            scanf("%d", &qtdCarga);

        printf("Deseja adicionar em ordem alfabética: \n Digite 's' ou 'n' para sim ou não, respectivamente!\n");
        fflush(stdin);
        scanf("%c", &c);
        if (c == 's')
        {
            adicionarVagaoOrdenado(&lista, nomeTrem, nomeVagao, qtdCarga);
        } else if(c == 'n'){
            printf("Deseja adicionar no inicio ou final da lista \n 'f' - Final \n 'i' - inicio\n");
            fflush(stdin);
            scanf("%c", &c);
            if (c == 'i')
            {
                adicionaVagaoInicio(&lista, nomeTrem, nomeVagao, qtdCarga);
            } else if (c == 'f')
            {
                adicionarVagaoFinal(&lista, nomeTrem, nomeVagao, qtdCarga);
            }
        } 
         break;

        case 4: 
            printf("Digite o nome do trem a ser retirado da plataforma:\n");
            scanf("%s", nomeTrem);
            removerTrem(&lista, nomeTrem);

            break;

        case 5: 
            printf("Digite o nome do trem cujo vagão será retirado: \n");
            scanf("%s", nomeTrem);
            printf("Digite o tipo de carga a ser retirado: \n");
            scanf("%s", nomeVagao);

            removerVagao(&lista, nomeTrem, nomeVagao);
            break;

        case 6: 
            printf("Digite o nome do primeiro trem cujo vagão será trocado: \n");
            scanf("%s", nomeTrem);
            fflush(stdin);
            printf("Digite o tipo de carga a ser trocado: \n");
            scanf("%s", nomeVagao);

            fflush(stdin);
            printf("Digite o nome do primeiro trem cujo vagão será trocado: \n");
            scanf("%s", nomeTrem2);
            printf("Digite o tipo de carga a ser trocado: \n");
            scanf("%s", nomeVagao2);

            TrocarVagoesEntreTrens(&lista, nomeTrem, nomeTrem2, nomeVagao, nomeVagao2 );
            break;

        default:
            break;
        }

        printf("\nEscolha outra opcao abaixo para continuar: \n 1 - Listar trens disponíveis na plataforma \n 2 - Adicionar trem na plataforma \n 3 - Adicionar vagão em um trem \n 4 - Remover trem da plataforma \n 5 - Remover vagão de um trem \n 6 - Trocar vagões entre trens\n 7 - Sair \n");

        scanf("%d", &escolha);
    }
    
        

    printf("Muito Obrigado por usar o Train's");
    





}