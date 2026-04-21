const graph = {
    A: { B: 2, C: 4 },
    B: { A: 2, C: 1, D: 7 },
    C: { A: 4, B: 1, D: 3 },
    D: { B: 7, C: 3 }
};

// Dijkstra
function dijkstra(start, end) {
    let dist = {};
    let prev = {};
    let visited = new Set();

    for (let node in graph) {
        dist[node] = Infinity;
        prev[node] = null;
    }

    dist[start] = 0;

    while (true) {
        let curr = null;

        for (let node in dist) {
            if (!visited.has(node)) {
                if (curr === null || dist[node] < dist[curr]) {
                    curr = node;
                }
            }
        }

        if (curr === null) break;

        visited.add(curr);

        for (let neighbor in graph[curr]) {
            let newDist = dist[curr] + graph[curr][neighbor];

            if (newDist < dist[neighbor]) {
                dist[neighbor] = newDist;
                prev[neighbor] = curr;
            }
        }
    }

    let path = [];
    let cur = end;

    while (cur) {
        path.unshift(cur);
        cur = prev[cur];
    }

    return { path, cost: dist[end] };
}

// reset
function reset() {
    document.querySelectorAll("circle").forEach(c => c.classList.remove("active"));
    document.querySelectorAll("line").forEach(l => l.classList.remove("path"));
}

// highlight
function highlight(path) {
    reset();

    path.forEach(n => {
        document.getElementById(n).classList.add("active");
    });

    for (let i = 0; i < path.length - 1; i++) {
        let e1 = path[i] + path[i + 1];
        let e2 = path[i + 1] + path[i];

        let edge = document.getElementById(e1) || document.getElementById(e2);

        if (edge) edge.classList.add("path");
    }
}

// run
function findPath() {
    let start = document.getElementById("start").value;
    let end = document.getElementById("end").value;

    let result = dijkstra(start, end);

    if (result.cost === Infinity) {
        document.getElementById("output").innerHTML =
            "❌ No path exists";
        return;
    }

    highlight(result.path);

    document.getElementById("output").innerHTML =
        "Shortest Path: " + result.path.join(" → ") +
        "<br>Cost: " + result.cost;
}