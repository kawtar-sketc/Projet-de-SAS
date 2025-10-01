#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

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

#define MAX_HIST 100
#define MAX_ACTION 200

typedef struct
{
    char action[MAX_ACTION];
} Historique;
Historique historique[MAX_HIST];
int nbrHistorique = 0;
// prototype.......................................................................................................

// 1
void menu();

void menuProfileClient();
void creerProfile();
void modifierProfile();
void AfficherProfile();

// 2
void menuSoldeVirtuel();
void consulterSolde();
void depotArgent();
void verificationAuto();

// 3

void catalogueProduits();
void AjoutProduit();
void initialiserCatalogue();
void afficherCatalogue();
void rechercherProduit();
void triProduit();
void detailsProduit();

// 4
void ProcessusAchat();
// 5
void ajouterHistorique();
void afficherHistorique();

int nbrProduits = 0;

// fonction main ...............................................................................................
int main()
{

    initialiserCatalogue();
    menu();
    ajouterHistorique("Premier action");
    ajouterHistorique("Deuxieme action");

    for (int i = 0; i < nbrHistorique; i++)
    {
        printf("%s\n", historique[i]);
    }

    return 0;
}
// Le Menu de l'application..................................................................................
void menu()
{

    int choix;

    printf("========================== Menu ========================\n");
    printf("1-Gestion du profil client \n");
    printf("2-Gestion du solde virtuel \n");
    printf("3-Catalogue des Produits\n");
    printf("4-Effectuer un achat \n");
    printf("5-Mes Historiques\n");
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
        break;
    case 3:
        catalogueProduits();
        break;
    case 4:
        ProcessusAchat();
        break;

    case 5:
        afficherHistorique();
        break;
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
    int validInput;

    printf("======================================= Menu de Profile de client =================================================\n");
    printf("1-Creer un profil\n");
    printf("2-Modifier un profil\n");
    printf("3-Consulter un profil\n");
    printf("4-Retour a menu principal\n");

    do
    {
        printf("Entrer un choix : ");
        validInput = scanf("%d", &choix);

        if (validInput != 1) {
            printf("Entrée invalide ! Veuillez entrer un nombre.\n");
            // vider le buffer
            while (getchar() != '\n');
            choix = 0; // force la boucle à continuer
        }
    } while (choix < 1 || choix > 4);

    // vider le buffer avant de continuer
    while (getchar() != '\n');

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
            menu();  // retour direct au menu principal
            return;  // empêche de rappeler menu() après
    }

    printf("\nAppuyez sur Entrée pour continuer...");
    getchar(); // pause
    menu();    // retour menu principal après actions 1,2,3
}

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

// menu de Gestion du Solde Virtuel ..............................................................................................
void menuSoldeVirtuel()
{

    printf("=================== Menu de Solde Virtuel ====================\n");
    int choix;
    do
    {

        printf("1-Consulter le solde:\n");
        printf("2-Depot d'argent\n");
        printf("3-Verifier solde pour achat\n");
        printf("4-Retour au menu \n");
        printf("Entrer un choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            consulterSolde();

            break;
        case 2:
            depotArgent();
            break;

        case 3:
            verificationAuto();
            break;
        case 4:
            menu();
        default:
            printf("Choix invalide!\n");
        }
    } while (choix != 4);
}
// fonction consulter sold .................................................................................
void consulterSolde()
{
    if (createdProfile == 0)
    {
        printf("il n'y a pas de profile veuillez creer un profile\n");
    }
    else
    {
        printf("le sold est : %.2f\n", client1.solde);
    }
    getchar();
    getchar();
    menuSoldeVirtuel();
}

