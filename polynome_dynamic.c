#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int* saisir_polynome(int *deg) {
    int n; // degre du polynome
    printf("Entrez le degre du polynome : ");
    scanf("%d", &n);

    int *poly = malloc((n + 1) * sizeof(int));

    for (int i = 0; i <= n; ++i) {
        printf("Entrez le coefficient a%d : ", i);
        scanf("%d", &poly[i]);
    }

    // mise à jour degre du polynome
    *deg = n;
    return poly;
}

int* ajuster_degre(int *poly, int *deg) {
    int nouveau_degre = *deg;

    // trouver le nouveau degre effectif
    while (nouveau_degre >= 0 && poly[nouveau_degre] == 0) {
        nouveau_degre--;
    }

    // allouer un tableau de la bonne taille
    int *nouveau_poly = malloc((nouveau_degre + 1) * sizeof(int));

    // copier les coefficients du polynome ajuste
    for (int i = 0; i <= nouveau_degre; ++i) {
        nouveau_poly[i] = poly[i];
    }

    // mise à jour degre du polynome
    *deg = nouveau_degre;

    return nouveau_poly;
}

// Fonction pour afficher le polynôme
void afficher_polynome(int *poly, int deg) {
    printf("f(x) = ");
    for (int i = deg; i >= 0; --i) {
        if (poly[i] != 0) {
            if (i == deg)
                printf("%dx^%d", poly[i], i);
            else {
                if (poly[i] > 0)
                    printf(" + ");
                else
                    printf(" - ");
                if (abs(poly[i]) != 1)
                    printf("%dx^%d", abs(poly[i]), i);
                else
                    printf("x^%d", i);
            }
        }
    }
    printf("\n");
}

int* soustraction_polynome(int *poly1, int deg1, int *poly2, int deg2, int *deg_result) {
    // trouver le degre du result
    *deg_result = (deg1 > deg2) ? deg1 : deg2;

    // allouer de l'espace pour le result
    int *result = malloc((*deg_result + 1) * sizeof(int));

    // soustraire les coefficients correspondants
    for (int i = 0; i <= *deg_result; ++i) {
        int coef1 = (i <= deg1) ? poly1[i] : 0;
        int coef2 = (i <= deg2) ? poly2[i] : 0;
        result[i] = coef1 - coef2;
    }

    return result;
}

int main() {
    int deg1;
    int *polynome1 = saisir_polynome(&deg1);
    int deg2;
    int *polynome2 = saisir_polynome(&deg2);
    int deg_result;
    int *result = soustraction_polynome(polynome1, deg1, polynome2, deg2, &deg_result);

    // Affichage du polynome pour verification
    printf("Polynome 1 saisi :\n");
    afficher_polynome(polynome1, deg1);

    free(polynome1);

    sleep(3);
    system("cls");

    // Affichage du polynome pour verification
    printf("Polynome 2 saisi :\n");
    afficher_polynome(polynome2, deg2);

    free(polynome2);

    sleep(3);
    system("cls");

    printf("Resultat de la soustraction :\n");
    afficher_polynome(result, deg_result);

    free(result);

    return 0;
}
