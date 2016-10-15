package study;

public class SelectionSort
{
    public static void main(String args[])
    {
        System.out.println("Selection Sort");
    }

    public void selectionSortRecursive(int[] data)
    {
        selectionSortRecursive(data, 0);
    }

    private void selectionSortRecursive(int[] data, int start)
    {
        if(start < data.length - 1) {
            swap(data, start, findMinimumIndex(data, start));
            selectionSortRecursive(data, start + 1);
        }
    }

    private int findMinimumIndex(int[] data, int start)
    {
        int minPos = start;
        for(int i = start + 1; i < data.length; ++i){
            if(data[i] < data[minPos]){
                minPos = i;
            }
        }
        return minPos;
    }

    private void swap(int[] data, int index1, int index2){
        if(index1 != index2){
            int tmp = data[index1];
            data[index1] = data[index2];
            data[index2] = tmp;
        }
    }
}
