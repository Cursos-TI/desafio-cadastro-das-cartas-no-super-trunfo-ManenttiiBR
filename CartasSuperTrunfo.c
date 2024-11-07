#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Definindo a estrutura da carta
typedef struct {
    char nome[50];
    char estado[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    int codigo;
} Carta;

// Função para inicializar cartas de exemplo
void inicializarCartas(Carta cartas[]) {
    strcpy(cartas[0].nome, "São Paulo");
    strcpy(cartas[0].estado, "SP");
    cartas[0].populacao = 12300000;
    cartas[0].area = 1521.11;
    cartas[0].pib = 700000;
    cartas[0].pontosTuristicos = 30;
    cartas[0].codigo = 1;

    strcpy(cartas[1].nome, "Rio de Janeiro");
    strcpy(cartas[1].estado, "RJ");
    cartas[1].populacao = 6748000;
    cartas[1].area = 1182.3;
    cartas[1].pib = 400000;
    cartas[1].pontosTuristicos = 25;
    cartas[1].codigo = 2;

    // Adicione mais cartas aqui conforme necessário
}

// Função para escolher uma carta aleatória
Carta escolherCarta(Carta cartas[], int n) {
    int indice = rand() % n;
    return cartas[indice];
}

// Função para mostrar uma carta
void mostrarCarta(Carta carta) {
    printf("\nCarta: %s (%s)\n", carta.nome, carta.estado);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

// Função para comparar os atributos das cartas
int compararCartas(Carta carta1, Carta carta2, int atributo) {
    switch (atributo) {
        case 1:
            return carta1.populacao - carta2.populacao;
        case 2:
            return (int)(carta1.area - carta2.area);
        case 3:
            return (int)(carta1.pib - carta2.pib);
        case 4:
            return carta1.pontosTuristicos - carta2.pontosTuristicos;
        default:
            return 0;
    }
}

int main() {
    srand(time(NULL));

    // Definindo o baralho de cartas
    Carta cartas[10];
    inicializarCartas(cartas);

    // Escolher cartas para dois jogadores
    Carta cartaJogador1 = escolherCarta(cartas, 2);
    Carta cartaJogador2 = escolherCarta(cartas, 2);

    printf("Jogador 1, sua carta:");
    mostrarCarta(cartaJogador1);

    printf("\nJogador 2, sua carta:");
    mostrarCarta(cartaJogador2);

    int atributoEscolhido;
    printf("\nEscolha o atributo para comparar:\n1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n");
    printf("Digite o número do atributo: ");
    scanf("%d", &atributoEscolhido);

    int resultado = compararCartas(cartaJogador1, cartaJogador2, atributoEscolhido);

    printf("\nResultado: ");
    if (resultado > 0) {
        printf("Jogador 1 venceu!\n");
    } else if (resultado < 0) {
        printf("Jogador 2 venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}
