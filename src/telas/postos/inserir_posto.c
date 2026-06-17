#include "inserir_posto.h"
#include "../../../utils/utils.h"
#include "../../data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Posto *posto;
int salvando = 0;

void mudarPostoNome() {
  char nome[100];
  printf("nome: ");
  scanf("%s", nome);

  strcpy(posto->nome, nome);
}


void mudarPostoCapacidade() {
  int energia;
  printf("capacidade: ");
  scanf("%d", &energia);

  posto->capacidade = energia;
}

void mudarLimiteVeiculos() {
  int energia;
  printf("limite de veiculos simultaneos: ");
  scanf("%d", &energia);

  posto->maxVeiculos = energia;
}

void salvarPosto() {
  if (!salvando) {
    adicionarPosto(*posto);
    salvando = 1;
    posto = &obterPostos()[obterPostosTamanho() - 1];
  }
}

MenuConteudoDinamico criarConteudo() {
  ArquivoResultado imagem = lerLinhaALinha("assets/ascii/opcoes/posto.txt");

  int previewTamanho = imagem.linhas + 6;
  String *preview = malloc(previewTamanho * sizeof(String));

  preview[0] = "preview";

  copiarEm(preview, imagem.conteudo, 1, imagem.linhas);

  int i = imagem.linhas + 1;

  preview[i] = stringf(100, "nome: %s", posto->nome);
  preview[i + 1] = "";
  preview[i + 2] = stringf(100, "capacidade por hora: %d", posto->capacidade);
  preview[i + 3] = "";
  preview[i + 4] =
      stringf(100, "limite de veiculos simultaneos: %d", posto->maxVeiculos);

  String opcoes[9] = {"0. fechar",
                       "",
                       "1. mudar nome",
                       "",
                       "2. mudar capacidade",
                       "",
                       "3. mudar limite de veiculos",
                       "",
                        salvando ? "" :"4. salvar"};

  String *tabela[2] = {preview, opcoes};
  int tamanhos[2] = {previewTamanho, len(opcoes)};
  MenuConteudoDinamico resultado  = {.conteudo = tabela, .tamanho = tamanhos};

  return resultado;
}

void editarPosto(Posto* editado) {
  posto = editado;
}

void inserirPostoMenu() {
  if (posto) {
    salvando = 1;
  } else {
    posto = malloc(sizeof(Posto));
    posto->capacidade = 40;
    posto->maxVeiculos = 2;
    posto->veiculosAtuais = 0;
    posto->nome[0] = '\0';
    salvando=0;
  }
  OpcaoMenu opcoes[4] = { mudarPostoNome, mudarPostoCapacidade, mudarLimiteVeiculos, salvarPosto };
  _criarMenuMultilinhaDinamica("edição de posto", criarConteudo, opcoes,
                               len(opcoes), 2, 2);
}