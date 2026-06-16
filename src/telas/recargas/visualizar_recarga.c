#include "../../../utils/utils.h"
#include "../../data.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct {
  int posto;
  Recarga *recargas;
  int tamanho;
} RecargaAgrupada;

void visualizarRecarga() {
  RecargaAgrupada *grupos = NULL;
  int tamanho = 0;
  for (int i = 0; i < obterRecargasTamanho(); i++) {
    Recarga recarga = obterRecargas()[i];
    if (recarga.concluido) {
      continue;
    }
    RecargaAgrupada *grupo = NULL;
    for (int j = 0; j < tamanho; j++) {
      if (grupos[j].posto == recarga.postoId) {
        grupo = &grupos[j];
      }
    }
    if (!grupo) {

      if (tamanho == 0) {
        grupos = malloc(sizeof(RecargaAgrupada));

      } else {
        grupos = realloc(grupos, sizeof(RecargaAgrupada) * (tamanho + 1));
      }
      RecargaAgrupada b;
      b.posto = recarga.postoId;
      b.tamanho = 0;
      grupos[tamanho] = b;
      grupo = &grupos[tamanho];
      tamanho++;

      if (grupo->tamanho == 0) {
        grupo->recargas = malloc(sizeof(recarga));
      } else {
        grupo->recargas =
            realloc(grupo->recargas, (grupo->tamanho + 1) * sizeof(Recarga));
      }
      grupo->recargas[grupo->tamanho] = obterRecargas()[i];
      grupo->tamanho++;
    }
  }
  
  if (tamanho == 0 || !grupos) {
    centralizar("sem recargas ativas", ' ');
    pausar();
  } else {
    for (int i = 0; i < tamanho; i++) {
      RecargaAgrupada grupo = grupos[i];
      String **conteudo = malloc(grupo.tamanho * sizeof(String *));
      int *tamanhos = malloc(sizeof(int) * grupo.tamanho);

      for (int j = 0; j < grupo.tamanho; j++) {
        Carro carro = obterCarros()[grupo.recargas[j].carroId];
        int tamanho = carro.asciiTamanho + 2;
        tamanhos[j] = tamanho;
        String *imagem = malloc(tamanho * sizeof(String));

        copiarEm(imagem, carro.ascii, 0, carro.asciiTamanho);
        int e = carro.asciiTamanho;
        imagem[e] = stringf(100, "energia: %.2f/%.2f", carro.energiaAtual,
                            carro.capacidade);
        imagem[e + 1] = stringf(100, "nome: %s", carro.nome);

        conteudo[j] = imagem;
      }
      centralizar(obterPostos()[grupo.posto].nome, ' ');
      criarTabelaMultilinha(conteudo, grupo.tamanho, tamanhos, 3);
    }
    pausar();
  }
  
  //   String *recargas[obterRecargasTamanho()];
  //   int tamanhos[obterRecargasTamanho()];
  //   ArquivoResultado imagem =
  //   lerLinhaALinha("assets/ascii/opcoes/posto.txt"); for (int i = 0; i <
  //   obterPostosTamanho(); i++) {
  //     Posto posto = obterPostos()[i];
  //     int tamanho = (imagem.linhas + 5);
  //     String *linha = malloc(tamanho * sizeof(String));
  //     tamanhos[i] = tamanho;
  //     linha[0] = stringf(100, "%s", posto.nome);
  //     copiarEm(linha, imagem.conteudo, 1, imagem.linhas);
  //     int j = imagem.linhas + 1;

  //     linha[j] = stringf(100, "capacidade: %d kH/h", posto.capacidade);
  //     linha[j + 1] = stringf(100, "energia maxima: %d", posto.maximo);
  //     linha[j + 2] = stringf(100, "capacidade de veiculos simultaneos: %d ",
  //                            posto.maxVeiculos);
  //     linha[j + 3] = stringf(100, "auto recarga diaria: %d",
  //     posto.energiaPorDia);

  //     postos[i] = linha;
  //   }

  //   criarTabelaMultilinha(postos, obterPostosTamanho(), tamanhos, 4);
  //   pausar();
}