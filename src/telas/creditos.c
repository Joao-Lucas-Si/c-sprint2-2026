#include "../../utils/utils.h"
#include "../ui.h"
#include <string.h>

void depois() { esperar(1); }

void antes() {
  String nome = obterNome();
  String conteudo = obterConteudo();

  if (conteudo && strcmp(conteudo, "8") == 0) {
    int tamanho = 1;
    int efeitos[1] = {aplicarEfeitoCor(TEXTO_CLARO, obterPrimario())};
    aplicarEfeitos(efeitos, 1);
  } else {
    int tamanho = 1;
    int efeitos[1] = {aplicarEfeitoCor(TEXTO_CLARO, obterSecundario())};
    aplicarEfeitos(efeitos, 1);
  }
}

void integrantesAntes() {
  String conteudo = obterConteudo();
  if (conteudo && (strcmp(conteudo, "|") == 0 || strcmp(conteudo, "\\") == 0 ||
                   strcmp(conteudo, "_") == 0 || strcmp(conteudo, "/") == 0)) {
    int efeitos[1] = {aplicarEfeitoCor(TEXTO_CLARO, obterSecundario())};
    aplicarEfeitos(efeitos, 1);
  } else {
    int efeitos[1] = {aplicarEfeitoCor(TEXTO_CLARO, obterPrimario())};
    aplicarEfeitos(efeitos, 1);
  }
}

void integrantesConteudo(Any *args) {
  ArquivoResultado arquivo = lerLinhaALinha("assets/ascii/integrantes.txt");
  criar_logo(arquivo.conteudo, arquivo.linhas, 110);
  String membros[6] = {"Joao Lucas", "Joao Evangelista", "Alan",
                       "Enzo",       "Gabriel",          "Joao Ribeiro"};
  resetarConfig();
  desativarEfeitos();
  criar_tabela(membros, 3);
}

void mostrarIntegrantes() {
  ArquivoResultado arquivo = lerLinhaALinha("assets/ascii/integrantes.txt");
  Any args[1];
  ativarAntes(integrantesAntes);
  ativarDepois(depois);
  centralizarVertical(integrantesConteudo, arquivo.linhas + 3, args);
}

void mostrarLogo(Any *a) {
  ArquivoResultado arquivo = lerLinhaALinha("assets/ascii/logo.txt");
  // forEachSize(arquivo.conteudo ,arquivo.linhas, debug);
  // debug(maxSize(arquivo.conteudo, arquivo.linhas));

  criar_logo(arquivo.conteudo, arquivo.linhas , 100);
}

void mostrarCreditos() {
  ArquivoResultado arquivo = lerLinhaALinha("assets/ascii/logo.txt");
  Any a[1];
  ativarAntes(antes);
  ativarDepois(depois);
  centralizarVertical(mostrarLogo, arquivo.linhas, a);
  resetarConfig();
  esperar(1000);
  limpar();
  // criarTitulo();
  mostrarIntegrantes();
  esperar(1000);
}