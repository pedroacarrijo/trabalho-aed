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


void printaLista(NoTrens **lista){
    NoTrens *aux = *lista;
    
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