#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
char data[][30] = {"fichier", "menu", "dossier", "fenetre", "reseau", "boucle", "Ordinateur", "Clavier", "smartphone", "programmation", "javascript", "tunisie"};
struct diff
{
    int binf;
    int bsup;
};
struct diff D[3] = {{2, 6}, {7, 10}, {11, 30}};
char *ChoisirUnMot(int diff)
{
    int indice;
    printf("Selection d'un  mot aleatoire de niveau %d encours ...\n",diff);

    do
    {
        srand(time(NULL));
        indice = rand() % (12);

    }
    while ((strlen(data[indice]) < D[diff - 1].binf) || (strlen(data[indice]) > D[diff - 1].bsup));
    printf("OK\n");
    return data[indice];
}
void jeux(int diff)
{
    char c;
    int nb=8,existe=0,i;
    char *mot = ChoisirUnMot(diff);
    // commenter la ligne suivante

    printf("Le mot à deviner est %s\n", mot);

    char *ch=(char*) malloc(sizeof(mot));
    for (int i = 0; i < strlen(mot); i++)
    {
        ch[i] = '*';
    }

    printf("\n");


    do
    {
        printf("%s\n", ch);

        printf("%d Essais restants \nDonner une lettre\n",nb);
        scanf(" %c",&c);
        existe=0;
        for (i = 0; i < strlen(mot); i++)
        {

            if (mot[i] == c)
            {
                existe=1;
                ch[i] = c;
            }
        }

        if(!existe)
        {
            nb--;
        }




    }
    while  ((nb) && (strcmp(ch,mot) ));
    if(!nb)
    {
        printf("Vous avez perdu!\n le mot est %s",mot);
    }
    else
    {
        printf("Vous avez gagné!\n");
    }
}
void menu()
{
    int v;
    printf("1-Jouer\n2-A propos\n3-Quitter\n");
    do
    {
        printf("Choix:");
        scanf("%d",&v);
    }
    while ((v<1)||(v>3));
    if(v==1)
    {
        printf("1-Niveau1\n2-Niveau2\n3-Niveau3\n");
        do
        {
            printf("Niveau:");
            scanf("%d",&v);
        }
        while ((v<1)||(v>3));
        jeux(v);
        printf("\n");

    }
    else if(v==2)
    {
        // noublez pas de changer le texte de a propos par votre texte

        printf("Cette solution est developpé par   JABALLAH.MOURAD De La TUNISIE\nVive La TUNISIE ....\n");
    }
    else
    {
        return;
    }
    menu();

}
int main()
{

    menu();

    return 0;
}
