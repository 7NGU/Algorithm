package WeekTwo;

import edu.princeton.cs.algs4.StdOut;

import java.util.Iterator;

public class Deque<Item> implements Iterable<Item> {

    private int count;
    private Node first;
    private Node last;

    private class Node {
        Item item;
        Node leftNext;
        Node rightNext;
    }

    // construct an empty deque
    public Deque() {
        count = 0;
        first = null;
        last = null;
    }

    // is the deque empty?
    public boolean isEmpty() {
        return count == 0;
    }

    // return the number of items on the deque
    public int size() {
        return count;
    }

    // add the item to the front
    public void addFirst(Item item) {
        if (item == null) {
            throw new java.lang.IllegalArgumentException("item is null");
        } else {
            Node oldfirst = first;

            first = new Node();   // 新加入节点元素
            first.item = item;
            first.leftNext = null;
            first.rightNext = null;

            if (!isEmpty()) { // 原队列中有元素
                first.rightNext = oldfirst;
                oldfirst.leftNext = first;
            } else { //原队列中无元素
                last = first;
            }
            count++;
        }
    }

    // add the item to the back
    public void addLast(Item item) {
        if (item == null) {
            throw new java.lang.IllegalArgumentException("item is null");
        } else {
            Node oldlast = last;

            last = new Node();
            last.item = item;
            last.leftNext = null;
            last.rightNext = null;

            if (!isEmpty()) {
                last.leftNext = oldlast;
                oldlast.rightNext = last;
            } else {
                first = last;
            }
            count++;
        }
    }

    // remove and return the item from the front
    public Item removeFirst() {
        if (isEmpty()) {
            throw new java.util.NoSuchElementException("the WeekTwo.Deque is empty");
        } else {
            Node oldfirst = first;
            count--;
            if (count == 0) {
                first = null;
                last = null;
            } else {
                first = first.rightNext;
                oldfirst.rightNext = null;
                first.leftNext = null;
            }
            return oldfirst.item;
        }
    }

    // remove and return the item from the back
    public Item removeLast() {
        if (isEmpty()) {
            throw new java.util.NoSuchElementException("the WeekTwo.Deque is empty");
        } else {
            Node oldlast = last;
            count--;
            if (count == 0) {
                last = null;
                first = null;
            } else {
                last = last.leftNext;
                oldlast.leftNext = null;
                last.rightNext = null;
            }
            return oldlast.item;
        }
    }

    // return an iterator over items in order from front to back
    public Iterator<Item> iterator() {
        return new MyDequeIterator();
    }

    private class MyDequeIterator implements Iterator<Item> { //实现迭代器的内部类
        private Node current = first;  //当前节点元素

        public boolean hasNext() {
            return current != null;
        }

        public Item next() {
            if (!hasNext()) {
                throw new java.util.NoSuchElementException("the naxt() is overflow");
            } else {
                Item item = current.item;
                current = current.rightNext;
                return item;
            }
        }

        public void remove() {
            throw new java.lang.UnsupportedOperationException("remove method is unsupported");
        }
    }

    // unit testing (required)
    public static void main(String[] args) {
        Deque<String> deque = new Deque<String>();
        deque.addFirst("addfirst1");
        deque.addFirst("addfirst2");
        deque.addLast("addlast1");
        deque.addLast("addlast2");
        deque.addFirst("addfirst3");
        for (String s:deque)
            StdOut.println(s);
        System.out.println(deque.size());
        deque.removeFirst();
        deque.removeLast();
        deque.addFirst("addfirst4");
        deque.addFirst("addfirst5");
        deque.addLast("addlast3");
        for (String s:deque)
            StdOut.println(s);
    }

}
