package brimzi.ds;


public class SegmentTree {
    private final int[] segtree;
    private final int[] ar;
    public SegmentTree(int[] a){
        this.segtree = new int[2*a.length];
        this.ar=a;
        build(1,0,ar.length-1);
    }

    private int build(int node, int start, int end){

        if(start==end){
            segtree[node]=ar[start];
            return segtree[node];
        }

        int m= start + (end-start)/2;
        int left = build(node*2,start,m);
        int right = build(node*2+1,m+1,end);
        segtree[node] = left +right;
        return segtree[node];
    }

    int query(int l,int r){
        return query(1,0,ar.length-1,l,r);
    }

    void update(int idx,int val){
         update(1,0,ar.length-1,idx,val);
    }

    private int query(int node,int start,int end,int l,int r){

        if(start>r || end <l){//out of range
            return 0;
        }

        if(start >= l && end <= r){//fully falls within range
            return segtree[node];
        }

        int m= start + (end-start)/2;

        int left = query(node*2,start,m,l,r);
        int right = query(node*2+1,m+1,end,l,r);

        return left + right;
    }

    private void update(int node,int start,int end,int idx,int val){

        if(start==end){
            ar[idx]+=val;
            segtree[node]+=val;
            return;
        }

        int m = start+ (end-start)/2;
        if(idx <= m){
            update(node*2,start,m,idx,val);
        }else{
            update(node*2+1,m+1,end,idx,val);
        }
        segtree[node]+=val;
    }

    public static void main(String[] args) {

        int[] a = {2,3,4,1,4,3,0,7,4};
        SegmentTree t = new SegmentTree(a);

        System.out.println(t.query(1,4));
        System.out.println(t.query(3,7));
        System.out.println(t.query(2,8));
        t.update(2,3);
        t.update(4,1);
        t.update(6,4);
        t.update(7,5);
        System.out.println("after update");
        System.out.println(t.query(1,4));
        System.out.println(t.query(3,7));
        System.out.println(t.query(2,8));
    }
}
