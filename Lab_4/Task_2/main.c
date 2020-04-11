#include <stdio.h>
#include <string.h>


int main() {

    char dictName[100] = "Dictionary";
    char fileName[100] = "myFile";

    FILE *fdict;
    FILE *file;

    if(!(fdict = fopen(dictName, "r"))){
        printf("ERROR to open Dictionary file\n");
        return 2;
    }

    if(!(file = fopen(fileName, "r"))){
        printf("ERROR to open file for scanning dictionary words\n");
        return 2;
    }

    char wordDict[800000] = {'\0'};
    char ch;
    int i = 0;


    // Перенос всего словаря в массив
    while(!feof(fdict)){
        ch = (char) getc(fdict);

        if(!feof(fdict)){
            wordDict[i] = ch;
            i++;
        }
    }

    printf("\nСлова из словаря:\n%s\n", wordDict);

    // Обход каждого слова словаря по всему файлу
    char * current = strtok(wordDict, " \n,.");
    while(current){

        printf("\nКоличество вхождений слова %s: ", current);
        int num = 0;
        ch = (char) fgetc(file);
        i = 0;

        while(!feof(file)){

            char buffer[100] = {'\0'};
            i = 0;

            while((ch != ' ') && (ch != '\n' && (ch != '\0') && (!feof(file)))){
                buffer[i] = ch;

                if (!feof(file))
                    ch = (char) fgetc(file);
                i++;
            }

            ch = (char) fgetc(file);

            if (!strcmp(buffer, current)){
                num ++;
            }

        }

        printf("%i\n", num);
        rewind(file);
        current = strtok(NULL, " \n,.");
    }

    return 0;
}
