#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalho.h"

int main(){

    NoTrens *lista;
    crialistaTrem(&lista);
    adicionaTrem(&lista, "OIII");
    adicionarVagaoOrdenado(&lista, "OIII", "madeira", 100);
    adicionarVagaoOrdenado(&lista, "OIII", "ferro", 100);
    adicionarVagaoOrdenado(&lista, "OIII", "carne", 100);
    adicionarVagaoOrdenado(&lista, "OIII", "pica", 100);
    adicionaTrem(&lista, "AAAAA");
    adicionaTrem(&lista, "BBBBB");

    adicionarVagaoOrdenado(&lista, "AAAAA", "picas", 15656);

    //removerTrem(&lista , "OIII");
    //removerVagao(&lista, "AAAAA", "picas");
    

    printaLista(&lista);





}