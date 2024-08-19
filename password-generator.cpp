#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void gerarSenha(int comprimento, int incluirMaiusculas, int incluirMinusculas, int incluirNumeros, int incluirEspeciais) {
   const char caracteresMaiusculos[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
   const char caracteresMinusculos[] = "abcdefghijklmnopqrstuvwxyz";
   const char caracteresNumeros[] = "0123456789";
   const char caracteresEspeciais[] = "!@#$%^&*()";

   char caracteresPermitidos[256] = "";

   if (incluirMaiusculas) {
      strcat(caracteresPermitidos, caracteresMaiusculos);
   }
   if (incluirMinusculas) {
      strcat(caracteresPermitidos, caracteresMinusculos);
   }
   if (incluirNumeros) {
      strcat(caracteresPermitidos, caracteresNumeros);
   }
   if (incluirEspeciais) {
      strcat(caracteresPermitidos, caracteresEspeciais);
   }

   srand(time(0));

   FILE *arquivo;
   arquivo = fopen("senha.txt", "w");

   if (arquivo == NULL) {
      printf("Erro ao abrir o arquivo.");
      exit(1);
   }

   char senha[comprimento + 1];

   for (int i = 0; i < comprimento; i++) {
      int index = rand() % strlen(caracteresPermitidos);
      senha[i] = caracteresPermitidos[index];
   }
   senha[comprimento] = '\0';

   fprintf(arquivo, "%s\n", senha);

   fclose(arquivo);

   printf("Senha gerada e salva em \"senha.txt\".\n");
}

int main() {
   int comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirEspeciais;

   printf("Bem-vindo ao Gerador de Senhas!\n");

   printf("Digite o comprimento da senha: ");
   scanf("%d", &comprimento);

   printf("Incluir letras maiusculas? (1 - Sim / 0 - Nao): ");
   scanf("%d", &incluirMaiusculas);

   printf("Incluir letras minusculas? (1 - Sim / 0 - Nao): ");
   scanf("%d", &incluirMinusculas);

   printf("Incluir numeros? (1 - Sim / 0 - Nao): ");
   scanf("%d", &incluirNumeros);

   printf("Incluir caracteres especiais? (1 - Sim / 0 - Nao): ");
   scanf("%d", &incluirEspeciais);

   gerarSenha(comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirEspeciais);

   return 0;
}