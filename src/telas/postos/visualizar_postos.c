
#include "../../../utils/utils.h"
#include "../../data.h"
#include "inserir_posto.h"
#include <stdio.h>
#include <stdlib.h>
void VisualizarPostos() {
  if (obterPostosTamanho()>0) {

    String *postos[obterPostosTamanho()];
    int tamanhos[obterPostosTamanho()];
    ArquivoResultado imagem = lerLinhaALinha("assets/ascii/opcoes/posto.txt");
    for (int i = 0; i < obterPostosTamanho(); i++) {
      Posto posto = obterPostos()[i];
      int tamanho = (imagem.linhas + 4);
      String *linha = malloc(tamanho * sizeof(String));
      tamanhos[i] = tamanho;
      linha[0] = stringf(100, "%s", posto.nome);
      copiarEm(linha, imagem.conteudo, 1, imagem.linhas);
      int j = imagem.linhas + 1;
  
      linha[j] = stringf(100, "capacidade: %d kH/h", posto.capacidade);
      linha[j + 1] = stringf(100, "veiculos sendo carregados: %d/%d ",
                             posto.veiculosAtuais, posto.maxVeiculos);
      linha[j + 2] = stringf(100, "taxa: %.2f", posto.taxa);
  
      postos[i] = linha;
    }
    int largura = obterLargura();
  
    while (1) {
      criarTabelaMultilinha(postos, obterPostosTamanho(), tamanhos,
                            largura > 170   ? 4
                            : largura > 100 ? 2
                                            : 1);
      int opcao;
      printf("digite 0 para sair ou o numero de um posto para editar: ");
      scanf("%d", &opcao);
  
      if (opcao < 0 || opcao > obterPostosTamanho()) {
        mostrarErro("opcao invalida\n");
        continue;
      }
  
      if (opcao == 0) {
        break;
      }
      opcao--;
      limpar();
      editarPosto(&obterPostos()[opcao]);
      inserirPostoMenu();
    }
  }
  else {
    centralizar("nenhum posto registrado", ' ');
    pausar();
  }
}