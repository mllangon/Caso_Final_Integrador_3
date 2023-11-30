#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

struct ColorConsole {
    static constexpr auto fg_blue = "\033[34m";
    static constexpr auto bg_white = "\033[47m";
};

struct ConsoleBox {
    void new_text() {/*...*/}
    void set_text(const string &text) { cout << text << endl; }
};

ConsoleBox *consoleBox = new ConsoleBox; // suponemos que ya está inicializado

bool is_filename_valid(const char* filename) {
    if (!filename || std::strlen(filename) == 0 || std::strlen(filename) >= 500) {
        return false;
    }
    // Añade aquí más reglas si es necesario.
    return true;
}

void load_script(const char* filename, bool show_script = false) {
    if (!is_filename_valid(filename)) {
        cerr << "Nombre de archivo no válido o demasiado largo: " << filename << endl;
        return;
    }

    string script;
    FILE* f = nullptr;
    try {
        f = fopen(filename, "rb");
        if (!f) {
            cerr << "Error de apertura de " << filename << endl;
            return;
        }

        int c;
        char buf[4001];
        while ((c = fread(buf, 1, 4000, f)) > 0) {
            buf[c] = 0;
            script.append(buf);
        }

        if (feof(f) && script.empty()) {
            cerr << "Archivo vacío: " << filename << endl;
            fclose(f);
            return;
        }

        if (ferror(f)) {
            cerr << "Error durante la lectura del archivo: " << filename << endl;
            fclose(f);
            return;
        }

        if (fclose(f) != 0) {
            cerr << "Error al cerrar el archivo: " << filename << endl;
            return;
        }
        f = nullptr;

        if (show_script) {
            cout << ColorConsole::fg_blue << ColorConsole::bg_white;
            cout << script << endl;
        }
        consoleBox->new_text();
        consoleBox->set_text(script);
    }
    catch (...) {
        cerr << "Excepción durante la operación con el archivo" << endl;
        if (f) fclose(f);
    }
}

void load_script() {
    char filename[500];
    printf("Archivo: ");
    scanf("%499s", filename);
    load_script(filename, true);
}

int main() {
    load_script();
    return 0;
}
