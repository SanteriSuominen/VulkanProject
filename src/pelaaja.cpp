#include "Pelaajat/pelaaja.hpp"

pelaaja::pelaaja(std::string& _nimi)
{
    nimi = _nimi;
}
pelaaja::~pelaaja()
{
}
int pelaaja::lisaapisteita(int& maara)
{
    pistemaara += maara;
    return pistemaara;
}

std::string pelaaja::getnimi() const 
{
    return nimi;
}

int pelaaja::getPistemaara() const
{
    return pistemaara;
}