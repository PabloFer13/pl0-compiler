#include <iostream>
#include <fstream>
#include "general.h"

using namespace std;

int main(int argc, char const *argv[])
{
  if (argc != 2)
  {
    cerr << "Debe indicar el nombre del archivo" << endl;
    return 1;
  }

  initEnv();

  string codeLine;
  ifstream sourceCode("textoEjemplo.pl");

  while (getline(sourceCode, codeLine, '\n'))
  {
    // Do stuff
  }

  sourceCode.close();
  cout << endl;

  return 0;
}
