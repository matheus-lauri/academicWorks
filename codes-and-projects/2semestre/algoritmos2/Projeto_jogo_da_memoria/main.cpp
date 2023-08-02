  #include <iostream>
  #include <stdio.h>
  #include <stdlib.h>
  #include <time.h>
  #include <locale.h>

  using namespace std;

  int main()
  {
  int i, j, k, l, m, n, o, inicio, jogada_1, jogada_2, selecao_matriz, pontuacao, mat_oculta [4] [4];
  string nome;
  int mat_transposta [4] [4], mat_inv_linha [4] [4], mat_inv_coluna [4] [4], mat_jogo[4][4];
  int mat_principal [4] [4] = {3,4,7,6,
  1,2,5,8,
  1,3,5,7,
  2,4,6,8};


  setlocale(LC_ALL, "Portuguese");
  pontuacao = 0;

  /// Criação transposta

  for ( i = 0 ; i < 4 ; i++ ){
  for ( j = 0 ; j < 4 ; j++ ){
  mat_transposta[i][j] = mat_principal[j][i];
  }
  }

  /// Matriz invertida por linha

  for ( i = 0 ; i < 4 ; i++ ){
  for ( j = 0 ; j < 4 ; j++){
  if ( i == 0 ){
  mat_inv_linha [i+3] [j] = mat_principal[i][j];
  }
  if ( i == 1 ){
  mat_inv_linha [i+1] [j] = mat_principal[i][j];
  }
  if ( i == 2 ){
  mat_inv_linha [i-1] [j] = mat_principal[i][j];
  }
  if ( i == 3 ){
  mat_inv_linha [i-3] [j] = mat_principal[i][j];
  }
  }
  }

  cout << endl;

  /// Matriz invertida por coluna

  for ( i = 0 ; i < 4 ; i++ ){
  for ( j = 0 ; j < 4 ; j++){
  if ( j == 0 ){
  mat_inv_coluna [i] [j+3] = mat_principal[i][j];
  }
  if ( j == 1 ){
  mat_inv_coluna [i] [j+1] = mat_principal[i][j];
  }
  if ( j == 2 ){
  mat_inv_coluna [i] [j-1] = mat_principal[i][j];
  }
  if ( j == 3 ){
  mat_inv_coluna [i] [j-3] = mat_principal[i][j];
  }
  }
  }

  /// Matriz oculta

  for ( i = 0 ; i < 4 ; i++ ){
  for ( j = 0 ; j < 4 ; j++){
  mat_oculta [i] [j] = 0 ;
  }
  }

  /// Inicio Interface

  system("CLS");

  cout << "*************************************************" << endl;
  cout << "* *" << endl;
  cout << "* Jogo da memoria *" << endl;
  cout << "* Feito por Giuseppe Sandrini *" << endl;
  cout << "* *" << endl;
  cout << "*************************************************" << endl;

  cout << "\n Selcione o que deseja fazer agora:" << endl;
  cout << "\n 1 - Aprender" << endl;
  cout << " 2 - Jogar" << endl;
  cout << " 3 - Sair" << endl;

  cin >> inicio;

  switch (inicio){

  case 1:
 system("CLS");
 cout << "Seja bem vindo ao Jogo da Memoria, feito por Giuseppe Sandrini." << endl;
 system("pause");
 system("CLS");
 cout << "Qual seu nome?" << endl;
 cin >> nome ;
 system("CLS");
 cout << "Muito bem " << nome << ", vamos ao jogo! Vou te explicar como irá funcionar a seleção das cartas." << endl;
 system("pause");
 system("CLS");
 cout << "Primeiro irei te pedir a linha da primeira carta desejada, depois a coluna." << endl;
 system("pause");
 system("CLS");
 cout << "Depois pedirei o mesmo para a segunda carta." << endl;
 system("pause");
 system("CLS");
 cout << "Vou te passar um esquema pra ficar mais facil!" << endl;
 system("pause");
 system("CLS");
 cout << "\n 1.1 1.2 1.3 1.4 \n 2.1 2.2 2.3 2.4 \n 3.1 3.2 3.3 3.4 \n 1.1 2.2 3.3 4.4" << endl;
 cout << "\n " << endl;
 system("pause");
 system("CLS");
 cout << "Tudo pronto, bora jogar!" << endl;
 system("pause");
 system("CLS");
 break;
 case 2:
 system("CLS");
 break;
 case 3:
 system("CLS");
 return 0;
 break;
 }

 /// Seleção da matriz que será usada no jogo

 srand(time(NULL)) ;

 selecao_matriz = rand() % 3 ;

 switch ( selecao_matriz ){

 case 0:

 for ( i = 0 ; i < 4 ; i++ ){
 for ( j = 0 ; j < 4 ; j++){
 mat_jogo [i] [j] = mat_principal [i] [j] ;
 }
 }
 break;

 case 1:

 for ( i = 0 ; i < 4 ; i++ ){
 for ( j = 0 ; j < 4 ; j++){
 mat_jogo [i] [j] = mat_inv_coluna [i] [j] ;
 }
 }
 break;

 case 2:

 for ( i = 0 ; i < 4 ; i++ ){
 for ( j = 0 ; j < 4 ; j++){
 mat_jogo [i] [j] = mat_inv_linha [i] [j] ;
 }
 }
 break;

 case 3:

 for ( i = 0 ; i < 4 ; i++ ){
 for ( j = 0 ; j < 4 ; j++){
 mat_jogo [i] [j] = mat_transposta [i] [j] ;
 }
 }
 break;


 }



 /// Jogo

 for ( k=1 ; k<=24 ; k++ ) {

 cout <<"Jogada " << k << " de 24. \n" << endl;

 for ( i = 0 ; i < 4 ; i++ ){
 for ( j = 0 ; j < 4 ; j++ ){
 cout << " |" << mat_oculta [i] [j] << "| ";
 if ( j == 3 ){
 cout << "\n \n" ;
 }
 }
 }

 cout << "\nSelecione a linha da primeira carta:"<< endl;
 cin >> n;
 cout << "\nSelecione a coluna primeira carta"<< endl;
 cin >> o;

 n--;
 o--;

 while ( mat_oculta[n][o] != 0){
 cout << "\nOuve um evicovo, essa carta já foi selecionada." << endl;
 cout << "\nSelecione a linha da primeira carta:"<< endl;
 cin >> n;
 cout << "\nSelecione a coluna primeira carta"<< endl;
 cin >> o;
 cout << "\n" << endl;
 n--;
 o--;
 }

 mat_oculta [n][o] = mat_jogo[n][o];

 jogada_1 = mat_oculta [n] [o];

 for ( i = 0 ; i < 4 ; i++ ){
 for ( j = 0 ; j < 4 ; j++ ){
 cout << " |" << mat_oculta [i] [j] << "| ";
 if ( j == 3 ){
 cout << "\n \n" ;
 }
 }
 }

 cout << "\nSelecione a linha da segunda carta:"<< endl;
 cin >> l;
 cout << "\nSelecione a coluna segunda carta"<< endl;
 cin >> m;

 l--;
 m--;

 while ( mat_oculta[l][m] != 0){
 cout << "\nOuve um evicovo, essa carta já foi selecionada." << endl;
 cout << "\nSelecione a linha da segunda carta:"<< endl;
 cin >> l;
 cout << "\nSelecione a coluna segunda carta"<< endl;
 cin >> m;
 cout << "\n" << endl;
 l--;
 m--;
 }



 mat_oculta [l][m] = mat_jogo[l][m];

 jogada_2 = mat_oculta [l] [m];

 for ( i = 0 ; i < 4 ; i++ ){
 for ( j = 0 ; j < 4 ; j++ ){
 cout << " |" << mat_oculta [i] [j] << "| ";
 if ( j == 3 ){
 cout << "\n \n" ;
 }
 }
 }

 if ( jogada_1 == jogada_2 ){

 cout << "\nJogada ok" << endl;
 pontuacao++ ;
 if ( pontuacao == 8 ){

 system("CLS");
 k = 25;

 }

 } else {

 cout << "\nJogada errada" << endl;

 mat_oculta [n] [o] = 0;
 mat_oculta [l] [m] = 0;

 }

 system("pause");
 system("CLS");

 }

 if ( pontuacao == 8 ){

 cout << "*************************************************" << endl;
 cout << "* *" << endl;
 cout << "* Parabens! *" << endl;
 cout << "* Você está com a memoria em dia *" << endl;
 cout << "* *" << endl;
 cout << "*************************************************" << endl;

 } else {

 cout << "*************************************************" << endl;
 cout << "* *" << endl;
 cout << "* Game Over *" << endl;
 cout << "* Você precisa melhorar sua memoria *" << endl;
 cout << "* *" << endl;
 cout << "*************************************************" << endl;

 }

 return 0;

 }
