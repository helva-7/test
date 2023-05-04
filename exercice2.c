#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct student {
    int code;
    char nom[50];
    char prenom[20];
    int age;
};

int main() {
    int num_students;
    struct student students[MAX_STUDENTS];

    printf("Entrez le nombre des etudiants: ");
    scanf("%d", &num_students);


    for (int i = 0; i < num_students; i++) {
        printf("Entrer l information pour l etudiant%d:\n", i + 1);
        printf("Code: ");
        scanf("%d", &students[i].code);
        printf("Nom: ");
        scanf("%s", students[i].nom);
        printf("Prenom: ");
        scanf("%s", students[i].prenom);
        printf("Age: ");
        scanf("%d", &students[i].age);
    }

     FILE *fp = fopen("etudiants.txt", "w");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }


    for (int i = 0; i < num_students; i++) {
        fprintf(fp, "Le Code :%d,NOM : %s,PRENOM : %s,AGE : %d ans \n", students[i].code, students[i].nom, students[i].prenom, students[i].age);
    }


    while (!feof(fp) && num_students < MAX_STUDENTS) {
        fscanf(fp, "%d,%s,%s,%d\n", &students[num_students].code, &students[num_students].nom, &students[num_students].prenom, &students[num_students].age);
        num_students++;
    }




    fclose(fp);
    return 0;
}
