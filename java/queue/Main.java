/* 

-------------------------- CUSTOM DATA STRUCTURE in Java - Queue -----------------------------
__ Created by https://github.com/bravTm

*/

import com.main.queue.*;

public class Main {
    public static void main(String[] args){
        Queue q = new Queue();

        q.push(10);
        q.push(3.5f);
        q.push(5.22f);

        q.printing(); // [10.0, 3.5, 5.22]

        System.out.println(q.pop()); // 10.0
        q.printing(); // [3.5, 5.22]

        System.out.println("HEAD: " + q.front() + "\tBACK: " + q.back()); // HEAD: 3.5	BACK: 5.22
    }
}

