#include <stdio.h>
#include <string.h>
#include <locale.h>

char palavrasecreta[20];

void abertura() {
    printf("***********************\n");
    printf("*    Jogo de Forca    *\n");
    printf("***********************\n\n");
}

void chuta(char chutes[26], int* tentativas) {
    char chute;
    printf("Qual letra? ");
    scanf(" %c", &chute);

    chutes[(*tentativas)] = chute;
    (*tentativas)++;
}

int jachutou(char letra, int* tentativas, char chutes[26]) {
    int achou = 0;

    for(int j = 0; j < (*tentativas); j++) {
    
        if(chutes[j] == letra) {

            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca(int* tentativas, char chutes[26]) {
    
    printf("Você já deu %d chutes\n", (*tentativas));

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i], tentativas, chutes)) {
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

int main() {
    setlocale(LC_ALL, "Portuguese");

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];    
    int tentativas = 0;

    abertura();
    escolhepalavra();

    do {
        
        desenhaforca(&tentativas, chutes);
        chuta(chutes, &tentativas);        

    } while(!acertou && !enforcou);
}