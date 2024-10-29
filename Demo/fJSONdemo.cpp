//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
#include "fJSONdemo.h"
#include "file.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
const String g_JsonFile = "properties.json";
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
: TForm(Owner)
, m_Document(nullptr)
{
    m_Document = new JSONdocument(g_JsonFile);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::OnChange(TObject *Sender)
{
    m_Document->Text = Edit1->Text;
    m_Document->Integer = SpinEdit1->Value;
    m_Document->Boolean = CheckBox1->Checked;
    try {
        m_Document->Float = StrToFloat(Edit2->Text);
    } catch (...) {
        m_Document->Float = 123.456;
    }
    m_Document->Save();
    UpdateJSON();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    Person p;
    p.First = Edit3->Text;
    p.Last = Edit4->Text;
    p.Age = SpinEdit2->Value;
    m_Document->Persons.push_back(p);
    ListBox1->Items->Add(p.First + "," + p.Last + "," + IntToStr(p.Age));
    m_Document->Save();
    UpdateJSON();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::UpdateJSON()
{
    Memo1->Lines->Clear();

    auto lines = Services::File::ReadLines(g_JsonFile);
    for (auto line : lines) {
        Memo1->Lines->Add(line);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    UpdateJSON();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
    UpdateJSON();
}
//---------------------------------------------------------------------------