// fonction depot dargent  .................................................................................
void depotArgent()
{
    if (createdProfile == 0)
    {
        printf("il n'y a pas de profile veuillez creer un profile\n");
    }
    else
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
}
void verificationAuto()
{
    if (createdProfile == 0)
    {
        printf("il n'y a pas de profile veuillez creer un profile\n");
    }
    else
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
    }
    getchar();
    getchar();
    menuSoldeVirtuel();
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
        break;
    case 2:
        rechercherProduit();
        break;

    case 3:
        triProduit();
        break;
    case 4:
        detailsProduit();
        break;

    case 5:
        menu();
    
    }
}
void initialiserCatalogue()
{
    if (nbrProduit == 0)
    {
        // produit1
        produit[nbrProduit].idProduit = idProduit++;
        strcpy(produit[nbrProduit].nom, "Ordinateur");
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
        strcpy(produit[nbrProduit].nom, "Casque");
        strcpy(produit[nbrProduit].categorie, "Accessoires");
        strcpy(produit[nbrProduit].description, "Casque sans fil Bluetooth");
        produit[nbrProduit].prix = 350;
        produit[nbrProduit].stock = 30;
        nbrProduit++;
        // produit4
        produit[nbrProduit].idProduit = idProduit++;
        strcpy(produit[nbrProduit].nom, "iphone");
        strcpy(produit[nbrProduit].categorie, "Electronique");
        strcpy(produit[nbrProduit].description, "Dernier modele iPhone 15 Pro Max, 256GB");
        produit[nbrProduit].prix = 12000;
        produit[nbrProduit].stock = 10;
        nbrProduit++;
    }
}
void afficherCatalogue()
{
    initialiserCatalogue();
    for (int i = 0; i < nbrProduit; i++)
    {
        printf("Produit : %d || le nom: %s ||  Categorie: %s || Prix: %.2fMAD|| Description: %s  ||  Stock :%d\n",
               produit[i].idProduit, produit[i].nom, produit[i].categorie, produit[i].prix, produit[i].description, produit[i].stock);
    }
}

// fonction Rechercher produit ....................................................................................

