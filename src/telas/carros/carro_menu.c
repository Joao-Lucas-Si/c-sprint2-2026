#include "../../menu_crud.h"
#include "inserir.h"
#include "visualizar_carros.h"
void carrosMenu() {
    OpcaoMenu opcoes[3] = { inserir, visualizarCarros  };
    menuCrud(opcoes);
}