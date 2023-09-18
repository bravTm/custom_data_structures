package com.main.stack;

public class Node {

    public float value;
    Node prev;

    public static int count = 0;

    public Node(float value){
        this.value = value;
        this.prev = null;

        count++;
    }


    public static void decreaseLength(){
        count--;
    }

}
