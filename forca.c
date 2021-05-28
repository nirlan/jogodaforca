#include <stdio.h>
#include <string.h>
#include <locale.h>

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

int jachutou(char letra, int tentativas, char chutes[26]) {
    int achou = 0;

    for(int j = 0; j < tentativas; j++) {
    
        if(chutes[j] == letra) {

            achou = 1;
            break;
        }
    }

    return achou;
}

void desenhaforca(char palavrasecreta[20], char chutes[26], int tentativas) {
    
    printf("Voc� j� deu %d chutes\n", tentativas);

    for(int i = 0; i < strlen(palavrasecreta); i++) {

        if(jachutou(palavrasecreta[i], tentativas, chutes)) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }        
    printf("\n");

}

void escolhepalavra(char palavrasecreta[20]) {
    sprintf(palavrasecreta, "MELANCIA");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    char palavrasecreta[20];

    int acertou = 0;
    int enforcou = 0;

    char chutes[26];    
    int tentativas = 0;

    escolhepalavra(palavrasecreta);
    abertura();
    
    do {
        
        desenhaforca(palavrasecreta, chutes, tentativas);
        chuta(chutes, &tentativas);        

    } while(!acertou && !enforcou);
}