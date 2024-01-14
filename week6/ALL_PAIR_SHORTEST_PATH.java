//JAVA 
import java.util.*;

class Main {
    static final int MAX_VERTICES = 111111;
    static final int MAX_EDGES = 311111;

    static List<Edge>[] adjacencyList = new ArrayList[MAX_EDGES];
    static boolean[] visited = new boolean[MAX_VERTICES];
    static int[] minDistances = new int[MAX_VERTICES];
    static int numVertices, numEdges;

    static class Edge {
        int destination;
        int weight;

        Edge(int destination, int weight) {
            this.destination = destination;
            this.weight = weight;
        }
    }

    static void applyDijkstra(int startVertex) {
        PriorityQueue<int[]> minHeap = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        Arrays.fill(minDistances, Integer.MAX_VALUE);
        Arrays.fill(visited, false);
        minDistances[startVertex] = 0;
        minHeap.add(new int[]{0, startVertex});

        while (!minHeap.isEmpty()) {
            int[] current = minHeap.poll();
            int currentVertex = current[1];

            if (!visited[currentVertex]) {
                for (Edge neighbor : adjacencyList[currentVertex]) {
                    int nextVertex = neighbor.destination;
                    int edgeWeight = neighbor.weight;

                    if (minDistances[nextVertex] > minDistances[currentVertex] + edgeWeight) {
                        minDistances[nextVertex] = minDistances[currentVertex] + edgeWeight;
                        minHeap.add(new int[]{minDistances[nextVertex], nextVertex});
                    }
                }
            }

            visited[currentVertex] = true;
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        numVertices = scanner.nextInt();
        numEdges = scanner.nextInt();

        for (int i = 1; i <= numVertices; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        for (int i = 0; i < numEdges; i++) {
            int source = scanner.nextInt();
            int destination = scanner.nextInt();
            int weight = scanner.nextInt();
            adjacencyList[source].add(new Edge(destination, weight));
        }

        for (int i = 1; i <= numVertices; i++) {
            applyDijkstra(i);

            for (int j = 1; j <= numVertices; j++) {
                if (i == j) {
                    System.out.print(0 + " ");
                } else {
                    System.out.print(minDistances[j] + " ");
                }
            }

            System.out.println();
        }
    }
}
