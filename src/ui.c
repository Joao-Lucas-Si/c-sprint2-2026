#include "../utils/utils.h"
#include "data.h"
#include <string.h>

void colorirTitulo() {
  String conteudo = obterConteudo();
  String nome = obterNome();
  if (conteudo && strcmp(conteudo, "=") == 0) {
    int efeitos[] = {aplicarEfeitoCor(TEXTO, obterPrimario())};
    aplicarEfeitos(efeitos, len(efeitos));
  } else if (nome && strcmp(nome, "conteudo-centralizado")) {
    int efeitos[] = {aplicarEfeitoCor(TEXTO, obterSecundario())};
    aplicarEfeitos(efeitos, len(efeitos));
  } else {
    aplicarEfeitos(NULL, 0);
  }
}
void criarTitulo() {
  ativarAntes(colorirTitulo);
  int largura = obterLargura();
  centralizar_limitado("carros", '=', largura - 5);
  print("%d:00", obterHoras());
  resetarConfig();
}