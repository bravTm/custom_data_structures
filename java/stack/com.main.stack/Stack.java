package com.main.stack;

public class Stack implements IStack {

    public Node top; // for cycles

    public Stack(){
        this.top = null;
    }


    @Override
    public void push(float value) {
        Node newItem = new Node(value);

        if(top == null) {
            top = newItem;
            return;
        }

        newItem.prev = top;
        top = newItem;
    }


    @Override
    public float pop(){
        if(this.size() == 1){
            float tmp = top.value;
            top = null;
            return tmp;
        }

        float tmp = top.value;
        top = top.prev;

        Node.decreaseLength();

        return tmp;
    }


    @Override
    public float top() {
        return top.value;
    }

    @Override
    public void printing() {
        System.out.print("[");

        for(Node item = top; item != null; item = item.prev){
            // Countdown starts from the top (Top)
            System.out.print(item.value);
            if(item.prev != null) System.out.print(", ");
        }

        System.out.println("]");
    }

    @Override
    public int size() {
        return Node.count;
    }
}
