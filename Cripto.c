#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{

    char ed[300];
    int i, j, tamanho_matriz, x, y, M[3][100], matriz_criptografada[3][100], chave[3][3];

    chave[0][0]=1;
    chave[0][1]=2;
    chave[0][2]=3;
    chave[1][0]=0;  //chave de criptografia.
    chave[1][1]=1;
    chave[1][2]=4;
    chave[2][0]=0;
    chave[2][1]=0;
    chave[2][2]=1;

    fflush(stdin);
    fgets(ed, 300, stdin); //recebe a mensagem.
    printf("\n\nMensagem Criptografada:\n\n");

    tamanho_matriz = strlen(ed) - 1; //conta os caracteres digitados para formatar a matriz.

    if(tamanho_matriz%3==1)
    {
        //adiciona um espaço para formatar a matriz.

        ed[tamanho_matriz]=' ';
        tamanho_matriz++;


    }
    if(tamanho_matriz%3==2)
    {
        //adiciona dois espaços para formatar a matriz.

        ed[tamanho_matriz]=' ';
        tamanho_matriz++;
        ed[tamanho_matriz]=' ';
        tamanho_matriz++;

    }

    x=0;
    y = tamanho_matriz/3;


    //transforma as letras em numeros.
    for(i=0; i<3; i++)
    {
        for(j=0; j<y; j++)
        {
            if(ed[x]=='A') M[i][j]=1;
            if(ed[x]=='B') M[i][j]=2;
            if(ed[x]=='C') M[i][j]=3;
            if(ed[x]=='D') M[i][j]=4;
            if(ed[x]=='E') M[i][j]=5;
            if(ed[x]=='F') M[i][j]=6;
            if(ed[x]=='G') M[i][j]=7;
            if(ed[x]=='H') M[i][j]=8;
            if(ed[x]=='I') M[i][j]=9;
            if(ed[x]=='J') M[i][j]=10;
            if(ed[x]=='K') M[i][j]=11;
            if(ed[x]=='L') M[i][j]=12;
            if(ed[x]=='M') M[i][j]=13;
            if(ed[x]=='N') M[i][j]=14;
            if(ed[x]=='O') M[i][j]=15;
            if(ed[x]=='P') M[i][j]=16;
            if(ed[x]=='Q') M[i][j]=17;
            if(ed[x]=='R') M[i][j]=18;
            if(ed[x]=='S') M[i][j]=19;
            if(ed[x]=='T') M[i][j]=20;
            if(ed[x]=='U') M[i][j]=21;
            if(ed[x]=='V') M[i][j]=22;
            if(ed[x]=='W') M[i][j]=23;
            if(ed[x]=='X') M[i][j]=24;
            if(ed[x]=='Y') M[i][j]=25;
            if(ed[x]=='Z') M[i][j]=26;
            if(ed[x]=='a') M[i][j]=27;
            if(ed[x]=='b') M[i][j]=28;
            if(ed[x]=='c') M[i][j]=29;
            if(ed[x]=='d') M[i][j]=30;
            if(ed[x]=='e') M[i][j]=31;
            if(ed[x]=='f') M[i][j]=32;
            if(ed[x]=='g') M[i][j]=33;
            if(ed[x]=='h') M[i][j]=34;
            if(ed[x]=='i') M[i][j]=35;
            if(ed[x]=='j') M[i][j]=36;
            if(ed[x]=='k') M[i][j]=37;
            if(ed[x]=='l') M[i][j]=38;
            if(ed[x]=='m') M[i][j]=39;
            if(ed[x]=='n') M[i][j]=40;
            if(ed[x]=='o') M[i][j]=41;
            if(ed[x]=='p') M[i][j]=42;
            if(ed[x]=='q') M[i][j]=43;
            if(ed[x]=='r') M[i][j]=44;
            if(ed[x]=='s') M[i][j]=45;
            if(ed[x]=='t') M[i][j]=46;
            if(ed[x]=='u') M[i][j]=47;
            if(ed[x]=='v') M[i][j]=48;
            if(ed[x]=='w') M[i][j]=49;
            if(ed[x]=='x') M[i][j]=50;
            if(ed[x]=='y') M[i][j]=51;
            if(ed[x]=='z') M[i][j]=52;
            if(ed[x]=='.') M[i][j]=53;
            if(ed[x]==' ') M[i][j]=54;
            if(ed[x]=='ç') M[i][j]=55;
            if(ed[x]=='Ç') M[i][j]=56;


            x++;
        }
    }

    //criptografa a matriz.
    for(i=0; i<3; i++)
    {
        for(j=0; j<y; j++)
        {

            matriz_criptografada[i][j] = chave[i][0]*M[0][j] + chave[i][1]*M[1][j] + chave[i][2]*M[2][j];


        }
    }


    //cria um arquivo para salvar a mensagem.
    FILE *file;
    file = fopen("MensagemCripto.txt", "w");
    fclose(file);
    file = fopen("MensagemCripto.txt", "a");

    //coloca no arquivo quantos caracteres foram digitados.
    fprintf(file, "%d\n", y*3);

    for(i=0; i<3; i++)
    {
        for(j=0; j<y; j++)
        {
            //imprime a matriz na tela e escreve a matriz no arquivo.
            printf("%4d ", matriz_criptografada[i][j]);
            fprintf(file, "%4d ", matriz_criptografada[i][j]);



        }

        printf("\n");
    }
    printf("\n\n\n");

    fclose(file); //fecha o arquivo.

    system("start Descripto.exe"); //abre o programa de descriptografia.



    system("pause");
    return 0;
}
