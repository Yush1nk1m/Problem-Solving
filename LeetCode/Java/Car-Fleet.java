class Solution {

    class Car implements Comparable<Car> {
        int position, speed;
        double time;

        public Car(int position, int speed) {
            this.position = position;
            this.speed = speed;
        }

        public int compareTo(Car other) {
            return Integer.compare(other.position, position);
        }
    }

    Car[] cars;
    Stack<Car> fleet = new Stack<>();

    public int carFleet(int target, int[] position, int[] speed) {
        cars = new Car[position.length];
        for (int i = 0; i < position.length; ++i) {
            cars[i] = new Car(position[i], speed[i]);
            cars[i].time = (double) (target - position[i]) / speed[i];
        }
        Arrays.sort(cars);

        fleet.push(cars[0]);
        for (int i = 1; i < cars.length; ++i) {
            if (fleet.peek().time < cars[i].time)
                fleet.push(cars[i]);
        }

        return fleet.size();
    }
}
