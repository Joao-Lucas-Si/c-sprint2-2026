#include "data.h"
#include "../utils/utils.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
Data data;

String dataSimplesCaminho = "assets/db/data-simples.bin";
String carrosCaminho = "assets/db/carros.bin";
String postosCaminho = "assets/db/postos.bin";
String recargasCaminho = "assets/db/recargas.bin";

void iniciarBanco() {
  if (arquivoExiste(dataSimplesCaminho)) {
    lerArquivoUnico(&data, Data, dataSimplesCaminho);
    data.carros = malloc(data.carrosTamanho * sizeof(Carro));
    ler_arquivo(data.carros, Carro, carrosCaminho);
    data.postos = malloc(data.postosTamanho * sizeof(Posto));
    ler_arquivo(data.postos, Posto, postosCaminho);
    data.recargas = malloc(data.recargaTamanho * sizeof(Recarga));
    ler_arquivo(data.recargas, Recarga, recargasCaminho);

  } else {
    data.carrosTamanho = 0;
    data.carros = malloc(sizeof(Carro));
    data.horas = 12;
    data.postosTamanho = 0;
    
    data.recargaTamanho = 0;
    data.recargas = malloc(sizeof(Recarga));
    data.postos = malloc(sizeof(Posto));
  }

  for (int i = 0; i < data.carrosTamanho; i++) {
    if (data.carros[i].modelo == 0) {
      data.carros[i].modelo = 1;
    }
    debug(data.carros[i].modelo);
    ArquivoResultado arquivo = lerLinhaALinha(stringf(
        100, "assets/ascii/carros/carro_%d.txt", data.carros[i].modelo));
    data.carros[i].asciiTamanho = arquivo.linhas;
    data.carros[i].ascii = arquivo.conteudo;
  }
}

void salvar() {
  escreverArquivoUnico(&data, Data, dataSimplesCaminho);
  escreverArquivoTamanho(data.carros, data.carrosTamanho, Carro, carrosCaminho);
  escreverArquivoTamanho(data.postos, data.postosTamanho, Posto, postosCaminho);
  escreverArquivoTamanho(data.recargas, data.recargaTamanho, Recarga,
                         recargasCaminho);
}

int obterHoras() { return data.horas; }

int obterDias() { return data.dias; }

Carro *obterCarros() { return data.carros; }

Carro obterCarro(int id) { return data.carros[id]; }

int obterCarrosTamanho() { return data.carrosTamanho; }

Posto *obterPostos() { return data.postos; }

Posto obterPosto(int id) { return data.postos[id]; }

Recarga *obterRecargas() { return data.recargas; }

int obterRecargasTamanho() { return data.recargaTamanho; }

int obterPostosTamanho() { return data.postosTamanho; }

void adicionarCarro(Carro carro) {
  if (data.semCarros) {
    data.carros[0] = carro;
    data.semCarros = 0;
  } else {
    data.carros =
        realloc(data.carros, (data.carrosTamanho + 1) * sizeof(Carro));
    data.carros[data.carrosTamanho] = carro;
  }
  data.carrosTamanho++;
  salvar();
}

void adicionarPosto(Posto posto) {
  if (data.semPostos) {
    data.postos[0] = posto;
    data.semPostos = 0;
  } else {
    data.postos =
        realloc(data.postos, (data.postosTamanho + 1) * sizeof(Posto));
    data.postos[data.postosTamanho] = posto;
  }
  data.postosTamanho++;
  salvar();
}

void adicionarRecarga(Recarga recarga) {
  if (data.semRecargas) {
    data.recargas[0] = recarga;
    data.semRecargas = 0;
  } else {
    data.recargas =
        realloc(data.recargas, (data.recargaTamanho + 1) * sizeof(Recarga));
    data.recargas[data.recargaTamanho] = recarga;
  }
  Posto *posto = &obterPostos()[recarga.postoId];
  Carro *carro = &obterCarros()[recarga.carroId];
  posto->veiculosAtuais++;
  carro->dividas = calcularCobranca(recarga);
  data.recargaTamanho++;
  salvar();
}

void passarHoras(int horas) {
  data.horas = (data.horas + horas);
  if (data.horas >= 24) {
    data.dias += data.horas / 24;
    data.horas %= 24;
  }

  for (int i = 0; i < obterRecargasTamanho(); i++) {
    Recarga *recarga = &obterRecargas()[i];
    if (!recarga->concluido) {

      Posto *posto = &obterPostos()[recarga->postoId];
      Carro *carro = &obterCarros()[recarga->carroId];

      int capacidade = posto->capacidade;

      if (posto->maxVeiculos > 3 && posto->veiculosAtuais == posto->maxVeiculos) {
        capacidade *= 0.8;
      }
      int total = horas * capacidade;
      if (
          (recarga->carregado + total) > recarga->energia) {
        int resto = (recarga->carregado + total) % recarga->energia;

        carro->energiaAtual -= recarga->carregado;
        
        carro->energiaAtual += recarga->energia;
        recarga->carregado = recarga->energia;
      } else {
        carro->energiaAtual += total;
        recarga->carregado += total;
      }

      if (carro->energiaAtual > carro->capacidade) {
        carro->energiaAtual = carro->capacidade;
      }

      if (recarga->carregado == recarga->energia) {
        carro->emRecarga = 0;
        recarga->concluido = 1;
        recarga->notificado = 0;
        posto->veiculosAtuais--;
      }
    }
  }
  salvar();
}