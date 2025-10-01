#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int choix;
typedef struct
{
    int idClient;
    char nom[30];
    char prenom[30];
    char email[30];
    float solde;
} Client;
Client client1;
int createdProfile = 0;

typedef struct
{
    int idProduit;
    char nom[50];
    char categorie[50];
    char description[100];
    float prix;
    int stock;
} Produit;
Produit produit[100];
int nbrProduit = 0;
int idProduit = 1;

// prototype.......................................................................................................

// 1
void menu();
void menuProfileClient();
void creerProfile();
void modifierProfile();
void AfficherProfile();

// 2
void menuSoldeVirtuel();
void cnsulterSold();
void depotArgent();
void verificationAuto();
// 3

void catalogueProduits();
void AjoutProduit();
void afficherCatalogue();
void rechercherProduit();
// void processusAchat();
// void menuRecherche();
// void menuStatistique();

int nbrProduits = 0;

// fonction main ...............................................................................................
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
    printf("1-Gestion du profil client \n");
    printf("2-Gestion du solde virtuel \n");
    printf("3-Catalogue des Produits\n");
    printf("4-Effectuer un achat \n");
    printf("5-Mes statistiques\n");
    printf("6- Quitter l'application\n");

    do
    {
        printf("Entrer un choix: ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 6);
    switch (choix)
    {
    case 1:
        menuProfileClient();
        break;
    case 2:
        menuSoldeVirtuel();
    case 3:
        catalogueProduits();
    case 4:
        // processusAchat();

    case 5:
        // menuStatistique();
    case 6:
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
    printf("1-Creer un profil\n");
    printf("2-Modifier un profil \n");
    printf("3-Consulter un profil\n");
    printf("4-Retour a menu principal \n");

    do
    {
        printf("Entrer un choix : ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 4);
    switch (choix)
    {
    case 1:
        creerProfile();
        break;
    case 2:
        modifierProfile();
        break;

    case 3:
        AfficherProfile();
        break;

    case 4:
        menu();
        break;
    default:
        printf("Choix invalide!\n");
    }
    getchar();
    getchar();
    menu();
}

// menu de Gestion du Solde Virtuel ..............................................................................................
void menuSoldeVirtuel()
{

    printf("======================================= Menu de Solde Virtuel =================================================\n");
    do
    {

        int choix;
        printf("1-Consulter le solde:\n");
        printf("2-Depot d'argent\n");
        printf("3-Verification automatique\n");
        printf("4-Quiter\n");
        printf("Entrer un choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            cnsulterSold();
        case 2:
            depotArgent();

        case 3:
            verificationAuto();
        case 4:
            exit(0);
        default:
            printf("Choix invalide!\n");
        }
    } while (choix != 5);
}
// Catalogue des Produits..............................................................................................
void catalogueProduits()
{

    printf("======================================= Catalogue des Produits  =================================================\n");
    printf("1-Affichager catalogue \n");
    printf("2-Recherche produits\n");
    printf("3-Tri des produits\n");
    printf("4-Details produit \n");

    printf("5-Quiter\n");

    int choix;
    do
    {
        printf("Entrer un choix:  ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 5);
    switch (choix)
    {
    case 1:
        afficherCatalogue();
    case 2:
        rechercherProduit();

    case 3:
        // triProduit();
    case 4:
        // detailsProduit();

    case 5:
        exit(0);
    default:
        printf("Choix invalide!\n");
    }
} /*
 // Processus d'Achat..............................................................................................
 void processuAchat()
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
        printf("Entrer un choix ");
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
 }*/
// fonction qui creer un  client1............................................................................
void creerProfile()
{
    client1.idClient = 1;
    printf("entrer le nom :");
    scanf("%s", client1.nom);
    printf("entrer le prenom :");
    scanf("%s", client1.prenom);
    client1.solde = 0.0;
    createdProfile = 1;
    getchar();
    getchar();
    menuProfileClient();
}
// fonction pour afficher un clien1.............................................................................

void AfficherProfile()
{
    char email[70];
    sprintf(email, "%s.%s@client.com", client1.prenom, client1.nom);

    printf("===== Informations Client =====\n");
    printf("id Client : %d || Nom : %s || Prenom: %s || Email : %s || Solde: %.2f MAD\n",
           client1.idClient, client1.nom, client1.prenom, email, client1.solde);
    getchar();
    getchar();
    menuProfileClient();
}

// fonction pour modifier le prodfile de client ...............................................................
void modifierProfile()
{
    int choix;
    char nvNom[30];
    char nvPrenom[30];

    printf("1-modifier le nom \n");
    printf("2-modifier le prenom \n");

    do
    {
        printf("Entrer un  choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n')
            ;

    } while (choix < 1 || choix > 2);
    getchar();
    switch (choix)
    {
    case 1:

        printf("entrer le nouveau nom ");
        scanf("%s", nvNom);
        strcpy(client1.nom, nvNom);
        break;
    case 2:

        printf("entrer le nouveau prenom ");
        scanf("%s", nvPrenom);
        strcpy(client1.prenom, nvPrenom);
        break;
    default:
        printf("error");
        break;
    }
    menuProfileClient();
}
// fonction consulter sold .................................................................................
void cnsulterSold()
{
    if (createdProfile == 0)
    {
        printf("il n'y a pas de profile veuillez creer un profile");
    }
    else
    {
        printf("le sold est : %.2f\n", client1.solde);
    }
}
// fonction depot dargent  .................................................................................
void depotArgent()
{
    int montant;
    printf("entrer un montant: ");
    scanf("%d", &montant);
    if (montant > 0)
    {
        client1.solde += montant;
    }
    else
    {
        printf("error");
    }
    printf("\nAppuyez sur Entree pour revenir au menu...");
    getchar();
    getchar();
    menuSoldeVirtuel();
}
void verificationAuto()
{
    int prixProd;
    printf("entrer le prix de produit que tu veux le acheter ");
    scanf("%d", &prixProd);
    if (prixProd <= client1.solde)
    {
        client1.solde = client1.solde - prixProd;
        printf("achat effectue avec succes");
    }
    else
    {
        printf("Solde insuffisant");
    }
    getchar();
    getchar();
    menuSoldeVirtuel();
}
void afficherCatalogue()
{

    // produit1
    produit[nbrProduit].idProduit = idProduit++;
    strcpy(produit[nbrProduit].nom, "Ordinateur portable");
    strcpy(produit[nbrProduit].categorie, "Electronique");
    strcpy(produit[nbrProduit].description, "Un ordinateur portable HP 16Go RAM 512Go SSD");
    produit[nbrProduit].prix = 8000;
    produit[nbrProduit].stock = 20;
    nbrProduit++;
    // produit2
    produit[nbrProduit].idProduit = idProduit++;
    strcpy(produit[nbrProduit].nom, "Smartphone");
    strcpy(produit[nbrProduit].categorie, "Electronique");
    strcpy(produit[nbrProduit].description, "Un smartphone Samsung Galaxy S21");
    produit[nbrProduit].prix = 6000;
    produit[nbrProduit].stock = 15;
    nbrProduit++;
    // produit3
    produit[nbrProduit].idProduit = idProduit++;
    strcpy(produit[nbrProduit].nom, "Casque Audio");
    strcpy(produit[nbrProduit].categorie, "Accessoires");
    strcpy(produit[nbrProduit].description, "Casque sans fil Bluetooth");
    produit[nbrProduit].prix = 350;
    produit[nbrProduit].stock = 30;
    nbrProduit++;
    // Produit 4
    produit[nbrProduit].idProduit = idProduit++;
    strcpy(produit[nbrProduit].nom, "iPhone 15");
    strcpy(produit[nbrProduit].categorie, "Electronique");
    strcpy(produit[nbrProduit].description, "Dernier modele iPhone 15 Pro Max, 256GB");
    produit[nbrProduit].prix = 12000;
    produit[nbrProduit].stock = 10;
    nbrProduit++;
    // afficher les produits ..................................................................................
    for (int i = 0; i < nbrProduit; i++)
    {
        printf("Produit : %d || le nom: %s ||  Categorie: %s || Prix: %.2fMAD|| Description: %s  ||  Stock :%d\n",
               produit[i].idProduit, produit[i].nom, produit[i].categorie, produit[i].prix, produit[i].description, produit[i].stock);
    }
}

// fonction Rechercher produit ....................................................................................

void rechercherProduit()
{ int choix;
    int i;
    char nomProduit[50];
    char categorieProduit[50];
     int nProduits;

    printf("1-recherche par nom \n");
    printf("2-recherche par categorie \n");

    do
    {
        printf("Entrer un  choix: ");
        scanf("%d", &choix);
        while (getchar() != '\n')
            ;

    } while (choix < 1 || choix > 2);
    getchar();
    switch (choix)
    {
    case 1:

        printf("Rechercher par nom ");
        scanf("%s", nomProduit);
        for (int i = 0; i < nProduits; i++) {
        if (strcasecmp(nomProduit, produit[i].nom)== 0)
        {
            printf("les resultat de recherche est :%s", produit[i].nom );
        }
}
        break;
    case 2:

        printf("Rechercher par categorie ");
         for (int i = 0; i < nProduits; i++) {
       if(strcmp(categorieProduit, produit[i].categorie)==0){
         printf("les resultat de recherche est :%s", produit[i].categorie);
       }
          }
        break;
    default:
        printf("error");
        break;
    }
     catalogueProduits();
}