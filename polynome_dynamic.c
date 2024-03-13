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

int main() {
    // Appel de la fonction pour ajuster le degre du polynome
    int new_deg = 4;
    int t[] = {3, -1, 0, 2};
    int *nouveau_t = ajuster_degre(t, &new_deg);

    printf("Nouveau degre : %d\n", new_deg);
    printf("Nouveau tableau :\n");
    afficher_polynome(nouveau_t, new_deg);

    free(nouveau_t);

    int deg;
    int *polynome = saisir_polynome(&deg);

    sleep(3);
	system("cls");

    // Affichage du polynome pour verification
    printf("Polynome saisi :\n");
    afficher_polynome(polynome, deg);

    free(polynome);
    return 0;
}
