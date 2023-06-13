struct patient_data {
    char reg_no[50];
    char pat_name[50];
    char guar_name[50];
    char gen[8];
    char bgrp[5];
    char age[10];
    char address[4][30];
    char phn[15];
    char dis_name[20];
    char doc_name[50];
    char his_desc[200];
    char date_treat[20];
    char treat_given[100];
    char med_pres[100];
};
void patient_new_entry(struct patient_data *ptr) {
    printf("Enter registration Number - ");
    gets((ptr + 0)->reg_no);

    printf("Enter Patient Name - ");
    gets((ptr + 0)->pat_name);

    printf("Enter Patient's Guardian Name - ");
    gets((ptr + 0)->guar_name);

    printf("Enter Patient's Gender - ");
    gets((ptr + 0)->gen);

    printf("Enter Patient's Blood Group - ");
    gets((ptr + 0)->bgrp);

    printf("Enter Patient's Age - ");
    gets((ptr + 0)->age);

    printf("Enter Patient's Address -\n");
    printf("\tHouse No - ");
    gets((ptr + 0)->address[0]);

    printf("\tStreet - ");
    gets((ptr + 0)->address[1]);

    printf("\tCity - ");
    gets((ptr + 0)->address[2]);

    printf("\tState - ");
    gets((ptr + 0)->address[3]);

    printf("Enter Phone Number - ");
    gets((ptr + 0)->phn);

    printf("Enter Disease Name - ");
    gets((ptr + 0)->dis_name);

    printf("Enter Doctor's Name - ");
    gets((ptr + 0)->doc_name);

    char c;
    printf("Enter Y/N if the patient has any history: ");
    scanf("%c", &c);
    fflush(stdin);

    if(c == 'Y') {
        printf("Enter History - ");
        gets((ptr + 0)->his_desc);

        printf("Enter Treatment Date - ");
        gets((ptr + 0)->date_treat);

        printf("Treatment Given - ");
        gets((ptr + 0)->treat_given);

        printf("Medicine Prescribed - ");
        gets((ptr + 0)->med_pres);
    }
    else if(c == 'N') {
        strcpy((ptr + 0)->his_desc, "None");
        strcpy((ptr + 0)->date_treat, "None");
        strcpy((ptr + 0)->treat_given, "None");
        strcpy((ptr + 0)->med_pres, "None");
    }

    FILE *cfptr;
    char cname[100];
    strcpy(cname, (ptr + 0)->reg_no);
    strcat(cname, (ptr + 0)->pat_name);
    strcat(cname, ".txt");

    cfptr = fopen(cname, "r");

    if(cfptr == NULL) {
        FILE *fptr;
        char fname[100];
        strcpy(fname, (ptr + 0)->reg_no);
        strcat(fname, (ptr + 0)->pat_name);
        strcat(fname, ".txt");

        fptr = fopen(fname, "w");

        fprintf(fptr, "%s\n", (ptr + 0)->reg_no);

        fprintf(fptr, "%s\n", (ptr + 0)->pat_name);

        fprintf(fptr, "%s\n", (ptr + 0)->guar_name);

        fprintf(fptr, "%s\n", (ptr + 0)->gen);

        fprintf(fptr, "%s\n", (ptr + 0)->bgrp);

        fprintf(fptr, "%s\n", (ptr + 0)->age);

        fprintf(fptr, "%s\n", (ptr + 0)->address[0]);

        fprintf(fptr, "%s\n", (ptr + 0)->address[1]);

        fprintf(fptr, "%s\n", (ptr + 0)->address[2]);

        fprintf(fptr, "%s\n", (ptr + 0)->address[3]);

        fprintf(fptr, "%s\n", (ptr + 0)->phn);

        fprintf(fptr, "%s\n", (ptr + 0)->dis_name);

        fprintf(fptr, "%s\n", (ptr + 0)->doc_name);

        fprintf(fptr, "%s\n", (ptr + 0)->his_desc);

        fprintf(fptr, "%s\n", (ptr + 0)->date_treat);

        fprintf(fptr, "%s\n", (ptr + 0)->treat_given);

        fprintf(fptr, "%s\n", (ptr + 0)->med_pres);

        fclose(fptr);


/*
        FILE *lfptr, *afptr;
        lfptr = fopen("pat_name.txt", "a");
        afptr = fopen("reg_no.txt", "a");

        fprintf(lfptr, "%s", (ptr + 0)->pat_name);
        fprintf(lfptr, "\n");
        fclose(lfptr);

        fprintf(afptr, "%s", (ptr + 0)->reg_no);
        fprintf(afptr, "\n");
        fclose(afptr);
*/

        FILE *cptr;
        cptr = fopen("count.txt", "r");
        char count[100];
        fscanf(cptr, "%s", count);
        fclose(cptr);
        int c = atoi(count);
        c++;
        FILE *captr;
        captr = fopen("count.txt", "w");
        fprintf(captr, "%d", c);
        fclose(captr);

        fflush(stdin);
        FILE *arfptr;
        arfptr = fopen("all_records.txt", "a");
        fprintf(arfptr, "%s %s", (ptr + 0)->reg_no, (ptr + 0)->pat_name);
        fprintf(arfptr, "\n");
        fclose(arfptr);
    } 
    else {
        printf("Record already exists for %s(%s)\n", (ptr+0)->pat_name, (ptr+0)->reg_no);
    }
}
