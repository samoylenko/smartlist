//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "CMyList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;
//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnTestClick(TObject *Sender)
{
    int nNodes = StrToInt( edtNodes->Text );

    CMyList* lst = new CMyList;

    if( lcb->Checked ) Log->Lines->Add( "==== log start ===");

    for( int i = 1; i < nNodes; i++ )
    {
        if( lcb->Checked ) Log->Lines->Add( "Adding 1 empty node" );
        lst->AddToEnd();
        if( lcb->Checked ) Log->Lines->Add( "lst->m_nNodes = " + IntToStr( lst->m_nNodes ) );
    }

    if( lcb->Checked ) Log->Lines->Add( ">>> deleting all nodes <<<");

    for( int i = 1; i < nNodes; i++ )
    {
        if( lcb->Checked ) Log->Lines->Add( "deleting 1 node" );
        lst->DeleteLast();
        if( lcb->Checked ) Log->Lines->Add( "lst->m_nNodes = " + IntToStr( lst->m_nNodes ) );
    }

    if( lcb->Checked ) Log->Lines->Add( "==== log end ===");

    ShowMessage( "Test complete!" ); 

    delete lst;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
    delete m_pList;
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::FormCreate(TObject *Sender)
{
    m_pList = new CMyList();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnAddClick(TObject *Sender)
{
    AnsiString name = InputBox( "Запрос", "Введите Имя:", "<empty>" );

    m_pList->AddToEnd( name );

    MakeList();
}
//---------------------------------------------------------------------------
void __fastcall TfrmMain::btnDeleteClick(TObject *Sender)
{
    m_pList->DeleteLast();

    MakeList();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::MakeList()
{
    CMyListNode *pNode = m_pList->GetLastNode();

    lb->Items->Clear();

    for( int i = 1; i <= m_pList->GetNodesCount(); i++ )
    {
        lb->Items->Add( pNode->GetName() );
        pNode = pNode->GetParent();
    }
}
void __fastcall TfrmMain::btnCloseClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::btnClearClick(TObject *Sender)
{
    m_pList->Clear();
    MakeList();
}
//---------------------------------------------------------------------------

