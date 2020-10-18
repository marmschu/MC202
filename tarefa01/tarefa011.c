#include <stdio.h>
#include <string.h>
#define numElementos 60

struct stc{
    char linha[5];
};


int main(void)
{
    struct stc matriz[numElementos];
    int numEscolhidos[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    
    for(int i=0;i<numElementos;i++){
        char templine[5];
        scanf("%s",&templine);
        strcpy(matriz[i].linha,templine);
    }
    int cont=0;
    for(int i=0;i<numElementos;i++){
      if(!strcmp(matriz[i].linha,"1")){
          numEscolhidos[cont] = i+1;
          cont++;
      }
    }
    
    return 0;
}