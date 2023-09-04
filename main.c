#include <stdio.h>
#include <string.h>

FILE  *ListaDeAlunos;
FILE *ListaOrdenadaAlunos;
char fieldContent[40];

void startFile(){
    ListaDeAlunos = fopen("listaDeAlunosOrdenada.txt","w");
    fclose(ListaDeAlunos);
}
void selectField(int field, char *data){

    char userData[90];

    strcpy(userData,data);

    int i = 0;

    char * token = strtok(userData, ",");

    while( i!=field ) {
        token = strtok(NULL, ",");
        i++;
    }

    strcpy(fieldContent,token); //saves token info on selectedField variable
    printf( " %s\n", fieldContent ); //selectedField

}


void writeOnFile(int semestre,  char sala,char periodo, char *nome, char *disciplina, float media ){
    ListaDeAlunos = fopen("listaOrdenadaDeAlunos.txt","a");
    fprintf(ListaDeAlunos,"%c,%c,%s,%s,%f\n",sala,periodo,nome,disciplina,media);
    fclose(ListaDeAlunos);
}

int searchDataInFile(char *data) {
    char linha[90];
    int index=0;
    ListaDeAlunos = fopen("listaDeAlunos.txt", "r");
    while (fscanf(ListaDeAlunos, "%s", linha) != EOF) {
        if (strcmp(linha, data) == 0) {
            return index;
        }
        index++;
    }
    fclose(ListaDeAlunos);
    return 0;
}



int main() {
startFile();

}
