#include "data.h"
#include "../utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
Data data;

String dataSimplesCaminho = "assets/db/data-simples.bin";
String carrosCaminho = "assets/db/carros.bin";
String postosCaminho = "assets/db/postos.bin";

void iniciarBanco() {
  if (arquivoExiste(dataSimplesCaminho)) {
    lerArquivoUnico(&data, Data, dataSimplesCaminho);
    data.carros = malloc(data.carrosTamanho * sizeof(Carro));
    ler_arquivo(data.carros, Carro, carrosCaminho);
    data.postos = malloc(data.postosTamanho * sizeof(Posto));
    ler_arquivo(data.postos, Posto, postosCaminho);
  } else {
    data.carrosTamanho = 0;
    data.carros = malloc(sizeof(Carro));
    data.horas = 12;
  }

  for (int i = 0; i < data.carrosTamanho; i++) {
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
}

int obterHoras() { return data.horas; }

Carro *obterCarros() { return data.carros; }

int obterCarrosTamanho() { return data.carrosTamanho; }

Posto *obterPostos() { return data.postos; }

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

void passarHoras(int horas) { 
  data.horas = (data.horas + horas) ;
  if (data.horas >= 24) {
    data.dias += data.horas / 24;
    data.horas %= 24;
  }
}