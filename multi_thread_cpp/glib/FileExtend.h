#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <dirent.h>
using namespace std;
void remove_adjacent_duplicate(string& dat1, string dat2);
vector<string> split(string dat, string separator);

void WriteVector(string path,vector<int>& out);

void list_all_files(string path, vector<string>& filepath, vector<string>& filename);