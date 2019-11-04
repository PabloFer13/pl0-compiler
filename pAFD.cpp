#include "general.h"
#include "afd.h"

using namespace std;

void AFD::pProcess()
{
  tokenValue += 'p';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'r' || c == 'R')
    {
      prProcess();
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

void AFD::prProcess()
{
  tokenValue += 'r';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'o' || c == 'O')
    {
      proProcess();
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

void AFD::proProcess()
{
  tokenValue += 'o';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'c' || c == 'C')
    {
      procProcess();
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

void AFD::procProcess()
{
  tokenValue += 'c';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'e' || c == 'E')
    {
      proceProcess();
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

void AFD::proceProcess()
{
  tokenValue += 'e';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'd' || c == 'D')
    {
      procedProcess();
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

void AFD::procedProcess()
{
  tokenValue += 'd';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'u' || c == 'U')
    {
      proceduProcess();
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

void AFD::proceduProcess()
{
  tokenValue += 'u';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'r' || c == 'R')
    {
      procedurProcess();
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

void AFD::procedurProcess()
{
  tokenValue += 'r';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'e' || c == 'E')
    {
      procedureProcess();
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

void AFD::procedureProcess()
{
  tokenValue += 'e';
  tokenType = TOKEN_TYPES::PROCEDURE_KEYWORD;
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
