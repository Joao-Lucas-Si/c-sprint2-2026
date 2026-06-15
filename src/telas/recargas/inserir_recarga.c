#include "inserir_recarga.h"
#include "../../../utils/utils.h"
#include "../../data.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
Recarga *recarga;
int salvando = 0;

void definirRecargaPosto() {
//   char nome[100];
//   printf("nome: ");
//   scanf("%s", nome);

//   strcpy(posto->nome, nome);
}

void definirRecargaEnergia() {
  int energia;
  printf("energia: ");
  scanf("%d", &energia);

  recarga->energia = energia;
}

void definirRecargaCarro() {
//   int energia;
//   printf("capacidade: ");
//   scanf("%d", &energia);

//   posto->capacidade = energia;
}

void salvarPosto() {
//   if (!salvando) {
//     adicionarPosto(*posto);
//     salvando = 1;
//     posto = &obterPostos()[obterPostosTamanho() - 1];
//   }
}

MenuConteudoDinamico criarConteudo() {
//   ArquivoResultado imagem = lerLinhaALinha("assets/ascii/opcoes/posto.txt");

//   int previewTamanho = imagem.linhas + 10;
//   String *preview = malloc(previewTamanho * sizeof(String));

//   preview[0] = "preview";

//   copiarEm(preview, imagem.conteudo, 1, imagem.linhas);

//   int i = imagem.linhas + 1;

//   preview[i] = stringf(100, "nome: %s", posto->nome);
//   preview[i + 1] = "";
//   preview[i + 2] = stringf(100, "energia por dia: %d", posto->energiaPorDia);
//   preview[i + 3] = "";
//   preview[i + 4] = stringf(100, "energia maxima: %d", posto->maximo);
//   preview[i + 5] = "";
//   preview[i + 6] = stringf(100, "capacidade por hora: %d", posto->capacidade);
//   preview[i + 7] = "";
//   preview[i + 8] =
//       stringf(100, "limite de veiculos simultaneos: %d", posto->maxVeiculos);

//   String opcoes[13] = {"0. fechar",
//                        "",
//                        "1. mudar nome",
//                        "",
//                        "2. mudar energia por dia",
//                        "",
//                        "3. mudar energia maxima",
//                        "",
//                        "4. mudar capacidade",
//                        "",
//                        "5. mudar limite de veiculos",
//                        "",
//                         salvando ? "" :"6. salvar"};

//   String *tabela[2] = {preview, opcoes};
//   int tamanhos[2] = {previewTamanho, len(opcoes)};
//   MenuConteudoDinamico resultado  = {.conteudo = tabela, .tamanho = tamanhos};

//   return resultado;
}

void inserirPostoMenu() {
//   if (salvando) {

//   } else {
//     posto = malloc(sizeof(Posto));
//     posto->maximo = 100;
//     posto->capacidade = 40;
//     posto->maxVeiculos = 2;
//     posto->energiaPorDia = 60;
//     posto->nome[0] = '\0';
//   }
//   OpcaoMenu opcoes[6] = { mudarPostoNome, mudarEnergiaDia, mudarEnergiaMaxima, mudarPostoCapacidade, mudarLimiteVeiculos, salvarPosto };
//   _criarMenuMultilinhaDinamica("edição de posto", criarConteudo, opcoes,
//                                len(opcoes), 2, 2);
}