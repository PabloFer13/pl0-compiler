#include "afd.h"

using namespace std;

void AFD::wProcess()
{
  tokenValue += 'w';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'h' || c == 'H')
    {
      whProcess();
    }
    else if (c == 'r' || c == 'R')
    {
      wrProcess();
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

void AFD::whProcess()
{
  tokenValue += 'h';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'i' || c == 'I')
    {
      whiProcess();
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

void AFD::wrProcess()
{
  tokenValue += 'r';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'i' || c == 'I')
    {
      wriProcess();
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

void AFD::whiProcess()
{
  tokenValue += 'i';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'l' || c == 'L')
    {
      whilProcess();
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

void AFD::wriProcess()
{
  tokenValue += 'i';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 't' || c == 'T')
    {
      writProcess();
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

void AFD::whilProcess()
{
  tokenValue += 'l';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'e' || c == 'E')
    {
      whileProcess();
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

void AFD::writProcess()
{
  tokenValue += 't';
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'e' || c == 'E')
    {
      writeProcess();
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

void AFD::whileProcess()
{
  tokenValue += 'e';
  tokenType = TOKEN_TYPES::WHILE;
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

void AFD::writeProcess()
{
  tokenValue += 'e';
  tokenType = TOKEN_TYPES::WRITE;
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
