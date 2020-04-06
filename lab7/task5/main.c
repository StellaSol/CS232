char password[8] = "secret";
int main() {
    char input[8];
    int i = 0;
    printf("please enter your password\n");
    scanf("%s", input);
    while(i<=7){
        if (input[i] < 'A' || input[i]> 'Z' ){
            i++;
        }
        else{
            input[i]=input[i] + ' ';
            i++;
        }
    }

    if(strcmp(input, password)!=0) {
        return 0;
    }
    else{
        return -1;
    }
}
