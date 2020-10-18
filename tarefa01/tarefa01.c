#include <stdio.h>
#include <string.h>
#define numLinhas 6
#define numColunas 10
#define numElementos 20


struct stc{
    char linha[5];
};


int main(void)
{
    struct stc matriz[numElementos];
    int numEscolhidos[6] = {0,0,0,0,0,0};
    
    for(int i=0;i<numElementos;i++){
        char templine[5];
        scanf("%s",&templine);
        strcpy(matriz[i].linha,templine);
    }
    
    int cont=0;
    for(int i=0;i<numElementos;i++){
      //printf("i: %d, termo: %s ",i,matriz[i].linha);
      if(!strcmp(matriz[i].linha,"1")){
          //printf("- É um!");
          numEscolhidos[cont] = i+1;
          cont++;
      }
      //printf("\n");
      if((i+1)%numColunas==0){
          printf("\n");
      }
      
    }
    
    for(int i=0;i<6;i++){
    printf("%d ",numEscolhidos[i]);
    }
    
    return 0;
}