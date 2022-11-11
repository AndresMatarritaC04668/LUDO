#include "FileReader.h"

/**
 * @brief Construct a new File Reader:: File Reader object
 * 
 */
FileReader::FileReader() {
    this->file_exist = false;
}

/**
 * @brief Constructor por argumentos de objeto filereader.
 * 
 * @param filename el nombre del archivo a abrir. Incluir extension.
 */
FileReader::FileReader(string filename) {
    this->lector.open(filename, ifstream::in);
    if (this->lector.fail()) {
        this->file_exist = false;
    } else {
        this->file_exist = true;
    }
}

/**
 * @brief Habre un archivo cuyo nombre es dado por argumento.
 * 
 * @param filename Nombre del archivo. Incluir extension. 
 * @return true Si se pudo abrir.
 * @return false Si no se pudo abrir.
 */
bool FileReader::openFile(string filename) {
    this->lector.open(filename, ifstream::in);

    if (this->lector.fail()) {
        this->file_exist = false;
    } else {
        this->file_exist = true;
    }

    return this->file_exist;
}

/**
 * @brief Cierra un archivo abierto, si es que existe. Hacer esto siempre tras
 * terminar de cargar.
 * 
 */
void FileReader::closeFile() {
    this->lector.close();
    this->line.clear();
}

/**
 * @brief Devuelve una linea del archivo abierto.
 * 
 * @return string La linea en cuestion. Copiar esta string en otra.
 */
string FileReader::getLine() {
    if (!(this->lector.eof())) {
        getline(this->lector, this->line);
        return this->line;
    } else {
        return NULL;
    }
}

/**
 * @brief Devuelve un booleano que indica si ya se llego al final del archivo. 
 * 
 * @return true 
 * @return false 
 */
bool FileReader::end_of_file() {
    return this->lector.eof();
}

/**
 * @brief Genera un archivo con el nombre dado. Por favor incluir la extension
 * de .json.
 * 
 * @param filename Nombre del archivo a crear.
 */
void FileReader::createFile(string filename) {
    ofstream { filename };
}