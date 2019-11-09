#include "general.h"
#include "afd.h"

using namespace std;

void AFD::oProcess()
{
  tokenValue += 'o';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'd' || c == 'D')
    {
      odProcess();
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

void AFD::odProcess()
{
  tokenValue += 'd';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'd' || c == 'D')
    {
      oddProcess();
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

void AFD::oddProcess()
{
  tokenValue += 'd';
  tokenType = TOKEN_TYPES::ODD_KEYWORD;
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
