package com.main.linkedlist;

public class Node {
    public float value;
    public Node next;
    public Node prev;

    public static int count; // for length

    public Node(float value){
        this.value = value;
        this.next = null;
        this.prev = null;

        count++;
    }


    public static void decreaseLength(){
        count--;
    }

}
