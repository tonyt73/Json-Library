# Json Library
 A C++ Builder JSON object/file helper
 This project allows you to easily manage Json files and there associated internal C++ objects.

**Writing**

The beauty (well in my eyes) is in how the objects are written/serialized to Json.
The example below shows that the code represents what the file contents will look like.

```
    Open(m_File);
    Push("SingleValues");
        Write("String", m_String);
        Write("Int", m_Int);
        Write("Float", m_Float);
        Write("Boolean", m_Boolean);
    Pop();  // Single values
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

    DoSave();	// Allow derived classes to write additional objects to our file
    JsonFile::Close();
```

**Loading**
Loading is mostly handled by the base JsonFile class by mapping objects/types to loader variables.
```
m_PropertyMap["String"] = &m_String;
```
Here we are mapping a property poorly named `"String"` to a class member called `m_String`.
When the loading code finds a Json property called `"String"` it will place the read value into `m_String`.
All basic types are supported: `String, int, float & bool`.

*Array's of objects*
In the above example we saved an `array of persons` (people) and the array contains the `person` type.
We need a helper object in our Json document class (derived from `JsonFile` that is an instance of the object type (`person`) for the loader to set each value of the object during the load process.
```
    m_PropertyMap["Persons[].First"] = &m_Person.First;
    m_PropertyMap["Persons[].Last"] = &m_Person.Last;
    m_PropertyMap["Persons[].Age"] = &m_Person.Age;
```
So here we are mapping all fields of the `person` type to each of the Json object fields.
Once the end of the object is found by the Json loader, it will fire a `OnEndObject` event in your Json document for you to handle placing the object into your array member.
```
void __fastcall JSONdocument::OnEndObject(const String& object)
{
    if (object == "Persons[]")
    {
        m_Persons.push_back(m_Person);
    }
}
```

**Multi-inheritence**
You can inherit from a base Json document type multiple times. see https://github.com/tonyt73/AGD-Studio/tree/master/Source/Project for detailed examples.


**More reading**
These classes were developed in the AGD Studio project. https://github.com/tonyt73/AGD-Studio
So for more usage examples see that project.