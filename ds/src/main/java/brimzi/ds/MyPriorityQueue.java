package brimzi.ds;

public class MyPriorityQueue {
    private final int[] ar;
    private int n;

    public MyPriorityQueue(int size) {
        this.ar = new int[size + 1];
    }

    void add(int v) {

        if (n >= ar.length) {
            throw new RuntimeException("exceeded capacity");
        }

        ar[++n] = v;
        swim(n);
    }

    int peek() {
        return ar[1];
    }

    int remove() {
        if (n < 1) {
            throw new RuntimeException("empty");
        }

        swap(1, n);
        int rtVal = ar[n--];
        sink(1);
        return rtVal;
    }

    int size() {
        return n > 0 ? n : 0;
    }

    private void swim(int pos) {
        if (pos <= 1) {
            return;
        }

        while (pos / 2 > 0) {
            if (ar[pos] > ar[pos / 2]) {
                swap(pos, pos / 2);
            } else {
                break;
            }
            pos=pos/2;
        }
    }

    private void sink(int pos) {

        while (pos * 2 <= n) {
            int child = pos * 2;
            if (child + 1 <= n && ar[child] < ar[child + 1]) {
                ++child;
            }

            if (ar[pos] < ar[child]) {
                swap(pos, child);
            } else {
                break;
            }
            pos = child;
        }
    }

    private void swap(int x, int y) {
        int tmp = ar[x];
        ar[x] = ar[y];
        ar[y] = tmp;
    }

    public static void main(String[] args) {

        int[] a = {4, 6, 9, 23, 5, 8, 5, 45,0,67,57,21};

        MyPriorityQueue q = new MyPriorityQueue(a.length);
        for (int v : a) {
            q.add(v);
        }

        System.out.println("size is :" + q.size());

        System.out.println("The order of values:");
        for (int i = 0; i < a.length; i++) {
            System.out.println(q.remove());
        }
    }
}
