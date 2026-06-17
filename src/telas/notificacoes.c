#include "../data.h"
#include "../../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>

void visualizarMudancas() {
    int tamanho = 0;
    for (int i = 0; i < obterRecargasTamanho(); i++) {
        Recarga* recarga = &obterRecargas()[i];
        if (recarga->concluido && !recarga->notificado) {
            
            Carro carro = obterCarros()[recarga->carroId];
            centralizar(stringf(100, "carro %s terminou sua recarga",carro.nome), ' ');
            recarga->notificado = 1;
            tamanho++;
        }
    }

    if (tamanho > 0) {
        // criarTitulo("");
        for (int i = 0; i < tamanho; i++) {
           
        }

        salvar();
        pausar();
    }
}