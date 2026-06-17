#include "data.h"
#include <math.h>

float calcularCobranca(Recarga recarga) {
  Posto posto = obterPostos()[recarga.postoId];
  Carro carro = obterCarros()[recarga.carroId];

  int horas = ceil((float)recarga.energia / (float)posto.capacidade);

  float valor;

  valor = recarga.energia * posto.taxa;

  if (posto.maxVeiculos > 4 && posto.veiculosAtuais > (posto.maxVeiculos * 0.7)) {
    valor *= 1.2;
  }

  return valor;
}

// int calcularTempo() {

// }