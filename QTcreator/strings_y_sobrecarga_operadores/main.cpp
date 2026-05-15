#include "string.h"
#include <iostream>

using namespace std;

int main()
{
    char cadena[] = "almendro y ciruela";
    String miString(cadena, sizeof(cadena));

    cout<<miString.inicio<<endl;
}
