#include "general.h"
#include "afd.h"

using namespace std;

AFD::AFD()
{
  estado = INICIAL;
}

void AFD::addLine(string line)
{
  lines.push(line);
}

queue<Token> AFD::getResult()
{
  return result;
}

bool AFD::processWords()
{
  bool everythingRight = true;
  pos = 0;
  lineNumber = 0;
  estado = INICIAL;
  while (!lines.empty() && estado != EST_ERROR)
  {
    codeLine = lines.front();
    while (pos < codeLine.size() && estado != EST_ERROR)
    {
      afdProcess();
    }
    lineNumber++;
  }
}

void AFD::afdProcess()
{
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == '+')
    {
      plusProcess();
    }
    else if (c == '-')
    {
      hyphenProcess();
    }
    else if (c == '*')
    {
      asteriskProcess();
    }
    else if (c == '/')
    {
      slashProcess();
    }
    else if (c == '=')
    {
      equalProcess();
    }
    else if (c == '<')
    {
      lessProcess();
    }
    else if (c == '>')
    {
      biggerProcess();
    }
    else if (c == '(')
    {
      openProcess();
    }
    else if (c == ')')
    {
      closeProcess();
    }
    else if (c == ',')
    {
      comaProcess();
    }
    else if (c == ';')
    {
      semicolonProcess();
    }
    else if (c == '.')
    {
      pointProcess();
    }
    else if (c == ':')
    {
      doubleProcess();
    }
    else if (c == ' ')
    {
      getToken();
    }
    else if (Letras.find(c) != Letras.end())
    {
      pos--;
      firstLetterProcess();
    }
    else if (Numeros.find(c) != Numeros.end())
    {
      numberProcess();
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
    }
  }
}

void AFD::firstLetterProcess()
{
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (c == 'o' || c == 'O')
    {
      oProcess();
    }
    else if (c == 'b' || c == 'B')
    {
      bProcess();
    }
    else if (c == 'e' || c == 'E')
    {
      eProcess();
    }
    else if (c == 'i' || c == 'I')
    {
      iProcess();
    }
    else if (c == 't' || c == 'T')
    {
      tProcess();
    }
    else if (c == 'w' || c == 'W')
    {
      wProcess();
    }
    else if (c == 'd' || c == 'D')
    {
      dProcess();
    }
    else if (c == 'c' || c == 'C')
    {
      cProcess();
    }
    else if (c == 'p' || c == 'P')
    {
      pProcess();
    }
    else if (c == 'v' || c == 'V')
    {
      vProcess();
    }
    else if (c == 'r' || c == 'R')
    {
      rProcess();
    }
    else if (Letras.find(c) != Letras.end())
    {
      tokenValue += c;
      identifierProcess();
    }
    else
    {
      pos--;
    }
  }
}

void AFD::identifierProcess()
{
  tokenType = TOKEN_TYPES::IDENTIFICADOR;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Letras.find(c) != Letras.end() || Numeros.find(c) != Numeros.end())
    {
      tokenValue += c;
      identifierProcess();
    }
    else
    {
      pos--;
    }
  }
}
