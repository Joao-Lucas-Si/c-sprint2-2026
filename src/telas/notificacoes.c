#include "../../utils/utils.h"
#include "../data.h"
#include "../ocpp.h"
#include <stdio.h>
#include <stdlib.h>

void visualizarMudancas() {
  int tamanho = 0;
  int ativos = 0;
  for (int i = 0; i < obterRecargasTamanho(); i++) {
    Recarga *recarga = &obterRecargas()[i];
    if (recarga->concluido && !recarga->notificado) {

      Carro carro = obterCarros()[recarga->carroId];
      centralizar(stringf(100, "carro %s terminou sua recarga", carro.nome),
                  ' ');
      recarga->notificado = 1;
      tamanho++;
    }
    if (!recarga->concluido) {
      ativos++;
    }
  }

  int pause = 0;
  if (tamanho > 0) {
    mensagemStopTransation();

    pause = 1;
  }
  if (ativos > 0) {
    mensagemMeterValue();
    pause = 1;
  }

  mensagemHeartbeat();
  salvar();

  pausar();
}