/* 

-------------------------- CUSTOM DATA STRUCTURE in Java - Secondly Linked List -----------------------------
__ Created by https://github.com/bravTm

*/

import com.main.linkedlist.*;

public class Main {
    public static void main(String[] args){
        LinkedList list = new LinkedList();

        list.push_front(2);
        list.push_front(3);
        list.push_front(5);
        list.push_front(6);

        list.push_back(10);

        list.pop_back();
        list.pop_front();

        list.insert(333, 1);

        list.printing(); // [5.0, 3.0, 2.0, 333.0]
        System.out.println(list.getLength()); // 4
    }
}

