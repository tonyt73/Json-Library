//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#include "JSONdocument.h"
#include "File.h"
#include "Folders.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall JSONdocument::JSONdocument(const String& name)
: JsonFile()
, m_File(name)
{
    // json loading properties
    m_PropertyMap["String"] = &m_String;
    m_PropertyMap["Int"] = &m_Int;
    m_PropertyMap["Float"] = &m_Float;
    m_PropertyMap["Boolean"] = &m_Boolean;
    m_PropertyMap["Persons[].First"] = &m_Person.First;
    m_PropertyMap["Persons[].Last"] = &m_Person.Last;
    m_PropertyMap["Persons[].Age"] = &m_Person.Age;
}
//---------------------------------------------------------------------------
__fastcall JSONdocument::~JSONdocument()
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall JSONdocument::Save()
{
    Open(m_File);
    Push("SingleValues");
        Write("String", m_String);
        Write("Int", m_Int);
        Write("Float", m_Float);
        Write("Boolean", m_Boolean);
    Pop();  // Single values

    // write arrays
    ArrayStart("Persons");
    for (const auto& person : m_Persons)
    {
        StartObject();
            Write("First", person.First);
            Write("Last", person.Last);
            Write("Age", person.Age);
        EndObject();
    }
    ArrayEnd(); // Persons

    DoSave();   // Allow derived classes to write additional objects to our file
    JsonFile::Close();
}
//---------------------------------------------------------------------------
bool __fastcall JSONdocument::Load()
{
    if (Services::File::Exists(m_File))
    {
        // yes, load it
        JsonFile::Load(m_File);
        return true;
    }
    return false;
}
//---------------------------------------------------------------------------
void __fastcall JSONdocument::Close()
{
    Save();
}
//---------------------------------------------------------------------------
void __fastcall JSONdocument::OnEndObject(const String& object)
{
    if (object == "Persons[]")
    {
        m_Persons.push_back(m_Person);
    }
}
//---------------------------------------------------------------------------
void __fastcall JSONdocument::DoSave()
{
    // Should be overridden to add extra values to the file saving from derived classes
}
//---------------------------------------------------------------------------
