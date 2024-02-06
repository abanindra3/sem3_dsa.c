#include <stdio.h>
#include <stdlib.h>

struct term{
    int coeff;                 //coefficient
    int expo;                  //exponent
    struct term* next;
};
struct term* create(int c,int e){
    struct term* new=(struct term*)malloc(sizeof (struct term));
    new->coeff=c;
    new->expo=e;
    new->next=NULL;
    return new;
}
struct term* insert(struct term** poly,int coeff,int expo){
    struct term* new=create(coeff,expo);
    if(*poly==NULL){
        *poly=new;
    }else{
        struct term* curr=*poly;
        while(curr->next!=NULL){
            curr=curr->next;
        }
        curr->next=new;
    }
    return *poly;
}
void print(struct term* poly){
    if(poly==NULL){
        printf("0");
    }else{
        while(poly!=NULL){
            printf("%d^%d",poly->coeff,poly->expo);
            if(poly->next!=NULL){
                printf("+");
            }
            poly=poly->next;
        }
    }
    printf("\n");
}
struct term* add(struct term* poly1, struct term* poly2) {
    struct term* res = NULL;

    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->expo > poly2->expo) {
            insert(&res, poly1->coeff, poly1->expo);
            poly1 = poly1->next;
        } else if (poly1->expo < poly2->expo) {
            insert(&res, poly2->coeff, poly2->expo);
            poly2 = poly2->next;
        } else {
            if (poly1->expo == poly2->expo) {
                insert(&res, poly1->coeff + poly2->coeff, poly1->expo);
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
    }

    while (poly1 != NULL) {                         // Insert remaining terms from poly1
        insert(&res, poly1->coeff, poly1->expo);
        poly1 = poly1->next;
    }                     
                                        
    while (poly2 != NULL){                             // Insert remaining terms from poly2
        insert(&res, poly2->coeff, poly2->expo);
        poly2 = poly2->next;
    }

    return res;
}

int main(){
    struct term* poly1 = NULL;
    struct term* poly2 = NULL;

    int coeff,expo;
    while(1){
        printf("ENTER COEFF-:");
        scanf("%d",&coeff);

        if(coeff==-1){
            break;
        }
        printf("ENTER EXPO");
        scanf("%d",&expo);

        insert(&poly1,coeff,expo);
    }
    while(1){
        printf("ENTER COEFF 2-:");
        scanf("%d",&coeff);

        if(coeff==-1){
            break;
        }
        printf("ENTER EXPO");
        scanf("%d",&expo);

        insert(&poly2,coeff,expo);
    }


    printf("Polynomial 1: ");
    print(poly1);

    printf("Polynomial 2: ");
    print(poly2);

    struct term* sum = add(poly1, poly2);
    printf("Sum of Polynomials: ");
    print(sum);

    // freePolynomial(poly1);
    // freePolynomial(poly2);
    // freePolynomial(sum);

    return 0;
}