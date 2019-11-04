#include "general.h"
#include "afd.h"

using namespace std;

void AFD::iProcess()
{
  tokenValue += 'i';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'n' || c == 'N')
    {
      inProcess();
    }
    else if (c == 'f' || c == 'F')
    {
      ifProcess();
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
}

void AFD::inProcess()
{
  tokenValue += 'n';
  tokenType = TOKEN_TYPES::IN_KEYWORD;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 't' || c == 'T')
    {
      intProcess();
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
}

void AFD::ifProcess()
{
  tokenValue += 'f';
  tokenType = TOKEN_TYPES::IF_KEYWORD;
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
}

void AFD::intProcess()
{
  tokenValue += 't';
  tokenType = TOKEN_TYPES::INT_KEYWORD;
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
}
