package com.main.linkedlist;

public class Node {
  float value;
  Node next;
  Node prev;

  private static int count; // for length 

  public class Node(float value){
    this.value = value;
    this.next = null;
    this.prev = null;
  }

}
