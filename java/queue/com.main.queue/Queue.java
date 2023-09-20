package com.main.queue;

public class Queue implements IQueue {

    public Node head;
    public Node tail;

    public Queue(){
        this.head = null;
        this.tail = null;
    }


    @Override
    public void push(float value) {
        Node newItem = new Node(value);

        if(tail == null){
            tail = newItem;
            head = newItem;
            return;
        }

        tail.next = newItem;
        newItem.prev = tail;
        tail = newItem;
    }


    @Override
    public Float pop() {
        if(head == null) return null;

        float tmp = head.value;
        head.next.prev = null;
        head = head.next;

        return tmp;
    }

    @Override
    public float front() {
        return head.value;
    }

    @Override
    public float back() {
        return tail.value;
    }

    @Override
    public int size(){
        return Node.count;
    }


    @Override
    public void printing(){
        System.out.print("[");

        for(Node item = head; item != null; item = item.next){
            System.out.print(item.value);

            if(item.next != null) System.out.print(", ");
        }

        System.out.println("]");
    }

}
