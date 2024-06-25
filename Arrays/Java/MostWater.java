class MostWater{
    public int maxArea(int[] height) {
        int i =0;
        int j = height.length-1;
        int area = 0;
        int maxArea = 0;
        while(i<j){
            if (height[i]<height[j]) {
                area = height[i] * (j - i);
                i++;
            }
            else {
                area = height[j] * (j - i);
                j--;
            }
            maxArea = Math.max(area, maxArea);

        }
        return maxArea;
    }
    public static void main(String[] args){
        MostWater mw = new MostWater();
        System.out.println(mw.maxArea(new int[]{1,8,6,2,5,4,8,3,7}));
    }
}