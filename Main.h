//---------------------------------------------------------------------------

#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CMyList.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// IDE-managed Components
    TGroupBox *GroupBox1;
    TGroupBox *GroupBox2;
    TListBox *lb;
    TBitBtn *btnDelete;
    TBitBtn *btnAdd;
    TMemo *Log;
    TBitBtn *btnClose;
    TBitBtn *btnTest;
    TEdit *edtNodes;
    TLabel *Label1;
    TCheckBox *lcb;
    TBitBtn *btnClear;
    void __fastcall btnTestClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall btnAddClick(TObject *Sender);
    void __fastcall btnDeleteClick(TObject *Sender);
    void __fastcall btnCloseClick(TObject *Sender);
    void __fastcall btnClearClick(TObject *Sender);
private:	// User declarations
public:
    CMyList * m_pList;		// User declarations
    __fastcall TfrmMain(TComponent* Owner);
    void __fastcall MakeList();
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
