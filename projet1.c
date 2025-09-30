#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
int nbrProduits = 0;

int main()
{
    menu();
    return 0;
}
// Le Menu de l'application..................................................................................
void menu()
{

    int choix;

    printf("======================================= Menu =================================================\n");
    printf("1-Gestion du profil client\n");
    printf("2-Gestion du solde virtuel\n");
    printf("3-Catalogue des Produits\n");
    printf("4-Effectuer un achat \n");
    printf("5-Mes statistiques\n");
    printf("6- Quitter l'application\n");

    do
    {
        printf("Entrer un choix ");
        scanf("%d", &choix);
    } while (choix < 1 && choix > 7);
    switch (choix)
    {
    case 1:
        menuProfileClient();
    case 2:
        menuSoldeVirtuel();
    case 3:
        catalogueProduits();
    case 4:
        processusAchat();
    case 5:
        menuRecherche();
    case 6:
        menuStatistique();
    case 7:
        exit(0);
    default:
        printf("Choix invalide!\n");
    }
}
// menu de profile de client  ..............................................................................................
void menuProfileClient()
{

    int choix;
    printf("======================================= Menu de de Profile de client  =================================================\n");
    printf("1-Créer un profil\n");
    printf("2-Modifier un profil \n");
    printf("3-Consulter un profil\n");
    printf("4-Générer l'email\n");
    printf("5-Quitter l'application\n");

    do
    {
        printf("Entrer un choix de l'Ajout");
        scanf("%d", &choix);
    } while (choix < 1 && choix > 5);
    switch (choix)
    {
    case 1:
        creerProfile();
    case 2:
        modifierProfile();

    case 3:
        consulterProfile();
    case 4:
        consulterProfile();
    case 5:
        exit(0);
    default:
        printf("Choix invalide!\n");
    }
}
// menu de Gestion du Solde Virtuel ..............................................................................................
void menuSoldeVirtuel()
{

    printf("======================================= Menu de Gestion du Solde Virtuel =================================================\n");
    printf("1-Consulter  le solde:\n");
    printf("2-Dépôt d'argent\n");
    printf("3-Vérification automatique\n");
    printf("4-Quiter\n");

    int choix;
    do
    {
        printf("Entrer un choix de l'Affichage");
        scanf("%d", &choix);
    } while (choix < 1 && choix > 4);
    switch (choix)
    {
    case 1:
        cnsulterSold();
    case 2:
        debutArgent();

    case 3:
        verificationAuto();
    case 4:
        exit(0);
    default:
        printf("Choix invalide!\n");
    }

} // Catalogue des Produits..............................................................................................
void menuModification()
{

    printf("======================================= Catalogue des Produits  =================================================\n");
    printf("1-Affichager catalogue :\n");
    printf("2-Recherche produits\n");
    printf("3-Tri des produits\n");
    printf("4-Détails produit \n");
    printf("5-Produits prédéfinis \n");
    printf("6-Quiter\n");

    int choix;
    do
    {
        printf("Entrer un choix de Modification");
        scanf("%d", &choix);
    } while (choix < 1 && choix > 6);
    switch (choix)
    {
    case 1:
        afficherCatalogue();
    case 2:
        rechercherProduit();

    case 3:
        triProduit();
    case 4:
        detailsProduit();
    case 5:
        produitPredefinis();
    case 6:
        exit(0);
    default:
        printf("Choix invalide!\n");
    }
}
// Processus d'Achat..............................................................................................
void menuRecherche()
{

    printf("======================================= Processus d'Achat =================================================\n");
    printf("1-Sélection de produit :\n");
    printf("2-Vérifications\n");
    printf("3-Paiement\n");
    printf("4-Mise à jour \n");
    printf("5-Confirmation\n");
    printf("6-Quiter\n");

    int choix;
    do
    {
        printf("Entrer un choix de Recherche");
        scanf("%d", &choix);
    } while (choix < 1 && choix > 6);
    switch (choix)
    {
    case 1:
        selectionneProduit();
    case 2:
        verifierStockSold();
    case 3:
        Paiement();
    case 4:
        miseAjour();
    case 5:
        Configuration();

    case 6:
        exit(0);
    default:
        printf("Choix invalide!\n");
  }
}
