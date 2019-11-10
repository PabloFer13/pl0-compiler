#include "afd.h"

using namespace std;

void AFD::dProcess()
{
  tokenValue += 'd';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'o' || c == 'O')
    {
      doProcess();
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

void AFD::doProcess()
{
  tokenValue += 'o';
  tokenType = TOKEN_TYPES::DO;
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
