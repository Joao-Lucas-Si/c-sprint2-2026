#include "../../../utils/utils.h"
#include "inserir_posto.h"
#include "../../menu_crud.h"
#include "visualizar_postos.h"
void postoMenu() {
  OpcaoMenu opcoes[3] = {inserirPostoMenu, VisualizarPostos};

  menuCrud(opcoes);
    
}