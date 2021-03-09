#include "TextFile.h"

string TextFile :: loadFileName()
{
    return FILE_NAME;
}

bool TextFile :: isFileEmpty()
{   fstream textfileA;
    bool isEmpty = true;
    textfileA.open(loadFileName().c_str(), ios::app);

    if (textfileA.good() == true)
    {
        textfileA.seekg(0, ios::end);
        if (textfileA.tellg() != 0)
            isEmpty = false;
    }

    textfileA.close();
    return isEmpty;
}
