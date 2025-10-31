#include <ctype.h>
#include <stdio.h>
#include <string.h>

char *keywords[] = {"int",    "float", "char", "if",   "else",   "while",
                    "return", "for",   "void", "main", "printf", "scanf"};

int is_keyword(char *word) {
  for (int i = 0; i < (sizeof(keywords) / sizeof(keywords[0])); i++) {
    if (strcmp(word, keywords[i]) == 0) {
      return 1;
    }
  }
  return 0;
}

int is_operator(char ch) {
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' ||
          ch == '<' || ch == '>' || ch == '!' || ch == '=');
}

int is_separator(char ch) {
  return (ch == '{' || ch == '}' || ch == '[' || ch == ']' || ch == ';' ||
          ch == ',' || ch == '(' || ch == ')');
}

void analyze(FILE *file) {
  char ch, word[100];
  int i = 0;
  while ((ch = fgetc(file)) != EOF) {
    if (isspace(ch))
      continue;

    if (ch == '/') {
      char next = fgetc(file);
      // Handle single-line comment
      if (next == '/') {
        while ((ch = fgetc(file)) != EOF && ch != '\n')
          ;
        continue;  // Skip the rest and go to next iteration
      }
      // Handle multi-line comment
      else if (next == '*') {
        while ((ch = fgetc(file)) != EOF) {
          if (ch == '*' && (ch = fgetc(file)) == '/') {
            break;
          }
        }
        continue;  // Skip comment completely
      } else {
        ungetc(next, file);  // Not a comment → put back the next char
      }
    }


    if (ch == '#') {
      printf("preprocessor directive:");
      while ((ch = fgetc(file)) != EOF && ch != '\n') {
        printf("%c", ch);
      }
      printf("\n");
    }

    if (isalpha(ch)||ch=='_') {
      i = 0;
      word[i++] = ch;
      while ((ch = fgetc(file)) != EOF && (isalnum(ch) || ch == '_')) {
        word[i++] = ch;
      }
      word[i] = '\0';
      ungetc(ch, file);
      if (is_keyword(word)) {
        printf("keyword:%s\n", word);
      } else {
        printf("identifier:%s\n", word);
      }
    }

    else if (isdigit(ch)) {
      i = 0;
      word[i++] = ch;
      while ((ch = fgetc(file)) != EOF && (isdigit(ch) || ch == '.')) {
        word[i++] = ch;
      }
      word[i] = '\0';
      printf("operand:%s\n", word);
      ungetc(ch, file);
    }

    else if (is_operator(ch)) {
      char next = fgetc(file);
      if (ch == '=' && next == ch) {
        printf("operator:%c%c\n", ch, next);
      } else {
        printf("operator:%c\n", ch);
        ungetc(next, file);
      }
    }

    else if (is_separator(ch)) {
      printf("separator:%c\n", ch);
    }

    else {
      printf("unknown:%d", ch);
    }
  }
}

int main() {
  FILE *file = fopen("test.c", "r");
  analyze(file);
  fclose(file);
  return 0;
}
