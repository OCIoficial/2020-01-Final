// Adapted from vardieri.cpp
import java.io.*;
import java.util.*;

class cubos {
    static public void main(String args[]) throws Exception {
        Scanner in = new Scanner(System.in);

        Cube cube1 = new Cube(in);
        Cube cube2 = new Cube (in);

        System.out.println(cube1.equalsUpToRotation(cube2) ? "1" : "0");
    }
}

class Cube {
    int[] arr = new int[6];

    public Cube(Scanner in) {
        for (int i = 0; i < 6; ++i) {
            arr[i] = in.nextInt();
        }
    }

    public Cube(int arr[]) {
        for (int i = 0; i < 6; ++i) {
            this.arr[i] = arr[i];
        }
    }

    public Cube rotateHorizontally() {
        int arr[] = this.arr.clone();
        int aux = 0;
        aux = arr[2];
        arr[2] = arr[3];
        arr[3] = arr[4];
        arr[4] = arr[5];
        arr[5] = aux;
        return new Cube(arr);
    }

    public Cube rotateVertically() {
        int arr[] = this.arr.clone();
        int aux = 0;
        aux = arr[0];
        arr[0] = arr[2];
        arr[2] = arr[1];
        arr[1] = arr[4];
        arr[4] = aux;
        return new Cube(arr);
    }

    public boolean equalsUpToRotation(Cube rhs) {
        for (int i = 0; i < 5; ++i) {
            if (equalsUpToHorizontalRotation(rhs))
                return true;
            rhs = rhs.rotateVertically();
        }
        rhs = rhs.rotateHorizontally().rotateVertically();
        if (equalsUpToHorizontalRotation(rhs))
            return true;
        rhs = rhs.rotateVertically().rotateVertically();
        if (equalsUpToHorizontalRotation(rhs))
            return true;
        return false;
    }

    public boolean equalsUpToHorizontalRotation(Cube rhs) {
        for (int i = 0; i < 5; ++i) {
            if (exactlyEqual(rhs))
                return true;
            rhs = rhs.rotateHorizontally();
        }
        return false;
    }

    public boolean exactlyEqual(Cube rhs) {
        for (int i = 0; i < 5; ++i) {
            if (arr[i] != rhs.arr[i])
                return false;
        }
        return true;
    }
}
