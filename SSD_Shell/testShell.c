#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[50];
char parsed[50];
char buf[20];
char num[20];
char hex[20];


int isValid_LBA(char num[]){
    if(strlen(num) > 2){
        printf("INVALID COMMAND\n");
        return 0;
    }

    for(int i = 0; i < strlen(num); i++){
        if(num[i] < '0' || num[i] > '9'){
            printf("INVALID COMMAND\n");
            return 0;
        }
    }

    return 1;
}

int isValid_HEX(char hex[]){
    if(hex[0] != '0' || hex[1] != 'x'){
        printf("INVALID COMMAND\n");
        return 0;
    }
    if(strlen(hex) != 10){
        printf("INVALID COMMAND\n");
        return 0;
    }

    for(int i = 2 ; i < strlen(hex); i++){
        if((hex[i] >= 'A' && hex[i] <= 'F') || (hex[i] >= '0' && hex[i] <= '9')) continue;
        else {
            printf("INVALID COMMAND\n");
            return 0;
        }
    }
    return 1;
}

void write(){
    sscanf(input, "%s %s %s", buf, num, hex);
    if(!isValid_LBA(num)) return;
    if(!isValid_HEX(hex)) return;

    sprintf(parsed, "ssd W %s %s", num, hex);
    //printf("%s\n", parsed);
    char prefix[70] = "./ssd ";
    strcat(prefix, parsed);
    printf("%s\n", prefix);
    system(prefix);
}

void read(){
    sscanf(input, "%s %s", buf, num);
    if(!isValid_LBA(num)) return;

    sprintf(parsed, "ssd R %s", num);
    //printf("%s\n", parsed);
    char prefix[70] = "./ssd ";
    strcat(prefix, parsed);
    printf("%s\n", prefix);
    system(prefix);
}

void exitt(){
    sscanf(input, "%s", buf);
    sprintf(parsed, "%s", buf);
    printf("OK BYE^^\n");
    return;
}
void help(){
    sscanf(input, "%s", buf);
    sprintf(parsed, "%s", buf);
    printf("%s\n", parsed);
    return;
}
void fullwrite(){
    sscanf(input, "%s %s", buf, hex);
    if(!isValid_HEX(hex)) return;
    //sprintf(parsed, "%s %s", buf, hex);
    //printf("%s\n", parsed);

    for(int j = 0; j < 100; j++) {
        memset(input, 0, sizeof(input));
        //strcpy(input, "write");
        sprintf(input, "write %d %s", j, hex);
        write();
    }

}
void fullread(){
    //sscanf(input, "%s", buf);
    //sprintf(parsed, "%s", buf);
    //printf("%s\n", parsed);
    for(int j = 0; j < 100; j++) {
        memset(input, 0, sizeof(input));
        //strcpy(input, "write");
        sprintf(input, "read %d", j);
        read();
    }
}


int main(){

    while(1){
        printf("TestShell>>_");	
        gets(input);
        sscanf(input, "%s", buf);

        if(!strcmp(buf, "write")) {
            write();
        }
        else if(!strcmp(buf, "read")) {
            read();
        }
        else if(!strcmp(buf, "exit")) {
            exitt();
            break;
        }
        else if(!strcmp(buf, "help")) {
            help();
        }
        else if(!strcmp(buf, "fullwrite")) {
            fullwrite();
        }
        else if(!strcmp(buf, "fullread")) {
            fullread();
        }
        else {
            printf("INVALID COMMAND\n");
            //break;
        }

    }
    return 0;
}
