#include<iostream>
#include<fstream>
#include<string>
using namespace std;

bool is_filename_valid(const string& filename) {
    return !filename.empty() && filename.size() < 256;
}

void load_script(const char* filename, bool show_script = false) {
    if (!is_filename_valid(filename)) {
        cout << "Nombre de archivo no válido." << endl;
        return;
    }

    ifstream file(filename);
    if (!file) {
        cout << "Error al abrir el archivo: " << filename << " ." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        if (file.fail()) {
            cout << "Error al leer el archivo: " << filename << " ." << endl;
            file.close();
            return;
        }
        if (show_script) {
            cout << line << endl;
        }
    }

    if (file.bad()) {
        cerr << "Error de lectura al final del archivo: " << filename << " ." << endl;
    }
    file.close();
}

void load_script() {
    string filename;
    cout << "Ingrese el nombre del archivo: ";
    getline(cin, filename);

    if (!is_filename_valid(filename)) {
        cout << "Nombre de archivo no válido." << endl;
        return;
    }

    load_script(filename.c_str(), true);
}

int main() {
    load_script();
    return 0;
}
