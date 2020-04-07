//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TMemo *Memo1;
  TPanel *Panel1;
  TButton *btnOpen;
  TButton *btnQuery;
  TButton *btnClose;
  TButton *btnSQL;
  void __fastcall btnOpenClick(TObject *Sender);
  void __fastcall btnCloseClick(TObject *Sender);
  void __fastcall btnQueryClick(TObject *Sender);
  void __fastcall btnSQLClick(TObject *Sender);
private:	// User declarations

public:		// User declarations
  __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

int Callback_ShowCol(void* para, int columenCount, char** columnValue, char** columnName);
//---------------------------------------------------------------------------
#endif
