#include "afd.h"

using namespace std;

AFD::AFD()
{
  estado = OK;
  periodFound = false;
  tokenType = TOKEN_TYPES::NULL_TOKEN;
  tokenValue = "";
}

void AFD::addLine(string line)
{
  lines.push(line);
}

void AFD::getResult(vector<Token> *v)
{
  while (!result.empty())
  {
    v->push_back(result.front());
    result.pop();
  }
}

void AFD::getToken()
{
  Token t;
  t.tipo = tokenType;
  t.valor = tokenValue;
  t.initialPos = initialPos;
  result.push(t);
  tokenType = TOKEN_TYPES::NULL_TOKEN;
  tokenValue.clear();
}

bool AFD::processWords()
{
  bool everythingRight = true;
  pos = 0;
  lineNumber = 0;
  estado = OK;
  while (!lines.empty() && estado != EST_ERROR)
  {
    codeLine.clear();
    pos = 0;
    estado = OK;
    codeLine = lines.front();
    while (pos < codeLine.size() && estado != EST_ERROR)
    {
      afdProcess();
    }
    lines.pop();
    if (estado != OK)
    {
      switch (err.type)
      {
      case EOL:
        std::cerr << "Unexpected end of line at line: " << lineNumber << " position: " << err.pos << endl;
        break;

      case UNKNOWN:
        std::cerr << "Unknown char: " << err.c << " at line: " << lineNumber << " position: " << err.pos << endl;
        break;

      case UNEXPECTED:
        std::cerr << "Unexpected char: " << err.c << " at line: " << lineNumber << " position: " << err.pos << endl;
        break;

      default:
        std::cerr << "Unhandled Error at line: " << lineNumber << " position: " << err.pos << " character: " << err.c << endl;
        break;
      }
    }
    lineNumber++;
  }
}

void AFD::afdProcess()
{
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    initialPos = pos;
    pos++;
    if (Simbolos.find(c) != Simbolos.end())
    {
      pos--;
      simbolProcess();
    }
    else if (Letras.find(c) != Letras.end())
    {
      pos--;
      firstLetterProcess();
    }
    else if (Numeros.find(c) != Numeros.end())
    {
      pos--;
      numberProcess();
    }
    else
    {
      estado = EST_ERROR;
      err.c = c;
      err.pos = pos - 1;
      err.type = UNKNOWN;
    }
  }
}

void AFD::firstLetterProcess()
{
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    tokenType = TOKEN_TYPES::IDENTIFIER;
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
  tokenType = TOKEN_TYPES::IDENTIFIER;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Letras.find(c) != Letras.end() || Numeros.find(c) != Numeros.end())
    {
      tokenValue += c;
      identifierProcess();
    }
    // else if (c == ' ')
    // {
    //   getToken();
    // }
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

void AFD::numberProcess()
{
  tokenType = TOKEN_TYPES::NUMBER;
  if (pos < codeLine.size() && estado != EST_ERROR)
  {
    char c = codeLine[pos];
    pos++;
    if (Numeros.find(c) != Numeros.end())
    {
      tokenValue += c;
      numberProcess();
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

void AFD::simbolProcess()
{
  if (tokenValue.size() > 0)
  {
    getToken();
  }
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
  }
  else
  {
    getToken();
  }
}
