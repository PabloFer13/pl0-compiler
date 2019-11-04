#include "general.h"
#include "afd.h"

using namespace std;

void AFD::bProcess()
{
  tokenValue += 'b';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'e' || c == 'E')
    {
      beProcess();
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

void AFD::beProcess()
{
  tokenValue += 'e';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'g' || c == 'G')
    {
      begProcess();
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

void AFD::begProcess()
{
  tokenValue += 'g';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'i' || c == 'I')
    {
      begiProcess();
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

void AFD::begiProcess()
{
  tokenValue += 'i';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'n' || c == 'N')
    {
      beginProcess();
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

void AFD::beginProcess()
{
  tokenValue += 'n';
  tokenType = TOKEN_TYPES::BEGIN_KEYWORD;
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
