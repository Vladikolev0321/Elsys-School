#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Smetki
{
    string IBAN;
    int nalichnost;
public:
    Smetki(string IBAN, int nalichnost)
    {
        this->IBAN = IBAN;
        this->nalichnost = nalichnost;
    }
};
class PayingSmetka : public Smetki
{

};
class CreditSmetka : public Smetki
{
    
};      
class User
{
    string username;
    string password;
    vector<Smetki> smetki;
public:
    User(string username, string password)
    {
        this->username = username;
        this->password = password;
    }
};