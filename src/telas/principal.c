#include "../../utils/utils.h"
#include "../data.h"
#include "../ui.h"
#include "carros/carro_menu.h"
#include "creditos.h"
#include "postos/opcao_postos.h"
#include "recargas/opcao_recarga.h"
#include "notificacoes.h"
#include <stdio.h>
void passarTempo() {
  int horas;

  printf("digite a quantidade de horas a passar: ");
  scanf("%d", &horas);

  passarHoras(horas);

  visualizarMudancas();
}

void menuPrincipal() {
  ArquivoResultado porta = lerLinhaALinha("assets/ascii/opcoes/saida.txt");
  ArquivoResultado papiro = lerLinhaALinha("assets/ascii/opcoes/papiro.txt");
  ArquivoResultado disquete = lerLinhaALinha("assets/ascii/opcoes/inserir.txt");
  ArquivoResultado carro = lerLinhaALinha("assets/ascii/opcoes/carros.txt");
  ArquivoResultado logo =
      lerLinhaALinha("assets/ascii/logos/logo_compacta.txt");
  ArquivoResultado bateriaVazia =
      lerLinhaALinha("assets/ascii/opcoes/recarga.txt");
  ArquivoResultado relogio = lerLinhaALinha("assets/ascii/opcoes/horario.txt");
  ArquivoResultado carregamento = lerLinhaALinha("assets/ascii/opcoes/posto.txt");
  OpcaoMenu opcoes[5] = {carrosMenu, postoMenu, opcaoRecarga,  passarTempo, mostrarCreditos};
  String fechar[porta.linhas + 1];
  fechar[0] = "0. fechar";
  copiarEm(fechar, porta.conteudo, 1, porta.linhas);

  String visualizar[carro.linhas + 1];
  visualizar[0] = "1. carros";
  copiarEm(visualizar, carro.conteudo, 1, carro.linhas);



  String postos[bateriaVazia.linhas + 1];

  postos[0] = "2. postos";

  copiarEm(postos, bateriaVazia.conteudo, 1, bateriaVazia.linhas);

  String horario[relogio.linhas + 1];

  horario[0] = "4. passar hora";
  copiarEm(horario, relogio.conteudo, 1, relogio.linhas);
  String creditos[logo.linhas + 1];
  creditos[0] = "5. mostrar creditos";
  copiarEm(creditos, logo.conteudo, 1, logo.linhas);
  String recargas[carregamento.linhas + 1];
  recargas[0] = "3. recargas";
  copiarEm(recargas, carregamento.conteudo, 1, carregamento.linhas);

  String *tabela[6] = {fechar, visualizar,
                       postos,   recargas, horario,  creditos};
  int tamanhos[6] = {len(fechar), len(visualizar),
                     len(postos), len(recargas), len(horario),    len(creditos)};

  _criarMenuMultilinha("Sistema", tabela, opcoes, len(opcoes), len(tabela),
                       tamanhos, 3);
}
