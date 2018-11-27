/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 22 novembre 2018, 10:27
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int readPGM(string fileName, int **grayLevel) {
    int w, h, maxGray;
    
    FILE* file = fopen(fileName, "r");
    string str;
    file >> str;
    file >> str;
    file >> w;
    file >> h;
    file >> maxGray;
    grayLevel = new int*[h];
    for(int i = 0; i < h; i++) {
        grayLevel[i] = new int[w];
        for(int j = 0; j < w; j++)
            file >> grayLevel[i][j];
    }
    fclose(file);
    return maxGray;
}

void writePGM(string fileName, int **grayLevel, int maxGray) {
    FILE* file = fopen(fileName, "w");
    
    file << "P2" << endl;
    file << "#" << endl;
    file << sizeof(grayLevel[0]) << "  " << sizeof(grayLevel) << endl;
    file << maxGray << endl;
    
    for(int i = 0; i < sizeof(grayLevel); i++) {
        for(int j = 0; j < sizeof(grayLevel[0]); j++)
            file << grayLevel[i][j] << endl;
    }
    
    fclose(file);
}

int main() {
    
    cout << "Hello World" << endl;
    
    return 0;
}

