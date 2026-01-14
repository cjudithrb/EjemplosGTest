struct Objeto {
    int valor;
    
    Objeto(int v = 100) : valor(v) {}
    
    bool estaActivo() const {
        return valor != 0;  // o la lógica que necesites
    }
};

Objeto* crearObjeto() {
    return new Objeto(100);
}