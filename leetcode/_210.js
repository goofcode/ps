const findOrder = (numCourses, prerequisites) => {
  const adj = new Array(numCourses).fill(null).map(() => []);
  const indegree = new Array(numCourses).fill(0);
  const visited = new Array(numCourses).fill(false);

  const result = [];

  for (const [cur, pre] of prerequisites) {
    adj[pre].push(cur);
    indegree[cur]++;
  }

  const dfs = (node) => {
    result.push(node);
    visited[node] = true;
    for (const next of adj[node]) {
      indegree[next]--;
      if (indegree[next] === 0 && !visited[next]) {
        dfs(next);
      }
    }
  };

  for (let i = 0; i < numCourses; i++) {
    if (indegree[i] === 0 && !visited[i]) {
      dfs(i);
    }
  }

  return result.length === numCourses ? result : [];
};

console.log(findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]));
console.log(findOrder(2, [[0, 1]]));
console.log(findOrder(1, []));
