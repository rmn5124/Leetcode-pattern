function reverse(a) {
    if (!a.length) return a;
     return reverse(a.slice(1)).concat(a[0]);
}
