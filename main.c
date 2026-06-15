#include "utils/array.c"
#include "utils/data.c"
#include "utils/input.c"
#include "utils/numerico.c"
#include "utils/print.c"
#include "utils/sistema.c"
#include "utils/string.c"
#include "utils/tui/animacao.c"
#include "utils/tui/cor.c"
#include "utils/tui/layout.c"
#include "utils/tui/menus.c"
#include "utils/tui/texto/multilinha.c"
#include "utils/tui/texto/tabela.c"
#include "utils/tui/ui.c"
#include "src/data.h"
#include "src/data.c"
#include "src/telas/creditos.c"
#include "src/ui.c"
#include "src/telas/carros/inserir.c"
#include "src/telas/carros/carros.c"
#include "src/menu_crud.c"
#include "src/telas/carros/carro_menu.c"
#include "src/telas/principal.c"
#include "src/telas/postos/inserir_posto.c"
#include "src/telas/recargas/opcao_recarga.c"
#include "src/telas/postos/opcao_postos.c"
#include "src/telas/postos/visualizar_postos.c"

int main() {
  iniciarBanco();
  configurarCores(VERMELHO, LARANJA);
  //mostrarCreditos();
  limpar();
  menuPrincipal();
  // OpcaoMenu opcoes[3] = {
  //   adicionarVeiculo(),
  // }
  //_criarMenuMultilinha("Gerenciamento", textos, OpcaoMenu *opcoes, int
  // tamanho, int *linhas, int colunas)
  // int linhas[3];
  // tabela.textos = textos;
  // tabela.linhas = linhas;
  // carrosParaTexto(&tabela, carros, 3);
  // // String* tabela[3] = {
  // //   c(carros[0]),
  // //   c(carros[1]),
  // //   c(carros[2])
  // // };
  // // int i[3] = {6, 6, 6};
  // char titulo[] = "Carro";
  // // centralizar(titulo, ' ');
  // // criarTabelaMultilinhaMap(carros, 3, i, 3, );

  // printf("pre\n");
  // printf("%s\n", tabela.textos[0][0]);
  // for (int i =0; i < tabela.linhas[0]; i++) {
  //   debug(tabela.textos[0][i]);
  // }

  // char** caracteres = malloc(1 * sizeof(char[100]));

  // caracteres[0][0] = 'a';
  // caracteres[0][1] = 0;
  // printf("%s", caracteres[0]);
  // criarTabelaMultilinha(tabela.textos, 3, tabela.linhas, 3);
  return 0;
}
