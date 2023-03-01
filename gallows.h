#ifndef WITH_TESTS_GALLOWS_H
#define WITH_TESTS_GALLOWS_H

#include <fstream>

// h. file to be called by tests, suppresses
//  "multiple definition s of function" error
bool test1(int ch);
bool test2(std::ifstream &dict);
bool GamePlay(char star[10], char word[10], int letter);
void PartyGame();
void SoloGame();

// Start() is never used in test project ->
//  explanation in gallows.cpp, main()
void Start();

#endif //WITH_TESTS_GALLOWS_H
