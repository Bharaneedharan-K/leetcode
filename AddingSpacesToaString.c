char * addSpaces(char * s, int* spaces, int spacesSize){
    
int length=strlen(s)+spacesSize;
char* str=(char*)malloc(sizeof(char)*(length+1));
if(str==NULL) {
    return NULL;
}
int start=0;
    int end=0;
for(int i=0; i<length; i++) {
    if(start<spacesSize  &&  spaces[start]==i) {
        str[end++]=' ';
        start++;
    }
    if(i<strlen(s)) {
    str[end++]=s[i];
    }
}
str[end]='\0';
return str;
}