#include <stdio.h>
#include <stdlib.h>
//Recursive function to print binary into file
void decimalToBinary(int n, FILE *fp){
    if(n>1){
        decimalToBinary(n/2, fp);
    }
    fprintf(fp, "%d", n%2);
}
int main(int argc, char *argv[]){
    FILE *fin, *fout;
    int n, num, count = 0;
    if(argc != 4){
        printf("Usage %s <n> <inputfile> <outputfile>\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);
    fin = fopen(argv[2], "r");
    if(fin == NULL){
        printf("cannot open input file.\n");
        return 1;
    }
    fout = fopen(argv[3], "w");
    if(fout == NULL){
        printf("Cannot create output file.\n");
        fclose(fin);
        return 1;
    }
    while (count < n && fscanf(fin, "%d", &num) == 1){
        fprintf(fout, "The binary equivalent of %d is ", num);
        if (num == 0){
            fprintf(fout, "0");
        } else{
            decimalToBinary(num, fout);
        }
        fprintf(fout, "\n");
        count++;
    }
    fclose(fin); fclose(fout);
    fout=fopen(argv[3], "r");
    printf("Contents of output file:\n\n"); char ch;
    while ((ch = fgetc(fout)) != EOF){
        putchar(ch);
    }
    fclose(fout);
    return 0;
}





