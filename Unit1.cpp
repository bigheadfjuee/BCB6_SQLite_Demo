//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
#include "sqlite-amalgamation/sqlite3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

sqlite3* sl3DB = NULL;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{


}
//---------------------------------------------------------------------------
void AnsiUnicodeUTF8() // BCB6 + sqlite3.c 要自己處理 UTF8 字元
{
  AnsiString ansi;
  WideString wStr;   //unicode
  UTF8String utf8;

  ansi = wStr;  //自動轉換
  wStr = ansi;  //自動轉換

  utf8 = AnsiToUtf8(ansi);
  ansi = Utf8ToAnsi(utf8);

  // Unicode 的好像只能轉 LE (Little Endian)
  // UTF8 的轉換 要把 BOM 去掉
}
//---------------------------------------------------------------------------
int Callback_ShowCol(void* unused, int columenCount, char** columnValue, char** columnName)
{
  AnsiString str;
  UTF8String utf8;

  Form1->Memo1->Lines->Add("---------");

  for(int i=0 ; i<columenCount ; i++ )
  {
    str = str.sprintf( "%s = %s" , columnName[i] , Utf8ToAnsi(columnValue[i]));
    Form1->Memo1->Lines->Add(str);
  }

  return SQLITE_OK;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnOpenClick(TObject *Sender)
{
  int ret =  sqlite3_open("test.db3", &sl3DB);
  Memo1->Lines->Add("sqlite3_open : " + AnsiString(ret));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnCloseClick(TObject *Sender)
{
  int ret = sqlite3_close(sl3DB);
  Memo1->Lines->Add("sqlite3_close : " + AnsiString(ret));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnQueryClick(TObject *Sender)
{
  char *errmsg;
  AnsiString  sql = "select * from MyTable";
  int ret = sqlite3_exec(sl3DB, sql.c_str(), Callback_ShowCol, NULL, &errmsg);
  Memo1->Lines->Add("sqlite3_exec : " + AnsiString(ret));
  Memo1->Lines->Add(errmsg);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnSQLClick(TObject *Sender)
{
  char *errmsg;
  AnsiString sql = "CREATE TABLE IF NOT EXISTS MyTable2( column1 int, column2 char(20) )";
  int ret = sqlite3_exec(sl3DB, sql.c_str(), NULL, NULL, &errmsg);
  Memo1->Lines->Add("sqlite3_exec : " + AnsiString(ret));
  Memo1->Lines->Add(errmsg);

  sql = "INSERT INTO MyTable VALUES( 1 , 'Hello World' )";
  ret = sqlite3_exec(sl3DB, sql.c_str(), NULL, NULL, &errmsg);
  Memo1->Lines->Add("sqlite3_exec : " + AnsiString(ret));
  Memo1->Lines->Add(errmsg);
}
//---------------------------------------------------------------------------

