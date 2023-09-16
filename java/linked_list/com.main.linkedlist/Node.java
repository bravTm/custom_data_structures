package com.main.linkedlist;

public class Node {
    public float value;
    public Node prev;
    public Node next;

    public static int count = 0; // for length

    public Node(float value) {
        this.value = value;
        this.prev = null;
        this.next = null;

        count++;
    }

    public static void decreaseLength(){
        count--;
    }
}
