package com.main.linkedlist;

public interface ILinkedList {

    public void push_front(float value);
    public void push_back(float value);
    public Float pop_front(); // Float for (null and float)
    public Float pop_back();
    public void insert(float value, int index);
    public void printing();
    public int getLength();

}
