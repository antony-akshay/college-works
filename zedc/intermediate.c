#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
  char op[3];
  char arg1[10];
  char arg2[10];
  char result[10];
} Quadraple;

typedef struct {
  char op[3];
  char arg1[10];
  char arg2[10];
} Triple;

char expr[MAX];

Quadraple quads[MAX];
Triple triples[MAX];
char operands[MAX][10];
int top = -1;
int var = 1;
int inter = 0;

void push(char *val) { strcpy(operands[++top], val); }

char *pop() { return operands[top--]; }

void generate(char op, char *arg1, char *arg2) {
  char temp[10];
  sprintf(temp, "t%d", var++);

  strcpy(quads[inter].arg1, arg1);
  strcpy(quads[inter].arg2, arg2);
  sprintf(quads[inter].op, "%c", op);
  strcpy(quads[inter].result, temp);

  strcpy(triples[inter].arg1, arg1);
  strcpy(triples[inter].arg2, arg2);
  sprintf(triples[inter].op, "%c", op);

  inter++;

  push(temp);
}

int precedence(char token) {
  if (token == '+' || token == '-') {
    return 1;
  }
  if (token == '*' || token == '/' || token == '%') {
    return 2;
  }
  return 0;
}

void parse(char *rhs) {
  char operators[MAX];
  int ontop = -1;
  char token;

  int i = 0;
  while (rhs[i] != '\0') {
    token = rhs[i];

    if (isspace(token)) {
      i++;
      continue;
    }
    if (isalnum(token)) {
      char temp[2] = {token, '\0'};
      push(temp);
    } else if (token == '(') {
      operators[++ontop] = token;
    } else if (token == ')') {
      while (ontop != -1 && operators[ontop] != '(') {
        char op = operators[ontop--];
        char *arg2 = pop();
        char *arg1 = pop();
        generate(op, arg1, arg2);
      }
      if (ontop != -1 && operators[ontop] == '(') {
        ontop--;
      } else {
        return;
      }
    } else if (token == '+' || token == '-' || token == '*' || token == '/') {
      while (ontop != -1 && operators[ontop] != '(' &&
             precedence(operators[ontop]) >= precedence(token)) {
        char op = operators[ontop--];
        char *arg2 = pop();
        char *arg1 = pop();
        generate(op, arg1, arg2);
      }
      operators[++ontop] = token;
    } else {
      return;
    }
    i++;
  }
  while (ontop != -1) {
    if (operators[ontop] == '(') {
      return;
    }
    char op = operators[ontop--];
    char *arg2 = pop();
    char *arg1 = pop();
    generate(op, arg1, arg2);
  }
}

int main() {
  char lhs, rhs[MAX];
  printf("expression:");
  fgets(expr, MAX, stdin);
  sscanf(expr, "%c = %[^\n]", &lhs, rhs);
  parse(rhs);

  char *finalTemp = pop();
  strcpy(quads[inter].op, "=");
  strcpy(quads[inter].arg1, finalTemp);
  strcpy(quads[inter].arg2, "-");
  char lhsStr[2] = {lhs, '\0'};
  strcpy(quads[inter].result, lhsStr);

  strcpy(triples[inter].op, "=");
  strcpy(triples[inter].arg1, finalTemp);
  strcpy(triples[inter].arg2, lhsStr);

  inter++;

  for (int i = 0; i < inter; i++) {
    if (strcmp(quads[i].op, "=") == 0) {
      printf("%s = %s\n", quads[i].result, quads[i].arg1);
    } else {
      printf("%s = %s %s %s\n", quads[i].result, quads[i].arg1, quads[i].op,
             quads[i].arg2);
    }
  }
}
