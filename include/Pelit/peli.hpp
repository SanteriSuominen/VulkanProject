#pragma once
#include "Pelaajat/pelaaja.hpp"
#include <string>
#include <vector>

class peli{
private:
std::string pelinNimi{};
int pelaajienLukumaara = 0;
std::vector<pelaaja> pelaajat; 

public:
peli(const std::string& nimi);
~peli();
void saveGame() const;
void lisaaPelaajia();
};