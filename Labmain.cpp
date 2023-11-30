#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool is_filename_valid(const string& filename) {

    return !filename.empty(); && filename.size < 256;
}