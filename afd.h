#include "general.h"

using namespace std;

enum ESTADOS
{
  EST_ERROR,
  OK
};

enum AFD_ERROR_TYPE
{
  EOL,
  UNKNOWN,
  UNEXPECTED
};

typedef struct AFDError
{
  int pos;
  char c;
  AFD_ERROR_TYPE type;
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
  int initialPos;
  int lineNumber;
  bool periodFound;
  AFDError err;
  void afdProcess();
  void firstLetterProcess();
  void identifierProcess();
  void numberProcess();
  void simbolProcess();
  void getToken();
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
  void plusProcess();
  void hyphenProcess();
  void asteriskProcess();
  void slashProcess();
  void equalProcess();
  void lessProcess();
  void biggerProcess();
  void openProcess();
  void closeProcess();
  void comaProcess();
  void semicolonProcess();
  void pointProcess();
  void doubleProcess();
  void notEqualProcess();
  void lessEqualProcess();
  void biggerEqualProcess();
  void assignmentProcess();

public:
  explicit AFD();
  void addLine(string);
  void getResult(vector<Token> *);
  bool processWords();
};
