#include "inserir_recarga.h"
#include "../../../utils/utils.h"
#include "../../data.h"
#include "../../utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Recarga *recarga;

void definirRecargaCarro() {

  String conteudo[obterCarrosTamanho() + 1];

  conteudo[0] = "cancelar";
  // int linhas[obterCarrosTamanho()];
  for (int i = 0; i < obterCarrosTamanho(); i++) {

    Carro *carro = &obterCarros()[i];
    conteudo[i + 1] =
        stringf(150, "%s%s", carro->nome,
                carro->energiaAtual == carro->capacidade ? "(cheio)"
                : carro->emRecarga                       ? "(carregando)"
                                                         : "");
  }

  while (1) {

    int opcao = criarMenuSwitch("escolha de carro", conteudo, 3);
    opcao--;
    if (opcao == 0) {
      break;
    }
    opcao--;
    Carro carro = obterCarros()[opcao];

    if (!carro.emRecarga && carro.energiaAtual < carro.capacidade) {

      recarga->carroId = opcao;
      break;
    }
    mostrarErro(carro.emRecarga ? "carro ja em recarga"
                                : "carro ja abastecido");
  }
}

void definirRecargaPosto() {

  int tamanho = obterPostosTamanho();

  String conteudo[tamanho + 1];
  conteudo[0] = "cancelar";
  // int linhas[obterCarrosTamanho()];
  for (int i = 0; i < tamanho; i++) {
    Posto posto = obterPostos()[i];
    conteudo[i + 1] = stringf(
        100, "%s%s", posto.nome,
        posto.veiculosAtuais == posto.maxVeiculos ? "(indisponivel)" : "");
  }
  while (1) {

    int opcao = criarMenuSwitch("escolha de posto", conteudo, 3);

    if (opcao == 1) {
      return;
    }
    opcao--;
    opcao--;
    Posto p = obterPostos()[opcao];

    if (p.maxVeiculos > p.veiculosAtuais) {
      recarga->postoId = opcao;
      break;
    }
    mostrarErro("posto indisponivel\n");
  }
}

void definirRecargaEnergia() {
  int energia;
  printf("energia: ");
  scanf("%d", &energia);

  recarga->energia = energia;
}

MenuConteudoDinamico criarRecargaConteudo() {
  ArquivoResultado imagem = lerLinhaALinha("assets/ascii/opcoes/recarga.txt");

  int previewTamanho = imagem.linhas + 10;
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
  preview[i + 5] = "";
  preview[i + 6] =
      stringf(100, "valor da cobranca: %.2f%s", calcularCobranca(*recarga),
              (posto->maxVeiculos > 4 &&
               posto->veiculosAtuais > (posto->maxVeiculos * 0.7))
                  ? "(aumento por uso excessivo)"
                  : "");
  preview[i + 7] = "";
  preview[i + 8] =
      (posto->maxVeiculos > 3 && posto->veiculosAtuais == (posto->maxVeiculos - 1))
          ? "ativa destribuicao de energia"
          : "";
  // preview[i + 5] = "";
  // preview[i + 6] = stringf(100, "capacidade por hora: %d", recarga->energia);
  // preview[i + 7] = "";
  // preview[i + 8] =
  //     stringf(100, "limite de veiculos simultaneos: %d", recarga->energia);

  String opcoes[9] = {"0. fechar",         "", "1. escolher carro", "",
                      "2. escolher posto", "", "3. mudar energia",  "",
                      "4. salvar"};

  String *tabela[2] = {preview, opcoes};
  int tamanhos[2] = {previewTamanho, len(opcoes)};
  MenuConteudoDinamico resultado = {.conteudo = tabela, .tamanho = tamanhos};

  return resultado;
}

void recargaErro(String mensagem) {
  mostrarErro(mensagem);
  pausar();
}

int validarRecarga() {
  for (int i = 0; i < obterCarrosTamanho(); i++) {
    Carro carro = obterCarros()[i];

    if (carro.capacidade > carro.energiaAtual && !carro.emRecarga) {
      return i;
    }
  }

  return -1;
}

int validarRecargaPosot() {
  for (int i = 0; i < obterPostosTamanho(); i++) {
    Posto posto = obterPostos()[i];

    if (posto.maxVeiculos > posto.veiculosAtuais) {
      return i;
    }
  }
  return -1;
}

void inserirRecargaMenu() {
  int valido = validarRecarga();
  int postoValido = validarRecargaPosot();

  if (valido == -1) {
    recargaErro("nenhum carro esta disponivel\n");
    return;
  }
  if (postoValido == -1) {
    recargaErro("nenhum posto esta disponivel\n");
    return;
  }

  recarga = malloc(sizeof(Recarga));
  recarga->energia = 100;
  recarga->carroId = valido;
  recarga->concluido = 0;
  recarga->carregado = 0;
  recarga->notificado = 0;
  recarga->postoId = postoValido;
  recarga->dia = 0;
  recarga->horario = 0;

  OpcaoMenu opcoes[3] = {definirRecargaCarro, definirRecargaPosto,
                         definirRecargaEnergia};
  while (1) {

    int selecionado = _criarMenuMultilinhaSwitchDinamico(
        "edicao de posto", criarRecargaConteudo, 2, 2);

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
      obterCarros()[recarga->carroId].emRecarga = 1;
      adicionarRecarga(*recarga);
      return;
    default:
      mostrarErro("opcao invalida");
      break;
    }
  }
}