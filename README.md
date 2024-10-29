# Json Library
 A C++ Builder JSON object/file helper

This project allows you to easily manage Json files and there associated internal C++ objects.

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

    //DoSave();
    JsonFile::Close();
```

