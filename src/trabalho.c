#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalho.h"

void crialistaTrem(NoTrens **listaTrens){
    *listaTrens = NULL;

}


NoTrens *criaTrem(char *nome){
    NoTrens *novo = (NoTrens *) malloc(sizeof(NoTrens));
    strcpy(novo->train, nome);
    novo->prox = NULL;
    novo->vagoes = NULL;
    return novo;

}

void adicionaTrem(NoTrens **listaTrens, char *nome){
    NoTrens *novo = criaTrem(nome);
    if(novo != NULL){
        novo->prox = *listaTrens;
        *listaTrens = novo;
    }



}

NoVagoes *criaVagao( char *tipo, int qtd){
    NoVagoes *novo = (NoVagoes *) malloc(sizeof(NoVagoes));
    strcpy(novo->tipoCarga, tipo);
    novo->maxQtd = qtd;
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}



int adicionaVagao(NoTrens **listaTrens, char *nome, char *tipoCarga, int qtd){
    NoTrens *aux = *listaTrens;
    while(aux != NULL && (strcmp(aux->train, nome) != 0)){
        aux = aux->prox;
    }
    if(aux == NULL){
        return 0;
    }else {
        NoVagoes *novo = criaVagao(tipoCarga, qtd);
        novo->prox = aux->vagoes;
        aux->vagoes = novo;
    }

}




void removerTrem(NoTrens **listaTrens, char *nome){
    NoTrens *aux = *listaTrens;
    NoTrens *ant = NULL;
    while (aux != NULL && (strcmp(aux->train, nome) != 0))
    {
        ant = aux;
       aux = aux->prox;
    }


    if (aux == *listaTrens)
    {
        *listaTrens = (*listaTrens)->prox;
        
    } else if( aux == NULL){
       printf("O trem mencionado não está listado");
        return;
    } 
    else {
        ant->prox = aux->prox;
    }

    NoVagoes *auxVag = NULL;
    while (aux->vagoes != NULL)
    {
        auxVag = aux->vagoes;
        aux->vagoes = aux->vagoes->prox;
        free(auxVag);
    }

    free(aux);
    
    
    
}

void removerVagao(NoTrens **listaTrens, char* nomeTrem, char *nomeVagao){
    NoTrens *aux = *listaTrens;
    while (aux != NULL && (strcmp(aux->train, nomeTrem) != 0))
    {
        aux = aux->prox;
    }
    
    if (aux == NULL)
    {
        printf("O trem mencionado não está listado");
        return;
    } else {
        NoVagoes *auxVag = aux->vagoes;
        NoVagoes *antVag = NULL;
        while (auxVag != NULL && (strcmp(auxVag->tipoCarga, nomeVagao) != 0 ))
        {
            antVag = auxVag;
            auxVag = auxVag->prox;
        }

        if(auxVag == NULL){
            printf("O vagao mencionado não está no trem: %s", aux->train);
            return;
        
        } else if( auxVag == aux->vagoes){
            aux->vagoes = aux->vagoes->prox;
            free (auxVag);
        }else {
            antVag->prox = auxVag->prox;
            free(auxVag);
        }
        
    }
    

}






void printaLista(NoTrens **listaTrens){
    NoTrens *aux = *listaTrens;
    
    while(aux != NULL){
        printf("Nome do trem: %s\n", aux->train );
        printf("Vagoes:\n");
        if(aux->vagoes == NULL){
            printf("----\n");
        }
        NoVagoes *auxVagoes = aux->vagoes;
        while (auxVagoes !=  NULL)
        {
            printf("%s | %d \n",auxVagoes->tipoCarga, auxVagoes->maxQtd);
            auxVagoes = auxVagoes->prox;
        }
        aux = aux->prox;
        
    }
}