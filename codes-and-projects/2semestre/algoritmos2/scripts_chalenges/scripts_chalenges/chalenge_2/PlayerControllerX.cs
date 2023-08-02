using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerControllerX : MonoBehaviour
{
    public GameObject dogPrefab;

    private float cont= 0.0f;

    // Update is called once per frame
    void Update()
    {
        cont = cont + Time.deltaTime;

        // On spacebar press, send dog
        if (Input.GetKeyDown(KeyCode.Space) && (cont > 2.0f))
        {
            Instantiate(dogPrefab, transform.position, dogPrefab.transform.rotation);
            cont= 0.0f;
        }
    }
}
