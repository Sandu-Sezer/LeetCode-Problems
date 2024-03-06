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

    for (int i = 0; i < size; ++i){
        s[i] = '0';
    }

    for (int i = 0; i < oneCounter - 1; ++i){
        s[i] = '1';
    }

    s[size - 1] = '1';

    strcpy(newString, s);

    return newString;
}
