#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct {
    float *poly;
    int degre;
} Polynome;

Polynome saisir_polynome(){
    Polynome p;
    printf("Entrez le degre du polynome : ");
    scanf("%i", &p.degre);

    p.poly = malloc((p.degre + 1) * sizeof(float));

    for (int i = 0; i <= p.degre; ++i) {
        printf("Entrez le coefficient a%d : ", i);
        scanf("%f", &p.poly[i]);
    }

    return p;
}

void afficher_polynome(Polynome p) {
    printf("f(x) = ");
    for (int i = p.degre; i >= 0; --i) {
        if (p.poly[i] != 0) {
            if (i == p.degre)
                printf("%fx^%d", p.poly[i], i);
            else {
                if (p.poly[i] > 0)
                    printf(" + ");
                else
                    printf(" - ");
                if (abs(p.poly[i]) != 1)
                    printf("%lfx^%d", fabs(p.poly[i]), i);
                else
                    printf("x^%d", i);
            }
        }
    }
    printf("\n");
}

void ajuster_degre(Polynome *p) {
    int new_degre = p->degre;
    while (p->poly[new_degre] == 0 && new_degre > 0) {
        new_degre--;
    }

    if (new_degre != p->degre) {
        float *n_poly = malloc((new_degre + 1) * sizeof(float));
        for (int i = 0; i <= new_degre; i++) {
            n_poly[i] = p->poly[i];
        }
        free(p->poly);
        p->poly = n_poly;
        p->degre = new_degre;
    }
}

Polynome soustraction_polynome(Polynome p1, Polynome p2) {
    Polynome result;
    result.degre = (p1.degre > p2.degre) ? p1.degre : p2.degre; //coeff
    result.poly = malloc((result.degre + 1) * sizeof(float));

    int isZero = 1;

    for (int i = 0; i <= result.degre; ++i) {
        float coeff1 = (i <= p1.degre) ? p1.poly[i] : 0;
        float coeff2 = (i <= p2.degre) ? p2.poly[i] : 0;
        result.poly[i] = coeff1 - coeff2;

        if (result.poly[i] != 0){
            isZero = 0;
        }
    }
    if (isZero) {
        free(result.poly);
        printf("f(x) = 0\n");
        result.degre = 0;
        result.poly = malloc(sizeof(float));
        result.poly[0] = 0;
    } else {
        ajuster_degre(&result);
    }
    return result;
}


int main(){
    Polynome p1, p2;

    printf("Saisie du polynome 1 :\n");
    p1 = saisir_polynome();
    
    printf("\nSaisie du polynome 2 :\n");
    p2 = saisir_polynome();

    sleep(3);
    system("cls");

    printf("\nPolynome 1 saisi :\n");
    afficher_polynome(p1);

    sleep(3);
    system("cls");

    printf("\nPolynome 2 saisi :\n");
    afficher_polynome(p2);

    sleep(3);
    system("cls");

    Polynome difference = soustraction_polynome(p1, p2);
    printf("\nPolynome 1 - Polynome 2 :\n");
    afficher_polynome(difference);

    free(p1.poly);
    free(p2.poly);
    free(difference.poly);

    return 0;
}