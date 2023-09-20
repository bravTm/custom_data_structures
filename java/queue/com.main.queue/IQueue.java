package com.main.queue;

public interface IQueue {

    void push(float value);
    Float pop(); // Float for  null and type float
    float front(); // get first element
    float back(); // get last element
    int size();
    void printing();

}
