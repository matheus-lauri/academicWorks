template <typename T>
struct Fila{
    T info[TAM];
    int comeco, fim;
};

template <typename T>
void inicializar(Fila <T> &f){
    f.comeco = 0;
    f.fim = -1;
}

template <typename T>
bool inserir( Fila <T> &f, T valor ){
    if( f.fim == TAM-1 ) return false;
    f.fim++;
    f.info[f.fim] = valor;
    return true;
}

template <typename T>
bool retirar( Fila <T> &f, T &valor ){
    if( f.comeco > f.fim ) return false;
    valor = f.info[f.comeco];
    f.comeco++;
    return true;
}
