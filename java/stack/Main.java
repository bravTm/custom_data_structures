/* 

-------------------------- CUSTOM DATA STRUCTURE on Java - Stack  -----------------------------
__ Created by https://github.com/bravTm

*/

import com.main.stack.*;


public class Main {

    public static void main(String[] args){

        Stack st = new Stack();

        st.push(10);
        st.push(20);
        st.push(4.5f);

        System.out.println(st.size()); // 3

        System.out.println(st.pop()); // 4.5
        System.out.println(st.size()); // 2

        System.out.println(st.top()); // 20
        st.printing(); // [20.0, 10.0]

    }
}

