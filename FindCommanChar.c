
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    int **visited = calloc (wordsSize, sizeof(int*));

    for(int i = 0; i < wordsSize; i++){
        visited[i] = calloc(26, sizeof(int));

        for(int j = 0; words[i][j]; j++)
            visited[i][words[i][j] - 'a']++;

        if(i){
            for(int k = 0; k < 26; k++)
                if(visited[i][k] || visited[i - 1][k])
                    visited[i][k] = visited[i][k] < visited[i - 1][k] ? visited[i][k] : visited[i - 1][k];
                
            free(visited[i - 1]);
        }
    }

    char **ret = malloc (100 * sizeof(char*));
    *returnSize = 0;

    for(int i = 0; i < 26; i++)
        while(visited[wordsSize - 1][i]--){
            ret[*returnSize] = malloc (2 * sizeof(char));
            ret[*returnSize][0] = i + 'a';
            ret[(*returnSize)++][1] = 0;
        }

    free(visited[wordsSize - 1]);
    free(visited);

    return ret;
}