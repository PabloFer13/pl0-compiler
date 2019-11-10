// #include <string>
// #include <cstdlib>
// #include <set>
// #include <queue>
// #include <iostream>
// #include <fstream>

#include <bits/stdc++.h>

using namespace std;

enum TOKEN_TYPES
{
  NEW_LINE,
  NULL_TOKEN,
  IF,
  IN,
  DO,
  ODD,
  END,
  ELSE,
  THEN,
  CALL,
  BEGIN,
  WHILE,
  WRITE,
  CONST,
  PROCEDURE,
  VAR,
  READ,
  IDENTIFIER,
  NUMBER,
  LESS,
  LESS_EQUAL,
  NOT_EQUAL,
  EQUAL,
  GREATER,
  GREATER_EQUAL,
  MULTIPLY,
  DIVIDE,
  ADD,
  SUBSTRACT,
  ASSIGNMENT,
  OPEN_PAR,
  CLOSE_PAR,
  COMA,
  SEMICOLON,
  PERIOD,
  DOUBLE_PERIOD
};

enum TOKEN_CATEGORY
{
  LOGIC,
  TERM_OPERATOR,
  EXPRESSION_OPERATOR,
  KEYWORD,
  NUMERIC
};

typedef struct
{
  TOKEN_TYPES tipo;
  string valor;
  int initialPos;
} Token;

extern set<char> Letras;
extern set<char> Numeros;
extern set<char> Simbolos;

void initEnv();
