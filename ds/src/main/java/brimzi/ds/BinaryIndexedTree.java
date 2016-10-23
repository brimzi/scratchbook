package brimzi.ds;

/**
 * Simple implementation of a binary indexed tree
 */
public class BinaryIndexedTree {

    private final int[] bit;

    public BinaryIndexedTree(int[] a){
        this.bit =new int[a.length+1];

        for(int i =0;i<a.length;i++){
            update(i,a[i]);
        }
    }

    void update(int idx,int value){
        for(int i=idx+1;i<bit.length;i +=  i & -i){
            bit[i]+=value;
        }
    }

    int query(int idx){
        int sum=0;
        for(int i=idx+1;i>=1;i-=i&-i){
            sum+=bit[i];
        }
        return sum;
    }

    public static void main(String[] args) {

        int[] a ={2,5,7,3,6,8,9,3,5,6,7};
        BinaryIndexedTree b =new BinaryIndexedTree(a);

        System.out.println(b.query(0));
        System.out.println(b.query(1));
        System.out.println(b.query(2));
        System.out.println(b.query(3));
        System.out.println(b.query(4));
        System.out.println(b.query(5));
        System.out.println(b.query(6));
        System.out.println(b.query(7));
        System.out.println(b.query(8));
        System.out.println(b.query(9));
        System.out.println(b.query(10));

        b.update(0,4);
        b.update(3,5);
        b.update(6,9);
        b.update(5,10);

        System.out.println("After updates");
        System.out.println(b.query(0));
        System.out.println(b.query(1));
        System.out.println(b.query(2));
        System.out.println(b.query(3));
        System.out.println(b.query(4));
        System.out.println(b.query(5));
        System.out.println(b.query(6));
        System.out.println(b.query(7));
        System.out.println(b.query(8));
        System.out.println(b.query(9));
        System.out.println(b.query(10));


    }
}
