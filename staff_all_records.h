void staff_all_records() {
	FILE *fptr;
	fptr = fopen("staff_count.txt", "r");

	if(fptr == NULL) {
		FILE *cptr;
		cptr = fopen("staff_count.txt", "w");
		fprintf(cptr, "0");
	}
	else {
		char count[10];
		fgets(count, sizeof(count), fptr);
		int c = atoi(count);

		FILE *all_records;
		all_records = fopen("staff_data.txt", "r");
		if(all_records == NULL) {
			printf("ERROR: FILE NOT FOUND");
		}
		else {
			char data[c][70];
			printf("ID   NAME\n");
			for (int i = 0; ((fgets(data[i], sizeof(data), all_records)) != NULL && (i < c)); i++)
			{
				printf("%s", data[i]);
			}
		}
	}
	fclose(fptr);
}