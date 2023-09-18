package com.main.linkedlist;

public class LinkedList implements ILinkedList {
    public Node head;
    public Node tail;

    public LinkedList(){
        this.head = null;
        this.tail = null;
    }


    @Override
    public void push_front(float value) {
        Node newItem = new Node(value);

        if(head == null){
            head = newItem;
            tail = newItem;
            return;
        }

        newItem.next = head;
        head.prev = newItem;

        head = newItem;
    }


    @Override
    public void push_back(float value){
        Node newItem = new Node(value);

        if(tail == null){
            tail = newItem;
            head = newItem;
            return;
        }

        newItem.prev = tail;
        tail.next = newItem;
        tail = newItem;
    }


    @Override
    public Float pop_front(){
        if(head == null) return null;

        if(Node.count == 1){
            float val = head.value;
            head = null;
            return val;
        }

        float val = head.value;
        head.next.prev = null;
        head = head.next;

        Node.decreaseLength();

        return val;
    }


    @Override
    public Float pop_back(){
        if(tail == null) return null;

        if(Node.count == 1){
            float val = tail.value;
            tail = null;
            return val;
        }

        float val = tail.value;
        tail.prev.next = null;
        tail = tail.prev;

        Node.decreaseLength();

        return val;
    }


    @Override
    public void insert(float value, int index){
        if(index <= 0) {
            push_front(value);
            return;
        } else if(Node.count < index) {
            push_back(value);
            return;
        }

        Node newItem = new Node(value);

        Node place = searchPlace(index);

        place.prev.next = newItem;
        newItem.prev = place.prev;
        newItem.next = place;
        place.prev = newItem;
    }


    private Node searchPlace(int index){
        int i = 0;

        for(Node item = head; item != null; item = item.next){
            if(i == index) return item;
            i++;
        }

        return null;
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

    @Override
    public int getLength(){
        return Node.count;
    }


}
