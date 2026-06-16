
#include "../../../utils/utils.h"
#include "../../data.h"
#include <stdlib.h>
void VisualizarPostos() {
  String *postos[obterPostosTamanho()];
  int tamanhos[obterPostosTamanho()];
  ArquivoResultado imagem = lerLinhaALinha("assets/ascii/opcoes/posto.txt");
  for (int i = 0; i < obterPostosTamanho(); i++) {
    Posto posto = obterPostos()[i];
    int tamanho = (imagem.linhas + 4);
    String *linha = malloc(tamanho  * sizeof(String));
    tamanhos[i] = tamanho;
    linha[0] = stringf(100, "%s", posto.nome);
    copiarEm(linha, imagem.conteudo, 1, imagem.linhas);
    int j = imagem.linhas + 1;

    linha[j] = stringf(100, "capacidade: %d kH/h", posto.capacidade);
    linha[j + 1] = stringf(100, "energia maxima: %d", posto.maximo);
    linha[j + 2] = stringf(100, "capacidade de veiculos simultaneos: %d ",
                           posto.maxVeiculos);

    postos[i] = linha;
  }

 criarTabelaMultilinha(postos, obterPostosTamanho(), tamanhos, 4);
  pausar();
}