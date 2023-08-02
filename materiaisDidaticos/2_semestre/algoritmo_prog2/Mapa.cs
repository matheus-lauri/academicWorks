using System.Collections;
using System.Collections.Generic;
using UnityEngine;

using System.IO; //necessário para leitura do arquivo


public class Mapa : MonoBehaviour
{
    //--------------------------
    public GameObject parede;
    //--------------------------
    // Start is called before the first frame update
    void Start()
    {
        CriaMapa();
    }

    void CriaMapa () {
        // -- Comando para ler do arquivo e salvar na matriz de inteiros --
        //meu arquivo é um csv, mas funciona com qualquer extensão de arquivo
        string arquivo = File.ReadAllText( @"D:\Workspace\UNITY\Aula\Labirinto\Files\m1.csv" );
        int[,] mapa = new int[41, 41];
        int i=0, j=0;
        
        foreach (var row in arquivo.Split('\n')) {
            j = 0;
            //separei meus números com vírgula, se o de vocês for espaço é só trocar no .Split()
            foreach (var col in row.Trim().Split(',')) { 
                mapa[i, j] = int.Parse(col.Trim());
                j++;
            }
            i++;
        }                                                                 
        // ----------------------------------------------------------------
        
        // -- percorre a matriz e insere o objeto quando lê 1 na matriz ---
        for (i=0; i<41; i++) {
            for (j=0; j<41; j++) {
                if (mapa[i,j] == 1){
                    //-20 é o ajuste para começar na parte superior esquerda
                    //posiciona em 2 de altura, pois o objeto altura 4 tem tamanho 2 para cima e 2 para baixo
                    Vector3 p = new Vector3(i-20f, 2.0f, j-20f); 
                    Instantiate(parede, p, Quaternion.identity);
                }
            }    
        }
        // ----------------------------------------------------------------
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
