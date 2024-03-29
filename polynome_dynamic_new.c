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

    return 0;
}