#include <string>
#include <cctype>
using namespace std;

bool esPasswordSegura(const string& pwd) {
    if (pwd.length() < 8) return false;
    
    bool tieneMayuscula = false;
    bool tieneNumero = false;
    
    for (char c : pwd) {
        if (isupper(c)) tieneMayuscula = true;
        else if (isdigit(c)) tieneNumero = true;
    }
    
    return tieneMayuscula && tieneNumero;
}