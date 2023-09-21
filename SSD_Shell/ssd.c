#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	//for(int i = 0; i <argc; i++) {
	//	printf("argv[%d]: %s\n",i, argv[i]);
	//}
//./ssd ssd	R/W RBA	value			
//	0	1	2	3	4(W_only)

	if (strcmp(argv[1], "ssd")) {
		printf("Not ssd\n");
		return 0;
	}
	
	if (*argv[2]=='R') {
		FILE* fp_nand = fopen("./nand.txt", "r");
		//char data100[110][50];	noNEED to use data100
		char buf[50];
		int tar_num = atoi(argv[3]);
		int while_cnt=0;
		while(!feof(fp_nand)){
			fgets(buf, 50, fp_nand);
			//strcpy(data100[while_cnt], buf);
			//printf("%s", buf);
			if(while_cnt == tar_num) break;
			while_cnt++;
		}
		fclose(fp_nand);
		
		FILE* fp_result = fopen("./result.txt", "w");
		fputs(buf, fp_result);
		printf("%s", buf);
		fclose(fp_result);
	}

	
	else if (*argv[2]=='W') {
		FILE* fp_nand = fopen("./nand.txt", "r");
		char data100[110][50];	
		char buf[50];
		int tar_num = atoi(argv[3]);
		//int tar_value = atoi(argv[4]);
		int while_cnt=0;
		while(!feof(fp_nand)){
			fgets(buf, 50, fp_nand);
			strcpy(data100[while_cnt], buf);
			while_cnt++;
		}
		fclose(fp_nand);
		//printf("%s", data100[tar_num]);
		//for (int i = 0; i < strlen(data100[tar_num]); i++) {
		//	printf("%d: %d\n", i, *(data100[tar_num]+i) );
		//}
		char tmp[50];
		memset(tmp, 0, sizeof(tmp));
		strncpy(tmp, data100[tar_num], 4);
		strcat(tmp, argv[4]);
		tmp[14] = 10; // ASCII10: [ENTER] IN .txt
		
		
		printf("%s", tmp);
		//for(int i = 0; i < strlen(tmp); i++) {
		//	printf("\n%d:%c, %d", i, tmp[i], tmp[i]);
		//}
		memset(data100[tar_num], 0, sizeof(data100[tar_num]));
		strcpy(data100[tar_num], tmp);
		//printf("===print 10===\n");
		//for(int i = 0;i < 10; i++) {
		//	printf("%s", data100[i]);
		//}
		

		//printf("data100[0]: %s", data100[0]);
		//for(int i = 0; i <50; i++) {
		//	printf("\n%d:%c, %d", i, tmp[i], tmp[i]);
		//}
		
		fp_nand= fopen("./nand.txt", "w");
		for(int i = 0; i < 100; i++) {
			fputs(data100[i], fp_nand);
		}
		fclose(fp_nand);
	}	
		
	return 0;
}
