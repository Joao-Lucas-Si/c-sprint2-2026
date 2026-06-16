#include "../../../utils/utils.h"
#include "../../menu_crud.h"
#include "opcao_recarga.h"
#include "inserir_recarga.h"
#include "visualizar_recarga.h"

void opcaoRecarga() {
    OpcaoMenu opcoes[3] = { inserirRecargaMenu, visualizarRecarga};
    menuCrud(opcoes);
}