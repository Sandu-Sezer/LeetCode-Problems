char* maximumOddBinaryNumber(char* s){
    int zeroCounter = 0;
    int oneCounter = 0;
    int size = strlen(s);
    char* newString = (char*) malloc((size + 1) * sizeof(char));

// Count the number of 0s and 1s in the string
    for (int i = 0; i < size; ++i){
        if (s[i] == '1'){
            oneCounter++;
        } else {
            zeroCounter++;
        }
    }
  
    for (int i = 0; i < size - 1; ++i){
        for (int j = 0; j < size - i - 1; ++j){
            if (s[j] < s[j+1]){
                char aux = s[j];
                s[j] = s[j+1];
                s[j+1] = aux;
            }
        }
    }

    s[oneCounter - 1] = '0'; 

    s[size - 1] = '1';

    strcpy(newString, s);

    return newString;
}
