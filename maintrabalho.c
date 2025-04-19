#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalho.h"

int main(){

    NoTrens *lista;
    crialistaTrem(&lista);
    adicionaTrem(&lista, "OIII");
    adicionaVagao(&lista, "OIII", "madeira", 100);
    adicionaVagao(&lista, "OIII", "ferro", 100);
    adicionaVagao(&lista, "OIII", "carne", 100);
    adicionaVagao(&lista, "OIII", "pica", 100);
    adicionaTrem(&lista, "AAAAA");
    adicionaTrem(&lista, "BBBBB");

    adicionaVagao(&lista, "AAAAA", "picas", 15656);

    

    printaLista(&lista);





}