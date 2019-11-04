#include "general.h"

using namespace std;

void initEnv()
{
  char a = 'a';
  char A = 'A';
  char cero = '0';
  for (int i = 0; i < 26; i++)
  {
    Letras.insert(a + i);
    Letras.insert(A + i);
  }
  for (int i = 0; i < 10; i++)
  {
    Numeros.insert(cero + i);
  }
}