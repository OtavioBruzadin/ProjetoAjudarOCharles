#include <stdio.h>
#include <string.h>

FILE  *ListaDeAlunos;
FILE *ListaOrdenadaAlunos;
char infoAluno[100];

void startFile(){
    ListaDeAlunos = fopen("listaDeAlunosOrdenada.txt","w");
    fclose(ListaDeAlunos);
}



void writeOnFile(int semestre,  char sala,char periodo, char *nome, char *disciplina, float media ){
    ListaDeAlunos = fopen("listaOrdenadaDeAlunos.txt","a");
    fprintf(ListaDeAlunos,"%c,%c,%s,%s,%f\n",sala,periodo,nome,disciplina,media);
    fclose(ListaDeAlunos);
}

void searchDataInFile(){
    char aluno[90];
    ListaDeAlunos = fopen("listaDeAlunos.txt","r");
    while (fscanf(ListaDeAlunos, "%s",aluno) != EOF)
        strcpy(infoAluno,aluno);
        printf("%s",aluno);
    fclose(ListaDeAlunos);
}



int main() {
startFile();




    searchDataInFile();

}
