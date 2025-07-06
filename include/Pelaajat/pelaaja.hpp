#pragma once

#include <string>

class pelaaja
{
private:
std::string nimi = "";
int pistemaara = 0;

public:
pelaaja(std::string&);
~pelaaja();
int lisaapisteita(int&);
std::string getnimi() const;
int getPistemaara() const;
};
