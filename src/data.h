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
  int emRecarga;

} Carro;

typedef struct {
  char nome[100];
  int capacidade;
  int maxVeiculos;
  // int energiaPorHora;
  int veiculosAtuais;
} Posto;

typedef struct {
  int carroId;
  int energia;
  int carregado;
  int horario;
  int dia;
  int postoId;
  int concluido;
  int notificado;
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

void salvar() ;

int obterCarrosTamanho();
Carro* obterCarros();
Carro obterCarro(int);
int obterPostosTamanho();
Posto* obterPostos();
Posto obterPosto(int);
void adicionarCarro(Carro);
void adicionarPosto(Posto);
void adicionarRecarga(Recarga);
Recarga* obterRecargas();
int obterRecargasTamanho();
int obterHoras();
int obterDias();
void passarHoras(int);

#endif