package com.main.queue;

public class Node {

    float value;
    Node prev;
    Node next; // for head

    public static int count = 0;


    public Node(float value){
        this.value = value;
        this.prev = null;
        this.next = null;

        count++;
    }


    public static void decreaseLength(){
        count--;
    }

}
