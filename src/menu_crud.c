#include "../utils/utils.h"

void menuCrud(OpcaoMenu opcoes[3]) {
  ArquivoResultado disquete = lerLinhaALinha("assets/ascii/opcoes/inserir.txt");
  ArquivoResultado porta = lerLinhaALinha("assets/ascii/opcoes/saida.txt");
  ArquivoResultado tela = lerLinhaALinha("assets/ascii/opcoes/visualizacao.txt");

  String sair[porta.linhas + 1];

  sair[0] = "0. fechar";
  copiarEm(sair, porta.conteudo, 1, porta.linhas);

  String adicionar[disquete.linhas + 1];

  adicionar[0] = "1. Adicionar";
  copiarEm(adicionar, disquete.conteudo, 1, disquete.linhas);

  String visualizar[tela.linhas + 1];

  visualizar[0] =  "2. Visualizar";
  copiarEm(visualizar, tela.conteudo, 1, tela.linhas);

  String* tabela[3] = { sair, adicionar, visualizar };
  int tamanhos[3] = {len(sair), len(adicionar), len(visualizar)};

  _criarMenuMultilinha("Controle", tabela, opcoes, 3, len(tabela), tamanhos, 3);
}