#include "Pelit/peli.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

peli::peli(const std::string& nimi) : pelinNimi(nimi)
{
    //lisaaPelaajia();
    //saveGame();
}

peli::~peli(){}

void peli::saveGame() const
{
    std::string input = "";
    if(fs::exists("Pelit"))
    {
        if(fs::exists("Pelit/" + pelinNimi + ".txt"))
        {
            std::cout << "This file already exists! Are you sure you want overwrite this savefile? (Y/N): ";
            std::getline(std::cin, input);
            
            if(input == "Y" || input == "y")
            {
                std::ofstream outFile("Pelit/" + pelinNimi + ".txt");
                outFile << pelinNimi + "\n";
                outFile << pelaajienLukumaara << "\n";
                for (int i = 0; i < pelaajienLukumaara; i++) 
                {
                    outFile << pelaajat[i].getnimi();
                    outFile << pelaajat[i].getPistemaara();
                }
            }

            else
            {
                std::cout << "Saving was interupted by user.";
                return;
            }
        }
    }
    else 
    {
        fs::create_directory("Pelit");
        std::ofstream outFile("Pelit/" + pelinNimi + ".txt");
        outFile << pelinNimi + "\n";
        outFile << pelaajienLukumaara << "\n";
        for (int i = 0; i < pelaajienLukumaara; i++) 
        {
            outFile << pelaajat[i].getnimi();
            outFile << pelaajat[i].getPistemaara();
        }
    }
}

void peli::lisaaPelaajia()
{
    std::string input = "";
    std::cout << "Amount of Players: ";
    std::cin >> pelaajienLukumaara;
    
    for (int i = 0; i < pelaajienLukumaara; i++) 
    {
        std::cout << i + 1 << ".nimi: ";
        std::cin >> input;
        pelaajat.push_back(pelaaja(input));
    }
}

