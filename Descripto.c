#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    int M[3][100], chave[3][3], recebe[300], i, j, matriz_criptografada[3][100];
    char ed[300];

    chave[0][0]=1;
    chave[0][1]=-2;
    chave[0][2]=5;
    chave[1][0]=0;
    chave[1][1]=1; //chave de criptografia.
    chave[1][2]=-4;
    chave[2][0]=0;
    chave[2][1]=0;
    chave[2][2]=1;


    int n=0, x=0;

    // abre o arquivo para ler a mensagem criptografada.
    FILE *file;
    file = fopen("MensagemCripto.txt", "r");

    fscanf(file, "%d", &x);
    // le o numero de caracteres da mensagem que foi salva.

    while( n<x )
    {

        fscanf(file,"%d",&recebe[n]);
        // le a mensagem criptografada.
        n++ ;
    }


    // formata uma matriz de tres linhas.
    n=(n++)/3;
    x=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {
            matriz_criptografada[i][j] = recebe[x];

            x++;
        }
    }
    x=0;


    // descriptografa a matriz.
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {

            M[i][j] = chave[i][0]*matriz_criptografada[0][j] + chave[i][1]*matriz_criptografada[1][j] + chave[i][2]*matriz_criptografada[2][j];


        }
    }

    // transforma a matriz de numeros em letras.
    x=0;
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {
            if(M[i][j]==1) ed[x]='A';
            if(M[i][j]==2) ed[x]='B';
            if(M[i][j]==3) ed[x]='C';
            if(M[i][j]==4) ed[x]='D';
            if(M[i][j]==5) ed[x]='E';
            if(M[i][j]==6) ed[x]='F';
            if(M[i][j]==7) ed[x]='G';
            if(M[i][j]==8) ed[x]='H';
            if(M[i][j]==9) ed[x]='I';
            if(M[i][j]==10) ed[x]='J';
            if(M[i][j]==11) ed[x]='K';
            if(M[i][j]==12) ed[x]='L';
            if(M[i][j]==13) ed[x]='M';
            if(M[i][j]==14) ed[x]='N';
            if(M[i][j]==15) ed[x]='O';
            if(M[i][j]==16) ed[x]='P';
            if(M[i][j]==17) ed[x]='Q';
            if(M[i][j]==18) ed[x]='R';
            if(M[i][j]==19) ed[x]='S';
            if(M[i][j]==20) ed[x]='T';
            if(M[i][j]==21) ed[x]='U';
            if(M[i][j]==22) ed[x]='V';
            if(M[i][j]==23) ed[x]='W';
            if(M[i][j]==24) ed[x]='X';
            if(M[i][j]==25) ed[x]='Y';
            if(M[i][j]==26) ed[x]='Z';
            if(M[i][j]==27) ed[x]='a';
            if(M[i][j]==28) ed[x]='b';
            if(M[i][j]==29) ed[x]='c';
            if(M[i][j]==30) ed[x]='d';
            if(M[i][j]==31) ed[x]='e';
            if(M[i][j]==32) ed[x]='f';
            if(M[i][j]==33) ed[x]='g';
            if(M[i][j]==34) ed[x]='h';
            if(M[i][j]==35) ed[x]='i';
            if(M[i][j]==36) ed[x]='j';
            if(M[i][j]==37) ed[x]='k';
            if(M[i][j]==38) ed[x]='l';
            if(M[i][j]==39) ed[x]='m';
            if(M[i][j]==40) ed[x]='n';
            if(M[i][j]==41) ed[x]='o';
            if(M[i][j]==42) ed[x]='p';
            if(M[i][j]==43) ed[x]='q';
            if(M[i][j]==44) ed[x]='r';
            if(M[i][j]==45) ed[x]='s';
            if(M[i][j]==46) ed[x]='t';
            if(M[i][j]==47) ed[x]='u';
            if(M[i][j]==48) ed[x]='v';
            if(M[i][j]==49) ed[x]='w';
            if(M[i][j]==50) ed[x]='x';
            if(M[i][j]==51) ed[x]='y';
            if(M[i][j]==52) ed[x]='z';
            if(M[i][j]==53) ed[x]='.';
            if(M[i][j]==54) ed[x]=' ';
            if(M[i][j]==55) ed[x]='ç';
            if(M[i][j]==56) ed[x]='Ç';

            x++;

        }
    }

    // imprime a matriz critografada.
    printf("Mensagem Criptografada:\n\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%3d ", matriz_criptografada[i][j]);

        }
        printf("\n");
    }


    // imprime a mensagem.
    printf("\n\nMensagem Descriptografada:\n\n");
    for(j=0; j<x; j++)
    {

        printf("%c", ed[j]);


    }
    printf("\n\n\n");



    system("pause");
    return 0;
}
