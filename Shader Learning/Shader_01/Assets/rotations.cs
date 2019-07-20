using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rotations : MonoBehaviour {

    public Transform target;
    public float smooth = 5.0F;
    void Update()
    {
        transform.position = Vector3.Lerp(transform.position, target.position, Time.deltaTime * smooth);
    }
}
