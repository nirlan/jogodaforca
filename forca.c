#include <stdio.h>
#include <string.h>
#include <locale.h>
#include "forca.h"

char palavrasecreta[20];
char chutes[26];
int chutesdados = 0;

void abertura() {
    printf("***********************\n");
    printf("*    Jogo de Forca    *\n");
    printf("***********************\n\n");
}

void chuta() {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[chutesdados] = chute;
    chutesdados++;
}

void desenhaforca() {

    printf("Voc� j� deu %d chutes\n", chutesdados);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");

}

void escolhepalavra() {
    sprintf(palavrasecreta, "MELANCIA");
}

int enforcou() {

    int erros = 0;

    for(int i = 0; i < chutesdados; i++) {
        int existe = 0;

        for(int j = 0; j < strlen(palavrasecreta); j++) {
            if(chutes[i] == palavrasecreta[j]) {

                existe = 1;
                break;
            }
        }

        if(!existe) erros++;

    }

    return erros >= 5;
}

int acertou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }

    return 1;
}

int jachutou(char letra) {
    int achou = 0;

    for(int j = 0; j < chutesdados; j++) {

        if(chutes[j] == letra) {

            achou = 1;
            break;
        }
    }

    return achou;
}


int main() {
    setlocale(LC_ALL, "Portuguese");

    escolhepalavra();
    abertura();

    do {

        desenhaforca();
        chuta();

    } while(!acertou() && !enforcou());
}