#ifndef DataFH
#define DataFH
#include "../utils/tipos.h"

typedef struct CarroStruct {
  int id;
  char nome[100];
  int modelo;
  String *ascii;
  int asciiTamanho;
  float capacidade;
  float energiaAtual;

} Carro;

typedef struct {
  char nome[100];
  int maximo;
  int capacidade;
  int maxVeiculos;
  int energiaPorDia;

} Posto;

typedef struct {
  int carroId;
  Carro* carro;
  int energia;

  int horario;
  int dia;
  int postoId;
  Posto* posto;
} Recarga;

typedef enum {
  RECARGA_INICIADA,
  RECARGA_FINALIZADA,
  CARRO_CRIADO,
  POSTO_CRIADO,

} RegistroTipo;

typedef struct {
  int hora;
  int dia;
  RegistroTipo tipo;

} Registro;

typedef struct {
  Carro *carros;
  int semCarros;
  int carrosTamanho;
  int horas;
  int dias;
  Posto* postos;
  int postosTamanho;
  int semPostos;

  Recarga* recargas;
  int recargaTamanho;
  int semRecargas;
} Data;

void iniciarBanco();

int obterCarrosTamanho();
Carro* obterCarros();
int obterPostosTamanho();
Posto* obterPostos();
void adicionarCarro(Carro);
void adicionarPosto(Posto);
void adicionarRecarga(Recarga);
Posto* obterRecargas();
int obterRecargasTamanho();
int obterHoras();
void passarHoras(int);

#endif