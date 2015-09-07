//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("SmartList.res");
USEFORM("Main.cpp", frmMain);
USEUNIT("CMyList.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TfrmMain), &frmMain);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
