#include "inserir.h"
#include "../../../utils/utils.h"
#include "../../data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ArquivoResultado asciis[9];

Carro *carro;

int salvando;

void mudarImagem() {
  String *modelos[9];
  int tamanhos[9];
  for (int i = 0; i < len(asciis); i++) {
    modelos[i] = malloc((asciis[i].linhas + 1) * sizeof(String));
    tamanhos[i] = asciis[i].linhas + 1;
    modelos[i][0] = stringf(100, "Carro %d", i + 1);
    copiarEm(modelos[i], asciis[i].conteudo, 1, asciis[i].linhas);
  }

  int selecionado =
      criarMenuSwitchMultilinha("Imagens", modelos, 9, tamanhos, 4) - 1;
  carro->ascii = asciis[selecionado].conteudo;
  carro->asciiTamanho = asciis[selecionado].linhas;
  carro->modelo = selecionado + 1;
}

void mudarCarroNome() {
  char nome[100];
  printf("nome: ");
  scanf("%s", nome);
  // lerString(nome, 100);

  strcpy(carro->nome, nome);
}

void mudarCarroCapacidade() {
  float capacidade;
  printf("capacidade: ");
  scanf("%f", &capacidade);
  carro->capacidade = capacidade;
}

void mudarEnergia() {
  float energia;
  printf("energia: ");
  scanf("%f", &energia);
  carro->energiaAtual = energia;
}

void salvaAr() {
  if (!salvando) {

    adicionarCarro(*carro);
    salvando = 1;
    carro = &obterCarros()[obterCarrosTamanho() - 1];
  }
}

MenuConteudoDinamico criarConteudoMenu() {
  int t = carro->asciiTamanho + 8;
  String *preview = malloc((t) * sizeof(String));

  preview[0] = "Preview";
  copiarEm(preview, carro->ascii, 1, carro->asciiTamanho);

  int comeco = carro->asciiTamanho + 1;
  preview[comeco] = stringf(100, "nome: %s", carro->nome);
  preview[comeco + 1] = "";
  preview[comeco + 2] = stringf(100, "capacidade: %.2f", carro->capacidade);
  preview[comeco + 3] = "";
  preview[comeco + 4] =
      stringf(100, "energia atual: %.2f", carro->energiaAtual);
  preview[comeco + 5] = "";

  preview[comeco + 6] = stringf(100, salvando ? "salvo" : "nao salvo");
  String opcoes[11] = {"0. fechar",        "", "1. mudar imagem",          "",
                       "2. mudar nome",    "", "3. mudar capacidade",      "",
                       "4. mudar energia", "", salvando ? "" : "5. salvar"};

  String **tabela = malloc(2 * sizeof(String));
  tabela[0] = preview;
  tabela[1] = opcoes;
  int tamanho[2] = {t, len(opcoes)};

  MenuConteudoDinamico conteudo = {.conteudo = tabela, .tamanho = tamanho};
  return conteudo;
}

void inserir() {
  for (int i = 0; i < len(asciis); i++) {
    String caminho = stringf(100, "assets/ascii/carros/carro_%d.txt", i + 1);
    asciis[i] = lerLinhaALinha(caminho);
  }
  if (carro == NULL) {
    carro = malloc(sizeof(Carro));
    // carro = &novo;
    carro->ascii = asciis[0].conteudo;
    carro->asciiTamanho = asciis[0].linhas;
    // carro->nome[0]='\0';
    sprintf(carro->nome, "carro");
    carro->capacidade = 100.0;
    carro->energiaAtual = 100.0;
    salvando = 0;
  } else {
    salvando = 1;
  }

  OpcaoMenu opcoes[5] = {mudarImagem, mudarCarroNome, mudarCarroCapacidade, mudarEnergia,
                         salvaAr};
  // criarConteudoMenu();
  _criarMenuMultilinhaDinamica("adicionar", criarConteudoMenu, opcoes,
                               len(opcoes), 2, 2);
  carro = NULL;
  salvando = 0;
}