#include "general.h"

using namespace std;

set<char> Letras;
set<char> Numeros;
set<char> Simbolos;

void initEnv()
{
  char a = 'a';
  char A = 'A';
  char cero = '0';

  for (int i = 0; i < 26; i++)
  {
    Letras.insert((char)(a + i));
    Letras.insert((char)(A + i));
  }

  for (int i = 0; i < 10; i++)
  {
    Numeros.insert((char)(cero + i));
  }

  Simbolos.insert('<');
  Simbolos.insert('>');
  Simbolos.insert('=');
  Simbolos.insert('+');
  Simbolos.insert('-');
  Simbolos.insert('*');
  Simbolos.insert('/');
  Simbolos.insert('.');
  Simbolos.insert(',');
  Simbolos.insert(';');
  Simbolos.insert(':');
  Simbolos.insert('(');
  Simbolos.insert(')');
  Simbolos.insert(' ');
  Simbolos.insert('\t');
}
