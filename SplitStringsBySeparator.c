char ** splitWordsBySeparator(char ** words, int wordsSize, char separator, int* returnSize){

    int maxwords = wordsSize*10;
    char **s = (char**)malloc(maxwords*sizeof(char*));
    int k=0,l=0;
    for(int i=0 ; i<wordsSize ; i++)
    {
        for(int j=0 ; words[i][j]!='\0' ; j++)
        {
            if(words[i][j]==separator)
            {
                if(l!=0)
                {
                    s[k][l]='\0'; l=0 ; k++;
                }
            }
            else
            {
                if(l==0)
                {
                    s[k] = (char*)malloc(256 * sizeof(char)); 
                }
                s[k][l] = words[i][j];  l++;
            }
        }
                if(l!=0)
                {
                    s[k][l]='\0'; l=0; k++;
                }
    }
    *returnSize = k;
    return s;
}