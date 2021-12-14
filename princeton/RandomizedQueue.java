package WeekTwo;

import edu.princeton.cs.algs4.StdOut;
import edu.princeton.cs.algs4.StdRandom;

import java.util.Iterator;

public class RandomizedQueue<Item> implements Iterable<Item> {
    private Item[] itemArray;
    private int count;

    // construct an empty randomized queue
    public RandomizedQueue() {
        itemArray = (Item[]) new Object[2];
        count = 0;
    }

    // is the randomized queue empty?
    public boolean isEmpty() {
        return count == 0;
    }

    // return the number of items on the randomized queue
    public int size() {
        return count;
    }

    // add the item
    public void enqueue(Item item) {
        if (item == null) {
            throw new java.lang.IllegalArgumentException("Item is null");
        } else {
            if (count == itemArray.length) { //数组已满
                resize(2 * itemArray.length);
            }
            itemArray[count++] = item;
        }
    }

    // remove and return a random item
    public Item dequeue() {
        if (count == 0) {
            throw new java.lang.IllegalArgumentException("the queue is empty");
        } else {
            int deletei = StdRandom.uniform(0, count);
            Item itemi = itemArray[deletei];
            if (deletei != --count) {
                itemArray[deletei] = itemArray[count]; // 用最后一个元素覆盖删除元素的位置
                itemArray[count] = null;
            }

            if (count > 0 && count == itemArray.length/4) { // 数组有效长度为四分之一，调整数组空间大小
                resize(itemArray.length / 2);
            }

            return itemi;
        }
    }

    // return a random item (but do not remove it)
    public Item sample() {
        if (count == 0) {
            throw new java.util.NoSuchElementException("the queue is empty");
        }
        else {
            int samplei = StdRandom.uniform(0, count); // 随机选取返回节点
            Item itemi = itemArray[samplei];   // itemi 为随机选取元素值
            return itemi;
        }
    }

    // return an independent iterator over items in random order
    public Iterator<Item> iterator() {
        return new MyRandomQueueIterator();
    }

    // 实现迭代器

    private class MyRandomQueueIterator implements Iterator<Item> {
        private int current = count; // current表示数组中有效数据个数
        private Item[] iterItemArray;
        public MyRandomQueueIterator() {
            iterItemArray = (Item[])new Object[current];
            for (int i = 0; i < current; i++) {
                iterItemArray[i] = itemArray[i];
            }
        }

        public boolean hasNext() {
            return current != 0;
        }

        public Item next() { // 随机选findi，将findi与末尾位置互换
            if (!hasNext()) {
                throw new java.util.NoSuchElementException("the naxt() is overflow");
            }
            else {
                int findi = StdRandom.uniform(0, current); // 随机选取本次访问位置
                Item itemi = iterItemArray[findi];
                --current;
                iterItemArray[findi] = iterItemArray[current];
                iterItemArray[current] = itemi;

                return itemi; // 返回本次选取数据
            }
        }

        public void remove() {
            throw new java.lang.UnsupportedOperationException("remove method is unsupported");
        }
    }


    // 数组长度加倍
    private void resize(int capacity) {  // 数组长度加倍
        Item[] copy = (Item[]) new Object[capacity];  // 新的数组
        for (int i = 0; i < count; i++)
            copy[i] = itemArray[i];
        itemArray = copy;
    }

    // unit testing (required)
    public static void main(String[] args) {

        RandomizedQueue<String> myRandomizedQueue = new RandomizedQueue<String>();
        myRandomizedQueue.enqueue("add1");
        myRandomizedQueue.enqueue("add2");
        myRandomizedQueue.enqueue("add3");
        myRandomizedQueue.enqueue("add4");
        myRandomizedQueue.enqueue("add5");
        myRandomizedQueue.enqueue("add6");
        myRandomizedQueue.enqueue("add7");
        myRandomizedQueue.enqueue("add8");
        myRandomizedQueue.enqueue("add9");
        myRandomizedQueue.enqueue("add10");
        myRandomizedQueue.enqueue("add11");
        System.out.println(myRandomizedQueue.size());
        System.out.println(myRandomizedQueue.dequeue());
        System.out.println(myRandomizedQueue.sample());
        System.out.println(myRandomizedQueue.size());
        for (int i = 0; i < 10; i++) {
            // System.out.println(myRandomizedQueue.sample());
        }

        for (String s:myRandomizedQueue) {
            StdOut.println(s);
        }
    }

}
