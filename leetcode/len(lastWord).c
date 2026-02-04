int lengthOfLastWord(char* s) {
    int l = strlen(s);
    int i = l-1;
    int count =0;
    for(i=l-1;i>=0;i--){
        if(s[i] != ' '){
            count++;
        }
        if(count > 0){
            if(s[i]== ' '){
                break;
            }
        }
    }
    return count;
}
