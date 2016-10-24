package brimzi.ds;


public class SegmentTree {
    private final int[] segtree;
    private final int[] ar;

    public SegmentTree(int[] a) {
        this.segtree = new int[2 * a.length];
        this.ar = a;
        build(1, 0, ar.length - 1);
    }

    private int build(int node, int start, int end) {

        if (start == end) {
            segtree[node] = ar[start];
            return segtree[node];
        }

        int m = start + (end - start) / 2;
        int left = build(node * 2, start, m);
        int right = build(node * 2 + 1, m + 1, end);
        segtree[node] = left + right;
        return segtree[node];
    }

    int query(int l, int r) {
        return query(1, 0, ar.length - 1, l, r);
    }

    void rangeUpdate(int idx, int val) {
        update(1, 0, ar.length - 1, idx, val);
    }

    void rangeUpdate(int l, int r, int val) {
        rangeUpdate(1, 0, ar.length - 1, l,r, val);
    }

    private int rangeUpdate(int node, int start, int end, int l, int r, int val) {

        if (start > r || end < l || start > end) {
            return 0;
        }

        if (start == end) {
            ar[start] += val;
            segtree[node] += val;
            return segtree[node];
        }
        int m = start + (end - start) / 2;

        int left = rangeUpdate(node * 2, start, m, l, r, val);
        int right = rangeUpdate(node * 2 + 1, m + 1, end, l, r, val);

        segtree[node] = left + right;
        return segtree[node];
    }

    private int query(int node, int start, int end, int l, int r) {

        if (start > r || end < l) {//out of range
            return 0;
        }

        if (start >= l && end <= r) {//fully falls within range
            return segtree[node];
        }

        int m = start + (end - start) / 2;

        int left = query(node * 2, start, m, l, r);
        int right = query(node * 2 + 1, m + 1, end, l, r);

        return left + right;
    }

    private void update(int node, int start, int end, int idx, int val) {

        if (start == end) {
            ar[idx] += val;
            segtree[node] += val;
            return;
        }

        int m = start + (end - start) / 2;
        if (idx <= m) {
            update(node * 2, start, m, idx, val);
        } else {
            update(node * 2 + 1, m + 1, end, idx, val);
        }
        segtree[node] += val;
    }

    public static void main(String[] args) {

        int[] a = {2, 3, 4, 1, 4, 3, 0, 7, 4};
        SegmentTree t = new SegmentTree(a);

        System.out.println(t.query(1, 4));
        System.out.println(t.query(3, 7));
        System.out.println(t.query(2, 8));
        t.rangeUpdate(2, 3);
        t.rangeUpdate(4, 1);
        t.rangeUpdate(6, 4);
        t.rangeUpdate(7, 5);
        System.out.println("after rangeUpdate");
        System.out.println(t.query(1, 4));
        System.out.println(t.query(3, 7));
        System.out.println(t.query(2, 8));

        t.rangeUpdate(0,8,1);
        System.out.println("after range rangeUpdate");
        System.out.println(t.query(1, 4));
        System.out.println(t.query(3, 7));
        System.out.println(t.query(2, 8));
    }
}
