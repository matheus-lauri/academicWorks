template <typename T>
struct FilaC{
    T info[TAM];
    int comeco, fim;
    int cont;
};

template <typename T>
void inicializar(FilaC <T> &f){
    f.comeco = 0;
    f.fim = -1;
    f.cont = 0;
}

template <typename T>
bool inserir( FilaC <T> &f, T valor ){
    if( f.cont == TAM ) return false;
    f.fim = (f.fim == TAM-1) ? 0 : f.fim+1;
    f.cont++;
    f.info[f.fim] = valor;
    return true;
}

template <typename T>
bool retirar( FilaC <T> &f, T &valor ){
    if( f.cont == 0 ) return false;
    valor = f.info[f.comeco];
    f.comeco = (f.comeco == TAM-1) ? 0 : f.comeco+1;
    f.cont--;
    return true;
}
