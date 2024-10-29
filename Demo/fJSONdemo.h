//---------------------------------------------------------------------------
#ifndef fJSONdemoH
#define fJSONdemoH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Samples.Spin.hpp>
#include "JSONdocument.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TEdit *Edit1;
    TLabel *Label1;
    TLabel *Label2;
    TSpinEdit *SpinEdit1;
    TLabel *Label3;
    TEdit *Edit2;
    TCheckBox *CheckBox1;
    TListBox *ListBox1;
    TLabel *Label4;
    TLabel *Label5;
    TEdit *Edit3;
    TLabel *Label6;
    TEdit *Edit4;
    TLabel *Label7;
    TSpinEdit *SpinEdit2;
    TButton *Button1;
    TMemo *Memo1;
    void __fastcall OnChange(TObject *Sender);
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
    JSONdocument*   m_Document;
    void    __fastcall UpdateJSON();
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
