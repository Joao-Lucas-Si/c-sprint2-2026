#include "../../menu_crud.h"
#include "inserir.h"
#include "carros.h"
void carrosMenu() {
    OpcaoMenu opcoes[3] = { inserir, carrosF  };
    menuCrud(opcoes);
}