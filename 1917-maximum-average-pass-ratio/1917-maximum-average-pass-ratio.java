class Solution {
    double maxAverageRatio(int[][] classes, int extraStudents) {

        PriorityQueue<double[]> pq = new PriorityQueue<>(
            (a, b) -> Double.compare(b[0], a[0])
        );

        for( int[] c : classes){
            int p = c[0], t = c[1];
            pq.offer(new double[]{gainCalculate(p, t), p, t});
        }

        while(extraStudents>0){
            double[] top = pq.poll();
            int p = (int) top[1];
            int t = (int) top[2];
            p++;
            t++;
            pq.offer(new double[]{gainCalculate(p, t), p, t});
            extraStudents--;
        }

        double total = 0.0;
        while (!pq.isEmpty()) {
            double[] cur = pq.poll();
            int p = (int) cur[1];
            int t = (int) cur[2];
            total += (double) p / t;
        }

        return  total/classes.length;
    }
    public double gainCalculate(int pass, int total){
       return (double)(pass + 1) / (total + 1) - (double) pass / total;
    }
}