#include "afd.h"

using namespace std;

void AFD::vProcess()
{
  tokenValue += 'v';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'a' || c == 'A')
    {
      vaProcess();
    }
    else if (Letras.find(c) != Letras.end() || Numeros.find(c) != Numeros.end())
    {
      pos--;
      identifierProcess();
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

void AFD::vaProcess()
{
  tokenValue += 'a';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'r' || c == 'R')
    {
      varProcess();
    }
    else if (Letras.find(c) != Letras.end() || Numeros.find(c) != Numeros.end())
    {
      pos--;
      identifierProcess();
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

void AFD::varProcess()
{
  tokenValue += 'r';
  tokenType = TOKEN_TYPES::VAR;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Letras.find(c) != Letras.end() || Numeros.find(c) != Numeros.end())
    {
      pos--;
      identifierProcess();
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
