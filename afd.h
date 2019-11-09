#include <string>
#include <stack>
#include <queue>
#include "general.h"

using namespace std;

enum ESTADOS
{
  TERMINAL,
  NO_TERMINAL,
  EST_ERROR,
  INICIAL
};

typedef struct AFDError
{
  int pos;
  char c;
} AFDError;

class AFD
{
private:
  queue<Token> result;
  queue<string> lines;
  ESTADOS estado;
  string tokenValue;
  string codeLine;
  TOKEN_TYPES tokenType;
  Token currentToken;
  int pos;
  int lineNumber;
  AFDError err;
  void afdProcess();
  void firstLetterProcess();
  void identifierProcess();
  void oProcess();
  void bProcess();
  void eProcess();
  void iProcess();
  void tProcess();
  void wProcess();
  void dProcess();
  void cProcess();
  void pProcess();
  void vProcess();
  void rProcess();
  void odProcess();
  void beProcess();
  void enProcess();
  void elProcess();
  void inProcess();
  void ifProcess();
  void thProcess();
  void whProcess();
  void wrProcess();
  void doProcess();
  void caProcess();
  void coProcess();
  void prProcess();
  void vaProcess();
  void reProcess();
  void oddProcess();
  void begProcess();
  void endProcess();
  void elsProcess();
  void intProcess();
  void theProcess();
  void whiProcess();
  void wriProcess();
  void calProcess();
  void conProcess();
  void proProcess();
  void varProcess();
  void reaProcess();
  void begiProcess();
  void elseProcess();
  void thenProcess();
  void whilProcess();
  void writProcess();
  void callProcess();
  void consProcess();
  void procProcess();
  void readProcess();
  void beginProcess();
  void whileProcess();
  void writeProcess();
  void constProcess();
  void proceProcess();
  void procedProcess();
  void proceduProcess();
  void procedurProcess();
  void procedureProcess();

public:
  explicit AFD();
  void addLine(string);
  bool processWords();
  queue<Token> getResult();
};