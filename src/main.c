/* Tarefa de decifrar uma cifra
 *
 * Dica: veja em referencia/cifrador.c o codigo-fonte do programa
 * que gerou as cifras que voce precisa decifrar!
 */

#include <stdio.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];

const char senha[] = "SENHASECRETA";

char decriptacao(char c, char k) {
  char c0, k0, p;
  if (c>='A' && c<='Z') {
    c0 = c - 'A';
    k0 = k - 'A';
    p = 'A' + (c0 - k0 + ('Z'-'A'+1)) % ('Z'-'A'+1);
    return p;
  } else {
    return c;
  }
}


int main() {
  int j=0;
  int i=0;
  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  for (i=0; (i<TAM_BUFFER) && (buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n'); i++) {
    buffer_saida[i] = decriptacao(buffer_entrada[i], senha[j]);
    j++;
    if (senha[j]=='\0'){
      j=0;
    }
  }
  buffer_saida[i]='\0';

  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
