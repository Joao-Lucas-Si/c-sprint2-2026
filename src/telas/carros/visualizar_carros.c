#include "../../../utils/utils.h"
#include "../../data.h"
#include "inserir.h"
#include <stdio.h>
#include <stdlib.h>

void visualizarCarros() {
  ArquivoResultado carro1 = lerLinhaALinha("assets/ascii/carros/carro_1.txt");
  ArquivoResultado carro2 = lerLinhaALinha("assets/ascii/carros/carro_2.txt");
  ArquivoResultado carro3 = lerLinhaALinha("assets/ascii/carros/carro_3.txt");

  obterLargura();

  // ativarAntes(antes);
  // ativarDepois(depois);
  // Any a[0];
  // centralizarVertical(mostrarLogo, 8, a);
  // esperar(1000);
  // limpar();
  // mostrarIntegrantes();
  // esperar(1000);
  // limpar();
  // struct CarroTextos tabela;

  if (obterCarrosTamanho()>0) {

    String *textos[obterCarrosTamanho()];
    int tamanhos[obterCarrosTamanho()];
    
    for (int i = 0; i < obterCarrosTamanho(); i++) {
      Carro carro = obterCarros()[i];
      tamanhos[i] = carro.asciiTamanho + 3;
      textos[i] = malloc((tamanhos[i]) * sizeof(String));
      textos[i][0] = stringf(100, "%d. %s", i+1, carro.nome);
      copiarEm(textos[i], carro.ascii, 1, carro.asciiTamanho);
  
      textos[i][carro.asciiTamanho + 1] = stringf(
          100, "energia: %2.f/%.2f", carro.energiaAtual, carro.capacidade);
      textos[i][carro.asciiTamanho +2] = stringf(100, "dividas: %.2f R$", carro.dividas);
    }
  
    criarTabelaMultilinha(textos, len(textos), tamanhos, 2);
    while (1) {
  
      int escolha = 0;
      printf("digite 0 para sair ou o numero de algum carro para editar: ");
      scanf("%d", &escolha);
  
      if (escolha > -1 && escolha <= obterCarrosTamanho()) {
        limpar();
          if (escolha == 0) {
              break;
          }
          escolha--;
          editar(&obterCarros()[escolha]);
          inserir();
          break;
      }
      mostrarErro("opcao invalida");
    }
  } else {
    centralizar("nenhum carro registrado", ' ');
    pausar();
  }
}