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

void adicionaTremFinal(NoTrens **listaTrens, char *nome){
    NoTrens *novo = criaTrem(nome);
    if( *listaTrens == NULL){
        novo->prox = *listaTrens;
        *listaTrens = novo;
    } else {
        NoTrens *aux = *listaTrens;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;

        
    }



}

void adicionarTremOrdenado(NoTrens **listaTrens, char *nome){
    NoTrens *novo;
    novo = criaTrem(nome);
    if (*listaTrens != NULL)
    {
        NoTrens *aux = *listaTrens;
    
    while (aux->prox != NULL && (strcmp(novo->train, aux->train) > 0 ))
    {
        aux = aux->prox;
    }
    if ( (aux == *listaTrens && (strcmp(novo->train, aux->train) <= 0)))
    {
        novo->prox = aux;
        *listaTrens = novo;
    } else {
        novo->prox = aux->prox;
        aux->prox = novo;
    }
    } else {
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



void adicionaVagaoInicio(NoTrens **listaTrens, char *nome, char *tipoCarga, int qtd){
    NoTrens *aux = *listaTrens;
    while(aux != NULL && (strcmp(aux->train, nome) != 0)){
        aux = aux->prox;
    }
    if(aux == NULL){
        printf("O trem mencionado não pode ser encontrado  \n");
        return;
    }else {
        NoVagoes *novo = criaVagao(tipoCarga, qtd);
        novo->prox = aux->vagoes;
        
        
        if (aux->vagoes != NULL)
        {
            aux->vagoes->ant = novo;
        } 
        aux->vagoes = novo;
        
    }

}

void adicionarVagaoFinal(NoTrens **listaTrens, char *nome, char *tipoCarga, int qtd){
    NoTrens *aux = *listaTrens;
    while (aux != NULL && (strcmp(aux->train, nome) != 0))
    {
        aux = aux->prox;
    } 
    if (aux == NULL){
        printf("O trem mencionado não pode ser encontrado \n");
        return;
    } else {
        NoVagoes *auxVag = aux->vagoes;
        NoVagoes *novo = criaVagao(tipoCarga, qtd);
        if (auxVag == NULL)
        {
            aux->vagoes = novo;
        } else {
        while (auxVag->prox != NULL)
        {
            auxVag = auxVag->prox;
        }
        
        novo->prox = auxVag->prox;
        auxVag->prox = novo;
        novo->ant = auxVag;
    }
        
        

    }
    
}

void adicionarVagaoOrdenado(NoTrens **listaTrens, char *nome, char *tipoCarga, int qtd){
    NoTrens *aux = *listaTrens;
    while (aux != NULL && (strcmp(aux->train, nome) != 0))
    {
        aux = aux->prox;
    } 
    if (aux == NULL){
        printf("O trem mencionado não pode ser encontrado \n");
        return;
    } else {
        NoVagoes *novo = criaVagao(tipoCarga, qtd);
        NoVagoes *auxVag = aux->vagoes;
        NoVagoes *ant = NULL;
        while (auxVag != NULL && (strcmp(auxVag->tipoCarga, tipoCarga) < 0))
        {
            ant = auxVag;
            auxVag = auxVag->prox;
        }

        novo->prox = auxVag;
        novo->ant = ant;

        if(ant == NULL){
            aux->vagoes = novo;
        }else {
            ant->prox = novo;
        }
        if (auxVag != NULL)
        {
            auxVag->ant = novo;
        }
        
        

    }
}




void removerTrem(NoTrens **listaTrens, char *nome){
    if (*listaTrens == NULL)
    {
        printf("A lista de trens está vazia! \n");

        return;
    } else{
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
       printf("O trem mencionado não está listado \n");
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
    
    
    
}

void removerVagao(NoTrens **listaTrens, char* nomeTrem, char *nomeVagao){
    NoTrens *aux = *listaTrens;
    while (aux != NULL && (strcmp(aux->train, nomeTrem) != 0))
    {
        aux = aux->prox;
    }
    
    if (aux == NULL)
    {
        printf("O trem mencionado não está listado \n");
        return;
    } else {
        NoVagoes *auxVag = aux->vagoes;
        
        while (auxVag != NULL && (strcmp(auxVag->tipoCarga, nomeVagao) != 0 ))
        {
            
            auxVag = auxVag->prox;
        }

        if(auxVag == NULL){
            printf("O vagao mencionado não está no trem: %s \n", aux->train);
            return;
        
        } else if( auxVag == aux->vagoes){
            
            aux->vagoes = aux->vagoes->prox;
            if (aux->vagoes != NULL)
            {
                aux->vagoes->ant = NULL;
            }
            
            
            
            free (auxVag);
        }else {
            
            if(auxVag->ant != NULL)
            auxVag->ant->prox = auxVag->prox;
            if (auxVag->prox !=NULL)
            auxVag->prox->ant = auxVag->ant;


            free(auxVag);
        }
        
    }
    

}

void TrocarVagoesEntreTrens(NoTrens **listaTrens, char *nomeTrem1, char *nomeTrem2, char *nomeVagao1, char* nomeVagao2){
    if(*listaTrens != NULL){
    NoTrens *aux1 = *listaTrens;
    NoTrens *aux2 = *listaTrens;
    while (aux1 != NULL && (strcmp(aux1->train, nomeTrem1) != 0))
    {
        aux1 = aux1->prox;
    }
    while (aux2 != NULL && (strcmp(aux2->train, nomeTrem2) != 0))
    {
        aux2 = aux2->prox;
    }

    if (aux1 == NULL  || aux2 == NULL)
    {
        printf("Não foi possivel encontrar um dos trens desejados, verifique novamente a lista de trens disponíveis ! \n");
        return;
    }

    NoVagoes *temp,  *auxVagao1, *auxVagao2, *prox1, *prox2, *ant1, *ant2;
    
    auxVagao1 = aux1->vagoes;
    auxVagao2 = aux2->vagoes;

    while (auxVagao1 != NULL && (strcmp(auxVagao1->tipoCarga, nomeVagao1) != 0))
    {
       auxVagao1 = auxVagao1->prox;
    }
    

    while (auxVagao2 != NULL && (strcmp(auxVagao2->tipoCarga, nomeVagao2) != 0))
    {
       auxVagao2 = auxVagao2->prox;
    }

    if (auxVagao1 == NULL || auxVagao2 == NULL)
    {
        printf("Não foi possivel encontrar um dos vagões mencionados, verifique novamente a lista!");
        return;
    }

    prox1 = auxVagao1->prox;
    prox2 = auxVagao2->prox;

    ant1 = auxVagao1->ant;
    ant2 = auxVagao2->ant;

    if (aux1->vagoes == auxVagao1)
    {
        aux1->vagoes = auxVagao2;
    }

    if (aux2->vagoes == auxVagao2)
    {
        aux2->vagoes = auxVagao1;
    }
    
    

    

    if (ant1 != NULL)
    {
        ant1->prox = auxVagao2;
    }

    if (ant2 != NULL)
    {
        ant2->prox = auxVagao1;
    }


    if (prox1 != NULL)
    {
        prox1->ant = auxVagao2;
    }

    if (prox2 != NULL)
    {
        prox2->ant = auxVagao1;
    }
    
    auxVagao1->ant = ant2;
    auxVagao1->prox = prox2;

    auxVagao2->ant = ant1;
    auxVagao2->prox = prox2;

    

    

    } else {
        printf("Lista vazia! \n");
        return;
    }
    
    
}






void printaLista(NoTrens **listaTrens){
    NoTrens *aux = *listaTrens;
    if (aux == NULL)
    {
        printf("Lista vazia! \n");
        return;
    }
    
    
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



