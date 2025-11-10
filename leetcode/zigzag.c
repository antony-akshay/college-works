char* convert(char* s, int numRows) {
    if (numRows <= 1) return s;
    int len = strlen(s);
    int cyclen = numRows * 2 - 2;
    char* result = malloc(len + 1);
    int k=0;
    for(int i=0;i<numRows;i++){
        for(int j=0;j+i<len;j+=cyclen){
            result[k++]=s[j+i];
            if(i!=0 && i != numRows-1 && j+cyclen-i<len){
                result[k++]=s[j+cyclen-i];
            }
        }
    } 
    result[k]='\0';
    return result;
}
