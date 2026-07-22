#include <stdio.h>
#include <stdlib.h>
// Recursive function to find GCD
int gcd(int a, int b){
    if(b==0){
        return a;
    } return gcd(b, a%b);
}
int main(int argc, char *argv[]){
    FILE *fin, *fout;
    int a, b;
    if(argc!=3){
        printf("Usage %s <inputfile> <outputfile>\n", argv[0]);
        return 1;
    }
    fin = fopen(argv[1], "r");
    if(fin==NULL){
        printf("Cant open input file.\n");
        return 1;
    }
    fout = fopen(argv[2], "w");
    if(fout == NULL){
        printf("Cant creat output file.\n");
        fclose(fin);
        return 1;
    }
    while (fscanf(fin, "%d %d", &a, &b) == 2){
        fprintf(fout, "The GCD of %d and %d is %d\n", a, b, gcd(a, b));
    }
    fclose(fin);
    fclose(fout);

    fout = fopen(argv[2], "r");
    printf("Contents of output fileL\n\n");
    char ch;
    while((ch=fgetc(fout))!= EOF){
        putchar(ch);
    }
    fclose(fout);
    return 0;
}