void rechercherProduit()
{
    int choix;
    int i;
    char nomProduit[50];
    char categorieProduit[50];
    printf("1-recherche par nom\n");
    printf("2-recherche par categorie\n");

    do
    {
        printf("Entrer un  choix: ");
        scanf("%d", &choix);

    } while (choix < 1 || choix > 2);
    int trouve = 0;
    switch (choix)
    {
    case 1:
        trouve = 0;

        printf("Rechercher par nom:");
        scanf(" %49s", nomProduit);

        for (int i = 0; i < nbrProduit; i++)
        {
            if (strcasecmp(nomProduit, produit[i].nom) == 0)

            {
                printf("=== Produit trouve ===\n");
                printf("ID: %d\n", produit[i].idProduit);
                printf("Nom: %s\n", produit[i].nom);
                printf("Categorie: %s\n", produit[i].categorie);
                printf("Prix: %.2f MAD\n", produit[i].prix);
                printf("Description: %s\n", produit[i].description);
                printf("Stock: %d\n", produit[i].stock);

                trouve = 1;
            }
        }
        if (!trouve)
        {
            printf("Aucun produit trouve avec ce nom.\n");
        }
        break;

    case 2:
        trouve = 0;

        printf("Rechercher par categorie:");
        scanf(" %49s", categorieProduit);

        for (int i = 0; i < nbrProduit; i++)
        {
            if (strcasecmp(categorieProduit, produit[i].categorie) == 0)

            {
                printf("=== Produit trouve ===\n");
                printf("ID: %d\n", produit[i].idProduit);
                printf("Nom: %s\n", produit[i].nom);
                printf("Categorie: %s\n", produit[i].categorie);
                printf("Prix: %.2f MAD\n", produit[i].prix);
                printf("Description: %s\n", produit[i].description);
                printf("Stock: %d\n", produit[i].stock);
                trouve = 1;
            }
        }
        if (!trouve)
        {
            printf("Aucun produit trouve avec cette categorie.\n");
        }
        break;
    }
    catalogueProduits();
}
// trier les produit par croissnat et decroissant et par nom alphabetique
void triProduit()
{
    int choix;
    Produit temp;
    printf("1-Tri par prix croissant\n");
    printf("2-Tri par prix decroissant\n");
    printf("3-Tri par nom alphabetique\n");
    do
    {

        printf("Entrer votre choix: ");
        scanf("%d", &choix);
    } while (choix < 1 || choix > 3);
    switch (choix)
    {
    // pour le prix croissant
    case 1:
        for (int i = 0; i < nbrProduit - 1; i++)
        {
            for (int j = i + 1; j < nbrProduit; j++)
            {
                if (produit[i].prix > produit[j].prix)
                {
                    temp = produit[i];
                    produit[i] = produit[j];
                    produit[j] = temp;
                }
            }
        }

        break;

    case 2: // pour le  prix decroissant
        for (int i = 0; i < nbrProduit - 1; i++)
        {
            for (int j = i + 1; j < nbrProduit; j++)
            {
                if (produit[i].prix < produit[j].prix)
                {
                    temp = produit[i];
                    produit[i] = produit[j];
                    produit[j] = temp;
                }
            }
        }
        break;
    case 3: // tri par nom alphabetique
        for (int i = 0; i < nbrProduit - 1; i++)
        {
            for (int j = i + 1; j < nbrProduit; j++)
            {
                if (strcasecmp(produit[i].nom, produit[j].nom) > 0)
                {
                    temp = produit[i];
                    produit[i] = produit[j];
                    produit[j] = temp;
                }
            }
        }
    default:
        printf("Choix invalide!\n");
        menu();
    }
    printf("=== Catalogue trie ===\n");
    afficherCatalogue();
    getchar();
    getchar();
    catalogueProduits();
}
// afficher les detailles d'un produit.....................................................................
void detailsProduit()
{
    int id;
    int trouve = 0;
    int i;

    printf("Entrer l'id du produit pour voir les details: ");
    scanf("%d", &id);

    for (i = 0; i < nbrProduit; i++)
    {
        if (produit[i].idProduit == id)
        {
            printf("============ Details du Produit =================\n");
            printf("ID: %d\n", produit[i].idProduit);
            printf("Nom: %s\n", produit[i].nom);
            printf("Categorie: %s\n", produit[i].categorie);
            printf("Prix: %.2f MAD\n", produit[i].prix);
            printf("Description: %s\n", produit[i].description);
            printf("Stock: %d\n", produit[i].stock);
            trouve = 1;
            break;
        }
    }

    if (!trouve)
    {
        printf("Aucun produit trouve avec cet ID.\n");
    }

    printf("\nAppuyez sur Entree pour revenir au catalogue...\n");
    getchar();
    getchar();
    catalogueProduits();
}
// pour selectionner un produit ..............................................
void ProcessusAchat()
{
    int quantite, choix;
    int trouve = 0;
    int i = -1;

    afficherCatalogue();

    printf("\n=== Selection de produit ===\n");

    do
    {
        printf("Entrer l'ID du produit que tu veux selectionner : ");
        scanf("%d", &choix);

        trouve = 0;
        for (int j = 0; j < nbrProduit; j++)
        {
            if (choix == produit[j].idProduit)
            {
                printf("Tu as choisi : %s avec prix %.2f MAD\n", produit[j].nom, produit[j].prix);
                trouve = 1;
                i = j;
                break;
            }
        }

        if (trouve == 0)
        {
            printf("Aucun produit avec cet ID.\n");
        }

    } while (trouve == 0);

    // Vérification du stock
    printf("Entrer la quantite que tu veux acheter : ");
    scanf("%d", &quantite);

    if (produit[i].stock < quantite)
    {
        printf("Stock insuffisant ! : %d\n", produit[i].stock);
        return;
    }

    // Vérification du solde
    float montantTotal = produit[i].prix * quantite;
    if (client1.solde < montantTotal)
    {
        printf("Solde insuffisant ! Ton solde actuel est : %.2f MAD\n", client1.solde);
        return;
    }

    // Paiement
    client1.solde -= montantTotal;
    produit[i].stock -= quantite;

    char action[MAX_ACTION];
    sprintf(action, "Achat de %d %s pour %.2f MAD", quantite, produit[i].nom, montantTotal);
    ajouterHistorique(action);

    // Confirmation
    printf("\n=== Achat reussi ===\n");
    printf("Nouveau solde : %.2f MAD\n", client1.solde);
    printf("Nouveau stock du produit %s : %d\n", produit[i].nom, produit[i].stock);
}
// historique
void ajouterHistorique(char action[MAX_ACTION])
{
    if (nbrHistorique >= MAX_HIST)
    {
        printf("Historique plein!\n");
        return;
    }

    strcpy(historique[nbrHistorique].action, action);
    nbrHistorique++;
}
// afficher historique
void afficherHistorique()
{
    printf("\n===== Historique des actions =====\n");

    if (nbrHistorique == 0)
    {
        printf("Aucune action enregistree.\n");
    }
    else
    {
        for (int i = 0; i < nbrHistorique; i++)
        {
            printf("%d- %s\n", i + 1, historique[i].action);
        }
    }
}
