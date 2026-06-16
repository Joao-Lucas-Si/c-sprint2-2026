#include "inserir_recarga.h"
#include "../../../utils/utils.h"
#include "../../data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Recarga *recarga;

void definirRecargaCarro() {

  String conteudo[obterCarrosTamanho()];
  // int linhas[obterCarrosTamanho()];
  for (int i = 0; i < obterCarrosTamanho(); i++) {
    conteudo[i] = stringf(100, "%d. %s", i + 1, obterCarros()[i].nome);
  }

  int opcao = criarMenuSwitch("escolha de carro", conteudo, 3);

  recarga->carroId = opcao - 1;
}

void definirRecargaPosto() {

  int tamanho = obterPostosTamanho();

  String conteudo[tamanho];
  // int linhas[obterCarrosTamanho()];
  for (int i = 0; i < tamanho; i++) {
    conteudo[i] = stringf(100, "%d. %s", i + 1, obterPostos()[i].nome);
  }

  int opcao = criarMenuSwitch("escolha de posto", conteudo, 3);

  recarga->postoId = opcao - 1;
}

void definirRecargaEnergia() {
  int energia;
  printf("energia: ");
  scanf("%d", &energia);

  recarga->energia = energia;
}

MenuConteudoDinamico criarRecargaConteudo() {
  ArquivoResultado imagem = lerLinhaALinha("assets/ascii/opcoes/recarga.txt");

  int previewTamanho = imagem.linhas + 6;
  String *preview = malloc(previewTamanho * sizeof(String));

  preview[0] = "preview";

  copiarEm(preview, imagem.conteudo, 1, imagem.linhas);

  int i = imagem.linhas + 1;
  int carros = obterCarrosTamanho();
  Carro *carro = &obterCarros()[recarga->carroId];
  Posto *posto = &obterPostos()[recarga->postoId];
  preview[i] = stringf(100, "carro: %s", carro->nome);
  preview[i + 1] = "";
  preview[i + 2] = stringf(100, "posto: %s", posto->nome);
  preview[i + 3] = "";
  preview[i + 4] = stringf(100, "energia: %d", recarga->energia);
  // preview[i + 5] = "";
  // preview[i + 6] = stringf(100, "capacidade por hora: %d", recarga->energia);
  // preview[i + 7] = "";
  // preview[i + 8] =
  //     stringf(100, "limite de veiculos simultaneos: %d", recarga->energia);

  String opcoes[9] = {"0. fechar",         "", "1. escolher carro", "",
                      "2. escolher posto", "", "3. mudar energia", "", "4. salvar"};

  String *tabela[2] = {preview, opcoes};
  int tamanhos[2] = {previewTamanho, len(opcoes)};
  MenuConteudoDinamico resultado = {.conteudo = tabela, .tamanho = tamanhos};

  return resultado;
}

void inserirRecargaMenu() {

  recarga = malloc(sizeof(Recarga));
  recarga->energia = 100;
  recarga->carroId = 0;
  recarga->postoId = 0;
  recarga->dia = 0;
  recarga->horario = 0;

  OpcaoMenu opcoes[3] = {definirRecargaCarro, definirRecargaPosto,
                         definirRecargaEnergia};
  while (1) {

    int selecionado = _criarMenuMultilinhaSwitchDinamico(
        "edição de posto", criarRecargaConteudo, 2, 2);

    if (selecionado == 0) {
      break;
    }
    selecionado--;
    switch (selecionado) {
    case 0:
    case 1:
    case 2:
      opcoes[selecionado]();
      break;
    case 3:
      adicionarRecarga(*recarga);
      return;
    default:
      mostrarErro("opção invalida");
      break;
    }
  }
}