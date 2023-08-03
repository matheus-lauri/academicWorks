template <typename T>
struct Pilha{
    T info[TAM];
    int topo;
};

template <typename T>
void inicializar(Pilha <T> &p){
    p.topo = -1;
}

template <typename T>
bool inserir( Pilha <T> &p, T valor ){
    if( p.topo == TAM-1 ) return false;
    p.topo++;
    p.info[p.topo] = valor;
    return true;
}

template <typename T>
bool retirar( Pilha <T> &p, T &valor ){
    if( p.topo == -1 ) return false;
    valor = p.info[p.topo];
    p.topo--;
    return true;
}
