const simplifyPath = (path) => {
  const dirs = path.split('/').filter((s) => s);
  const result = [];
  for (const dir of dirs) {
    if (dir === '..') {
      if (result.length > 0) result.pop();
      continue;
    }
    if (dir === '.') {
      continue;
    }

    result.push(dir);
  }
  return `/${result.join('/')}`;
};

console.log(simplifyPath('/a/./b/../../c/'));
