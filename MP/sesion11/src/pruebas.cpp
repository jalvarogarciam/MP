#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string cadena = "               ,                      ";

    istringstream iss;
    iss.str(cadena);

    string basura;
    if (!(iss>>basura)) cout<< "vacia"<<endl;
    else cout<< "llena"<<endl;
    while (iss>>basura) cout<<"hola"<<endl;
}