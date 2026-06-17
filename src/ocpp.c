#include <stdio.h>
void mensagemHeartbeat() {
    printf("[OCPP:HeartBeat]: enviando sinalizacao de atividade ao sistema central\n");
}

void mensagemBoot() {
    printf("[OCPP:BootMessage]: novo posto detectado, estabelecendo comunicacao via WebSocket com o servidor central...\n");
}

void mensagemStartTransaction() {
    printf("[OCPP:StartTransaction]: nova recarga iniciada, submetendo json de nova transacao ao sistema central...\n");
}

void mensagemMeterValue() {
    printf("[OCPP:MeterValue]: enviado dados sobre recargas ativas ao sistema central...\n");
}

void mensagemStopTransation() {
    printf("[OCPP:StopTransaction]: recarga finalizada, sinalizando ao servidor central...\n");
}