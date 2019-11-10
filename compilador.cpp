// #include <iostream>
// #include <fstream>
#include "afd.h"

using namespace std;

vector<Token> t;

int main(int argc, char const *argv[])
{
  AFD simpleAFD;
  int nameSize;
  if (argc != 2)
  {
    cerr << "Debe indicar el nombre del archivo" << endl;
    return 1;
  }

  nameSize = strlen(argv[1]);

  if (argv[1][nameSize - 4] != '.' || argv[1][nameSize - 3] != 'p' || argv[1][nameSize - 2] != 'l' || argv[1][nameSize - 1] != '0')
  {
    cerr << "La extension del archivo debe ser  \".pl0\"" << endl;
    return 1;
  }

  initEnv();

  string codeLine;
  ifstream sourceCode(argv[1]);

  while (getline(sourceCode, codeLine, '\n'))
  {
    simpleAFD.addLine(codeLine);
  }

  simpleAFD.processWords();

  simpleAFD.getResult(&t);

  for (int i = 0; i < t.size(); i++)
  {
    cout << "Token " << i << ":" << endl;
    cout << "\tType: " << t[i].tipo << endl;
    cout << "\tValue: " << t[i].valor << endl;
  }

  sourceCode.close();
  cout << endl;

  return 0;
}
