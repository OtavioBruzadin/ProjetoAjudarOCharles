#include <stdio.h>
#include <string.h>

FILE  *ListaDeAlunos;
FILE *ListaAuxiliar;
FILE *ListaOrdenadaAlunos;
char fieldContent[40];

void startFile(){
    //reseta o arquivo que ira receber a lista de alunos ordenada
    ListaDeAlunos = fopen("listaDeAlunosOrdenada.txt","w");
    fclose(ListaDeAlunos);
}
void selectField(int field, char *data){
    //coloca o valor lido depois da N virgula em fieldContent
    //para acessar semestre field devera receber 0
    // para acessar turma field devera receber 1
    //para acessar periodo field devera receber 2
    // para acessar nome field devera receber 3
    // para acessar materia field devera receber 4
    // para acessar media field devera receber 5
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
    //Procura a string inteira no arquivo listaDeAlunos.txt e retorna o indice em que ela esta
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

void copyFile(){

        //Procura a string inteira no arquivo listaDeAlunos.txt e retorna o indice em que ela esta
        char linha[90];
        ListaDeAlunos = fopen("listaDeAlunos.txt", "r");
    ListaAuxiliar = fopen("listaAuxiliar.txt", "a");

    while (fscanf(ListaDeAlunos, "%s", linha) != EOF) {
            fprintf(ListaAuxiliar,"%s\n", linha);
        }
        fclose(ListaDeAlunos);


}


int main() {
startFile();
copyFile();
    selectField(5,"2,A,N,maria_rodrigues,portugues,7.3");
    printf("%s",fieldContent);
    printf("%d",searchDataInFile("2,A,N,maria_rodrigues,portugues,7.3"));
}
