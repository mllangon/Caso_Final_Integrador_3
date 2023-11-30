#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool is_filename_valid(const string& filename) {

    return !filename.empty(); && filename.size < 256;
}

void load_script(const char* filename, bool show_script = false){
    if(!is_filename_valid(filename)){
        cout << "Nombre no encontrado: " << endl;
        return;
    }


}