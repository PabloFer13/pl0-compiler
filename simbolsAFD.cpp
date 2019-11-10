#include "afd.h"

using namespace std;

void AFD::plusProcess()
{
  tokenValue += '+';
  tokenType = TOKEN_TYPES::ADD;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::hyphenProcess()
{
  tokenValue += '-';
  tokenType = TOKEN_TYPES::SUBSTRACT;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::asteriskProcess()
{
  tokenValue += '*';
  tokenType = TOKEN_TYPES::MULTIPLY;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::slashProcess()
{
  tokenValue += '/';
  tokenType = TOKEN_TYPES::DIVIDE;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::equalProcess()
{
  tokenValue += '=';
  tokenType = TOKEN_TYPES::MULTIPLY;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::lessProcess()
{
  tokenValue += '<';
  tokenType = TOKEN_TYPES::LESS;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == '>')
    {
      tokenValue += c;
      notEqualProcess();
    }
    else if (c == '=')
    {
      tokenValue += c;
      lessEqualProcess();
    }
    else if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::biggerProcess()
{
  tokenValue += '>';
  tokenType = TOKEN_TYPES::GREATER;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == '=')
    {
      tokenValue += c;
      biggerEqualProcess();
    }
    else
    {
      pos--;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::openProcess()
{
  tokenValue += '(';
  tokenType = TOKEN_TYPES::OPEN_PAR;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::closeProcess()
{
  tokenValue += ')';
  tokenType = TOKEN_TYPES::CLOSE_PAR;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::comaProcess()
{
  tokenValue += ',';
  tokenType = TOKEN_TYPES::COMA;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::semicolonProcess()
{
  tokenValue += ';';
  tokenType = TOKEN_TYPES::SEMICOLON;
  getToken();
  while (pos < codeLine.size())
  {
    if (codeLine[pos] != ' ' || codeLine[pos] != '\t')
    {
      estado = EST_ERROR;
      err.c = codeLine[pos];
      err.pos = pos - 1;
      err.type = EOL;
      pos = codeLine.size();
    }
    pos++;
  }
}

void AFD::pointProcess()
{
  tokenValue += '.';
  tokenType = TOKEN_TYPES::PERIOD;
  periodFound = true;
  getToken();
  while (pos < codeLine.size())
  {
    if (codeLine[pos] != ' ' || codeLine[pos] != '\t')
    {
      estado = EST_ERROR;
      err.c = codeLine[pos];
      err.pos = pos - 1;
      err.type = EOL;
      pos = codeLine.size();
    }
    pos++;
  }
}

void AFD::doubleProcess()
{
  tokenValue += ':';
  tokenType = TOKEN_TYPES::DOUBLE_PERIOD;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c = '=')
    {
      assignmentProcess();
    }
    else
    {
      pos--;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::notEqualProcess()
{
  tokenValue = '>';
  tokenType = TOKEN_TYPES::NOT_EQUAL;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::lessEqualProcess()
{
  tokenValue = '=';
  tokenType = TOKEN_TYPES::LESS_EQUAL;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::biggerEqualProcess()
{
  tokenValue = '=';
  tokenType = TOKEN_TYPES::GREATER_EQUAL;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}

void AFD::assignmentProcess()
{
  tokenValue += '=';
  tokenType = TOKEN_TYPES::ASSIGNMENT;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end() || Letras.find(c) != Letras.end())
    {
      pos--;
      getToken();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (c == '(')
    {
      pos--;
    }
    else if (Simbolos.find(c) != Simbolos.end())
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNEXPECTED;
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
  else
  {
    getToken();
  }
}
