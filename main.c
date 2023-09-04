#include <stdio.h>
#include <string.h>

FILE  *ListaDeAlunos;


void startFile(){
    ListaDeAlunos = fopen("listaDeAlunos.txt","w");
    fclose(ListaDeAlunos);
}

void writeOnFile(char *message){
    ListaDeAlunos = fopen("listaDeAlunos.txt","a");
    fprintf(ListaDeAlunos,"%s\n",message);
    fclose(ListaDeAlunos);
}



int main() {
        startFile();
        char palavra[] = "2,2,2,2,bosta,50";

    char palavra2[] = "2,2,2,2,bosta,50";
    writeOnFile(palavra);

    writeOnFile(palavra2);

}
