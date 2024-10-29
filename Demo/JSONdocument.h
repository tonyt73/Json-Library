//---------------------------------------------------------------------------
#ifndef JSONdocumentH
#define JSONdocumentH
//---------------------------------------------------------------------------
#include <list>
#include "JsonFile.h"
//---------------------------------------------------------------------------
using namespace Services;
typedef struct Person
{
    String  First;
    String  Last;
    int     Age;
} _person;
typedef std::list<Person> PersonList;
//---------------------------------------------------------------------------
class JSONdocument : public JsonFile
{
private:
            // File name
            String              m_File;
            String              m_String;
            int                 m_Int;
            float               m_Float;
            bool                m_Boolean;
            Person              m_Person;   // used for object loading
            PersonList          m_Persons;

            void    __fastcall  OnEndObject(const String& object);

protected:
    virtual void    __fastcall  DoSave();   // allow for inherited classes to add to the base save functionality

public:
                    __fastcall  JSONdocument(const String& name);
                    __fastcall ~JSONdocument();

    virtual void    __fastcall  Save();
    virtual bool    __fastcall  Load();
            void    __fastcall  Close();

        __property      String  Text    = { read = m_String, write = m_String };
        __property      int     Integer = { read = m_Int, write = m_Int };
        __property      float   Float   = { read = m_Float, write = m_Float };
        __property      bool    Boolean = { read = m_Boolean, write = m_Boolean };
        __property  PersonList& Persons = { read = m_Persons, write = m_Persons };
};
//---------------------------------------------------------------------------
#endif
