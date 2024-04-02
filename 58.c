int lengthOfLastWord(char* s) {
    int rez = 0;
    int len = strlen(s);
    bool isLetter = false;

    for (int i = len - 1; i >= 0; i--){
        if (s[i] != ' '){
            rez++;
            isLetter = true;
        } else if (isLetter == true){
            break;
        }
    }
    return rez;
}